#include <network/include/precompiled.h>
#include <network/include/manager.h>
#include <algorithm> 
#include <thread>
#include <atomic>

using namespace network;

namespace
{
/// @brief ���������� ���������� ������� ������
///
IdScanTask CreateIdScanTask(void)
{
	static std::atomic<IdScanTask> idScanTask = 0;
	return ++idScanTask;
}
}

IdScanTask Task::AddTask(const network::enums::TypeScan typeScan, const HostProfileManagerPtr& hostProfileManager)
{
	EthernetHostProfileList hostProfile;

	switch (typeScan)
	{
	case network::enums::Arp:
	{
		hostProfile = network::ArpScanProbe();
		break;
	}
	case network::enums::Icmp:
	{
		hostProfile = network::icmp::ScanIcmpProbe();
		break;
	}
	case network::enums::ArpHost:
	{
		hostProfile = network::ArpHostTableProbe();
		break;
	}
	default:
		break;
	}

	//���������� ���������
	hostProfileManager ? hostProfileManager->ChangeEthernetHostProfile(NO_TASK, hostProfile) : (void)hostProfileManager;

	network::logger::dump(hostProfile);

	return NO_TASK;
}

IdScanTask Task::AddThreadTask(const network::enums::TypeScan typeScan, const HostProfileManagerPtr& hostProfileManager)
{
	//��������� ������
	const auto idTask = CreateIdScanTask();
	BeginChangeHosts(idTask);

    auto self = shared_from_this();
	auto func = [self, hostProfileManager](const network::enums::TypeScan typeScan, const IdScanTask idTask)
	{
		EthernetHostProfileList hostTableProbe;

		switch (typeScan)
		{
		case network::enums::Arp:
		{
			hostTableProbe = network::ArpScanProbe();
			break;
		}
		case network::enums::Icmp:
		{
			hostTableProbe = network::icmp::ScanIcmpProbe();
			break;
		}
		case network::enums::ArpHost:
		{
			hostTableProbe = network::ArpHostTableProbe();
			break;
		}
		default:
			break;
		}

		//��������� ������
		self ? self->EndChangeHosts(hostTableProbe, idTask, hostProfileManager) : (void)self;
	};

	//��������� �����
	std::thread thread(func, typeScan, idTask);
	thread.detach();

	return idTask;
}


void Task::BeginChangeHosts(const IdScanTask idTask)
{
	if (idTask == NO_TASK || NO_TASK == INVALID_HANDLE){
		return;
	}

	//���������� �����
	std::lock_guard<std::mutex> lock(guard_);

	//��������� ������
	idScanTaskList_.insert(idTask);
}

void Task::EndChangeHosts(const EthernetHostProfileList& hostProfile, const IdScanTask idTask, const HostProfileManagerPtr& hostProfileManager)
{
	if (idTask == NO_TASK || NO_TASK == INVALID_HANDLE){
		return;
	}

	//���������� �����
	std::lock_guard<std::mutex> lock(guard_);

	//��������� ������
	idScanTaskList_.erase(idTask);

	//���������� ���������
	hostProfileManager ? hostProfileManager->ChangeEthernetHostProfile(idTask, hostProfile) : (void)hostProfileManager;

	network::logger::dump(hostProfile);
}

bool Task::IsTask(const IdScanTask idScan) const
{
	if (NO_TASK == idScan){
		return true;
	}

	if (INVALID_HANDLE == idScan){
		return true;
	}

	//���������� �����
	std::lock_guard<std::mutex> lock(guard_);

	return idScanTaskList_.find(idScan) == idScanTaskList_.end() ? true : false;
}

Task::Task()
{
}

Task::~Task()
{
}

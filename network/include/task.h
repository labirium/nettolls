#pragma once

#include <mutex>
#include <functional>

namespace network
{

/// @brief ����� ������������ ���������� ������
///
class Task : public std::enable_shared_from_this<Task>
{
public:
	/// @brief �����������
	///
	Task();
	/// @brief ����������
	///
	~Task();
public:
	/// @brief ������������ ���������� ������ � ��������� �����
	///
	/// @param[in] typeScan typeScan ��� ������������
	/// @param[in] hostProfileManager �������� ��������� ��� ��������� ���������� ������������ ����
	IdScanTask AddThreadTask(const network::enums::TypeScan typeScan, const HostProfileManagerPtr& hostProfileManager);
	/// @brief ������������ ���������� ������
	///
	/// @param[in] typeScan ��� ������������
	/// @param[in] hostProfileManager �������� ��������� ��� ��������� ���������� ������������ ����
	IdScanTask AddTask(const network::enums::TypeScan typeScan, const HostProfileManagerPtr& hostProfileManager);
	/// @brief �������� ������ ������������
	///
	/// @param[in] idScan ����� ������
	/// @return ���������� true ���� ������ ���������
	bool IsTask(const IdScanTask idScan) const;
private:
	/// @brief ������������ ��������� ������ ����� �� ������ ���������� ������������
	///
	/// @param[in] idTask ����� ������
	void BeginChangeHosts(const IdScanTask idTask);
	/// @brief ������������ ��������� ������ ����� �� ������ ���������� ������������
	///
	/// @param[in] ethernetHostProfile ������ �������� ������� ��������� 
	/// @param[in] idTask ����� ������
	/// @param[in] hostProfileManager �������� ��������� ��� ��������� ���������� ������������ ����
	void EndChangeHosts(const EthernetHostProfileList& ethernetHostProfile, const IdScanTask idTask, const HostProfileManagerPtr& hostProfileManager);
private:
	/// ������ �������� �����
	IdScanTaskList idScanTaskList_;
private:
	mutable std::mutex guard_;
};
}
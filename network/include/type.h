
#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <functional>


struct sockaddr_in;

namespace network
{

typedef enum tagProtectedLevel
{
	Unknown,
	Normal,
	TrustedVendors,
	Strict

}ProtectedLevel;

namespace protocol
{
class RpcClient;
/// ��������� �� �������� ���������� �����������
typedef std::shared_ptr<RpcClient> RpcClientPtr;

/// �������� ��������� ������
typedef std::map<std::wstring, std::wstring> MapData;
}

class RemoveHost;
/// ��������� �� ������� ����
typedef std::shared_ptr<RemoveHost> RemoveHostPtr;

class RemoveHostProfile;
/// ��������� �� �������� ���������� ����
typedef std::shared_ptr<RemoveHostProfile> RemoveHostProfilePtr;

class RemoveHostProfileManager;
/// ��������� �� �������� ��������� �����
typedef std::shared_ptr<RemoveHostProfileManager> RemoveHostProfileManagerPtr;
typedef std::map<RemoveHost, RemoveHostProfilePtr> RemoveHostList;


typedef std::function<void(const std::string& ethernetId, const std::string& host, const network::protocol::MapData& data)> RpcCallback;
typedef std::shared_ptr<RpcCallback> RpcCallbackPtr;

/// @brief �������� ���� ������������
typedef int IdScanTask;

class EthernetProfile;
/// @brief ��������� �� �������� ethernet
typedef std::shared_ptr<EthernetProfile> EthernetProfilePtr;
/// @brief ������ �� �������� ethernet
typedef std::vector<EthernetProfilePtr> EthernetProfileList;

class InterfaceProfiles;
/// @brief ��������� c������ ��������� ����������
typedef std::shared_ptr<InterfaceProfiles> InterfaceProfilesPtr;
/// @brief ������ �� c������ ��������� ����������
typedef std::vector<InterfaceProfilesPtr> InterfaceProfilesList;

/// @brief BLOB Mac �����
typedef std::vector<char> MacAddress;

class HostProfile;
/// @brief ��������� �� �������� �����
typedef std::shared_ptr<HostProfile> HostProfilePtr;
/// @brief ������ �����
typedef std::vector<HostProfilePtr> HostProfileList;

/// @brief ����������� �������� ���������� � ���������� ������
typedef std::map<EthernetProfilePtr, HostProfileList> EthernetHostProfileList;

/// @brief ��������� �� ����� �������������� ��������� ������
class Task;
typedef std::shared_ptr<Task> TaskPtr;

/// @brief ��������� �� ����� ���������� ������ ���������� ������������
class HostProfileManager;
typedef std::shared_ptr<HostProfileManager> HostProfileManagerPtr;

/// @brief ��������� �� ����� �������������� ����� ��������� � ����
class Manager;
typedef std::shared_ptr<Manager> ManagerPtr;
/// @brief ������ �����
typedef std::set<IdScanTask> IdScanTaskList;

namespace icmp
{
/// @brief Blob �����
typedef std::vector<char> BlobPacket;
}

}
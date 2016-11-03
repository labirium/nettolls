#pragma once

#include <mutex>

namespace network
{
namespace enums
{
	/// ��� ������������
	enum
	{
		/// Arp ������������
		Arp,
		/// ������ arp ������� �����
		ArpHost,
		/// Icmp ������������
		Icmp
	};

	/// ��� ������������
	typedef int TypeScan;

}

/// ���������� ��������
#define INVALID_HANDLE -1
/// ���������� ����
#define NO_TASK 0


/// @brief ����� ������������ ����� ��������� � ����
///
class Manager
{
public:
	/// @brief ������������
	///
	Manager( void );
	/// @brief ����������
	///
	~Manager();
	/// @brief ����������� �����������
	Manager(const Manager& that) = delete;
public:
	/// @brief ���������� ������ ������� �����������
	///
	network::EthernetProfileList GetEthernetProfileList(void) const;
	/// @brief ���������� ������ ������� ����� ��� ��������� ����������
	/// 
	/// @param[in] ethernetProfile �������� �������� ����������
	HostProfileList GetHostProfileList(const EthernetProfilePtr& ethernetProfile) const;
	/// @brief ���������� ������ ������� ����� ��� ��������� ����������
	/// 
	/// @param[in] index ������ �������� ����������
	HostProfileList GetHostProfileList(const uint64_t index) const;
public:
	/// @brief ������ ������ �� ������������
	///
	/// @param[in] typeScan ��� ������������
	/// @return ���������� 0 ���� ���������  �� ������� ����������� ���������
	///         ���������� INVALID_HANDLE ���� ������������ ��������� � �������
	///         ���������� �������� ��� �������� ��� ���������� � IdScanTask
	IdScanTask AddTask(const network::enums::TypeScan typeScan);
	/// @brief �������� ������ ������������
	///
	/// @param[idScan] ����� ������
	/// @return ���������� true ���� ������ ���������
	bool IsTask(const IdScanTask idScan) const;
private:
	/// �������� �����
	TaskPtr task_;
	/// �������� ������
	HostProfileManagerPtr hostProfileManager_;
};
}
#pragma once

#include <vector>

namespace networktools
{
namespace manager
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
typedef int32_t TypeScan;
;
}

/// @brief �������� ���� ������������
typedef int32_t IdScanTask;

/// @brief ��������� �������� ����
///
struct IHostProfile : public IUnknown
{
	/// @brief ���������� Ip �����
	///
	virtual BSTR STDMETHODCALLTYPE GetIp(void) const throw() = 0;
	/// @brief ���������� ����� ������
	///
	virtual uint64_t STDMETHODCALLTYPE GetTime(void) const throw() = 0;
};

/// @brief ��������� ������� ��������
///
struct IInterfaceProfiles : public IUnknown
{
	/// @brief ���������� Ip �����
	///
	virtual BSTR STDMETHODCALLTYPE GetIp(void) const throw() = 0;
	/// @brief ���������� �����
	///
	virtual BSTR STDMETHODCALLTYPE GetMask(void) const throw() = 0;
};

/// @breif ��������� �������� ����������
///
struct IEthernetProfile : public IUnknown
{
	/// @brief ���������� ������ �������� ����������
	///
	virtual uint64_t STDMETHODCALLTYPE GetIndex(void) const throw() = 0;
	/// @brief ���������� true ���� ��������� ������� VPN
	///
	virtual bool STDMETHODCALLTYPE IsVpn(void) const throw() = 0;
	/// @brief ���������� ��� ����������
	///
	virtual BSTR STDMETHODCALLTYPE GetName(void) const throw() = 0;
	/// @brief ���������� �������� ����������
	///
	virtual BSTR STDMETHODCALLTYPE GetDescription(void) const = 0;
public:
	/// @brief ���������� ������ ������� ��������
	///
	virtual SAFEARRAY FAR* STDMETHODCALLTYPE GetInterfaceProfiles(void) const throw() = 0;
};

/// @brief ��������� ��� �������� ��������������
///
struct INetworkManager : public IUnknown
{
	/// @brief ���������� ������ ������� �����������
	///
	virtual SAFEARRAY FAR* STDMETHODCALLTYPE GetNetworkEthernet(void) const throw() = 0;
	/// @brief ���������� ������ ������� ����� ��� ��������� ����������
	/// 
	/// @param[in] profile �������� �������� ����������
	virtual SAFEARRAY FAR* STDMETHODCALLTYPE GetHostProfileList(const IEthernetProfile& profile) const throw() = 0;
public:
	/// @brief ������ ������ � �������
	///
	/// @param[in] typeScan ��� ������������
	/// @return ���������� id ������
	virtual IdScanTask STDMETHODCALLTYPE AddTask(const enums::TypeScan typeScan) throw() = 0;
	/// @brief �������� ���������� ���������� ������
	/// 
	/// @param[in] idTask ������ 
	/// @return ���������� true ���� ������ ���������
	virtual bool STDMETHODCALLTYPE IsTask(const IdScanTask idTask) const throw() = 0;
};

}
}

// {864DFD92-00C7-43E4-8856-CD3490769CDA}
DEFINE_GUID(IID_IHostProfile,
0x864dfd92, 0xc7, 0x43e4, 0x88, 0x56, 0xcd, 0x34, 0x90, 0x76, 0x9c, 0xda);

// {6F4EBF8F-A620-4CEA-8A88-2A168563A9E0}
DEFINE_GUID(IID_InterfaceProfiles,
	0x6f4ebf8f, 0xa620, 0x4cea, 0x8a, 0x88, 0x2a, 0x16, 0x85, 0x63, 0xa9, 0xe0);

// {2B3F116C-2717-4A29-8C5E-50F2566BFFC7}
DEFINE_GUID(IID_IEthernetProfile,
	0x2b3f116c, 0x2717, 0x4a29, 0x8c, 0x5e, 0x50, 0xf2, 0x56, 0x6b, 0xff, 0xc7);

// {D1C66136-AB61-4F6C-8984-50B128750CD1}
DEFINE_GUID(IID_INetworkManager,
	0xd1c66136, 0xab61, 0x4f6c, 0x89, 0x84, 0x50, 0xb1, 0x28, 0x75, 0xc, 0xd1);

/// @brief Factory function
///
extern "C" NETWORK_TOOLS networktools::manager::INetworkManager* WINAPI CreateNetworkManager();

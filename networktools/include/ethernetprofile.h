#pragma once

namespace networktools
{
/// @breif ���������� �������� �������� ����������
///
class EthernetProfile : public networktools::manager::IEthernetProfile
{
public:
	/// @brief �����������
	///
	explicit EthernetProfile(const network::EthernetProfilePtr& ethernetProfile );
	/// @brief ����������
	///
	~EthernetProfile();
protected:
	/// @brief ���������� COM ������
	///
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject);
	/// @breif ������������ ���������� ������ COM �������
	///
	ULONG STDMETHODCALLTYPE AddRef(void);
	/// @breif ������������ ���������� ������ COM �������
	///
	ULONG STDMETHODCALLTYPE Release(void);
public:
	/// @brief ���������� ������ �������� ����������
	///
	uint64_t STDMETHODCALLTYPE GetIndex(void) const throw();
	/// @brief ���������� true ���� ��������� ������� VPN
	///
	bool STDMETHODCALLTYPE IsVpn(void) const throw();
	/// @brief ���������� ��� ����������
	///
	BSTR STDMETHODCALLTYPE GetName(void) const throw();
	/// @brief ���������� �������� ����������
	///
	BSTR STDMETHODCALLTYPE GetDescription(void) const throw();
public:
	/// @brief ���������� ������ ������� ��������
	///
	SAFEARRAY FAR* STDMETHODCALLTYPE GetInterfaceProfiles(void) const throw();
private:
	/// �������� �������� ����������
	network::EthernetProfilePtr ethernetProfile_;
private:
	/// �������� ���������� ������ �� ������
	ULONG ref_;
};
}

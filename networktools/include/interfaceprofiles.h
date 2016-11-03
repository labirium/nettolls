#pragma once

namespace networktools
{
/// @brief ��������� ������� ��������
///
class  InterfaceProfiles : public networktools::manager::IInterfaceProfiles
{
public:
	/// @brief �����������
	///
	/// @param[in] interfaceProfile �������� ������� ��������
	explicit InterfaceProfiles(const network::InterfaceProfilesPtr& interfaceProfile);
	/// @brief ����������
	///
	~InterfaceProfiles();
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
	/// @brief ���������� Ip �����
	///
	BSTR STDMETHODCALLTYPE GetIp(void) const throw();
	/// @brief ���������� �����
	///
	BSTR STDMETHODCALLTYPE GetMask(void) const throw();
private:
	/// �������� ������� ��������
	network::InterfaceProfilesPtr interfaceProfile_;
private:
	/// �������� ���������� ������ �� ������
	ULONG ref_;
};
}
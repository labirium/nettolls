#pragma once

namespace networktools
{
/// @brief �������� ����
///
class HostProfile : public networktools::manager::IHostProfile
{
public:
	/// @brief �����������
	///
	explicit HostProfile(const network::HostProfilePtr& hostprofile);
	/// @brief ����������
	///
	~HostProfile();
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
	/// @brief ���������� ����� ������
	///
	uint64_t STDMETHODCALLTYPE GetTime(void) const throw();
	/// @brief ���������� Ip �����
	///
	BSTR STDMETHODCALLTYPE GetIp(void) const throw();
private:
	/// �������� �������� ����������
	network::HostProfilePtr hostProfile_;
private:
	/// �������� ���������� ������ �� ������
	ULONG ref_;
};
}

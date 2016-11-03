#pragma once

namespace networktools
{
/// @brief ����� �������� ���������� ���������� �������� ��������������
///
class NetworkManager : public networktools::manager::INetworkManager
{
public:
	/// @brief �����������
	///
	NetworkManager();
	/// @brief ����������
	///
	~NetworkManager();
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
	/// @brief ���������� ������ ������� �����������
	///
	SAFEARRAY FAR* STDMETHODCALLTYPE GetNetworkEthernet(void) const throw();
	/// @brief ���������� ������ ������� ����� ��� ��������� ����������
	/// 
	/// @param[in] profile �������� �������� ����������
	SAFEARRAY FAR* STDMETHODCALLTYPE GetHostProfileList(const networktools::manager::IEthernetProfile& profile) const throw();
public:
	/// @brief ������ ������ � �������
	///
	/// @param[in] typeScan ��� ������������
	/// @return ���������� id ������
	manager::IdScanTask STDMETHODCALLTYPE AddTask(const manager::enums::TypeScan typeScan) throw();
	/// @brief �������� ���������� ���������� ������
	/// 
	/// @param[in] idTask ������ 
	/// @return ���������� true ���� ������ ���������
	bool STDMETHODCALLTYPE IsTask(const manager::IdScanTask idTask) const throw();
private:
	/// ������������ ����� ��������� � ����
	network::ManagerPtr manager_;
private:
	/// �������� ���������� ������ �� ������
	ULONG ref_;
};
}

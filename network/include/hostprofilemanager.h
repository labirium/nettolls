#pragma once

namespace network
{
/// @brief �������� � ������������ ��������� ������������ ����
///
class HostProfileManager
{
public:
	/// @brief �����������
	///
	HostProfileManager();
	/// @brief ����������
	///
	~HostProfileManager();
public:
	/// @brief ���������� ������ ������� ����� ��� ��������� ����������
	/// 
	/// @param[in] index ������ �������� ����������
	HostProfileList GetHostProfileList(const uint64_t index) const;
	/// @brief ������������ ��������� ������� ��������� ������ ���������
	///
	/// @param[in] task ����� �����
	/// @param[in] hostProfile ������ ���������
	void ChangeEthernetHostProfile(const IdScanTask task, const EthernetHostProfileList& hostProfile);
private:
	/// �������� ��������� ������������������� ������� ����
	EthernetHostProfileList ethernetHostsProfile_;
private:
	mutable std::mutex guard_;
};
}

#pragma once

namespace network
{
/// @brief �������� ����
///
class HostProfile
{
public:
	/// @brief �����������
	/// 
	/// @param[in] ip IP �����
	/// @param[in] mac ���������� �����
	/// @param[in] time ����� ��������� ������
	HostProfile(const struct in_addr& ip, const MacAddress& mac, const time_t time);
	/// @brief ����������
	///
	~HostProfile();
public:
	/// @brief ������������ ����������� ������� ���������� ����
	///
	void ChangeRemoveHostProfile(const RemoveHostProfilePtr& removeHostProfile);
public:
	/// @brief ���������� ���������� ������
	///
	const MacAddress& GetMacAddress(void) const;
	/// @brief ���������� Ip �����
	///
	const struct in_addr& GetIp(void) const;
	/// @brief ���������� ����� ������
	///
	time_t GetTime(void) const;
private:
	/// ip �����
	struct in_addr ip_;
	/// ���������� �����
	MacAddress mac_;
	/// ����� ������������ �������
	time_t time_;
};
}

#pragma once

namespace network
{
/// @brief ������� ��������� ����������
class InterfaceProfiles
{
public:
	/// @brief �����������
	///
	/// @param[in] ip �����
	/// @param[in] mask ����� ����
	InterfaceProfiles(const struct in_addr& ip, const struct in_addr& mask);
	/// @brief �����������
	///
	/// @param[in] ip �����
	/// @param[in] mask ����� ����
	InterfaceProfiles(const unsigned long ip, const unsigned long mask);
	/// @brief ����������
	///
	~InterfaceProfiles();
public:
	/// @brief ���������� Ip �����
	///
	const struct in_addr& GetIp(void) const;
	/// @brief ���������� �����
	///
	const struct in_addr& GetMask(void) const;
private:
	/// ip �����
	struct in_addr ip_;
	/// �����
	struct in_addr mask_;
};
}


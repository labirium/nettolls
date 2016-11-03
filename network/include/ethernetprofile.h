#pragma once

namespace network
{
/// @brief �������� ����������
///
class EthernetProfile
{
public:
	/// @brief �����������
	///
	/// @param[in] index ������ �������� ����������
	/// @param[in] name ��� ����������
	/// @param[in] description �������� ����������
	/// @param[in] macAddress ���������� �����
	/// @param[in] isVpn true - ���������� ������� ��������� ��� VPN
	/// @param[in] interfaceProfiles �������� �������� ����������
	EthernetProfile(const uint64_t index, const std::string& name, const std::string& description, const MacAddress& macAddress, const bool isVpn, const InterfaceProfilesList& interfaceProfiles);
	/// @brief ���������
	///
	~EthernetProfile();
public:
	/// @brief ���������� ������ �������� ����������
	///
	uint64_t GetIndex(void) const;
	/// @brief ���������� ��� ����������
	///
	const std::string& GetName(void) const;
	/// @brief ���������� �������� ����������
	///
	const std::string& GetDescription(void) const;
	/// @brief ���������� ���������� �����
	///
	const MacAddress& GetMacAddress(void) const;
	/// @brief ���������� true ���� ��������� ������� VPN
	///
	bool IsVpn(void) const;
	/// @brief ���������� ������ ������� �����������
	///
	const InterfaceProfilesList& GetInterfaceProfilesList(void) const;
private:
	/// ������ ������� �����������
	InterfaceProfilesList interfaceProfiles_;
	/// ���������� �����
	MacAddress macAddress_;
	/// ��� ����������
	std::string name_;
	/// �������� ����������
	std::string description_;
	///  ������ �������� ����������
	uint64_t index_;
	/// ������� VPN
	bool isVpn_;
};
}

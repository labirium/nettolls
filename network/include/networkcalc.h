#pragma once

namespace network
{
namespace tools
{
/// @brief ���������� ip ����� � ��������� ���������
///
std::string GetIpStr(const network::InterfaceProfilesPtr& data);
/// @brief ���������� ip ����� � ��������� ���������
///
std::string GetIpStr(const network::HostProfilePtr& data);
/// @brief ���������� mask ����� � ��������� ���������
///
std::string GetMaskStr(const network::InterfaceProfilesPtr& data);

/// @brief ���������� ���������� ip ����� ����
///
/// @param[in] data �������� ���������� �� ������ �������� �������� �������
uint32_t GetStartIp(const network::InterfaceProfilesPtr& data);

/// @brief ���������� ���������� ip ������� � ����
///
/// @param[in] data �������� ���������� �� ������ �������� �������� �������
uint32_t GetCountIp(const network::InterfaceProfilesPtr& data);

/// @brief ���������� ��������� ip ����� ����
///
/// @param[in] data �������� ���������� �� ������ �������� �������� �������
uint32_t GetEndIp(const network::InterfaceProfilesPtr& data);
}
}

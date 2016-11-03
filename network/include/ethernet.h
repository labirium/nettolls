#pragma once

#include <network/include/precompiled.h>

namespace network
{
namespace ethernet
{
/// @brief ���������� ������ ��� �������� ����������
///
/// @param[in] name ��� �������� ����������
/// @param[out] index ���������� ������ ����������
/// @param[out] isVpn ���������� true ���� ������� ��������� ������������ ��� VPN
/// @return ���������� ��������� ��������
bool GetIndexInterface(const std::string& name, uint64_t& index, bool& isVpn);
/// @brief ���������� ���������� ����� �� ����� ����������
///
/// @param[in] name ��� �������� ����������
/// @return ���������� ���������� �����
MacAddress GetMacAddress(const std::string& name);

/// @brief ���������� ������ ��������� ������� �����������
///
EthernetProfileList GetEthernetProfileList(void);
}
}


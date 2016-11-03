#pragma once

namespace network
{
/// @brief ���������� ������ ������ �� ������ ���������� ������� ������������
///
/// @param[in] ethernetProfile �������� �������� ����������
/// @param[out] hosts ������ ���������� ������
bool GetArpHostTalbeForInterface(const EthernetProfilePtr& ethernetProfile, HostProfileList& hosts );
}


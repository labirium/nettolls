
#pragma once

namespace network
{
namespace icmp
{
/// @brief ������������ ������������ �������� ������� �����������
///
EthernetHostProfileList ScanIcmpProbe(const EthernetProfileList& ethernetsProfiles);
/// @brief ������������ ���� ������� �����������
///
EthernetHostProfileList ScanIcmpProbe(void);
}
}

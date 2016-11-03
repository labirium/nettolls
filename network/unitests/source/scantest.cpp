/// @file �������� ����� ������ ��� ������������ ������������ ����

#include <unitests/include/precompiled.h>

//=====================================================================================================================
/// @brief ������������ ������� �� arp �������
///
TEST(Arp, ArpHostTableProbe)
{
	const auto data = network::ArpHostTableProbe();
	EXPECT_NE(data.size(), 0);

	network::logger::dump(data);
}
//=====================================================================================================================
/// @brief ������������ arp ������������ �� ���� �����������
///
TEST(Arp, ArpScanProbe)
{
	const auto data = network::ArpScanProbe();
	EXPECT_NE(data.size(), 0);

	network::logger::dump(data);
}
//=====================================================================================================================

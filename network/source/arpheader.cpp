#include <network/include/precompiled.h>

#include <pcap/pcap.h>

using namespace network::arp;
using namespace network;

void network::arp::arp_pack_hdr_ethip_f(uint8_t* hdr, uint16_t op, const char*sha, const struct in_addr& spa, const char*tha, const struct in_addr& tpa)
{
	struct arp_hdr *pack_arp_p = (struct arp_hdr *)(hdr);

	pack_arp_p->ar_hrd = htons(ARP_HRD_ETH);
	//��� �������� ���������. ��������, ��� IPv4 ����� �������� 0x0800.
	pack_arp_p->ar_pro = htons(ARP_PRO_IP);
	//����� ����������� ������ � ������. ������ Ethernet ����� ����� 6 ����.
	pack_arp_p->ar_hln = ETH_ADDR_LEN;
	//����� ����������� ������ � ������. IPv4 ������ ����� ����� 4 �����.
	pack_arp_p->ar_pln = IP_ADDR_LEN;
	//��� �������� �����������: 0001 � ������ ������� � 0002 � ������ ������.
	pack_arp_p->ar_op = htons(op);

	struct arp_ethip *pack_ethip_p = (struct arp_ethip *)((uint8_t *)(hdr)+ARP_HDR_LEN);
	//���������� ����� �����������.
	memcpy(pack_ethip_p->ar_sha, sha, ETH_ADDR_LEN);
	//���������� ����� �����������.
	memcpy(pack_ethip_p->ar_spa, &spa.S_un.S_addr, IP_ADDR_LEN);
	//���������� ����� ����������. ���� ����� ��� �������.
	memcpy(pack_ethip_p->ar_tha, tha, ETH_ADDR_LEN);
	//���������� ����� ����������.
	memcpy(pack_ethip_p->ar_tpa, &tpa.S_un.S_addr, IP_ADDR_LEN);
}

void network::arp::eth_pack_hdr_f(uint8_t* hdr, const char* dst, const char* src, uint16_t type)
{
	struct eth_hdr *eth_pack_p = (struct eth_hdr *)(hdr);
	memmove(&eth_pack_p->eth_dst, dst, ETH_ADDR_LEN);
	memmove(&eth_pack_p->eth_src, src, ETH_ADDR_LEN);
	eth_pack_p->eth_type = htons(type);
}

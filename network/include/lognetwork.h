#pragma once

namespace network
{
namespace logger
{

/// @brief �������������� ����
void Info(const char*, ...) throw();
/// @brief ��������������
void Warning(const char*, ...) throw();
/// @brief ������
void Error(const char*, ...)throw() ;


/// @brief ����������� �����
///
void dump(const HostProfilePtr& host) throw();
/// @brief ����������� ������ ������
///
void dump(const HostProfileList& hostProfiles) throw();
/// @brief ����������� ����������
///
void dump(const EthernetProfilePtr& ethernetProfile) throw();
/// @brief ����������� ������ �����������
///
void dump(const EthernetHostProfileList& ethernetHostProfile) throw();

}
}

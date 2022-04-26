/*
 * @Author: hongdong.liao
 * @Date: 2022-04-26 09:40:58
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-04-26 10:23:21
 * @FilePath: /test/IpAddress.hpp
 */
#include <arpa/inet.h>
#include <cerrno>
#include <ifaddrs.h>
#include <iostream>
#include <net/if.h>
#include <string>
#include <string.h>
#include <sysexits.h>
#include <sys/socket.h>
#include <sys/types.h>

class IpAddress {
public:
    // 获取本机所有网卡的IP地址
    std::string getIp();
    // 判断ip是否在局域网内
    bool checkIpIsIntranet();
};
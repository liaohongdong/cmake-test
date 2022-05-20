/*
 * @Author: hongdong.liao
 * @Date: 2022-03-21 10:51:51
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-20 15:05:12
 * @FilePath: /test/main.cpp
 */
// #include "Message.hpp"
// #include "Student.hpp"

#include "IpAddress.hpp"

// #include <cstdlib>
// #include <iostream>

int main(int argc, const char *argv[])
{
    // Message say_hello("Hello, CMake World!");
    std::cout << "hello world!!!" << std::endl;

    IpAddress ip;
    // std::string address = ip.getIpBySystem();
    // std::cout << "ip address: " << address << std::endl;

    // std::string strJson = ip.getIpByWeb();
    // std::cout << "strJson: " << strJson << std::endl;
    // std::string dom = ip.getJsonByDom("(.*)bar|(.*)bah", "abcbar");
    // std::string dom = ip.getJsonByDom();
    // std::cout << "strJson: " << dom << std::endl;
    std::string ip_addr = ip.getInternetIp();
    std::cout << "ip_addr: " << ip_addr << std::endl;

    bool result = ip.checkIpIsIntranet(ip_addr);
    if (result) {
        std::cout << "内网" << std::endl;
    } else {
        std::cout << "外网" << std::endl;
    }

    return EXIT_SUCCESS;
}

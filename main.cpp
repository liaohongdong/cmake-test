/*
 * @Author: hongdong.liao
 * @Date: 2022-03-21 10:51:51
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-19 17:48:13
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
    std::string address = ip.getIpBySystem();
    std::cout << "ip address: " << address << std::endl;

    std::string strJson = ip.getIpByWeb();
    // std::cout << "strJson: " << strJson << std::endl;
    std::string dom = ip.getJsonByDom();
    std::cout << "strJson: " << dom << std::endl;

    bool result = ip.checkIpIsIntranet(address);
    if (result) {
        std::cout << "内网" << std::endl;
    } else {
        std::cout << "外网" << std::endl;
    }

    return EXIT_SUCCESS;
}

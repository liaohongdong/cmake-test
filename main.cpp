/*
 * @Author: hongdong.liao
 * @Date: 2022-03-21 10:51:51
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-20 16:35:07
 * @FilePath: /test/main.cpp
 */
#include "Message.hpp"
// #include "Student.hpp"

#include <cstdlib>
#include <iostream>

int main(int argc, const char *argv[])
{
    Message say_hello("Hello, CMake World!");
    std::cout << say_hello << std::endl;

    return EXIT_SUCCESS;
}

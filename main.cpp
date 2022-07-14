/*
 * @Author: hongdong.liao
 * @Date: 2022-03-21 10:51:51
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-07-14 14:42:50
 * @FilePath: /cmake-test/main.cpp
 */
#include "sum_integers.hpp"
// #include "Message.hpp"
// #include "Student.hpp"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, const char *argv[])
{
    // Message say_hello("Hello, CMake World!");
    // std::cout << say_hello << std::endl;

    std::vector<int> integers;
    for (auto i = 1; i < argc; i++)
    {
        integers.push_back(std::stoi(argv[i]));
    }
    auto sum = sum_integers(integers);
    std::cout << sum << std::endl;

    return EXIT_SUCCESS;
}

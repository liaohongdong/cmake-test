/*
 * @Author: hongdong.liao
 * @Date: 2022-07-14 18:19:50
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-07-14 18:20:22
 * @FilePath: /cmake-test/sum_integers.cpp
 */
#include "sum_integers.hpp"

#include <vector>

int sum_integers(const std::vector<int> integers)
{
    auto sum = 0;
    for (auto i : integers)
    {
        sum += i;
    }
    return sum;
}

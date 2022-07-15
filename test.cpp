/*
 * @Author: hongdong.liao
 * @Date: 2022-07-14 18:21:05
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-07-14 18:44:12
 * @FilePath: /cmake-test/test.cpp
 */
#include "sum_integers.hpp"

#include <vector>

#define BOOST_TEST_MODULE example_test_suite
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(add_example)
{
    auto integers = {1, 2, 3, 4, 5};
    auto result = sum_integers(integers);
    BOOST_REQUIRE(result == 15);
}

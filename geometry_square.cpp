/*
 * @Author: hongdong.liao
 * @Date: 2022-06-14 10:25:35
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-06-14 10:30:40
 * @FilePath: /cmake-test/geometry_square.cpp
 */
#include "geometry_square.hpp"

#include <cmath>

namespace geometry {
namespace area{
    double square(double l) {
        return std::pow(l, 2);
    }
}
}
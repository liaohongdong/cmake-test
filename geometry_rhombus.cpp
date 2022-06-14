/*
 * @Author: hongdong.liao
 * @Date: 2022-06-14 10:23:30
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-06-14 10:23:53
 * @FilePath: /cmake-test/geometry_rhombus.cpp
 */
#include "geometry_rhombus.hpp"

namespace geometry {
namespace area {
    double rhombus(double d1, double d2) {
        return (d1 * d2) / 2.0;
    }
}
}
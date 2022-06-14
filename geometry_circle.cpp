/*
 * @Author: hongdong.liao
 * @Date: 2022-06-14 09:51:13
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-06-14 09:57:41
 * @FilePath: /cmake-test/geometry_circle.cpp
 */
#include "geometry_circle.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

namespace geometry {
namespace area {
    double circle(double area) {
        return M_PI * std::pow(area, 2);
    }
}
}
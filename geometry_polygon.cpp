/*
 * @Author: hongdong.liao
 * @Date: 2022-06-14 09:55:44
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-06-14 10:02:26
 * @FilePath: /cmake-test/geometry_polygon.cpp
 */
#include "geometry_polygon.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

namespace geometry {
namespace area {
    double polygon(double nSides, double side) {
        double perimeter = nSides * side;
        double apothem = side / (2.0 * std::tan(M_PI / nSides));
        return (perimeter * apothem) / 2.0;
    };
}
}
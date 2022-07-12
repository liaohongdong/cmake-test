/*
 * @Author: hongdong.liao
 * @Date: 2022-03-21 10:51:51
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-07-12 15:55:23
 * @FilePath: /cmake-test/main.cpp
 */
#include "Message.hpp"
// #include "Student.hpp"

#include <cstdlib>
#include <iostream>

#include <chrono>
#include <Eigen/Dense>

std::string timePointAsString(const std::chrono::system_clock::time_point& tp) {
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::string ts = std::ctime(&t);
    ts.resize(ts.size()-1);
    return ts;
}

EIGEN_DONT_INLINE
double simple_function(Eigen::VectorXd &va, Eigen::VectorXd &vb) {
    double d = va.dot(vb);
    return d;
}

int main(int argc, const char *argv[])
{
    Message say_hello("Hello, CMake World!");
    std::cout << say_hello << std::endl;

    int len = 1000000;
    int num_repetitions = 100;

    Eigen::VectorXd va = Eigen::VectorXd::Random(len);
    Eigen::VectorXd vb = Eigen::VectorXd::Random(len);

    double result;
    auto start = std::chrono::system_clock::now();
    std::cout << "start: " << timePointAsString(start) << std::endl;
    for (auto i = 0; i < num_repetitions; i++) {
        result = simple_function(va, vb);
    }
    auto end = std::chrono::system_clock::now();
    std::cout << "end: " << timePointAsString(end) << std::endl;
    auto elapsed_seconds = end - start;

    std::cout << "result: " << result << std::endl;
    std::cout << "elapsed seconds: " << elapsed_seconds.count() << std::endl;

    return EXIT_SUCCESS;
}

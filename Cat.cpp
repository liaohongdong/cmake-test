/*
 * @Author: hongdong.liao
 * @Date: 2022-04-21 15:52:21
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-20 17:02:12
 * @FilePath: /test/Cat.cpp
 */
#include "Cat.hpp"

std::string Cat::name_impl() const
{
    return "Cat " + name_;
}
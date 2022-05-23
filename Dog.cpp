/*
 * @Author: hongdong.liao
 * @Date: 2022-04-21 15:52:30
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-20 17:04:38
 * @FilePath: /test/Dog.cpp
 */
#include "Dog.hpp"

std::string Dog::name_impl() const
{
    return "Dog " + name_;
}
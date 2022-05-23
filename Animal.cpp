/*
 * @Author: hongdong.liao
 * @Date: 2022-04-21 15:53:06
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-20 16:58:28
 * @FilePath: /test/Animal.cpp
 */
#include "Animal.hpp"

Animal::Animal(const std::string &name)
    : name_(name)
{
}

std::string Animal::name() const
{
    return name_impl();
}
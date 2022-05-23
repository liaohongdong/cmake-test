/*
 * @Author: hongdong.liao
 * @Date: 2022-04-21 15:52:19
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-20 17:01:57
 * @FilePath: /test/Cat.hpp
 */
#pragma once

#include "Animal.hpp"

class Cat final : public Animal
{
public:
    Cat(const std::string &name) : Animal(name) {};

private:
    std::string name_impl() const override;
};
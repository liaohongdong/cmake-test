/*
 * @Author: hongdong.liao
 * @Date: 2022-04-21 15:52:38
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-20 17:04:25
 * @FilePath: /test/Dog.hpp
 */
#pragma once

#include "Animal.hpp"

class Dog final : public Animal
{
public:
    Dog(const std::string &name) : Animal(name){};

private:
    std::string name_impl() const override;
};
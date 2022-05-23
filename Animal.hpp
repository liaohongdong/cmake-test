/*
 * @Author: hongdong.liao
 * @Date: 2022-04-21 15:53:16
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-20 16:57:06
 * @FilePath: /test/Animal.hpp
 */
#pragma once

#include <string>

class Animal
{
public:
    Animal() = delete;
    explicit Animal(const std::string &name);
    std::string name() const;

protected:
    std::string name_;

private:
    virtual std::string name_impl() const = 0;
};
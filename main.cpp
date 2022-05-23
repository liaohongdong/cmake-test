/*
 * @Author: hongdong.liao
 * @Date: 2022-03-21 10:51:51
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-23 09:49:27
 * @FilePath: /test/main.cpp
 */
#include "Message.hpp"
// #include "Student.hpp"

#include <cstdlib>
#include <iostream>
#include <functional>
#include <memory>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Factory.hpp"

typedef std::function<std::unique_ptr<Animal>(const std::string &)> CreateAnimal;

int main(int argc, const char *argv[])
{
    Message say_hello("Hello, CMake World!");
    std::cout << say_hello << std::endl;

    Factory<CreateAnimal> farm;
    farm.subscribe("Cat",
                   [](const std::string &n)
                   { return std::make_unique<Cat>(n); });

    farm.subscribe("Dog",
                   [](const std::string &n)
                   { return std::make_unique<Dog>(n); });

    std::unique_ptr<Animal> smallCat = farm.create("Cat", "Tom");
    std::unique_ptr<Animal> smallDog = farm.create("Dog", "Jerry");

    std::cout << smallCat->name() << std::endl;
    std::cout << smallDog->name() << std::endl;

    return EXIT_SUCCESS;
}

/*
 * @Author: hongdong.liao
 * @Date: 2022-04-20 16:39:48
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-04-20 16:45:09
 * @FilePath: /test/Student.cpp
 */
#include "Student.hpp"

Student::Student(string name, int age)
{
    this->name = name;
    this->age = age;
}

Student::~Student()
{
}

void Student::setName(string name)
{
    this->name = name;
}

void Student::setAge(int age)
{
    this->age = age;
}

string Student::getName()
{
    return this->name;
}

int Student::getAge()
{
    return this->age;
}

string Student::toString()
{
    return "name: " + this->name + " age: " + to_string(this->age);
}
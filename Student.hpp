/*
 * @Author: hongdong.liao
 * @Date: 2022-04-20 16:37:44
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-04-20 16:45:01
 * @FilePath: /test/Student.hpp
 */
#pragma once
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int age;

public:
    Student(string name, int age);
    ~Student();
    void setName(string name);
    void setAge(int age);
    string getName();
    int getAge();
    string toString();
};
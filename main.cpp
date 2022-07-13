/*
 * @Author: hongdong.liao
 * @Date: 2022-03-21 10:51:51
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-07-12 18:12:56
 * @FilePath: /cmake-test/main.cpp
 */
#include "Message.hpp"
// #include "Student.hpp"

#include <cstdlib>
#include <iostream>

#include <Python.h>

int main(int argc, char *argv[])
{
    Message say_hello("Hello, CMake World!");
    std::cout << say_hello << std::endl;

    Py_SetProgramName((wchar_t *)argv[0]);
    Py_Initialize();
    PyRun_SimpleString("import random\n"
                        "print('Today is', random.randint(1, 10000))\n");
    Py_Finalize();

    return EXIT_SUCCESS;
}

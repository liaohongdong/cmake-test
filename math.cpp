/*
 * @Author: hongdong.liao
 * @Date: 2022-05-07 11:16:23
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-07 17:35:28
 * @FilePath: /test/math.cpp
 */
/*
 * @Author: hongdong.liao
 * @Date: 2022-04-26 15:18:56
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-07 11:05:51
 * @FilePath: /test/math.cpp
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <emscripten.h>

using namespace std;
#ifdef __cplusplus
extern "C"
{
#endif
    void EMSCRIPTEN_KEEPALIVE echo(int x)
    {
        cout << "this number you input is:" << x << endl;
        return;
    }
    int EMSCRIPTEN_KEEPALIVE add(int x, int y)
    {
        return x + y;
    }
    void EMSCRIPTEN_KEEPALIVE log(string str)
    {
        std::cout << "log = " << str << std::endl;
    };
    char* EMSCRIPTEN_KEEPALIVE joinString(char *str)
    {
        char targetStr[] = "hello!";
        strcat(str, targetStr);
        return str;
    };

#ifdef __cplusplus
}
#endif
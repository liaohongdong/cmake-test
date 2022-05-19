/*
 * @Author: hongdong.liao
 * @Date: 2022-04-29 18:10:23
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-04-29 18:27:52
 * @FilePath: /test/tests/hello_world_file.cpp
 */
#include <stdio.h>

int main()
{
    FILE *file = fopen("hello_world_file.txt", "rb");
    if (!file)
    {
        printf("open file failed\n");
        return 1;
    }

    while (!feof(file))
    {
        char c = fgetc(file);
        if (c != EOF)
        {
            putchar(c);
        }
    }
    fclose(file);
    return 0;
}
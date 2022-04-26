/*
 * @Author: hongdong.liao
 * @Date: 2022-03-30 15:27:46
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-03-31 14:57:37
 * @FilePath: /test/Message.hpp
 */
#pragma once

#include <iosfwd>
#include <string>

class Message
{
public:
    Message(const std::string &m) : message_(m) {}

    friend std::ostream &operator<<(std::ostream &os, Message &obj)
    {
        return obj.printObject(os);
    }

private:
    std::string message_;
    std::ostream &printObject(std::ostream &os);
};

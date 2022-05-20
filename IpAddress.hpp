/*
 * @Author: hongdong.liao
 * @Date: 2022-04-26 09:40:58
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-20 14:38:50
 * @FilePath: /test/IpAddress.hpp
 */
#include <arpa/inet.h>
#include <cerrno>
#include <ifaddrs.h>
#include <iostream>
#include <net/if.h>
#include <string>
#include <string.h>
#include <sysexits.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "root_certificates.hpp"

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/beast/core/buffers_to_string.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/regex.hpp>
#include <cstdlib>


namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
namespace ssl = net::ssl;           // from <boost/asio/ssl.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>


class IpAddress {
private:
    http::response<http::dynamic_body> dom;

public:
    void setDom(http::response<http::dynamic_body> dom) {
        this->dom = dom;
    }
    http::response<http::dynamic_body> getDom() {
        return this->dom;
    }
    // 获取本机所有网卡的IP地址 依靠系统接口
    std::string getIpBySystem();

    // 获取本机所有网卡的IP地址 依靠系统接口
    std::string getIpByWeb();

    // 判断ip是否在局域网内
    bool checkIpIsIntranet(const std::string ip);

    // 提取 json
    std::string getJsonByDom();

    // 获取ip
    std::string getInternetIp();
};

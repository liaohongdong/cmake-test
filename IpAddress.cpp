/*
 * @Author: hongdong.liao
 * @Date: 2022-04-26 09:46:52
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-19 18:07:18
 * @FilePath: /test/IpAddress.cpp
 */
#include "IpAddress.hpp"

std::string IpAddress::getIpBySystem() {
    struct ifaddrs* ptr_ifaddrs = nullptr;
    auto result = getifaddrs(&ptr_ifaddrs);
    if( result != 0 ){
        std::cout << "`getifaddrs()` failed: " << strerror(errno) << std::endl;
        // return EX_OSERR;
        return "";
    }
    std::string ipaddress = "";
    for(
        struct ifaddrs* ptr_entry = ptr_ifaddrs;
        ptr_entry != nullptr;
        ptr_entry = ptr_entry->ifa_next
    ){
        std::string ipaddress_human_readable_form;
        std::string netmask_human_readable_form;
        std::string interface_name = std::string(ptr_entry->ifa_name);
        sa_family_t address_family = ptr_entry->ifa_addr->sa_family;
        if( address_family == AF_INET ){
            if( ptr_entry->ifa_addr != nullptr ){
                char buffer[INET_ADDRSTRLEN] = {0, };
                inet_ntop(
                    address_family,
                    &((struct sockaddr_in*)(ptr_entry->ifa_addr))->sin_addr,
                    buffer,
                    INET_ADDRSTRLEN
                );
                ipaddress_human_readable_form = std::string(buffer);
            }
            if( ptr_entry->ifa_netmask != nullptr ){
                char buffer[INET_ADDRSTRLEN] = {0, };
                inet_ntop(
                    address_family,
                    &((struct sockaddr_in*)(ptr_entry->ifa_netmask))->sin_addr,
                    buffer,
                    INET_ADDRSTRLEN
                );
                netmask_human_readable_form = std::string(buffer);
            }
            // std::cout << interface_name << ": IP address = " << ipaddress_human_readable_form << ", netmask = " << netmask_human_readable_form << std::endl;
            ipaddress = ipaddress_human_readable_form;
        }
        // else if( address_family == AF_INET6 ){
        //     // IPv6
        //     uint32_t scope_id = 0;
        //     if( ptr_entry->ifa_addr != nullptr ){
        //         char buffer[INET6_ADDRSTRLEN] = {0, };
        //         inet_ntop(
        //             address_family,
        //             &((struct sockaddr_in6*)(ptr_entry->ifa_addr))->sin6_addr,
        //             buffer,
        //             INET6_ADDRSTRLEN
        //         );
        //         ipaddress_human_readable_form = std::string(buffer);
        //         scope_id = ((struct sockaddr_in6*)(ptr_entry->ifa_addr))->sin6_scope_id;
        //     }
        //     if( ptr_entry->ifa_netmask != nullptr ){
        //         char buffer[INET6_ADDRSTRLEN] = {0, };
        //         inet_ntop(
        //             address_family,
        //             &((struct sockaddr_in6*)(ptr_entry->ifa_netmask))->sin6_addr,
        //             buffer,
        //             INET6_ADDRSTRLEN
        //         );
        //         netmask_human_readable_form = std::string(buffer);
        //     }
        //     std::cout << interface_name << ": IP address = " << ipaddress_human_readable_form << ", netmask = " << netmask_human_readable_form << ", Scope-ID = " << scope_id << std::endl;
        // }
        else {
            // AF_UNIX, AF_UNSPEC, AF_PACKET etc.
            // If ignored, delete this section.
        }
    }
    freeifaddrs(ptr_ifaddrs);
    return ipaddress;
};

std::string IpAddress::getIpByWeb() {
    try {
        auto const host = "www.ifconfig.me";
        // auto const host = "127.0.0.1";
        auto const port = "443";
        // auto const port = "8080";
        auto const target = "/all.json";
        // auto const target = "/";
        int version = 11; // 10 http 11 https
        // --------------- http ---------------
        // net::io_context ioc{1};
        // 所有的 IO 都需要 I/O 上下文
        // net::io_context ioc;
        // // 输入输出
        // tcp::resolver resolver(ioc);
        // beast::tcp_stream stream(ioc);
        // // 查找域名
        // auto const results = resolver.resolve(host, port);
        // //在查找得到的IP地址上建立连接
        // stream.connect(results);
        // //设置HTTP GET请求消息
        // http::request<http::string_body> req{http::verb::get, target, version};
        // req.set(http::field::host, host);
        // req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        // req.set(http::field::content_type, "application/json; charset=utf-8");

        // //将HTTP请求发送到远程主机
        // http::write(stream, req);
        // //此缓冲区用于读取，必须保留
        // beast::flat_buffer buffer;
        // //声明一个容器来保存响应
        // http::response<http::dynamic_body> res;
        // // http::response<http::string_body> res;
        // //接收HTTP响应
        // http::read(stream, buffer, res);
        // //将消息写入标准输出
        // std::cout << res << std::endl;
        // // std::cout << res.body() << std::endl;

        // //关闭连接
        // beast::error_code ec;
        // stream.socket().shutdown(tcp::socket::shutdown_both, ec);
        // // 异常处理
        // if (ec && ec != beast::errc::not_connected)
        //     throw beast::system_error{ec};
        // --------------- http ---------------
        // The io_context is required for all I/O
        net::io_context ioc;
        ssl::context ctx(ssl::context::tlsv12_client);
        load_root_certificates(ctx);
        ctx.set_verify_mode(ssl::verify_peer);
        tcp::resolver resolver(ioc);
        beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);
        if(! SSL_set_tlsext_host_name(stream.native_handle(), host))
        {
            beast::error_code ec{static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()};
            throw beast::system_error{ec};
        }
        auto const results = resolver.resolve(host, port);
        beast::get_lowest_layer(stream).connect(results);
        stream.handshake(ssl::stream_base::client);
        http::request<http::string_body> req{http::verb::get, target, version};
        req.set(http::field::host, host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        http::write(stream, req);
        beast::flat_buffer buffer;
        http::response<http::dynamic_body> res;
        http::read(stream, buffer, res);
        std::cout << "==============" << std::endl;
        // std::cout << res << std::endl;
        this->setDom(res);
        std::cout << "==============" << std::endl;
        beast::error_code ec;
        stream.shutdown(ec);
        if(ec == net::error::eof)
        {
            ec = {};
        }
        if(ec)
            throw beast::system_error{ec};

        return "已经输出了";
    } catch (std::exception const & e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return "报错了啊";
    }
}

bool IpAddress::checkIpIsIntranet(const std::string ip) {
    std::cout << "检查 ip 是否内网 ip" << std::endl;

    int n = ip.size();
    int ip_num = 0;
    bool is_net = false;
    for(int i = 0; i < n; i++)
    {
        if(ip[i] == '.')
        {
            if(ip_num == 10 || ip_num == 127 || ip_num==17216 || ip_num ==192168 || ip_num==17231)
            {
                is_net = true;
                break;
            }
        }
        else
        {
            ip_num = ip_num * 10 + (ip[i] - '0');
        }
    }
    return is_net;
};

std::string IpAddress::getJsonByDom() {
    std::cout << "获取 dom:" << this->getDom() << std::endl;
}
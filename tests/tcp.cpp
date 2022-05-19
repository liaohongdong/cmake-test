/*
 * @Author: hongdong.liao
 * @Date: 2022-05-18 18:19:44
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-05-18 18:50:17
 * @FilePath: /test/tests/tcp.cpp
 */
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

namespace beast = boost::beast; // from <boost/beast.hpp>
namespace http = beast::http;   // from <boost/beast/http.hpp>
namespace net = boost::asio;    // from <boost/asio.hpp>
using tcp = net::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

// Performs an HTTP GET and prints the response
int main(int argc, char **argv)
{
    try
    {
        std::string url = "https://www.ifconfig.me/";
        std::string port = "80";
        // Create a I/O context
        boost::asio::io_context ioc{};
        // Create an I/O object, that takes in the io context as an intermediary to talk with you
        tcp::socket socket(ioc);

        // Resolve address to ip
        boost::system::error_code ec{};
        tcp::resolver resolver{ioc};
        auto resolverIt{resolver.resolve(url, port, ec)};

        // Talk to the socket using I/O context
        socket.connect(*resolverIt);

        // Now that talking to the socket is succcessful,
        // we tie the socket object to a websocket stream
        boost::beast::websocket::stream<boost::beast::tcp_stream> ws(std::move(socket));

        // Now, perform a websocket handshake
        ws.handshake(url, "/echo", ec);

        // Now the socket is connected to the server, write data to it
        boost::asio::const_buffer data("toioest", 7);
        ws.write(data);

        boost::beast::flat_buffer response;
        ws.read(response);

        std::cout << boost::beast::make_printable(response.data());
        return EXIT_SUCCESS;
    }
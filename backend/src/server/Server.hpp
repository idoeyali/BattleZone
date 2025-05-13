#pragma once
#include "crow_all.h"

#include <boost/asio.hpp>
#include <memory>
#include <string>
#include <vector>

class Server {
public:
    Server(boost::asio::io_context& io_context, short port);
    ~Server();

    void start();
    void stop();

private:
    void do_accept();
    void handle_accept(std::shared_ptr<boost::asio::ip::tcp::socket> socket,
                      const boost::system::error_code& error);

    boost::asio::io_context& io_context_;
    boost::asio::ip::tcp::acceptor acceptor_;
    bool running_;
};
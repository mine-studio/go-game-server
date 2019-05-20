#pragma once

#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>
#include <boost/asio.hpp>
#include <spdlog/spdlog.h>

#include <game_session.hpp>
using boost::asio::ip::tcp;

class game_server {
public:
  explicit game_server(boost::asio::io_context &io_context,
                       const tcp::endpoint &endpoint)
      : acceptor_(io_context, endpoint) {
    do_accept();
  }

private:
  void do_accept() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
          if (!ec) {
            std::make_shared<game_session>(std::move(socket), room_)->start();
          }

          do_accept();
        });
  }

  tcp::acceptor acceptor_;
  game_room room_;
};



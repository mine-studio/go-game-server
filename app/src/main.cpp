#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>
#include <boost/asio.hpp>
#include <spdlog/spdlog.h>

#include <chat_message.hpp>
#include <game_participant.hpp>
#include <game_room.hpp>
#include <game_session.hpp>
#include <game_server.hpp>

using boost::asio::ip::tcp;

//----------------------------------------------------------------------

int main(int argc, char *argv[]) {
  try {
    if (argc < 2) {
      spdlog::error("Usage: mine-go-server <port> [<port> ...]");
      return 1;
    }

    boost::asio::io_context io_context;

    std::list<game_server> servers;
    for (int i = 1; i < argc; ++i) {
      tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[i]));
      spdlog::info("listening on tcp://{}:{}", endpoint.address().to_string(), endpoint.port());
      servers.emplace_back(io_context, endpoint);
    }

    io_context.run();
  }
  catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
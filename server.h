#pragma once
#include <array>
#include <boost/asio.hpp>
#include <mutex>
#include <vector>

#include "auction_house.h"

using boost::asio::ip::tcp;

class Server {
 public:
  Server(boost::asio::io_context& io_context, short port);
  ~Server();

  void Run();

 private:
  // functions
  // connection
  void StartAccept();
  void HandleAccept(const std::shared_ptr<tcp::socket>& client,
                    const boost::system::error_code& error);
  void StartReceive(const std::shared_ptr<tcp::socket>& socket);
  void HandleReceive(std::shared_ptr<tcp::socket>& socket,
                     const boost::system::error_code& error,
                     std::size_t bytes_read);

  // publish to clients
  void PublishSubscribedAuctionToAllClients();
  void ScheduleAuctionPublishToAllClients();

  void RunIoContext();
  void StopIoContext();
  void Shutdown();

  // member variables
  // core
  AuctionHouse house_{};
  std::vector<std::shared_ptr<tcp::socket>> clients_{};

  // connection
  boost::asio::io_context& io_context_;
  tcp::acceptor acceptor_;
  std::array<char, 1024> buffer_{};

  // io
  std::mutex io_mutex_{};
  std::thread io_thread_;
  boost::asio::steady_timer timer_;

  std::atomic<bool> shutdown_{false};
};

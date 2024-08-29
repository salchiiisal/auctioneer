#include "server.h"

#include <boost/bind/bind.hpp>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>

#include "auction_house.h"

Server::Server(boost::asio::io_context& io_context, short port)
    : io_context_{io_context},
      acceptor_{io_context, tcp::endpoint(tcp::v4(), port)},
      timer_{io_context} {
  StartAccept();
}

Server::~Server() { Shutdown(); }

void Server::Run() {
  io_thread_ = std::thread([this]() {
    ScheduleAuctionPublishToAllClients();
    RunIoContext();
  });
}

void Server::StartAccept() {
  auto socket{std::make_shared<tcp::socket>(io_context_)};
  acceptor_.async_accept(*socket,
                         boost::bind(&Server::HandleAccept, this, socket,
                                     boost::asio::placeholders::error));
}

void Server::HandleAccept(const std::shared_ptr<tcp::socket>& client,
                          const boost::system::error_code& error) {
  if (!error) {
    std::scoped_lock io_lock{io_mutex_};
    clients_.push_back(client);
    StartReceive(client);
  }

  StartAccept();
}

void Server::StartReceive(const std::shared_ptr<tcp::socket>& client) {
  client->async_receive(
      boost::asio::buffer(buffer_), 0,
      boost::bind(&Server::HandleReceive, this, client,
                  boost::asio::placeholders::error,
                  boost::asio::placeholders::bytes_transferred));
}

void Server::HandleReceive(std::shared_ptr<tcp::socket>& socket,
                           const boost::system::error_code& error,
                           std::size_t bytes_read) {
  if (!error) {
    std::cout << "Received data: " << std::string(buffer_.data(), bytes_read)
              << '\n';
    StartReceive(socket);
  } else {
    {
      std::scoped_lock io_lock{io_mutex_};
      clients_.erase(std::remove(clients_.begin(), clients_.end(), socket),
                     clients_.end());
    }
  }
}

void Server::ScheduleAuctionPublishToAllClients() {
  timer_.expires_after(std::chrono::seconds(1));
  timer_.async_wait([this](boost::system::error_code ec) {
    if (!ec) {
      PublishSubscribedAuctionToAllClients();
      ScheduleAuctionPublishToAllClients();
    }
  });
}

void Server::PublishSubscribedAuctionToAllClients() {
  // TODO:
}

void Server::RunIoContext() {
  if (!shutdown_.load(std::memory_order_relaxed)) {
    io_context_.run();
  }
}

void Server::StopIoContext() { io_context_.stop(); }

void Server::Shutdown() {
  StopIoContext();
  if (io_thread_.joinable()) {
    io_thread_.join();
  }
}

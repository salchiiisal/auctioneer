#pragma once
#include <vector>

#include "auction_house.h"

class Server {
 public:
  void Run();

 private:
  // functions

  // member variables
  AuctionHouse auction_house_{};
};

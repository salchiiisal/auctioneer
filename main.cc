#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

#include "server.h"

int main() {
  boost::asio::io_context ioContext;
  Server server{ioContext, 8080};
  server.Run();

  // indefinite wait on main thread
  std::mutex mtx;
  std::condition_variable cv;
  std::unique_lock<std::mutex> lock(mtx);
  cv.wait(lock, [] { return false; });

  return 0;
}

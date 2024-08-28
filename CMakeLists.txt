cmake_minimum_required(VERSION 3.14)

project(
    Auctioneer
    VERSION 0.1
    DESCRIPTION "Auctioneer"
    LANGUAGES CXX
)

find_package(Boost REQUIRED COMPONENTS system)

add_executable(Auctioneer main.cc)

target_link_libraries(Auctioneer PRIVATE Boost::system)
target_compile_features(Auctioneer PRIVATE cxx_std_20)
target_compile_options(Auctioneer PRIVATE -pthread -Wall)

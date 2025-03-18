cmake_minimum_required(VERSION 3.10.0)
project(chat_log VERSION 0.1.0 LANGUAGES C CXX)

add_executable(chat_log Chat.cpp Logger.cpp main.cpp)


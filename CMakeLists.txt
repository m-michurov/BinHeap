cmake_minimum_required(VERSION 3.12)
project(BinHeap C)

set(CMAKE_C_STANDARD 11)

add_executable(BinHeap main.c binheap.c binheap.h)
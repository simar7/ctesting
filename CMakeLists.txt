cmake_minimum_required(VERSION 3.17)
project(ctesting C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ctesting
        tracee.bpf.c tracee.bpf.h test_tracee.bpf.c)

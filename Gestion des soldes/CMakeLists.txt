cmake_minimum_required(VERSION 3.23)
project(Gestion_des_soldes)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Gestion_des_soldes
        main.cpp
        Reduction.h article.h formateurReduction.h)

cmake_minimum_required(VERSION 3.14)
project(systemy-cyfrowe)

add_executable(LogisimTestVectorGenerator)

target_sources(LogisimTestVectorGenerator
        PRIVATE
        src/LogisimTestVectorGenerator.cpp
        )

target_compile_features(LogisimTestVectorGenerator
        PRIVATE
        cxx_std_14
        )

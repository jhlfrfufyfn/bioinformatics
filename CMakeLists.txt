cmake_minimum_required(VERSION 3.15)
project(bioinformatics)

set(CMAKE_CXX_STANDARD 17)

add_executable(bioinformatics rosalind/calculating_protein_mass.cpp)
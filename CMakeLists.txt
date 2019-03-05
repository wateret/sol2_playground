cmake_minimum_required(VERSION 3.1)

project(sol2_playground)

# sol2 Installation

## Configuration

set(SOL2_TAG v2.20.6)
set(SOL2_INSTALL_DIR "${CMAKE_BINARY_DIR}/include")
set(SOL2_REPO_URL "https://github.com/ThePhD/sol2/releases/download")

function(download_and_install FILENAME MD5)
    message("Installing '${FILENAME}' (${SOL2_TAG}) from '${SOL2_REPO_URL}'")
    file(DOWNLOAD "${SOL2_REPO_URL}/${SOL2_TAG}/${FILENAME}" "${SOL2_INSTALL_DIR}/${FILENAME}"
         EXPECTED_MD5 "${MD5}"
         SHOW_PROGRESS)
endfunction()

## Download header files

set(SOL2_HPP "sol.hpp")
set(SOL2_HPP_MD5 "8bae033629d61dea6c5060e205bbc89b")
download_and_install(${SOL2_HPP} ${SOL2_HPP_MD5})

set(SOL2_FORWARD_HPP "sol_forward.hpp")
set(SOL2_FORWARD_HPP_MD5 "00e4f2c0d46d70302c00eeb3b9bb37ee")
download_and_install(${SOL2_FORWARD_HPP} ${SOL2_FORWARD_HPP_MD5})

include_directories(SYSTEM ${CMAKE_BINARY_DIR}/include)

# Basic configuration

set(CMAKE_CXX_STANDARD 14)

find_package(Lua) # TODO Check version
link_libraries(${LUA_LIBRARIES})
include_directories(${LUA_INCLUDE_DIR})

# Targets

add_executable(hello_world hello_world.cc)
add_executable(usertype usertype.cc)
add_executable(lazy_binding lazy_binding.cc)

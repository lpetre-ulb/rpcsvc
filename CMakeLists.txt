cmake_minimum_required(VERSION 2.8.12)
project(rpcsvc)

add_compile_options(-std=c++11)

# Define our sources
set(SRCS
    rpcsvc.cpp
    run_client.cpp
    ModuleManager.cpp
    wiscRPCMsg.cpp
    LogManager.cpp
    LockTools.cpp)

set(PROTOS
    rpcmsg.proto)

# Search for Protobuf
find_package(Protobuf REQUIRED)

# Define the rpcsvc executable
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTOS})

add_executable(rpcsvc ${SRCS} ${PROTO_SRCS} ${PROTO_HDRS})

target_include_directories(rpcsvc PRIVATE ${PROTOBUF_INCLUDE_DIRS})
target_include_directories(rpcsvc PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(rpcsvc PRIVATE dl rt z ${PROTOBUF_LITE_LIBRARIES})

# Install
install(TARGETS rpcsvc
        RUNTIME DESTINATION bin)


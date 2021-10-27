cmake_minimum_required(VERSION 3.10)
project (RpcServerDemo)

set(SOURCES 
    ${PROJECT_SOURCE_DIR}/src/RpcServer.cpp
)

set(HEADER
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_HOME_DIRECTORY}/open_source/spdlog/include
    ${CMAKE_HOME_DIRECTORY}/open_source/rpclib/include
)

include_directories(${PROJECT_NAME} ${HEADER})
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    rpc
)

project (RpcClientDemo)

set(SOURCES 
    ${PROJECT_SOURCE_DIR}/src/RpcClient.cpp
)

set(HEADER
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_HOME_DIRECTORY}/open_source/spdlog/include
    ${CMAKE_HOME_DIRECTORY}/open_source/rpclib/include
)

include_directories(${PROJECT_NAME} ${HEADER})
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    rpc
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
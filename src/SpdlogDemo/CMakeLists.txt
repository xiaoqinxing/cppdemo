cmake_minimum_required(VERSION 3.10)
project (SpdlogDemo)

set(SOURCES 
    ${PROJECT_SOURCE_DIR}/src/demo.cpp
)

set(HEADER
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_HOME_DIRECTORY}/open_source/spdlog/include
)

include_directories(${PROJECT_NAME} ${HEADER})
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    spdlog
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
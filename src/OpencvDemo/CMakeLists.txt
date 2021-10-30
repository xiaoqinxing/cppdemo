cmake_minimum_required(VERSION 3.10)
project (OpencvDemo)

set(SOURCES 
    ${PROJECT_SOURCE_DIR}/src/videocapture_camera.cpp
)

set(OpenCV_DIR ${CMAKE_HOME_DIRECTORY}/prebuilts/opencv/lib/cmake/opencv4)
find_package(OpenCV REQUIRED)

set(HEADER
    ${PROJECT_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)

include_directories(${PROJECT_NAME} ${HEADER})
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
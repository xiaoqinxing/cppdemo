cmake_minimum_required(VERSION 3.10)
project (OpencvDemo)

set(SOURCES 
    ${PROJECT_SOURCE_DIR}/src/videocapture_camera.cpp
)

set(HEADER
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_HOME_DIRECTORY}/install/include/opencv4
)

include_directories(${PROJECT_NAME} ${HEADER})
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PUBLIC opencv_core opencv_highgui opencv_imgproc opencv_videoio
)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
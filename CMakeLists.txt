cmake_minimum_required(VERSION 3.5)
project(MyDiceGame)


# set(Qt5_DIR "/Users/mrlaw/Qt/5.15.2/clang_64/lib/cmake/Qt5")
# set(CMAKE_PREFIX_PATH "/Users/mrlaw/Qt/5.15.2/clang_64")

find_package(Qt5 COMPONENTS Widgets REQUIRED)
set(SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

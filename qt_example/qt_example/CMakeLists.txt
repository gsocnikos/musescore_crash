cmake_minimum_required(VERSION 2.8.12)

project(qt_example LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)


set(SOURCES
    client/windows/handler/exception_handler.cc
    common/windows/string_utils.cc
    common/windows/guid_string.cc
    client/windows/crash_generation/crash_generation_client.cc

)

set(HEADERS
    crash_handler.h
    crash_handler.cpp
    common/windows/string_utils-inl.h
    common/windows/guid_string.h
    client/windows/handler/exception_handler.h
    client/windows/common/ipc_protocol.h
    google_breakpad/common/minidump_format.h
    google_breakpad/common/breakpad_types.h
    client/windows/crash_generation/crash_generation_client.h
    common/scoped_ptr.h
)

add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc" ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)

ADD_DEFINITIONS(-DUNICODE)



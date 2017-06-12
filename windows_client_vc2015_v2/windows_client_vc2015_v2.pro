TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

# Windows
HEADERS += $$PWD/common/windows/string_utils-inl.h
HEADERS += $$PWD/common/windows/guid_string.h
HEADERS += $$PWD/client/windows/handler/exception_handler.h
HEADERS += $$PWD/client/windows/common/ipc_protocol.h
HEADERS += $$PWD/google_breakpad/common/minidump_format.h
HEADERS += $$PWD/google_breakpad/common/breakpad_types.h
HEADERS += $$PWD/client/windows/crash_generation/crash_generation_client.h
HEADERS += $$PWD/common/scoped_ptr.h
SOURCES += $$PWD/client/windows/handler/exception_handler.cc
SOURCES += $$PWD/common/windows/string_utils.cc
SOURCES += $$PWD/common/windows/guid_string.cc
SOURCES += $$PWD/client/windows/crash_generation/crash_generation_client.cc


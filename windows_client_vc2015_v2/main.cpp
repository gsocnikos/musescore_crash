#include "client/windows/handler/exception_handler.h"
#include <iostream>
#include <windows.h>

//static bool dumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
//void* context, bool succeeded) {
//  printf("Dump path: %s\n", descriptor.path());
//  return succeeded;
//}

static std::wstring dump_file;
static google_breakpad::ExceptionHandler* pHandler;



bool dumpCallback(const wchar_t* dump_path,
                    const wchar_t* minidump_id,
                    void* context,
                    EXCEPTION_POINTERS* exinfo,
                    MDRawAssertionInfo* assertion,
                    bool succeeded) {
  dump_file = dump_path;
  dump_file += L"\\";
  dump_file += minidump_id;
  dump_file += L".dmp";
    return succeeded;
}

void crash() { volatile int* a = (int*)(NULL); *a = 1; }

int main(int argc, char* argv[]) {
//int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
//    {
       //MessageBox (NULL, L"Hello", L"Hello Demo", MB_OK);
  //google_breakpad::MinidumpDescriptor descriptor("/tmp");
  //google_breakpad::ExceptionHandler eh(descriptor, NULL, dumpCallback, NULL, true, -1);
    //std::wstring pathAsStr = (const wchar_t*)dumpPath.utf16();
    std::wstring pathAsStr = L"c:\\temp";
    pHandler = new google_breakpad::ExceptionHandler(
        pathAsStr,
        /*FilterCallback*/ 0,
        dumpCallback,
        /*context*/
        0,
        true
        );




    crash();
  return 0;
}

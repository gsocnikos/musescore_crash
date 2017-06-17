# we stored our dump file into our home directory:
c:\Users\nickhatz\a32acd69-0d4a-4630-a1e8-6ebc6b7ac502.dmp

# Generation of symbol files using dump_syms precompile from breakpads git
C:\Users\nickhatz\breakpad\src\tools\windows\binaries\dump_syms.exe qt_example.pdb > qt_example.sym

# create symbol folder and stor symbol file 
create_sym_dir.sh

# create crash reports using cygwin
/usr/local/breakpads/bin/minidump_stackwalk.exe a32acd69-0d4a-4630-a1e8-6ebc6b7ac502.dmp symbols 1> stackwalk.txt 2> stackwalk.log

# from stackwalk.txt we can identify the lines in our source
# of where the crash was located:

2  qt_example.exe!buggyFunc() [main.cpp : 9 + 0x1d]

3  qt_example.exe!main [main.cpp : 26 + 0x5]
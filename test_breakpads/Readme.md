# Test breakpads

This an example I run to demonstrate how breakpads is working

## Installing breakpads

I Installed breakpads by downloading the source from : https://chromium.googlesource.com/breakpad/breakpad/

```
./configure --prefix=/usr/local/breakpads
make
make install
```

for testing a cpp application with breakpads we compile the test.cpp with the compile.sh script
this will create the test executable

to create the sym file which are our symbol file we run the command:
```
/usr/local/breakpads/bin/dump_syms ./test > test.sym
```

we pass our symbol file into the symbols folders by using the create_sym.sh

to create the mini dump file inside our test.cpp 

we call google_breakpad::ExceptionHandler 

this will create the dmp file under tmp in our case: /tmp/0e90bbe2-da5b-69f4-4a00207a-3c83079a.dmp

now that we have the sym file and the dmp we can create a stackable human readable file by using:
```
/usr/local/breakpads/bin/minidump_stackwalk 22b4cea6-be2a-15e7-07d297b7-179f0d51.dmp ./symbols/ > human_readable_stack_trace.txt 2>&1
```


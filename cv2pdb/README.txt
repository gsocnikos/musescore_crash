License information
-------------------

This code is distributed under the term of the Artistic License 2.0.
For more details, see the full text of the license in the file LICENSE.

The file demangle.cpp is an adaption of denangle.d to C++ distributed with
the DMD compiler. It is placed into the Public Domain.

The file mscvpdb.h is taken from the WINE-project (http://www.winehq.org)
and is distributed under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
See the file header for more details and 
http://www.gnu.org/licenses/lgpl.html for the full license.

The file dwarf.h is taken from the libdwarf project 
(http://reality.sgiweb.org/davea/dwarf.html)
and is distributed under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
See the file header for more details and 
http://www.gnu.org/licenses/lgpl.html for the full license.

Installation
------------

after you download the source code from: 
https://github.com/rainers/cv2pdb

you will find the cv2pdb.vcproj under src folder. 
You double click the file then the visual studio opens
then select from the task bar: build -> build cv2pdb
this procedure will create the cv2pdb.exe


Visual Studio Studio
--------------------

For mingw32 5.3.0 it requires Visual Studio 2015, with the 14393 Windows SDK to build.

Install Visual Studio 2015 Update 3 or later - Community Edition should work if its license is appropriate for you. Use the Custom Install option and select:

    Visual C++, which will select three sub-categories including MFC
    Universal Windows Apps Development Tools > Tools (1.4.1) and Windows 10 SDK (10.0.14393)

You must have the 14393 Windows SDK installed. It is okay to have multiple SDK versions installed as long as 14393 is one of them. The installer can be found in the Windows SDK archive.

When installing the 14393 Windows SDK choose Debugging Tools For Windows in order to get windbg and cdb. The latter is required for the build to succeed as some tests use it for symbolizing crash dumps.

Usage
-----

Quick start:

Simply run

cv2pdb debuggee.exe

it will produce a file:
debuggee.pdb

in the case that outputs:

no code view found 

that means that the executable does not contains the symbols and allocation tables
to enable them compile the source gode with the -g option:
g++ -g debuggee.cpp -o debuggee.exe


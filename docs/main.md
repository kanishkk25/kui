@mainpage
@author Kanishk Chouhan

KUI library to be used when user wants some simple GUI interaction on terminal.
This library will help the user to write application that uses minimal GUI programming.

This library has currently only one part conaiting \ref kui_vt100.h and libkui.a

<hr/>
<h1>How to compile</h1>

Place the header file (\ref kui_vt100.h) and library file (libkui.a) in folders of your choice
<br>
<br>
Include the \ref kui_vt100.h in your source code that uses kui library functions.

To compile -
<pre>
gcc		<your_source_code.c>	-I <path_to_header_file_folder>		-L <path_to_library_file_folder>		-lkui		-o		<executable_file_name>
</pre>
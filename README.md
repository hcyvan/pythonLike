<h1>Description</h1>
I want to create some python-like function. The name of these function are just like "basicnamepy". basicname is the function name in python.
This c++ static library and head files alse include some useful funtion and macros for me. 
<h1>use</h1>
1.The header and lib can be compiled by g++-4.9.2 and used on ubuntu11.01 <br>
<B>make</B> <i>create "test" and "libmyLib.a"</i><br>
"test" is the object of test.cc and libmyLib.a,which is use to test the pythonLike lib;libmyLib.a include:myLib.cc pyLib.cc<br>
<B>make clean</B> <i>remove myLib.o pyList.o</i><br>
<B>make clean-all</B> <i>remove myLib.o pyList.o libmyLib.a test</i><br>
2.we can use <B>pyList.h pyList.cc </B>and <B>py.h</B> to initialize the use c++ like python<br>
3.myLib.h inclue some usefull macros and the declare of myLib.cc<br>
<h1>This repository is in building...</h1>

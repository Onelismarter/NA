Running 'make run' will compile and execute all .cpp files, outputting the results of all problems. 
Running 'make report' will generate a Report.pdf.
'make clean' will remove all newly generated files.

！因为画图的原因，我这里头文件中的 matplotlibcpp.h 是一个开源的包，链接了python，所以需要在(.vscode/c_cpp_properties.json)的configurations中 改成自己电脑里头文件 Python.h和 arrayobject.h的路径 就可以编译成功。
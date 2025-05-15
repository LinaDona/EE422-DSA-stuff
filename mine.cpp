#include <iostream>
#include <ctime>

// using namespace std;

int main(int argc, char const *argv[])
{
    std::cout << "Hello, Lina!\n";
    std::cin.get();
    return 0;
} 

/*
-lstdc++ stands for linker standard c++, it adds the c++ linker so that the linking proceeds successfully.
The error resulting from the command "gcc mine.cpp" is not a compiling error, it's a linking error.

you can either: gcc mine.C -lstdc++ OR gcc mine.cc -lstdc++ 
OR g++ mine.cpp
don't forget the option -o mine to name the executable file.

g++ -S mine.cpp generates a .s file which is an assembly source file that needs to be assembled + linked to
become an exe.

g++ -c mine.cpp generates an object code but without doing the linking process.
*/

#include <iostream>
#include <StaticLibrary/foo.h>
#include <StaticLibrary/bar/bar.h>

int main()
{
	std::cout << "Hello, world!" << std::endl;
	std::cout << (sizeof(void*) * 8) << "-bit architecture" << std::endl;
    foo_func();
    bar_func();
}

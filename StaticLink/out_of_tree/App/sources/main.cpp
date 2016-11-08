#include <iostream>
#include <MyLib/foo.h>
#include <MyLib/bar/bar.h>

int main()
{
	std::cout << "Hello, world!" << std::endl;
	std::cout << (sizeof(void*) * 8) << "-bit architecture" << std::endl;
    foo_func();
    bar_func();
}

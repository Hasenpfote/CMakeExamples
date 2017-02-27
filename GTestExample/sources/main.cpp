#include <iostream>
#include "bar.h"
#include "foo.h"

int main()
{
    Bar bar;
    std::cout << "bar is ready? " << std::boolalpha << bar.IsReady() << std::endl;

    Foo foo(2);
    std::cout << "foo(2) is odd? " << std::boolalpha << foo.IsOdd() << std::endl;
    std::cout << "foo(2) is even? " << std::boolalpha << foo.IsEven() << std::endl;

    return 0;
}

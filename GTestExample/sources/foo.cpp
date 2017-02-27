#include "foo.h"

Foo::Foo(int num)
    : num_(num)
{
}

bool Foo::IsOdd() const
{
    return (num_ % 2) == 0; // bug!
}

bool Foo::IsEven() const
{
    return (num_ % 2) == 0;
}
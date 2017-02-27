#pragma once

class Foo
{
public:
    Foo(int num);
    bool IsOdd() const;
    bool IsEven() const;
    
private:
    int num_;
};

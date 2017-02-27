#pragma once

class Bar
{
public:
    Bar();
    bool IsReady() const;
    
private:
    bool ready_;
};

#include "bar.h"

Bar::Bar()
    : ready_(false)
{
}

bool Bar::IsReady() const
{
    return ready_;
}
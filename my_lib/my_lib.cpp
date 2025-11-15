// Copyright (c) 2022-2024 Xiao Pan

#include "my_lib/my_lib.h"

namespace my_lib
{
GregorianYear::GregorianYear(int year) : year_(year) {}

bool GregorianYear::IsLeap() const
{
    if (year_ <= 0)
    {
        return false;
    }
    if (year_ % 100 == 0)
    {
        return year_ % 400 == 0;
    }
    return year_ % 4 == 0;
}
}  // namespace my_lib

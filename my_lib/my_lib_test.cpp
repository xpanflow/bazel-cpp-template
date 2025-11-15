// Copyright (c) 2022-2024 Xiao Pan

#include "my_lib/my_lib.h"

#include <gtest/gtest.h>

namespace
{
TEST(LeapYear, GivenYear2024_WhenCheckingIsLeap_ThenReturnsTrue)
{
    const my_lib::GregorianYear year{2024};
    const bool is_leap = year.IsLeap();
    EXPECT_TRUE(is_leap);
}

TEST(LeapYear, GivenYear2023_WhenCheckingIsLeap_ThenReturnsFalse)
{
    const my_lib::GregorianYear year{2023};
    const bool is_leap = year.IsLeap();
    EXPECT_FALSE(is_leap);
}

TEST(LeapYear, GivenYear1900_WhenCheckingIsLeap_ThenReturnsFalse)
{
    const my_lib::GregorianYear year{1900};
    const bool is_leap = year.IsLeap();
    EXPECT_FALSE(is_leap);
}

TEST(LeapYear, GivenYear2000_WhenCheckingIsLeap_ThenReturnsTrue)
{
    const my_lib::GregorianYear year{2000};
    const bool is_leap = year.IsLeap();
    EXPECT_TRUE(is_leap);
}

TEST(LeapYear, GivenYearZero_WhenCheckingIsLeap_ThenReturnsFalse)
{
    const my_lib::GregorianYear year{0};
    const bool is_leap = year.IsLeap();
    EXPECT_FALSE(is_leap);
}

TEST(LeapYear, GivenNegativeYearDivisibleByFour_WhenCheckingIsLeap_ThenReturnsFalse)
{
    const my_lib::GregorianYear year{-4};
    const bool is_leap = year.IsLeap();
    EXPECT_FALSE(is_leap);
}
}  // namespace

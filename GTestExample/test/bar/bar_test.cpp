#include <gtest/gtest.h>
#include <bar.h>

namespace {

class BarTest : public ::testing::Test {};

TEST_F(BarTest, IsReady)
{
    Bar b1;
    EXPECT_EQ(false, b1.IsReady());
}

}
#include <gtest/gtest.h>
#include "../helpers/micro_scheme.h"

TEST(MicroSchemeTest, PlusExpr) {
    EXPECT_STREQ("3", MicroScheme("(+ 1 2)").result().c_str());
    EXPECT_STREQ("10", MicroScheme("(+ 2 2 6)").result().c_str());
    EXPECT_STREQ("-6", MicroScheme("(+ -2 2 -6)").result().c_str());
    EXPECT_ANY_THROW(MicroScheme("(+ 1)").result());
}

TEST(MicroSchemeTest, MinusExpr) {
    EXPECT_STREQ("2", MicroScheme("(- 9 7)").result().c_str());
    EXPECT_STREQ("-16", MicroScheme("(- -9 7)").result().c_str());
    EXPECT_ANY_THROW(MicroScheme("(- 1)").result());
    EXPECT_ANY_THROW(MicroScheme("(- 1 2 3)").result());
}

#include <gtest/gtest.h>
#include <string>
#include "../helpers/micro_scheme.h"

TEST(UserFunctionTest, Factorial) {
    std::string def = "(define (fact n) (if (= n 0) 1 (* n (fact (- n 1)))))";
    EXPECT_STREQ("1", MicroScheme(def).next("(fact 0)").result().c_str());
    EXPECT_STREQ("2", MicroScheme(def).next("(fact 2)").result().c_str());
    EXPECT_STREQ("120", MicroScheme(def).next("(fact 5)").result().c_str());
}

TEST(UserFunctionTest, SubFunction) {
    std::string def = "(define (sub n) (define (f x) (+ x 1)) (f n))";
    EXPECT_STREQ("2", MicroScheme(def).next("(sub 1)").result().c_str());
    EXPECT_STREQ("3", MicroScheme(def).next("(sub 2)").result().c_str());
    EXPECT_ANY_THROW(MicroScheme(def).next("(f 2)").result());
}

TEST(UserFunctionTest, FunctionAsArgument) {
    std::string f = "(define (f x) (+ x x 50))";
    std::string g = "(define (g h x) (h x))";
    EXPECT_STREQ("54", MicroScheme(f).next(g).next("(g f 2)").result().c_str());
    EXPECT_STREQ("64", MicroScheme(f).next(g).next("(g f 7)").result().c_str());
}

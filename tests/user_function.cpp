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
    std::string f = "(define (f x) (+ x x -5))";
    std::string g = "(define (g f x) (f (* x x)))";
    EXPECT_STREQ("3", MicroScheme(f).next(g).next("(g f 2)").result().c_str());
    EXPECT_STREQ("93", MicroScheme(f).next(g).next("(g f 7)").result().c_str());
}

TEST(UserFunctionTest, Alias) {
    std::string def = "(define (f) +)";
    EXPECT_STREQ("7", MicroScheme(def).next("(f 2 5)").result().c_str());
    EXPECT_STREQ("-6", MicroScheme(def).next("(f 3 -4 -5)").result().c_str());
}

TEST(UserFunctionTest, Closure) {
    std::string def = "(define (f x) (define (sub y) (+ x y)) sub)";
    EXPECT_STREQ("function", MicroScheme(def).next("(f 0)").result().c_str());
    EXPECT_STREQ("15", MicroScheme(def).next("((f 5) 10)").result().c_str());
    EXPECT_STREQ("-1", MicroScheme(def).next("((f 1) -2)").result().c_str());
}

TEST(UserFunctionTest, Closure2) {
    std::string f = "(define (f x) (define (g y z) (* x (+ y z))) g)";
    std::string g = "(define (g f x y) (- (f x y) 10))";
    EXPECT_STREQ("5", MicroScheme(f).next(g).next("(g (f 3) 1 4)").result().c_str());
    EXPECT_STREQ("-7", MicroScheme(f).next(g).next("(g (f 1) -2 5)").result().c_str());
}

#include <gtest/gtest.h>
#include "../helpers/micro_scheme.h"

TEST(MicroSchemeTest, WrongExpr) {
    EXPECT_ANY_THROW(MicroScheme(")").result());
    EXPECT_ANY_THROW(MicroScheme("()").result());
    EXPECT_ANY_THROW(MicroScheme("(1)").result());
    EXPECT_ANY_THROW(MicroScheme("(1 2)").result());
}

TEST(MicroSchemeTest, PlusExpr) {
    EXPECT_STREQ("3", MicroScheme("(+ 1 2)").result().c_str());
    EXPECT_STREQ("10", MicroScheme("(+ 2 2 6)").result().c_str());
    EXPECT_STREQ("7", MicroScheme("(+ 1 1 1 1 1 1 1)").result().c_str());
    EXPECT_STREQ("-6", MicroScheme("(+ -2 2 -6)").result().c_str());
    EXPECT_STREQ("4.4", MicroScheme("(+ 2.4 2)").result().c_str());
    EXPECT_ANY_THROW(MicroScheme("(+)").result());
    EXPECT_ANY_THROW(MicroScheme("(+ 1)").result());
}

TEST(MicroSchemeTest, MinusExpr) {
    EXPECT_STREQ("2", MicroScheme("(- 9 7)").result().c_str());
    EXPECT_STREQ("-16", MicroScheme("(- -9 7)").result().c_str());
    EXPECT_STREQ("1.5", MicroScheme("(- 8.5 7)").result().c_str());
    EXPECT_ANY_THROW(MicroScheme("(-)").result());
    EXPECT_ANY_THROW(MicroScheme("(- 1)").result());
    EXPECT_ANY_THROW(MicroScheme("(- 1 2 3)").result());
}

TEST(MicroSchemeTest, MultiplyExpr) {
    EXPECT_STREQ("2", MicroScheme("(* 1 2)").result().c_str());
    EXPECT_STREQ("24", MicroScheme("(* 2 2 6)").result().c_str());
    EXPECT_STREQ("128", MicroScheme("(* 2 2 2 2 2 2 2)").result().c_str());
    EXPECT_STREQ("-36", MicroScheme("(* 2 3 -6)").result().c_str());
    EXPECT_STREQ("6.9", MicroScheme("(* 2.3 3)").result().c_str());
    EXPECT_ANY_THROW(MicroScheme("(*)").result());
    EXPECT_ANY_THROW(MicroScheme("(* 1)").result());
}

TEST(MicroSchemeTest, DivideExpr) {
    EXPECT_STREQ("2.5", MicroScheme("(/ 5 2)").result().c_str());
    EXPECT_STREQ("-5", MicroScheme("(/ -10 2)").result().c_str());
    EXPECT_ANY_THROW(MicroScheme("(/)").result());
    EXPECT_ANY_THROW(MicroScheme("(/ 1)").result());
    EXPECT_ANY_THROW(MicroScheme("(/ 1 2 3)").result());
}

TEST(MicroSchemeTest, EqExpr) {
    EXPECT_STREQ("false", MicroScheme("(= 3 2)").result().c_str());
    EXPECT_STREQ("false", MicroScheme("(= 2.01 2)").result().c_str());
    EXPECT_STREQ("true", MicroScheme("(= -10 -10)").result().c_str());
    EXPECT_ANY_THROW(MicroScheme("(=)").result());
    EXPECT_ANY_THROW(MicroScheme("(= 1)").result());
    EXPECT_ANY_THROW(MicroScheme("(= 1 2 3)").result());
}

TEST(MicroSchemeTest, IfExpr) {
    EXPECT_STREQ("10", MicroScheme("(if (= 1 1) 10 20)").result().c_str());
    EXPECT_STREQ("20", MicroScheme("(if (= 1 2) 10 20)").result().c_str());
    EXPECT_ANY_THROW(MicroScheme("(if 10 20 30)").result());
    EXPECT_ANY_THROW(MicroScheme("(if (= 1 1) 10)").result());
    EXPECT_ANY_THROW(MicroScheme("(if (= 1 1) 10 20 30)").result());
}

TEST(MicroSchemeTest, DefineExpr) {
    EXPECT_STREQ("ok", MicroScheme("(define (f) 5)").result().c_str());
    EXPECT_STREQ("ok", MicroScheme("(define (f x) x)").result().c_str());
    EXPECT_STREQ("ok", MicroScheme("(define (f x y) (+ (/ x x) y))").result().c_str());
    EXPECT_ANY_THROW(MicroScheme("(define 1 2)").result());
    EXPECT_ANY_THROW(MicroScheme("(define (1) 2)").result());
    EXPECT_ANY_THROW(MicroScheme("(define (1 2) 3)").result());
    EXPECT_ANY_THROW(MicroScheme("(define (f 2) 3)").result());
}


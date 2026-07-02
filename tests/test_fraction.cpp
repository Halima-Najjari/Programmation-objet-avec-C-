#include <gtest/gtest.h>
#include "Fraction.h"

TEST(FractionTest, DefaultConstructor) {
    Fraction f;
    EXPECT_EQ(f.getNum(), 0);
    EXPECT_EQ(f.getDen(), 1);
}

TEST(FractionTest, IntegerConstructor) {
    Fraction f(5);
    EXPECT_EQ(f.getNum(), 5);
    EXPECT_EQ(f.getDen(), 1);
}

TEST(FractionTest, TwoArgConstructorNormalized) {
    Fraction f(2, 4);
    EXPECT_EQ(f.getNum(), 1);
    EXPECT_EQ(f.getDen(), 2);
}

TEST(FractionTest, TwoArgConstructorAlreadyReduced) {
    Fraction f(3, 7);
    EXPECT_EQ(f.getNum(), 3);
    EXPECT_EQ(f.getDen(), 7);
}

TEST(FractionTest, NegativeDenominator) {
    Fraction f(3, -4);
    EXPECT_EQ(f.getNum(), -3);
    EXPECT_EQ(f.getDen(), 4);
}

TEST(FractionTest, BothNegative) {
    Fraction f(-3, -4);
    EXPECT_EQ(f.getNum(), 3);
    EXPECT_EQ(f.getDen(), 4);
}

TEST(FractionTest, CopyConstructor) {
    Fraction f1(3, 4);
    Fraction f2(f1);
    EXPECT_EQ(f2.getNum(), 3);
    EXPECT_EQ(f2.getDen(), 4);
}

TEST(FractionTest, Somme) {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction result = f1.somme(f2);
    EXPECT_EQ(result.getNum(), 5);
    EXPECT_EQ(result.getDen(), 6);
}

TEST(FractionTest, SommeWithZero) {
    Fraction f1(3, 4);
    Fraction f2;
    Fraction result = f1.somme(f2);
    EXPECT_EQ(result.getNum(), 3);
    EXPECT_EQ(result.getDen(), 4);
}

TEST(FractionTest, Difference) {
    Fraction f1(3, 4);
    Fraction f2(1, 4);
    Fraction result = f1.difference(f2);
    EXPECT_EQ(result.getNum(), 1);
    EXPECT_EQ(result.getDen(), 2);
}

TEST(FractionTest, DifferenceResultNegative) {
    Fraction f1(1, 4);
    Fraction f2(3, 4);
    Fraction result = f1.difference(f2);
    EXPECT_EQ(result.getNum(), -1);
    EXPECT_EQ(result.getDen(), 2);
}

TEST(FractionTest, Produit) {
    Fraction f1(2, 3);
    Fraction f2(3, 5);
    Fraction result = f1.produit(f2);
    EXPECT_EQ(result.getNum(), 2);
    EXPECT_EQ(result.getDen(), 5);
}

TEST(FractionTest, ProduitWithOne) {
    Fraction f1(3, 7);
    Fraction f2(1);
    Fraction result = f1.produit(f2);
    EXPECT_EQ(result.getNum(), 3);
    EXPECT_EQ(result.getDen(), 7);
}

TEST(FractionTest, Division) {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction result = f1.division(f2);
    EXPECT_EQ(result.getNum(), 2);
    EXPECT_EQ(result.getDen(), 3);
}

TEST(FractionTest, DivisionByItself) {
    Fraction f(5, 7);
    Fraction result = f.division(f);
    EXPECT_EQ(result.getNum(), 1);
    EXPECT_EQ(result.getDen(), 1);
}

TEST(FractionTest, LargeNormalization) {
    Fraction f(100, 250);
    EXPECT_EQ(f.getNum(), 2);
    EXPECT_EQ(f.getDen(), 5);
}

TEST(FractionTest, SommeNormalized) {
    Fraction f1(1, 6);
    Fraction f2(1, 6);
    Fraction result = f1.somme(f2);
    EXPECT_EQ(result.getNum(), 1);
    EXPECT_EQ(result.getDen(), 3);
}

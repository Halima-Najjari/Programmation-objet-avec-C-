#include <gtest/gtest.h>
#include <cmath>
#include "Complexe.h"

class ComplexeTest : public ::testing::Test {
protected:
    Complexe c1{3.0f, 4.0f};
    Complexe c2{1.0f, -2.0f};
};

TEST_F(ComplexeTest, ConstructorWithBothParts) {
    EXPECT_FLOAT_EQ(c1.real(), 3.0f);
    EXPECT_FLOAT_EQ(c1.imag(), 4.0f);
}

TEST_F(ComplexeTest, ConstructorWithDefaultImaginary) {
    Complexe c(5.0f);
    EXPECT_FLOAT_EQ(c.real(), 5.0f);
    EXPECT_FLOAT_EQ(c.imag(), 0.0f);
}

TEST_F(ComplexeTest, Norme) {
    float expected = sqrt(3.0f * 3.0f + 4.0f * 4.0f);
    EXPECT_FLOAT_EQ(c1.norme(), expected);
}

TEST_F(ComplexeTest, NormeZero) {
    Complexe c(0.0f, 0.0f);
    EXPECT_FLOAT_EQ(c.norme(), 0.0f);
}

TEST_F(ComplexeTest, NormePurelyReal) {
    Complexe c(7.0f, 0.0f);
    EXPECT_FLOAT_EQ(c.norme(), 7.0f);
}

TEST_F(ComplexeTest, NormePurelyImaginary) {
    Complexe c(0.0f, 3.0f);
    EXPECT_FLOAT_EQ(c.norme(), 3.0f);
}

TEST_F(ComplexeTest, Conjugue) {
    Complexe conj = c1.conjugue();
    EXPECT_FLOAT_EQ(conj.real(), 3.0f);
    EXPECT_FLOAT_EQ(conj.imag(), -4.0f);
}

TEST_F(ComplexeTest, ConjugueNegativeImaginary) {
    Complexe conj = c2.conjugue();
    EXPECT_FLOAT_EQ(conj.real(), 1.0f);
    EXPECT_FLOAT_EQ(conj.imag(), 2.0f);
}

TEST_F(ComplexeTest, Somme) {
    Complexe result = c1.somme(c2);
    EXPECT_FLOAT_EQ(result.real(), 4.0f);
    EXPECT_FLOAT_EQ(result.imag(), 2.0f);
}

TEST_F(ComplexeTest, Difference) {
    Complexe result = c1.difference(c2);
    EXPECT_FLOAT_EQ(result.real(), 2.0f);
    EXPECT_FLOAT_EQ(result.imag(), 6.0f);
}

TEST_F(ComplexeTest, Produit) {
    // (3+4i)(1-2i) = 3 - 6i + 4i - 8i^2 = 3 - 2i + 8 = 11 - 2i
    Complexe result = c1.produit(c2);
    EXPECT_FLOAT_EQ(result.real(), 11.0f);
    EXPECT_FLOAT_EQ(result.imag(), -2.0f);
}

TEST_F(ComplexeTest, ProduitWithZero) {
    Complexe zero(0.0f, 0.0f);
    Complexe result = c1.produit(zero);
    EXPECT_FLOAT_EQ(result.real(), 0.0f);
    EXPECT_FLOAT_EQ(result.imag(), 0.0f);
}

TEST_F(ComplexeTest, ProduitWithOne) {
    Complexe one(1.0f, 0.0f);
    Complexe result = c1.produit(one);
    EXPECT_FLOAT_EQ(result.real(), 3.0f);
    EXPECT_FLOAT_EQ(result.imag(), 4.0f);
}

TEST_F(ComplexeTest, SommeCommutative) {
    Complexe r1 = c1.somme(c2);
    Complexe r2 = c2.somme(c1);
    EXPECT_FLOAT_EQ(r1.real(), r2.real());
    EXPECT_FLOAT_EQ(r1.imag(), r2.imag());
}

TEST_F(ComplexeTest, ProduitCommutative) {
    Complexe r1 = c1.produit(c2);
    Complexe r2 = c2.produit(c1);
    EXPECT_FLOAT_EQ(r1.real(), r2.real());
    EXPECT_FLOAT_EQ(r1.imag(), r2.imag());
}

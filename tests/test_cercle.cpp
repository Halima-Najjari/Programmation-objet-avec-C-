#include <gtest/gtest.h>
#include <cmath>
#include "Cercle.h"

class CercleTest : public ::testing::Test {
protected:
    Cercle c;

    void SetUp() override {
        c.initialiser(5.0f, 1.0f, 2.0f);
    }
};

TEST_F(CercleTest, Initialiser) {
    EXPECT_FLOAT_EQ(c.getRayon(), 5.0f);
    EXPECT_FLOAT_EQ(c.getAbscisse(), 1.0f);
    EXPECT_FLOAT_EQ(c.getOrdonnee(), 2.0f);
}

TEST_F(CercleTest, CalculerSurface) {
    float expected = 3.14159f * 5.0f * 5.0f;
    EXPECT_FLOAT_EQ(c.calculerSurface(), expected);
}

TEST_F(CercleTest, CalculerSurfaceZeroRayon) {
    Cercle c0;
    c0.initialiser(0.0f, 0.0f, 0.0f);
    EXPECT_FLOAT_EQ(c0.calculerSurface(), 0.0f);
}

TEST_F(CercleTest, CalculerPerimetre) {
    float expected = 2 * 3.14159f * 5.0f;
    EXPECT_FLOAT_EQ(c.calculerPerimetre(), expected);
}

TEST_F(CercleTest, CalculerPerimetreZeroRayon) {
    Cercle c0;
    c0.initialiser(0.0f, 0.0f, 0.0f);
    EXPECT_FLOAT_EQ(c0.calculerPerimetre(), 0.0f);
}

TEST_F(CercleTest, Deplacer) {
    c.deplacer(3.0f, -1.0f);
    EXPECT_FLOAT_EQ(c.getAbscisse(), 4.0f);
    EXPECT_FLOAT_EQ(c.getOrdonnee(), 1.0f);
}

TEST_F(CercleTest, DeplacerNegatif) {
    c.deplacer(-5.0f, -5.0f);
    EXPECT_FLOAT_EQ(c.getAbscisse(), -4.0f);
    EXPECT_FLOAT_EQ(c.getOrdonnee(), -3.0f);
}

TEST_F(CercleTest, Agrandir) {
    c.agrandir(2.0f);
    EXPECT_FLOAT_EQ(c.getRayon(), 10.0f);
}

TEST_F(CercleTest, AgrandirFractional) {
    c.agrandir(0.5f);
    EXPECT_FLOAT_EQ(c.getRayon(), 2.5f);
}

TEST_F(CercleTest, SurfaceAfterAgrandir) {
    c.agrandir(3.0f);
    float expected = 3.14159f * 15.0f * 15.0f;
    EXPECT_FLOAT_EQ(c.calculerSurface(), expected);
}

TEST_F(CercleTest, PerimetreAfterAgrandir) {
    c.agrandir(2.0f);
    float expected = 2 * 3.14159f * 10.0f;
    EXPECT_FLOAT_EQ(c.calculerPerimetre(), expected);
}

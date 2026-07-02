#include <gtest/gtest.h>
#include "Produit.h"

class ProduitTest : public ::testing::Test {
protected:
    Produit p;

    void SetUp() override {
        p.initialiser(123, 10.5f, 20);
    }
};

TEST_F(ProduitTest, Initialiser) {
    EXPECT_EQ(p.getRef(), 123);
    EXPECT_FLOAT_EQ(p.getPuht(), 10.5f);
    EXPECT_EQ(p.getQuantite(), 20);
}

TEST_F(ProduitTest, CalculerPrixTTC) {
    float expected = 10.5f * 1.2f;
    EXPECT_FLOAT_EQ(p.calculerPrixTTC(), expected);
}

TEST_F(ProduitTest, CalculerPrixTTCZero) {
    Produit p0;
    p0.initialiser(1, 0.0f, 10);
    EXPECT_FLOAT_EQ(p0.calculerPrixTTC(), 0.0f);
}

TEST_F(ProduitTest, PrixTotal) {
    float expected = 10.5f * 20;
    EXPECT_FLOAT_EQ(p.prix_total(), expected);
}

TEST_F(ProduitTest, PrixTotalZeroQuantite) {
    Produit p0;
    p0.initialiser(1, 10.0f, 0);
    EXPECT_FLOAT_EQ(p0.prix_total(), 0.0f);
}

TEST_F(ProduitTest, Retirer) {
    p.retirer(5);
    EXPECT_EQ(p.getQuantite(), 15);
}

TEST_F(ProduitTest, RetirerAll) {
    p.retirer(20);
    EXPECT_EQ(p.getQuantite(), 0);
}

TEST_F(ProduitTest, Ajouter) {
    p.ajouter(10);
    EXPECT_EQ(p.getQuantite(), 30);
}

TEST_F(ProduitTest, AjouterEtRetirer) {
    p.ajouter(5);
    p.retirer(10);
    EXPECT_EQ(p.getQuantite(), 15);
}

TEST_F(ProduitTest, PrixTotalAfterRetirer) {
    p.retirer(10);
    float expected = 10.5f * 10;
    EXPECT_FLOAT_EQ(p.prix_total(), expected);
}

TEST_F(ProduitTest, PrixTotalAfterAjouter) {
    p.ajouter(30);
    float expected = 10.5f * 50;
    EXPECT_FLOAT_EQ(p.prix_total(), expected);
}

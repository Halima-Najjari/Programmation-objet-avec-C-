#include <gtest/gtest.h>
#include "CompteBancaire.h"

class CompteBancaireTest : public ::testing::Test {
protected:
    CompteBancaire compte{1, 1000.0f};
};

TEST_F(CompteBancaireTest, Construction) {
    EXPECT_EQ(compte.getNumero(), 1);
    EXPECT_FLOAT_EQ(compte.getSolde(), 1000.0f);
}

TEST_F(CompteBancaireTest, Deposer) {
    compte.deposer(500.0f);
    EXPECT_FLOAT_EQ(compte.getSolde(), 1500.0f);
}

TEST_F(CompteBancaireTest, DeposerZero) {
    compte.deposer(0.0f);
    EXPECT_FLOAT_EQ(compte.getSolde(), 1000.0f);
}

TEST_F(CompteBancaireTest, DeposerMultiple) {
    compte.deposer(100.0f);
    compte.deposer(200.0f);
    compte.deposer(300.0f);
    EXPECT_FLOAT_EQ(compte.getSolde(), 1600.0f);
}

TEST_F(CompteBancaireTest, RetirerSuffisant) {
    compte.retirer(300.0f);
    EXPECT_FLOAT_EQ(compte.getSolde(), 700.0f);
}

TEST_F(CompteBancaireTest, RetirerTout) {
    compte.retirer(1000.0f);
    EXPECT_FLOAT_EQ(compte.getSolde(), 0.0f);
}

TEST_F(CompteBancaireTest, RetirerInsuffisant) {
    compte.retirer(1500.0f);
    EXPECT_FLOAT_EQ(compte.getSolde(), 1000.0f);
}

TEST_F(CompteBancaireTest, VirementSuffisant) {
    CompteBancaire dest(2, 500.0f);
    compte.virement(dest, 300.0f);
    EXPECT_FLOAT_EQ(compte.getSolde(), 700.0f);
    EXPECT_FLOAT_EQ(dest.getSolde(), 800.0f);
}

TEST_F(CompteBancaireTest, VirementInsuffisant) {
    CompteBancaire dest(2, 500.0f);
    compte.virement(dest, 2000.0f);
    EXPECT_FLOAT_EQ(compte.getSolde(), 1000.0f);
    EXPECT_FLOAT_EQ(dest.getSolde(), 500.0f);
}

TEST_F(CompteBancaireTest, VirementTotal) {
    CompteBancaire dest(2, 0.0f);
    compte.virement(dest, 1000.0f);
    EXPECT_FLOAT_EQ(compte.getSolde(), 0.0f);
    EXPECT_FLOAT_EQ(dest.getSolde(), 1000.0f);
}

TEST_F(CompteBancaireTest, VirementZero) {
    CompteBancaire dest(2, 500.0f);
    compte.virement(dest, 0.0f);
    EXPECT_FLOAT_EQ(compte.getSolde(), 1000.0f);
    EXPECT_FLOAT_EQ(dest.getSolde(), 500.0f);
}

TEST_F(CompteBancaireTest, DeposerPuisRetirer) {
    compte.deposer(500.0f);
    compte.retirer(200.0f);
    EXPECT_FLOAT_EQ(compte.getSolde(), 1300.0f);
}

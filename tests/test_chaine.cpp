#include <gtest/gtest.h>
#include <cstring>
#include "chaine.h"

TEST(ChaineTest, DefaultConstructor) {
    chaine c;
    EXPECT_EQ(c.getLongueur(), 0);
    EXPECT_STREQ(c.getTexte(), "");
}

TEST(ChaineTest, ParameterConstructor) {
    chaine c("Bonjour");
    EXPECT_EQ(c.getLongueur(), 7);
    EXPECT_STREQ(c.getTexte(), "Bonjour");
}

TEST(ChaineTest, ParameterConstructorEmpty) {
    chaine c("");
    EXPECT_EQ(c.getLongueur(), 0);
    EXPECT_STREQ(c.getTexte(), "");
}

TEST(ChaineTest, CopyConstructor) {
    chaine c1("Hello");
    chaine c2(c1);
    EXPECT_EQ(c2.getLongueur(), 5);
    EXPECT_STREQ(c2.getTexte(), "Hello");
}

TEST(ChaineTest, CopyConstructorIndependence) {
    chaine c1("Test");
    chaine c2(c1);
    c1.concatenation(chaine("X"));
    EXPECT_STREQ(c2.getTexte(), "Test");
}

TEST(ChaineTest, Concatenation) {
    chaine c1("Hello");
    chaine c2(" World");
    c1.concatenation(c2);
    EXPECT_EQ(c1.getLongueur(), 11);
    EXPECT_STREQ(c1.getTexte(), "Hello World");
}

TEST(ChaineTest, ConcatenationWithEmpty) {
    chaine c1("Hello");
    chaine c2("");
    c1.concatenation(c2);
    EXPECT_STREQ(c1.getTexte(), "Hello");
    EXPECT_EQ(c1.getLongueur(), 5);
}

TEST(ChaineTest, ConcatenationEmptyWithNonEmpty) {
    chaine c1("");
    chaine c2("World");
    c1.concatenation(c2);
    EXPECT_STREQ(c1.getTexte(), "World");
    EXPECT_EQ(c1.getLongueur(), 5);
}

TEST(ChaineTest, AccesValidIndex) {
    chaine c("ABCDE");
    EXPECT_EQ(c.acces(0), 'A');
    EXPECT_EQ(c.acces(2), 'C');
    EXPECT_EQ(c.acces(4), 'E');
}

TEST(ChaineTest, Affectation) {
    chaine c1("Original");
    chaine c2("New");
    c1.affectation(c2);
    EXPECT_STREQ(c1.getTexte(), "New");
    EXPECT_EQ(c1.getLongueur(), 3);
}

TEST(ChaineTest, AffectationSelf) {
    chaine c("Self");
    c.affectation(c);
    EXPECT_STREQ(c.getTexte(), "Self");
    EXPECT_EQ(c.getLongueur(), 4);
}

TEST(ChaineTest, AffectationIndependence) {
    chaine c1("First");
    chaine c2("Second");
    c1.affectation(c2);
    c2.concatenation(chaine("X"));
    EXPECT_STREQ(c1.getTexte(), "Second");
}

TEST(ChaineTest, MultipleConcatenations) {
    chaine c("A");
    c.concatenation(chaine("B"));
    c.concatenation(chaine("C"));
    c.concatenation(chaine("D"));
    EXPECT_STREQ(c.getTexte(), "ABCD");
    EXPECT_EQ(c.getLongueur(), 4);
}

TEST(ChaineTest, LongueurAfterOperations) {
    chaine c("Hello");
    EXPECT_EQ(c.getLongueur(), 5);
    c.concatenation(chaine(" World"));
    EXPECT_EQ(c.getLongueur(), 11);
}

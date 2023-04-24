#include "HashTable1.h"
#include <gtest.h>
#include "Polinom.h"
//TEST(HashTable1, can_make_table) {
//    ASSERT_NO_THROW(HashTable1 <string, Polinom> A);
//}
TEST(HashTable1, can_insert_polinom) {
    HashTable1 <string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    ASSERT_NO_THROW(A.Insert("a", a));
}
TEST(HashTable1, can_find_polinom) {
    HashTable1 <string, Polinom> A;
    string ans="-2XYZ-3XY+8X^2Z^3";
    Polinom a(ans);
    A.Insert("a", a);
    Polinom* pa = A.Find("a");
    string EXans=pa->GetInfix();
    EXPECT_EQ(ans, EXans);
}
TEST(HashTable1, can_delete_polinom) {
    HashTable1 <string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    ASSERT_NO_THROW(A.Delete("a"));
}
TEST(HashTable1, can_give_table) {
    HashTable1 <string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    Polinom b("XYZ+3XY+9X^2Z");
    A.Insert("a", a);
    A.Insert("b", b);
    vector<string> ans=A.GiveTable();
    vector<string> EXans={"a = -2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3",
    "b = 1.000000X^1Y^1Z^1+3.000000X^1Y^1Z^0+9.000000X^2Y^0Z^1"};
    EXPECT_EQ(ans, EXans);
}
TEST(HashTable1, can_insert_right) {
    HashTable1 <string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    A.Insert("a", a);
    vector<string> ans = A.GiveTable();
    vector<string> EXans = { "a = -2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3"};
    EXPECT_EQ(ans, EXans);
}
TEST(HashTable1, can_nit_insert_same_polinoms) {
    HashTable1 <string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    A.Insert("a", a);
    A.Insert("a", a);
    vector<string> ans = A.GiveTable();
    vector<string> EXans = { "a = -2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3" };
    EXPECT_EQ(ans, EXans);
}
TEST(HashTable1, can_delete_right) {
    HashTable1 <string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    Polinom b("XYZ+3XY+9X^2Z");
    A.Insert("a", a);
    A.Insert("b", b);
    A.Delete("b");
    vector<string> ans = A.GiveTable();
    vector<string> EXans = { "a = -2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3" };
    EXPECT_EQ(ans, EXans);
}
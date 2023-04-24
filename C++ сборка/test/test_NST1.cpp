#include "NoSortedTable1.h"
#include <gtest.h>
#include "Polinom.h"
//TEST(NoSortedTable1 , can_make_table) {
//    ASSERT_NO_THROW(NoSortedTable1 <string, Polinom> A);
//}
TEST(NoSortedTable1, can_insert_polinom) {
    NoSortedTable1<string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    ASSERT_NO_THROW(A.Insert("a", a));
}
TEST(NoSortedTable1, can_delete_polinom) {
    NoSortedTable1 <string, Polinom>A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    ASSERT_NO_THROW(A.Delete("a"));
}
TEST(NoSortedTable1, can_find_polinom) {
    NoSortedTable1<string, Polinom> A;
    string ans="-2XYZ-3XY+8X^2Z^3";
    Polinom a(ans);
    A.Insert("a",a);
    Polinom* pa = A.Find("a");
    string EXans=pa->GetInfix();
    EXPECT_EQ(ans, EXans);
}
TEST(NoSortedTable1, can_give_table) {
    NoSortedTable1<string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    Polinom b("XYZ+3XY+9X^2Z");
    A.Insert("a", a);
    A.Insert("b", b);
    vector<string> ans=A.GiveTable();
    vector<string> EXans={"a = -2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3",
    "b = 1.000000X^1Y^1Z^1+3.000000X^1Y^1Z^0+9.000000X^2Y^0Z^1"};
    EXPECT_EQ(ans, EXans);
}
TEST(NoSortedTable1, can_insert_right) {
    NoSortedTable1<string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    A.Insert("a", a);
    vector<string> ans = A.GiveTable();
    vector<string> EXans = { "a = -2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3"};
    EXPECT_EQ(ans, EXans);
}
TEST(NoSortedTable1, can_nit_insert_same_polinoms) {
    NoSortedTable1 <string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    A.Insert("a", a);
    A.Insert("a", a);
    vector<string> ans = A.GiveTable();
    vector<string> EXans = { "a = -2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3" };
    EXPECT_EQ(ans, EXans);
}
TEST(NoSortedTable1, can_delete_right) {
    NoSortedTable1<string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    Polinom b("XYZ+3XY+9X^2Z");
    A.Insert("a", a);
    A.Insert("b", b);
    A.Delete("b");
    vector<string> ans = A.GiveTable();
    vector<string> EXans = { "a = -2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3" };
    EXPECT_EQ(ans, EXans);
}
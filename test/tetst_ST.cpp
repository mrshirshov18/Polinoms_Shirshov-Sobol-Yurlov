#include "SortedTable.h"
#include <gtest.h>
#include "Polinom.h"
//TEST(SortedTable, can_make_table) {
//    ASSERT_NO_THROW(SortedTable <string, Polinom> A);
//}
TEST(SortedTable, can_insert_polinom) {
    SortedTable <string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    ASSERT_NO_THROW(A.Insert("a",a));
}
TEST(SortedTable, can_delete_polinom) {
    SortedTable <string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    ASSERT_NO_THROW(A.Delete("a"));
}
TEST(SortedTable, can_find_polinom) {
    SortedTable <string, Polinom> A;
    string ans = "-2XYZ-3XY+8X^2Z^3";
    Polinom a(ans);
     A.Insert("a", a);
    Polinom* pa = A.Find("a");
    string EXans = pa->GetInfix();
    EXPECT_EQ(ans, EXans);
}
TEST(SortedTable, can_give_table) {
    SortedTable <string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    Polinom b("XYZ+3XY+9X^2Z");
    A.Insert("a", a);
    A.Insert("b", b);
    vector<string> ans = A.GiveTable();
    vector<string> EXans = { "a = -2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3",
    "b = 1.000000X^1Y^1Z^1+3.000000X^1Y^1Z^0+9.000000X^2Y^0Z^1" };
    EXPECT_EQ(ans, EXans);
}
TEST(SortedTable, can_insert_right) {
    SortedTable <string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    A.Insert("a", a);
    vector<string> ans = A.GiveTable();
    vector<string> EXans = { "a = -2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3" };
    EXPECT_EQ(ans, EXans);
}
TEST(SortedTable, can_nit_insert_same_polinoms) {
    SortedTable <string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    A.Insert("a", a);
    A.Insert("a", a);
    vector<string> ans = A.GiveTable();
    vector<string> EXans = { "a = -2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3" };
    EXPECT_EQ(ans, EXans);
}
TEST(SortedTable, can_delete_right) {
    SortedTable <string, Polinom> A;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    Polinom b("XYZ+3XY+9X^2Z");
    A.Insert("a", a);
    A.Insert("b", b);
    A.Delete("b");
    vector<string> ans = A.GiveTable();
    vector<string> EXans = { "a = -2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3" };
    EXPECT_EQ(ans, EXans);
}
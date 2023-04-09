#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_parse_negative_number) {
    string str = "-3+1";
    ASSERT_NO_THROW(TPostfix expression(str));
}

TEST(TPostfix, can_calculate_expression_with_numbers_and_variables)
{
    NoSortedTable1 <string, Polinom> A;
    NoSortedTable2  <string, Polinom> B;
    SortedTable <string, Polinom>  C;
    HashTable1  <string, Polinom> D;
    HashTable2  <string, Polinom> G;
    TreeTable <string, Polinom> E;
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    Polinom b("XYZ+3XY+9X^2Z");
    Polinom c = a + b;
    A.Insert("a",a);
    A.Insert("c",c);
    TPostfix tre("a+c+1");
    Polinom res = tre.Calculate(1, A, B, C, D, G, E);
    string ans = res.GivePolinom();
    string EXans="-3.000000X^1Y^1z^1-3.000000X^1Y^1z^0+16.000000X^2Y^0z^3+9.000000X^2Y^0z^1+1.000000X^0Y^0z^0";
    EXPECT_EQ(EXans, ans);
}
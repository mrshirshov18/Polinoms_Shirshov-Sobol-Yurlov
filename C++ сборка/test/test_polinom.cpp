#include "Polinom.h"
#include <gtest.h>

TEST(Polinom, can_parse_polinom_with_negative_number) {
    string str="-2XYZ-3XY+8X^2Z^3";
    ASSERT_NO_THROW(Polinom a(str));
}
TEST(Polinom, can_parse_polinom) {
    string str ="XYZ+3XY+9X^2Z" ;
    ASSERT_NO_THROW(Polinom b(str));
}
TEST(Polinom, can_parse_empty_polinom) {
    ASSERT_NO_THROW(Polinom b());
}
TEST(Polinom, can_not_parse_reverse_order1) {
    string str = "XZY";
    ASSERT_ANY_THROW(Polinom b(str));
}
TEST(Polinom ,can_not_parse_reverse_order2) {
    string str = "YZX";
    ASSERT_ANY_THROW(Polinom b(str));
}
TEST(Polinom, give_input)
{
    string str = "-2XYZ-3XY+8X^2Z^3";
    Polinom a(str, "a");
    string ans = a.GetInfix();
    string EXans = "-2XYZ-3XY+8X^2Z^3";
    EXPECT_EQ(ans, EXans);
}
TEST(Polinom, get_name)
{
    string str = "-2XYZ-3XY+8X^2Z^3";
    Polinom a(str, "a");
    string ans = a.Get_name();
    string EXans = "a";
    EXPECT_EQ(ans, EXans);
}
TEST(Polinom, give_name)
{
    string str = "-2XYZ-3XY+8X^2Z^3";
    Polinom a(str, "a");
    a.Give_name("new");
    string ans = a.Get_name();
    string EXans = "new";
    EXPECT_EQ(ans, EXans);
}
TEST(Polinom, get_siZe_of_name)
{
    string str = "-2XYZ-3XY+8X^2Z^3";
    Polinom a(str, "a");
    int ans=a.Get_size_of_name();
    int EXans = 1;
    EXPECT_EQ(ans, EXans);
}
TEST(Polinom, can_parse_right_1)
{
    string str = "-2XYZ-3XY+8X^2Z^3";
    Polinom a(str,"a");
    string ans=a.GivePolinom();
    string EXans="-2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3";
    EXPECT_EQ(ans, EXans);
}
TEST(Polinom, can_parse_right_2)
{
    string str = "XYZ+3XY+9X^2Z";
    Polinom a(str, "a");
    string ans = a.GivePolinom();
    string EXans = "1.000000X^1Y^1Z^1+3.000000X^1Y^1Z^0+9.000000X^2Y^0Z^1";
    EXPECT_EQ(ans, EXans);
}
TEST(Polinom, can_give_point)
{
    string str = "-2XYZ-3XY+8X^2Z^3";
    Polinom a(str, "a");
    double ans=a.Point(1.0, 1.0, 1.0);
    EXPECT_EQ(ans, 3.0);
}

TEST(Polinom, can_add_polinoms)
{
    string str = "-2XYZ-3XY+8X^2Z^3";
    Polinom a(str, "a");
    string str2 = "XYZ+3XY+9X^2Z";
    Polinom b(str2, "b");
    Polinom c=a+b;
    string ans=c.GivePolinom();
    string EXans = "-1.000000X^1Y^1Z^1+8.000000X^2Y^0Z^3+9.000000X^2Y^0Z^1";
    EXPECT_EQ(ans, EXans );
}
TEST(Polinom, can_subtract_polinoms)
{
    string str = "-2XYZ-3XY+8X^2Z^3";
    Polinom a(str, "a");
    string str2 = "XYZ+3XY+9X^2Z";
    Polinom b(str2, "b");
    Polinom c = a - b;
    string ans = c.GivePolinom();
    string EXans = "-3.000000X^1Y^1Z^1-6.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3-9.000000X^2Y^0Z^1";
    EXPECT_EQ(ans, EXans);
}
TEST(Polinom, can_multiply_on_const)
{
    string str = "-2XYZ-3XY+8X^2Z^3";
    Polinom a(str, "a");
    Polinom c = a*3.0;
    string ans = c.GivePolinom();
    string EXans = "-6.000000X^1Y^1Z^1-9.000000X^1Y^1Z^0+24.000000X^2Y^0Z^3";
    EXPECT_EQ(ans, EXans);
}
TEST(Polinom, can_multiply_on_negative_const)
{
    string str = "-2XYZ-3XY+8X^2Z^3";
    Polinom a(str, "a");
    Polinom c = a * (-3.0);
    string ans = c.GivePolinom();
    string EXans = "6.000000X^1Y^1Z^1+9.000000X^1Y^1Z^0-24.000000X^2Y^0Z^3";
    EXPECT_EQ(ans, EXans);
}
TEST(Polinom, can_add_const)
{
    string str = "-2XYZ-3XY+8X^2Z^3";
    Polinom a(str, "a");
    Polinom c = a + 2.1;
    string ans = c.GivePolinom();
    string EXans = "-2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3+2.100000X^0Y^0Z^0";
    EXPECT_EQ(ans, EXans);
}
TEST(Polinom, can_subtract_const)
{
    string str = "-2XYZ-3XY+8X^2Z^3";
    Polinom a(str, "a");
    Polinom c = a - 2.1;
    string ans = c.GivePolinom();
    string EXans = "-2.000000X^1Y^1Z^1-3.000000X^1Y^1Z^0+8.000000X^2Y^0Z^3-2.100000X^0Y^0Z^0";
    EXPECT_EQ(ans, EXans);
}

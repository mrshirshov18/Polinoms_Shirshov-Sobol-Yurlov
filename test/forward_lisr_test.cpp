#include "f_list.h"
#include <gtest.h>
TEST(f_list, correct_create){

    EXPECT_NO_THROW(f_list<int>a);
}
TEST(f_list, can_push_front){
    f_list<int>a;
    a.push_front(0);
    a.push_front(1);
    EXPECT_EQ(1, a.begin()->data);
}
TEST(f_list, can_pop_front){
    f_list<int>a;
    a.push_front(0);
    a.push_front(1);
    a.pop_front();
    EXPECT_EQ(0, a.begin()->data);
}
TEST(f_list, can_push_after)
{
    f_list<int>a;
    a.insert_after(a.begin(), 0);
    a.insert_after(a.begin(), 1);
    a.pop_front();
    EXPECT_EQ(1, a.begin()->data);
}
TEST(f_list, can_copy)
{
    f_list<int>a;
    f_list<int>b;
    a.push_front(0);
    a.push_front(1);
    a.push_front(2);
    b=a;
    EXPECT_EQ(true, a==b);
    
}
TEST(f_list, copied_list_has_own_memory)
{
    f_list<int>a;
    f_list<int>b;
    a.push_front(0);
    a.push_front(1);
    a.push_front(2);
    b=a;
    a.clear_all();
    EXPECT_EQ(2, b.begin()->data);
}

TEST(f_list, can_erase_after)
{
    f_list<int>a;
    a.push_front(0);a.push_front(1);
    a.erase_after(a.begin());
    EXPECT_EQ(a.begin()->data, 1);
}

TEST(f_list, correct_delete)
{
    f_list<int>a;a.push_front(3);
    a.push_front(4);
    a.delete_last(4);
    EXPECT_EQ(3, a.begin()->data);
}

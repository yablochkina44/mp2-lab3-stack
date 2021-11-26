#include "gtest.h"
#include "../mp2-lab3-stack/TStack.h"
TEST(TStack, can_create_stack_with_positive_size)
{
	ASSERT_NO_THROW(TStack<int> m(5));
}
TEST(TStack, cant_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStack<int> m(-5));
}
TEST(TStack, cant_push_in_stack)
{
	TStack<int> m(10);
	ASSERT_NO_THROW( m.Push(3));
}
TEST(TStack, cant_pop_from_empty_stack)
{
	TStack<int> m(1);
	ASSERT_ANY_THROW(m.Pop());
}
TEST(TStack, cant_push_in_full_stack)
{
	TStack<int> m(1);
	m.Push(1);
	ASSERT_ANY_THROW(m.Push(2));
}
TEST(TStack, can_copy_stack)
{
	TStack<int> m(10);
	ASSERT_NO_THROW(TStack <int> n(m));
}
TEST(TStack, can_see_top_of_stack)
{
	TStack<int> m(10);
	m.Push(5);
	EXPECT_EQ(m.Top(), 5);
}
#include "MyStack.h"

#include <gtest.h>

TEST(TStack, throws_when_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStack<int> s(-5));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> s(5);
	ASSERT_NO_THROW(TStack<int> s1(s));
}

TEST(TStack, can_get_size)
{
	TStack<int> s(5);
	EXPECT_EQ(5, s.GetSize());
}

TEST(TStack, can_get_top)
{
	TStack<int> s(5);
	EXPECT_EQ(0, s.GetTop());
}

TEST(TStack, can_push_element)
{
	TStack<int> s(5);
	ASSERT_NO_THROW(s.Push(1));
}

TEST(TStack, can_pop_element)
{
	TStack<int> s(5);
	s.Push(1);
	ASSERT_NO_THROW(s.Pop());
}

TEST(TStack, can_get_top_element)
{
	TStack<int> s(5);
	s.Push(1);
	ASSERT_NO_THROW(s.TopView());
}

TEST(TStack, can_check_is_empty)
{
	TStack<int> s(5);
	EXPECT_EQ(true, s.IsEmpty());
	
	s.Push(2);
	EXPECT_EQ(false, s.IsEmpty());
}

TEST(TStack, can_check_is_full)
{
	TStack<int> s(1);
	s.Push(2);
	EXPECT_EQ(true, s.IsFull());

	s.Pop();
	EXPECT_EQ(false, s.IsFull());
}

TEST(TStack, can_equate_stacks)
{
	TStack<int> s(1), s1(1);
	s.Push(1);
	ASSERT_NO_THROW(s = s1);
}

TEST(TStack, throws_when_push_into_full_stack)
{
	TStack<int> s(2);
	s.Push(1);
	s.Push(1);
	ASSERT_ANY_THROW(s.Push(1));
}

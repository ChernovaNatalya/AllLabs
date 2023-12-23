#include "MyQueue.h"

#include <gtest.h>

TEST(TQueue, throws_when_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> s(-5));
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> s(5);
	ASSERT_NO_THROW(TQueue<int> s1(s));
}

TEST(TQueue, can_get_size)
{
	TQueue<int> s(5);
	EXPECT_EQ(5, s.GetSize());
}

TEST(TQueue, can_get_end)
{
	TQueue<int> s(5);
	EXPECT_EQ(0, s.GetEnd());
}

TEST(TQueue, can_push_element)
{
	TQueue<int> s(5);
	ASSERT_NO_THROW(s.Push(1));
}

TEST(TQueue, can_pop_element)
{
	TQueue<int> s(5);
	s.Push(1);
	ASSERT_NO_THROW(s.Pop());
}

TEST(TQueue, can_check_is_empty)
{
	TQueue<int> s(5);
	EXPECT_EQ(true, s.IsEmpty());

	s.Push(2);
	EXPECT_EQ(false, s.IsEmpty());
}

TEST(TQueue, can_check_is_full)
{
	TQueue<int> s(1);
	s.Push(2);
	EXPECT_EQ(true, s.IsFull());

	s.Pop();
	EXPECT_EQ(false, s.IsFull());
}

TEST(TQueue, can_equate_queues)
{
	TQueue<int> s(1), s1(1);
	s.Push(1);
	ASSERT_NO_THROW(s = s1);
}

TEST(TQueue, can_compare_queues)
{
	TQueue<int> s(1), s1(1);
	s.Push(2);
	s1.Push(2);
	EXPECT_EQ(true, s == s1);
}

TEST(TQueue, throws_when_push_into_full_queue)
{
	TQueue<int> s(2);
	s.Push(1);
	s.Push(1);
	ASSERT_ANY_THROW(s.Push(1));
}

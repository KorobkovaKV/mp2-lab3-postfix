#include "stack.h"
#include <gtest.h>

using namespace std;
TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, cant_create_too_large_size_of_stack)
{
	ASSERT_ANY_THROW(TStack<int> st(MaxStackSize + 1));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, not_can_pop_if_stack_empty)
{
	TStack<int> STACK(3);							//������ ����
	ASSERT_ANY_THROW(STACK.POP_El());				//���� ����� ������� �� ������� �����
}

TEST(TStack, not_can_push_if_stack_full)
{
	TStack<int> STACK(3);
	for (int k = 0; k < 3; k++)			//��������� ����������
		STACK.PUSH_El(1);
	ASSERT_ANY_THROW(STACK.PUSH_El(4));
}

TEST(TStack, can_push_and_pop_element)
{
	TStack<int> STACK(4);							//������ ����
	STACK.PUSH_El(1);
	EXPECT_EQ(STACK.POP_El(), 1);						//���������, ��� ��� ������� ����� � �����
}

TEST(TStack, full_is_correct_1)
{
	TStack<int> STACK(4);						//������ ����
	EXPECT_EQ(STACK.Full(), false);						//���� ���� �� ��������, ������ false ����
}

TEST(TStack, full_is_correct_2)
{
	TStack<int> STACK(1);
	STACK.PUSH_El(5);
	EXPECT_EQ(STACK.Full(), true);						//���� ��������, ���� true
}

TEST(TStack, empty_is_correct_1)
{
	TStack<int> STACK(4);						//������ ����
	EXPECT_EQ(STACK.Empty(), true);						//���� ���� �� ��������, ������ true ����
}

TEST(TStack, empty_is_correct_2)
{
	TStack<int> STACK(1);
	STACK.PUSH_El(5);
	EXPECT_EQ(STACK.Empty(), false);						//���� ��������, ���� false
}







#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}

TEST(TPostfix, convert_infix_to_postfix)		//ďđĺîáđŕçîâŕíčĺ
{
	TPostfix v("a+b*c");
	v.ToPostfix();
	EXPECT_EQ(v.GetPostfix(), "bc*a+");
}

TEST(TPostfix, convert_equal_expression)			//đŕâĺíńňâî îäčíŕęîâűő âűđŕćĺíčé
{
	TPostfix v("(a+b*c)");
	v.ToPostfix();
	TPostfix n("a+b*c");
	n.ToPostfix();
	EXPECT_EQ(v.GetPostfix(), n.GetPostfix());
}

TEST(TPostfix, calculation_accuary)					//ęîđđĺęňíîńňü âű÷čńëĺíč˙
{
	TPostfix v("2+2*2");
	v.ToPostfix();
	EXPECT_EQ(v.Calculate(), 6);
}

TEST(TPostfix, convert_infix_with_brackets)		//ďđŕâčëüíŕ˙ îáđŕáîňęŕ âűđŕćĺíčé ńî ńęîáęŕěč
{
	TPostfix v("(a+b)*c+d");
	v.ToPostfix();
	EXPECT_EQ(v.GetPostfix(), "ab+c*d+");
}


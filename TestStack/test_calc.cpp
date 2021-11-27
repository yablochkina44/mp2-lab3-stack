#include "gtest.h"
#include "../mp2-lab3-stack/TCalculator.h"

TEST(TCalculator, can_create_calculator)
{
	ASSERT_NO_THROW(TCalculator m);
}
TEST(TCalculator, can_mult_)
{
	TCalculator m;
	m.SetExpression("10*2");
	EXPECT_EQ(m.Calc(), 20);
}
TEST(TCalculator, can_add)
{
	TCalculator m;
	m.SetExpression("2+10");
	EXPECT_EQ(m.Calc(), 12);
}
TEST(TCalculator, can_sub)
{
	TCalculator m;
	m.SetExpression("10-6");
	EXPECT_EQ(m.Calc(), 4);
}
TEST(TCalculator, can_div)
{
	TCalculator m;
	m.SetExpression("12/2");
	EXPECT_EQ(m.Calc(), 6);
}
TEST(TCalculator, can_calculate_expression_not_in_postfix)
{
	
	TCalculator m;
	m.SetExpression("(2+2)*2");
	EXPECT_EQ(m.Calc(), 8);
}
TEST(TCalculator, can_calculate_expression_in_postfix)
{
	
	TCalculator m;
	m.SetExpression("(2+2)*2");
	m.ToPostfix();
	EXPECT_EQ(m.CalcPostfix(), 8);
}
TEST(TCalculator, can_calculate_sin)
{

	TCalculator m;
	m.SetExpression("sin(0)+2");
	EXPECT_EQ(m.Calc(), 2);
}
TEST(TCalculator, can_calculate_cos)
{

	TCalculator m;
	m.SetExpression("cos(0)+2");
	EXPECT_EQ(m.Calc(), 3);
}
TEST(TCalculator, can_calculate_tan)
{

	TCalculator m;
	m.SetExpression("tg(0)+4");
	EXPECT_EQ(m.Calc(), 4);
}

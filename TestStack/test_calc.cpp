#include "gtest.h"
#include "../mp2-lab3-stack/TCalculator.h"

TEST(TCalculator, can_create_calculator)
{
	ASSERT_NO_THROW(TCalculator m);
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

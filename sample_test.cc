#include <gtest/gtest.h>

#include "sample.h"

class QueueTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // q0_ remains empty
        q1_.Enqueue(1);
        q2_.Enqueue(2);
        q2_.Enqueue(3);
    }

    // void TearDown() override {}

    Queue<int> q0_;
    Queue<int> q1_;
    Queue<int> q2_;
};

TEST_F(QueueTest, IsEmptyInitially)
{
    EXPECT_EQ(q0_.size(), 0);
}

TEST_F(QueueTest, DequeueWorks)
{
    int *n = q0_.Dequeue();
    EXPECT_EQ(n, nullptr);

    n = q1_.Dequeue();
    EXPECT_NE(n, nullptr);
    EXPECT_EQ(*n, 1);
    EXPECT_EQ(q1_.size(), 0);
    // delete n;

    n = q2_.Dequeue();
    ASSERT_NE(n, nullptr); // 失败就不往下执行
    EXPECT_EQ(*n, 2);      // 失败继续往下执行
    EXPECT_EQ(q2_.size(), 1);
    // delete n;

    std::cout << "执行结束......" << std::endl;
}

// Tests factorial of 0.
TEST(FactorialTest, HandlesZeroInput)
{
    EXPECT_EQ(Factorial(0), 1);
}

// Tests factorial of positive numbers.
TEST(FactorialTest, HandlesPositiveInput)
{
    EXPECT_EQ(Factorial(1), 1);
    EXPECT_EQ(Factorial(2), 2);
    EXPECT_EQ(Factorial(3), 6);
    EXPECT_EQ(Factorial(8), 40320);
}
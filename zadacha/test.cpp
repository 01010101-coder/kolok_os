// test.cpp
#include <gtest/gtest.h>
#include <stdexcept>
#include "factorial.h"
#include "reverse_list.h"

// Тесты для функции factorial
TEST(FactorialTest, PositiveNumbers) {
EXPECT_EQ(factorial(4), 24);  // 4! = 24
EXPECT_EQ(factorial(6), 720); // 6! = 720
EXPECT_EQ(factorial(7), 5040); // 7! = 5040
EXPECT_EQ(factorial(8), 40320); // 8! = 40320
}

TEST(FactorialTest, InvalidInput) {
EXPECT_THROW(factorial(-5), std::invalid_argument); // Проверка на отрицательное число
}

// Тесты для функции remove_duplicates
TEST(RemoveDuplicatesTest, BasicTest) {
std::vector<int> input = { 3, 4, 4, 2, 5, 5, 6 };
std::vector<int> result = remove_duplicates(input);
EXPECT_EQ(result.size(), 4); // Ожидается 4 уникальных элемента
EXPECT_EQ(result[0], 3);
EXPECT_EQ(result[1], 4);
EXPECT_EQ(result[2], 5);
EXPECT_EQ(result[3], 6);
}

// Тесты для функции reverse_list
TEST(ReverseListTest, BasicTest) {
Node* head = new Node(10);
head->next = new Node(20);
head->next->next = new Node(30);
head->next->next->next = new Node(40);

Node* reversed = reverse_list(head);

EXPECT_EQ(reversed->data, 40);
EXPECT_EQ(reversed->next->data, 30);
EXPECT_EQ(reversed->next->next->data, 20);
EXPECT_EQ(reversed->next->next->next->data, 10);
}

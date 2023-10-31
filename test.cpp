#include <iostream>
#include <vector>
#include "class_task.h"

// Макрос для проверки условия и вывода результата теста
#define TEST_CASE(condition, message)                         \
    if (condition) {                                          \
        std::cout << "[SUCCESS] - " << message << std::endl;  \
    } else {                                                  \
        std::cout << "[FAILED] - " << message << " in file "  \
                  << __FILE__ << " on line " << __LINE__     \
                  << std::endl;                                \
    }

int main() {
    // Тесты для функции Join
    std::vector<std::string> tokens1 = {"a", "b", "c"};
    std::string joined1 = Join(tokens1, ',');
    TEST_CASE(joined1 == "a,b,c", "Join: Test Case 1");

    std::vector<std::string> tokens2 = {"x", "y", "z"};
    std::string joined2 = Join(tokens2, '|');
    TEST_CASE(joined2 == "x|y|z", "Join: Test Case 2");

    // // Тесты для функции Split
    // std::string str1 = "Hello,World";
    // std::vector<std::string> split1 = Split(str1, ',');
    // TEST_CASE(split1 == std::vector<std::string>{"Hello", "World"}, "Split: Test Case 1");

    // std::string str2 = "1|2|3|4|5";
    // std::vector<std::string> split2 = Split(str2, '|');
    // TEST_CASE((split2 == std::vector<std::string>{"1", "2", "3", "4", "5"}), "Split: Test Case 2");

    return 0;
}

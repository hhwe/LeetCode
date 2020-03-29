#include "test.h"


TEST(test_generate_parenthesis, generateParenthesis001)
{
        cout << "1" << endl;
    int size = 1;
    string a[size] = {
        "()",
    };

    int n = 1;
    int returnSize;
    cout << "1" << endl;
    char **ret = generateParenthesis(n, &returnSize);
cout << "1" << endl;
    ASSERT_EQ(size, returnSize);
    for (int i = 0; i < size; i++)
    {
        ASSERT_EQ(a[i], ret[i]);
    }
}

TEST(test_generate_parenthesis, generateParenthesis002)
{
    int size = 2;
    string a[size] = {
        "(())",
        "()()",
    };

    int n = 2;
    int returnSize;
    char **ret = generateParenthesis(n, &returnSize);

    ASSERT_EQ(size, returnSize);
    for (int i = 0; i < size; i++)
    {
        ASSERT_EQ(a[i], ret[i]);
    }
}

TEST(test_generate_parenthesis, generateParenthesis003)
{
    int size = 5;
    string a[size] = {
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()",
    };

    int n = 5;
    int returnSize;
    char **ret = generateParenthesis(n, &returnSize);

    ASSERT_EQ(size, returnSize);
    for (int i = 0; i < size; i++)
    {
        ASSERT_EQ(a[i], ret[i]);
    }
}

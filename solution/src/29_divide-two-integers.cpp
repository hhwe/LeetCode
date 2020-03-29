/* 
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

 

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
解释: 7/-3 = truncate(-2.33333..) = -2
 

提示：

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include "solution.h"

#define INT_MAX 0X7FFFFFFF
#define INT_MIN 0X80000000

int divide(int dividend, int divisor)
{
    unsigned ret = 0;
    // Line 8: Char 9: runtime error: negation of -2147483648 cannot be represented in type 'int'; cast to an unsigned type to negate this value to itself (solution.c)
    // int a = abs(dividend);
    // int b = abs(divisor);
	if (dividend == INT_MIN && divisor == -1) {
		return INT_MAX;
	}
    unsigned a = dividend == INT_MIN ? INT_MIN : abs(dividend);
    unsigned b = divisor == INT_MIN ? INT_MIN : abs(divisor);

    while (a >= b)
    {
        long c = 1;
        long d = b;
        while (a > (d << 1))
        {
            c <<= 1;
            d <<= 1;
        }
        ret += c;
        a -= d;
    }
    if (ret == (unsigned)INT_MIN) {
        return INT_MIN;
    }
    return ((dividend ^ divisor) < 0) ? -(int)ret : (int)ret;
}
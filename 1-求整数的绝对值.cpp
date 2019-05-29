/***********************************************************************
*   Copyright (C) 2019  Yinheyi. <chinayinheyi@163.com>
*   
* This program is free software; you can redistribute it and/or modify it under the terms
* of the GNU General Public License as published by the Free Software Foundation; either 
* version 2 of the License, or (at your option) any later version.

*   Brief:    
*   Author: yinheyi
*   Email: chinayinheyi@163.com
*   Version: 1.0
*   Created Time: 2019年05月29日 星期三 21时54分53秒
*   Modifed Time: 2019年05月29日 星期三 22时58分10秒
*   Blog: http://www.cnblogs.com/yinheyi
*   Github: https://github.com/yinheyi
*   
***********************************************************************/
#include <iostream>

// 1.说明： 计算机中的整数都是采用补码的形式来保存的。
// 2.原码的含义：使用最高位表示符号位，剩余位表示值的大小。正整数的符号位为0, 负整数的符
// 号位为1. 例如对于8位的二进制数来说， 6可以表示为00000110, -6可以表示为10000110.
// 3.补码的含义：正整数的补码为原码本身， 负整数的补码为对应正整数的补码取反，然后加1.
// 例如：对于6的补码表示为00000110, 对于-6的补码表示为11111001+1=11111010.
// 4. 使用补码之后，可以简化计算机的加减运算，使用-6+2, 我们直接使用-6的补码加2的补码即
// 可。不需要考虑符号位。
//         11111010 
//      +  00000010
//      -------------
//         11111100    -----> 即正好是-4的补码形式。


int abs(int value_)
{
	// 符号位右移到最右边. 右移时，使用符号位补全 ,所以:
	// 于正整数的结果为00000000, 对于负整数的结果为11111111
	// 右移运行符的优先级低于加减运行符
	int mask = value_ >> sizeof(value_) * 8 - 1;

	// 当为正整数时，value 加上零之后还是value, value异或0之后还是value.
	// 当为负整数时，mask的所有位全为1,即mask的值等于-1, 相当于对value作减1操作，然后的
	// 结果对所有位全为1的mask执行异或操作相当于对结果执行了取反操作。
	// 按位异或的优先级低于加减运行符的优先级。
	return (value_ + mask) ^ mask;
}
/**********************    测试程序     *************************/
int main(int argc, char* argv[])
{

	int number1 = 0;
	std::cout << "0的绝对值为：" << abs(number1) << std::endl;

	int number2 = -1;
	std::cout << "-1的绝对值为：" << abs(number2) << std::endl;

	int number3 = -23432;
	std::cout << number3 << "的绝对值为：" << abs(number3) << std::endl;

	// 该边界会出错，因为最小的负整数的值对值没有办法表示.
	// 有符号整数的表示范围为：[-2^n ~ 2^n -1] 
	int number4 =  1 << sizeof(int)* 8 - 1;
	std::cout << number4 <<"的绝对值为：" << abs(number4) << std::endl;

	int number5 =  -1 ^ number4;
	std::cout << number5 <<"的绝对值为：" << abs(number5) << std::endl;
	return 0;
}


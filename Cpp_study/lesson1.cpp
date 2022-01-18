//http://c.biancheng.net/cpp/biancheng/view/2760.html

//名字空间的定义
//名字空间除了系统定义的名字空间之外，还可以自己定义，定义名字空间用关键字“namespace”，使用名字空间时用符号“::”指定。
//不指定名字空间的变量或函数都是当前名字空间下的变量或函数。
//不定义名字空间的情况下，都属于全局名字空间。
//同一个名字空间可以定义多次

// Cpp_study.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "lesson1.h"

using namespace std;

namespace na
{
	void print(int n) {     //与名字空间nb的函数名相同_test
		cout << "na::print: " << n << endl;
	}
}

namespace nb
{
	void print(int n) {     //与名字空间na的函数名相同
		cout << "nb::print: " << n << endl;
	}
}

namespace na  // 同一个名字空间可以定义多次
{
	void print2(int a, int b) {
		print(a);
		print(b);
	}
}

int lesson1()
{
	na::print(3);        // 指定na下的print函数
	nb::print(4);        // 指定na下的print函数
	na::print2(5, 6);    // 指定na下的print2函数
	cout << "WORI";
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

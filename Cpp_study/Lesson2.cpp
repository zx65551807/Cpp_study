// http://c.biancheng.net/cpp/biancheng/view/2761.html

#include <iostream>
using namespace std;


//在C++中参数可以设置缺省值，设置了缺省值之后，这个参数在调用时可以省略。
//
//注意：设置缺省值的参数只能是最后的几个参数。也就是说某一个参数一旦设置了缺省值，
//其后而的参数也必须设置缺省值。例如：f()函数有3个参数，如果只设置第2个有缺省值，这就错了。
//因为调用时只输入2个参数时，系统不知道究竟是第2个参数还是第3个参数。

int sum(int x = 0, int y = 100, int z = 0) { return x + y + z; }
//int sum(int x, int y=100, int z=0) { ... }   //这是正确的
//int sum(int x, int y, int z=0) { ... }       //这也是正确的
//int plus(int x, int y=100, int z) { ... }    //这是错误的

/* 函数的重载在C++中具有重要作用，重载(overload)不要和后面要学的覆盖(override)混淆起来。
重载是指相同的函数名，但参数的类型或个数中只要有所不同，便进行再定义，编译之后重载的函数都具有不同的地址，
也就是说虽然函数名相同，实际上是不同的函数，在调用时，编译系统会根据不同之处自动区别是调用哪一个函数。
对于普通函数和后面要学的类的成员函数都适用。
覆盖只对类的构造函数或成员函数适用，是子类继承父类是才使用的非常有用的功能。重载可以针对运算符，而覆盖不行。
上一节中缺省值的设置，实际上在编译时等价于重载，被生成了4个不同的函数。

早期的C++版本，在定义重载函数时要加上关键字overload，现在不用了。在使用重载函数时，
如果有类型的自动转换时要特别注意，初学者往往出错在这儿 */

float fun(float x);
double fun(double x);

float fun(float x)
{
	return x / 2.0;
}

double fun(double x)
{
	return x / 3.0;
}

int lesson2(void)
{
	cout << sum() << endl;
	cout << sum(6) << endl;
	cout << sum(6, 10) << endl;
	cout << sum(6, 10, 20) << endl;

	float f = 132.64;
	double d = 132.64;
	cout << "float f= 132.64, f/2" << fun(f) << endl;
	cout << fun(d) << endl;
	//cout << fun(5) << endl;    //编译错，参数5可以转换为float，也可转换为double


	return 0;
}


/* 
下面列举的重载函数是设计时就出了问题，两个函数本身就具有重复的意义。
#include <iostream>
using namespace std;

int fun(int a, int b);
int fun(int a, int &b);

int main()
{
	int x = 1, y = 2;
	cout << fun(x, y) << endl;    //这句编译时出错

	return 0;
}

int fun(int a, int b);
{
	return a + b;
}

int fun(int a, int& b);
{
	return a - b;
}
上面例子用到了int&，这叫“引用”
*/

void space(int count);
void space(int count, char ch);
int lesson2_2()
{
	//有一个整型参数的函数指针
	void(*fp1)(int);
	//有一个整型参数、一个字符型参数的函数指针
	void(*fp2)(int, char);
	fp1 = space;    //取space(int)函数的地址
	fp2 = space;    //取space(int, char)函数的地址
	fp1(20);        //输出20个空格
	cout << "|" << endl;
	fp2(20, '=');   //输出20个等号
	cout << "|" << endl;
	return 0;
}
//输出count个空格字符
void space(int count)
{
	for (; count; count--) cout << ' ';
}
//输出count个ch字符
void space(int count, char ch)
{
	for (; count; count--) cout << ch;
}
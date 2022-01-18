// http://c.biancheng.net/cpp/biancheng/view/2761.html

#include <iostream>
using namespace std;


//��C++�в�����������ȱʡֵ��������ȱʡֵ֮����������ڵ���ʱ����ʡ�ԡ�
//
//ע�⣺����ȱʡֵ�Ĳ���ֻ�������ļ���������Ҳ����˵ĳһ������һ��������ȱʡֵ��
//�����Ĳ���Ҳ��������ȱʡֵ�����磺f()������3�����������ֻ���õ�2����ȱʡֵ����ʹ��ˡ�
//��Ϊ����ʱֻ����2������ʱ��ϵͳ��֪�������ǵ�2���������ǵ�3��������

int sum(int x = 0, int y = 100, int z = 0) { return x + y + z; }
//int sum(int x, int y=100, int z=0) { ... }   //������ȷ��
//int sum(int x, int y, int z=0) { ... }       //��Ҳ����ȷ��
//int plus(int x, int y=100, int z) { ... }    //���Ǵ����

/* ������������C++�о�����Ҫ���ã�����(overload)��Ҫ�ͺ���Ҫѧ�ĸ���(override)����������
������ָ��ͬ�ĺ������������������ͻ������ֻҪ������ͬ��������ٶ��壬����֮�����صĺ��������в�ͬ�ĵ�ַ��
Ҳ����˵��Ȼ��������ͬ��ʵ�����ǲ�ͬ�ĺ������ڵ���ʱ������ϵͳ����ݲ�֮ͬ���Զ������ǵ�����һ��������
������ͨ�����ͺ���Ҫѧ����ĳ�Ա���������á�
����ֻ����Ĺ��캯�����Ա�������ã�������̳и����ǲ�ʹ�õķǳ����õĹ��ܡ����ؿ������������������ǲ��С�
��һ����ȱʡֵ�����ã�ʵ�����ڱ���ʱ�ȼ������أ���������4����ͬ�ĺ�����

���ڵ�C++�汾���ڶ������غ���ʱҪ���Ϲؼ���overload�����ڲ����ˡ���ʹ�����غ���ʱ��
��������͵��Զ�ת��ʱҪ�ر�ע�⣬��ѧ��������������� */

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
	//cout << fun(5) << endl;    //���������5����ת��Ϊfloat��Ҳ��ת��Ϊdouble


	return 0;
}


/* 
�����оٵ����غ��������ʱ�ͳ������⣬������������;����ظ������塣
#include <iostream>
using namespace std;

int fun(int a, int b);
int fun(int a, int &b);

int main()
{
	int x = 1, y = 2;
	cout << fun(x, y) << endl;    //������ʱ����

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
���������õ���int&����С����á�
*/

void space(int count);
void space(int count, char ch);
int lesson2_2()
{
	//��һ�����Ͳ����ĺ���ָ��
	void(*fp1)(int);
	//��һ�����Ͳ�����һ���ַ��Ͳ����ĺ���ָ��
	void(*fp2)(int, char);
	fp1 = space;    //ȡspace(int)�����ĵ�ַ
	fp2 = space;    //ȡspace(int, char)�����ĵ�ַ
	fp1(20);        //���20���ո�
	cout << "|" << endl;
	fp2(20, '=');   //���20���Ⱥ�
	cout << "|" << endl;
	return 0;
}
//���count���ո��ַ�
void space(int count)
{
	for (; count; count--) cout << ' ';
}
//���count��ch�ַ�
void space(int count, char ch)
{
	for (; count; count--) cout << ch;
}
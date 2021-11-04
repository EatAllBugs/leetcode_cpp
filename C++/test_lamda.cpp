// TestLambda.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void myPrintf(int elem)
{
	cout << elem << " ";
}

int main()
{
	cout << "-----------lambda表达式的使用----------" << endl;
	vector<int> tmpVector{};
	tmpVector.resize(10);
	int i = 10;
	int num = 0;
	cout << "-----------使用lambda表达给tmpVector赋值----------" << endl;
	generate(tmpVector.begin(), tmpVector.end(), [i,&num]() {
			num=i*i+num;
		return num;
	});
	cout << "-----------打印i和num的值，以查看值传递和引用传递的区别----------" << endl;
	cout << "i=" << i << "  num=" << num << endl;// i == 10 num == 100
	cout << "-----------打印tmpVector中的值----------" << endl;
	for_each(tmpVector.begin(), tmpVector.end(), myPrintf);
	cout << endl;

	cout << "-----------给lambda表达指定一个名字----------" << endl;
	int a = 100;
	auto bFun = [a]()->int {return a / 10; }; // bFun是lambda表达式的名字
	int c = bFun();
	cout << "c=" << c << endl;// c == 10

	cout << "-----------lambda表达传形参----------" << endl;
	int countIndex = count_if(tmpVector.begin(), tmpVector.end(), 
		[](int x) {
		return x / 1000 == 0; // 找到除以1000等于零的那个数在第几个，注意下标序号从0开始
	});
	cout << "除以1000等于零在vector中的索引为：countIndex=" << countIndex << endl;

	cout << "-----------lambda表达默认捕获外部变量,形参以值传递方式----------" << endl;
	int tmpNum1 = 10;
	int tmpNum2 = 5;
	for_each(tmpVector.begin(), tmpVector.end(), [=](int x) {
		
		x = x * tmpNum1 + tmpNum2;
		cout << "x=" << x << endl;
	});
	for_each(tmpVector.begin(), tmpVector.end(), myPrintf);
	cout << endl;
	cout << "-----------lambda表达默认捕获外部变量,形参以引用传递方式----------" << endl;
	for_each(tmpVector.begin(), tmpVector.end(), [=](int &x) {

		x = x * tmpNum1 + tmpNum2;
		cout << "x=" << x << endl;
	});
	for_each(tmpVector.begin(), tmpVector.end(), myPrintf);
	cout << endl;
    std::cout << "Hello World!\n";
	getchar();
}

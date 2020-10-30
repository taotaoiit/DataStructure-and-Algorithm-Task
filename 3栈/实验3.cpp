#include<iostream>
using namespace std;
#define MAXSIZE 100

//用类stack实现顺序表

class Stack
{
private:
	int* base;//栈底指针
	int* top;//栈顶指针
	int stacksize;//最大容量
public:
	void initStack();//初始化
	void push(int e);//入栈
	int pop();//出栈并返回栈顶元素
	int getTop();//返回栈顶元素
	void show();//打印栈内元素但会导致全部出栈
};
void Stack::initStack()
{
	base = new int[MAXSIZE];
	top = base;
	stacksize = MAXSIZE;
}
void Stack::push(int e)
{
	if (top - base == stacksize)
	{
		cout << "栈已满，操作失败。。" << endl;
		return;
	}
	*top = e;
	top++;
}
int Stack::pop()
{
	if (top == base)
	{
		cout << "栈为空，出栈失败。。" << endl;
		return -10000;//避免和0混淆
	}
	return *--top;
}
int Stack::getTop()
{
	if (top != base)
		return *(top - 1);
	else return 9999;
}
void Stack::show()
{
	while (top - base > 0)
		cout << pop() << ' ';
	cout << endl;
}

//递归函数，用来转换进制
void digui(int n,int b,Stack &S)
{
	if (n == 0);
	else 
	{
		int t;
		t = n % b;
		S.push(t);//对n求余的值t依次插入栈中
		digui(n / b, b, S);//递归调用
	}
}
//进制转换函数
void transBase()
{
	int n,b;
	Stack S;
	S.initStack();
	cout << "请输入待转换的10进制数：";
	cin >> n;
	cout << "请输入转换的进制：";
	cin >> b;
	digui(n, b, S);
	S.show();
}
//显示菜单
void showMenu()
{
	cout << "****************************操作菜单*********************************" << endl;
	cout << "*****************功能1：初始化顺序栈                *****************" << endl;
	cout << "*****************功能2：入栈                        *****************" << endl;
	cout << "*****************功能3：出栈并返回栈顶元素          *****************" << endl;
	cout << "*****************功能4：返回栈顶元素                *****************" << endl;
	cout << "*****************功能5：打印栈内元素但会导致全部出栈*****************" << endl;
	cout << "*****************功能6：进制转换                    *****************" << endl;
	cout << "*****************功能0：退出顺序栈结束程序          *****************" << endl;
	cout << "*********************************************************************" << endl;
}
int main()
{
	Stack S;
	char f;
	int Choice = 0;
	cout << "是否初始化顺序栈？(y/n)" << endl;//初始化顺序栈
	cin >> f;
	if (f == 'n')
		return 0;//若不初始化顺序栈程序结束。。
	S.initStack();
	cout << "初始化栈成功。。" << endl;
	while (true)
	{
		system("cls");//清屏
		showMenu();//显示菜单
		cout << "请选择功能：";
		while (true)
		{
			cin >> Choice;
			if (Choice >= 0 && Choice <= 6)
				break;
			else
				cout << "输入错误，请重新输入" << endl;
		}
		switch (Choice)
		{
		case 1://功能1：初始化顺序栈
			S.initStack();
			cout << "初始化顺序栈成功。。" << endl;
			system("pause");
			break;
		case 2://功能2：入栈
			int e2;
			cout << "输入待入栈元素：" << endl;
			cin >> e2;
			S.push(e2);
			system("pause");
			break;
		case 3://功能3：出栈并返回栈顶元素
			int e3;
			e3 = S.pop();
			if (e3!=-10000)
				cout << "出栈成功。。栈顶元素为：" << e3 << endl;
			system("pause");
			break;
		case 4://功能4：返回栈顶元素
			cout << "栈顶元素为：" << S.getTop() << endl;
			system("pause");
			break;
		case 5://功能5：//打印栈内元素但会导致全部出栈
			S.show();
			system("pause");
			break;
		case 6://功能6：//进制转换
			transBase();
			system("pause");
			break;
		case 0://功能6：退出系统
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	return 0;
}
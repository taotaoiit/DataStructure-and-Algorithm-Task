//循环队列，舞伴问题
#include<iostream>
#include<string>
using namespace std;
#define MAXSIZE 100

struct Person
{
	string name;
	char sex;
};
Person newPerson(string name, char sex)
{
	Person P;
	P.name = name;
	P.sex = sex;
	return P;

}

class Queue
{
private:
	Person* base;//队列初始地址
	int front;//类似于头指针
	int rear;//类似于尾指针
public:
	void InitQueue();//初始化顺序队列
	int QueueLen();//返回队列长度
	void EnQueue(Person e);//入队
	Person DeQueue();//出队
	Person GetHead();//取头元素
	void ShowQueue();//显示队列元素
};
void Queue::InitQueue()//初始化队列，将尾指针与头指针归0，注：此指针非彼指针
{
	base = new Person[MAXSIZE];
	front = rear = 0;
}
int Queue::QueueLen()//返回队列长度
{
	return((rear - front + MAXSIZE) % MAXSIZE);
}
void Queue::EnQueue(Person e)//入队，尾指针前进
{
	if ((rear + 1) % MAXSIZE == front)//判断是否队满
	{
		cout << "队满。。。。操作失败" << endl;
	}
	*(base + rear) = e;//填充rear“指针指向”的空间
	rear = (rear + 1) % MAXSIZE;//前进！！
}
Person Queue::DeQueue()//出队，头指针进一
{
	if (rear == front)//判断是否队空
	{
		cout << "队空！操作失败。。。" << endl;
	}
	Person e;
	e = *(base + front);//保存对头元素
	front = (front + 1) % MAXSIZE;//头指针前进！！
	return e;//返回保存的元素值
}
Person Queue::GetHead()//仅返回对头元素
{
	if (rear == front)
	{
		cout << "队空！操作失败。。。" << endl;
	}
	return *(base + front);

}

//功能2函数
void EnPerson(Queue& Q)//导入人员
{
	string name;
	char sex;
	char f;
	while (true)//构造循环，可以一直导入
	{
		cout << "是否导入成员？（y/n）" << endl;
		cin >> f;
		if (f == 'n')
			break;
		cout << "请输入姓名+空格+性别(m/f)：";//m是男人，f是女人
		cin >> name;
		cin >> sex;
		Person P = newPerson(name, sex);
		Q.EnQueue(P);
	}
	cout << "已输入" << Q.QueueLen() << "个人" << endl;
}

//功能3函数
void DePerson(Queue& Q, Queue& Qm, Queue& Qf)//从队列中导出成员，并根据性别保存到对应队列
{
	int n = Q.QueueLen();
	while (n)
	{
		n--;
		Person P;
		P = Q.DeQueue();
		if (P.sex == 'm')//男的
			Qm.EnQueue(P);//保存到男性队列
		else if (P.sex == 'f')//女的
			Qf.EnQueue(P);//保存到女性队列
		else
			cout << "性别有误，删除此人。。" << endl;
	}
	cout << "已全部出队，并将出队的成员根据性别保存到对应的队。。。" << endl;
}

//功能4函数
void PaPerson(Queue& Qm, Queue& Qf)
{
	int L;
	Qm.QueueLen() < Qf.QueueLen() ? L = Qm.QueueLen() : L = Qf.QueueLen();//取男女队列中最小的队列长度
	while (L)//配对
	{
		Person Pm, Pf;//Pm是男人中间变量，Pf是女人中间变量
		Pm = Qm.DeQueue();
		Pf = Qf.DeQueue();
		cout << Pm.name << "与" << Pf.name << "配对成功" << endl;
		L--;
	}
	if (Qm.QueueLen() < Qf.QueueLen())//如果男生的人数比女生少
	{
		Person P;
		P = Qf.GetHead();//返回队头女生
		cout << P.name << "未配对" << endl;
	}
	else if (Qm.QueueLen() > Qf.QueueLen())//如果男生人数比女生多
	{
		Person P;
		P = Qm.GetHead();//返回队头男生
		cout << P.name << "未配对" << endl;
	}
	else
		cout << "全部配对！" << endl;
}

//显示菜单界面
void showMenu()
{
	cout << "****************************操作菜单*********************************" << endl;
	cout << "*****************功能1：初始化循环队列              *****************" << endl;
	cout << "*****************功能2：导入全部人                  *****************" << endl;
	cout << "*****************功能3：出队并根据性别保存到对应队  *****************" << endl;
	cout << "*****************功能4：男女配对返回配对列表及第一个未配对人姓名*****" << endl;
	cout << "*****************功能0：退出并结束程序              *****************" << endl;
	cout << "*************************———————******************************" << endl;
	cout << "************************* 1901103班2组 ******************************" << endl;
	cout << "*************************———————******************************" << endl;
}
int main()
{
	Queue Q,Qm,Qf;//创建一个队列对象
	int Choice = 0;
	Q.InitQueue();
	Qm.InitQueue();
	Qf.InitQueue();
	cout << "初始化循环队列成功。。。。" << endl;
	while (true)
	{
		system("cls");//清屏
		showMenu();//显示菜单
		cout << "请选择功能：";
		while (true)
		{
			cin >> Choice;
			if (Choice >= 0 && Choice <= 4)
				break;
			else
				cout << "输入错误，请重新输入" << endl;
		}
		switch (Choice)
		{
		case 1://功能1：初始化循环队列
			Q.InitQueue();
			cout << "初始化顺序栈成功。。" << endl;
			system("pause");
			break;
		case 2://功能2：导入全部人
			EnPerson(Q);
			system("pause");
			break;
		case 3://功能3：出队并根据性别保存到对应队
			DePerson(Q, Qm, Qf);
			system("pause");
			break;
		case 4://功能4：男女配对返回配对列表及第一个未配对人姓名
			PaPerson(Qm, Qf);
			system("pause");
			break;
		case 0://功能5：退出系统
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	return 0;
}
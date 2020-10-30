#include<iostream>
using namespace std;
#include<string>
struct List
{
	List* next;
	string name;
};
//所有的操作函数如下：
/*
void createList_front(Lis*& L,int n)//用前插法建立有头节点的链表，并初始化n个元素
void createList_back(List*& L, int n)//用后插法建立有头节点的链表，并初始化n个元素
void createList(List*& L)//将前插法与后插法合并，创建链表
string getElem(List*& L, int n)//得到第n个位置上的元素值
void locateElem(List*& L,string e)//查找出链表中所有元素值为e的元素位置
void insertElem(List*& L, int i, string e)//在链表的第i个位置插入新元素，值为e
void showList(List*& L)//显示当前链表
void deleteElem(List*& L,int n)//删除第n个位置上的元素
void showMenu()//菜单
*/
void createList_front(List*& L,int n)//用前插法建立有头节点的链表
{
	L = new List;
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		List* p = new List;
		cin >> p->name;
		p->next = L->next;
		L->next = p;
	}
	cout << "初始化成功。。。" << endl;
}
void createList_back(List*& L, int n)//用后插法建立有头节点的链表
{
	L = new List;
	List* R = new List;
	L->next = NULL;
	R= L;
	for (int i = 0; i < n; i++)
	{
		List* p = new List;
		cin >> p->name;
		R->next = p;
		p->next = NULL;
		R = p;
	}
	cout << "初始化成功。。。" << endl;
}
void createList(List*& L)//将前插法与后插法合并，创建链表
{
	char j,k;
	cout << "是否创建链表？y/n" << endl;
	cin >> j;
	if (j == 'y')
	{
		int n;
		cout << "请选择创建链表的方法：（前插法输入f，后插法输入b）" << endl;
		cin >> k;
		if (k == 'f')
		{
			cout << "请输入创建链表时，想要初始化的元素个数：" << endl;
			cin >> n;
			cout << "请输入元素：" << endl;
			createList_front(L, n);
		}
		else if (k == 'b')
		{
			cout << "请输入创建链表时，想要初始化的元素个数：" << endl;
			cin >> n;
			cout << "请输入元素：" << endl;
			createList_back(L, n);
		}
	}
	else
	{
		cout << "程序退出。" << endl;
	}
}
string getElem(List*& L, int n)
{
	List* p = new List;
	int i;
	p = L;
	for (i = 0; i < n; i++)
	{
		p = p->next;
	}
	if (!p || i > n)
	{
		cout << "运行错误" << endl;
		return "error_opreate";
	}
	cout << "第" << n << "个位置的元素为：" << p->name << endl;
	return p->name;
}
void locateElem(List*& L,string e)
{
	List* p = new List;
	p = L->next;
	int num=1;
	while (p)
	{
		if (p->name == e)
		{
			cout << "第" << num << "个位置上的元素值等于" << e << "，地址值为：" << p << endl;;
		}
		num++;
		p = p->next;
	}
}
void insertElem(List*& L, int i, string e)
{
	List* p = L;
	int j = 0;
	while (p && (j < i - 1))
	{
		p = p->next; 
		j++;
	}
	if (!p || j > i - 1)
	{
		cout << "错误！" << endl;
		return;
	}
	List* s = new List;
	s->name = e;
	s->next = p->next;
	p->next = s;
}
void showList(List*& L)//显示当前链表
{
	List* p = new List;
	p = L->next;
	cout << "当前链表中元素为：";
	while (p)
	{
		cout << p->name << "  ";
		p = p->next;
	}
	cout << endl;
}
void deleteElem(List*& L,int n)
{
	List* p = new List;
	p = L;
	for (int i = 0; i < n-1; i++)
	{
		p = p->next;
		if (!p) 
		{
			cout << "error_operate"<<endl;
			return;
		}
	}
	if (!p->next)
	{
		cout << "error_operate"<<endl;
		return;
	}
	List* q = new List;
	q = p->next;
	p->next = q->next;
	cout << "successfully deleted" << endl;
	delete q;
}
void showMenu()
{
	cout << "**********************操作菜单***************************" << endl;
	cout << "*****************功能1：创建链表并初始化*****************" << endl;
	cout << "*****************功能2：提取某位置元素值*****************" << endl;
	cout << "*****************功能3：查找某元素值位置*****************" << endl;
	cout << "*****************功能4：插入元素到某位置*****************" << endl;
	cout << "*****************功能5：删除某个位置元素*****************" << endl;
	cout << "*****************功能0：退出链表结束程序*****************" << endl;
	cout << "*********************************************************" << endl;
}
int main()
{
	List* L;
	int a, b, c;
	string e,g;
	///////////////////////////////
	int Choice = 0;
	bool flag=false;
	while (true)
	{
		system("cls");
		showMenu();
		if(flag==true)
			showList(L);
		cout << "请选择功能：" << endl;
		while (true)
		{
			cin >> Choice;
			if (Choice >= 0 && Choice <= 5)
			{
				break;
			}
			else
			{
				cout << "输入错误，程序退出" << endl;
				Choice = 0;
				return 0;
			}
		}
		switch (Choice)
		{
		case 1://功能1：创建链表并初始化
			createList(L);
			showList(L);
			flag = true;
			system("pause");
			break;
		case 2://功能2：得到某位置上的元素值
			cout << "输入位置：" << endl;
			cin >> a;
			getElem(L, a);
			system("pause");
			break;
		case 3://功能3：查找某元素值在链表中位置
			cout << "输入待查找元素值：" << endl;
			cin >> e;
			locateElem(L, e);
			system("pause");
			break;
		case 4://功能4：在链表某位置插入元素
			cout << "请输入插入元素的位置：" << endl;
			cin >> b;
			cout << "请输入插入元素的值：" << endl;
			cin >> g;
			insertElem(L, b, g);
			showList(L);
			system("pause");
			break;
		case 5://功能5：删除链表中某位置元素
			cout << "请输入删除的位置：" << endl;
			cin >> c;
			deleteElem(L, c);
			showList(L);
			system("pause");
			break;
		case 0://功能6：退出系统
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;


}
#include <iostream>
using namespace std;
#define maxSize 100
class SeqList 
{
private:
	char* p;
	int last;
public:
	
	void InitList();
	void DestroyList();
	void ListInsert(int i, char e);
	void ListDelete(int i);
	void printdata();
	void import_data(const char* t);
	void search_elem(char e);
};
void SeqList::InitList()
{
	p = new char[maxSize];
	last = 0;
}
void SeqList::DestroyList()
{
	last = 0;
	delete []p;
}
void SeqList::ListInsert(int i, char e)
{
	if (last>= maxSize)
	{
		cout << "储存空间已满！" << endl;
		return ;
	}
	if (i > last + 1)
	{
		cout << "该顺序表仅有" << last << "个元素，插入位置错误！" << endl;
		return;
	}
	if (last == 0)
	{
		*p = e;
		last++;
		return;
	}
	if (i==last+1)
	{
		*(p + last) = e;
		last++;
		return;
	}
	for (int n = last - 1; n >= i - 1; n--)
	{
		*(p + n + 1) = *(p + n);
	}
	*(p + i - 1) = e;
	last++;
}
void SeqList::ListDelete(int i)
{
	if (last == 0)
	{
		cout << "表中无数据用来删除" << endl;
		return;
	}
	if (i > last)
	{
		cout << "该顺序表仅有" << last << "个元素，操作错误！" << endl;
		return;
	}
	for (int n = i - 1; n <= last - 2; n++)
	{
		*(p + n) = *(p + n + 1);
	}
	last--;
}
void SeqList::printdata()
{
	cout << "此时顺序表中的元素为：" << endl;
	for (int i = 0; i < last ; i++)
		cout << *(p + i) << " ";
	cout << endl;
}
void SeqList::import_data(const char* t)
{
	if (strlen(t) +last> maxSize)
	{
		cout << "导入的字符串过长！" << endl;
		return;
	}
	for (int i = last; i < strlen(t); i++)
	{
		ListInsert(i + 1, *(t + i));
	}
}
void SeqList::search_elem(char e)
{
	bool flag = false;
	for (int i = 0; i < last; i++)
	{
		if (*(p + i) == e)
		{
			cout << "第" << i + 1 << "个元素的值等于" << e << endl;
			flag = true;
		}
	}
	if (flag == false)
		cout << "顺序表中无等于" << e << "的元素" << endl;
}
int main()
{
	SeqList L;
	const char* t = "hello_data_structure";
	cout << "产生顺序表：" << endl;
	L.InitList();
	cout << "导入元素:" << endl;
	L.import_data(t);
	L.printdata();
	cout << "在位置1插入字符1：" << endl;
	L.ListInsert(1, '1');
	L.printdata();
	cout << "在位置3插入字符3：" << endl;
	L.ListInsert(3, '3');
	L.printdata();
	cout << "在位置5插入字符5：" << endl;
	L.ListInsert(5, '5');
	L.printdata();
	cout << "在位置8插入字符8：" << endl;
	L.ListInsert(8, '8');
	L.printdata();
	cout << "删除位置8元素：" << endl;
	L.ListDelete(8);
	L.printdata();
	cout << "删除位置5元素：" << endl;
	L.ListDelete(5);
	L.printdata();
	cout << "删除位置3元素：" << endl;
	L.ListDelete(3);
	L.printdata();
	cout << "删除位置1元素：" << endl;
	L.ListDelete(1);
	L.printdata();
	cout << "查找元素:" << endl;
	L.search_elem('a');
	L.search_elem('b');
	cout << "成功删除顺序表！" << endl;
	L.DestroyList();
	return 0;

}

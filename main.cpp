#include<iostream>
using namespace std;

struct Book {
	string id;
	string name;
	double price;
	string author;
};

typedef struct LNode {
	Book date;
	struct LNode* next;
}; LNode;
typedef LNode* LinkList;

bool InitList(LinkList& L)
{
	L = new LNode;  // 分配头节点的内存空间
	L->next = NULL;  // 初始时，指针域为 NULL
	return true;
}

bool InsertBook(Book& b, LinkList& L, int i)  //在链表的第i个节点插入数据
{
	LinkList p = L;
	int j = 0;
	while (p->next && (j < i-1))
	{
		p = p->next;
		++j;
	}
	if (!p || j > i-1)
		return false;
	LinkList s = new LNode;
	s->date = b;
	s->next = p->next;
	p->next = s;
	return true;
}

bool DeleteBookId(LinkList& L, string id)       //删除Id为id的图书
{
	LinkList p = L;
	while (p->next && id != p->next->date.id)
	{
		p = p->next;
	}
	if (!p->next || id != p->next->date.id)
		return false;
	LinkList q = p->next;
	p->next = q->next;
	delete q;
	return true;
}

bool DeleteBookName(LinkList& L, string name)       //删除书名为name的书
{
	LinkList p = L;
	while (p->next && name != p->next->date.name)
	{
		p = p->next;
	}
	if (!p->next || name != p->next->date.name)
		return false;
	LinkList q = p->next;
	p->next = q->next;
	delete q;
	return true;
}


bool FindBookId(LinkList& L, string id)                       //查找书号为id的书
{
	LinkList p = L;
	while (p->next && id!=p->date.id)
	{
		p = p->next;
	}
	if (id != p->date.id)
	{
		cout << "查无此书！" << endl;
		return false;
	}
	else
	{
		cout << "查找成功！" << endl;
		cout << "此书的"<<"id:" << p->date.id << " 书名: " << p->date.name << " 作者: " << p->date.author << " 售价: " << p->date.price << endl;
		return true;
	}
}

bool FindBookName(LinkList& L, string name)                       //查找书名为name的书
{
	LinkList p = L;
	while (p->next && name != p->date.name)
	{
		p = p->next;
	}
	if (name != p->date.name)
	{
		cout << "查无此书！" << endl;
		return false;
	}
	else
	{
		cout << "查找成功！" << endl;
		cout << "此书的" << "id:" << p->date.id << " 书名 : " << p->date.name << " 作者" << p->date.author << " 售价 : " << p->date.price << endl;
		return true;
	}
}

bool UpdateBookId(LinkList& L, string id, double new_price)  //修改书号为id的图书价格为new_price
{
	LinkList p = L;
	while (p->next && id != p->date.id)
	{
		p = p->next;
	}
	if (id != p->date.id)
	{
		cout << "查无此书！" << endl;
		return false;
	}
	else
	{
		p->date.price = new_price;
		cout << "Id为"<<id<<"的书价格修改成功！" << endl;
		return true;
	}
}

int CountBook(LinkList& L)//统计图书数量
{
	LinkList p = L;
	int j = 0;  
	while (p->next != NULL)  
	{
		++j;
		p = p->next;
	}
	cout <<"当前图书总数：" << j << endl;
	return j;
}

bool DeleteList(LinkList& L)  //销毁链表
{
	LinkList p = L;
	while (L != NULL)
	{
		p = L;
		L = L->next;
		delete p;
	}
	return true;
}

void PrintList(LinkList& L)  //打印链表
{
	if (L)
	{
		LinkList p = L->next;  
		while (p != NULL) {
			cout << "id:" << p->date.id << " 书名:" << p->date.name << " 作者: " << p->date.author << " 售价:" << p->date.price << endl;
			p = p->next;  
		}
	}
}


int main()
{
	Book book1;
	book1.author = "auther_one";
	book1.id = "001";  
	book1.name = "book1";  
	book1.price = 23.5;

	Book book2;
	book2.author = "auther_two";
	book2.id = "002";  
	book2.name = "book2";  
	book2.price = 46.8;

	Book book3;
	book3.author = "auther_three";
	book3.id = "003";  
	book3.name = "book3";  
	book3.price = 38.4;

	LinkList L;

	InitList(L);
	
	InsertBook(book1, L, 1);
	InsertBook(book2, L, 2);
	InsertBook(book3, L, 3);
	cout << "------------------------------After InsertBook,PrintList and CountBook-----------------------------------" << endl;
	CountBook(L);
	PrintList(L);
	cout << endl << "------------------------------After FindBookId-----------------------------------" << endl;
	FindBookId(L, "002");
	cout <<endl<< "------------------------------After DeleteBookId,PrintList and CountBook---------------------------------" << endl;
	DeleteBookId(L, "002");
	CountBook(L);
	PrintList(L);
	cout << endl << "------------------------------After DeleteBookName,PrintList and CountBook--------------------------------" << endl;
	DeleteBookName(L, "book3");
	CountBook(L);
	PrintList(L);
	cout << endl << "------------------------------After UpdateBookId,PrintList-----------------------------------" << endl;
	UpdateBookId(L, "001",3.9);
	PrintList(L);
	cout << endl << "------------------------------After DeleteList,PrintList-----------------------------------" << endl;
	DeleteList(L);
	PrintList(L);
	return 0;
}
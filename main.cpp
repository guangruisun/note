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
	L = new LNode;  // ����ͷ�ڵ���ڴ�ռ�
	L->next = NULL;  // ��ʼʱ��ָ����Ϊ NULL
	return true;
}

bool InsertBook(Book& b, LinkList& L, int i)  //������ĵ�i���ڵ��������
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

bool DeleteBookId(LinkList& L, string id)       //ɾ��IdΪid��ͼ��
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

bool DeleteBookName(LinkList& L, string name)       //ɾ������Ϊname����
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


bool FindBookId(LinkList& L, string id)                       //�������Ϊid����
{
	LinkList p = L;
	while (p->next && id!=p->date.id)
	{
		p = p->next;
	}
	if (id != p->date.id)
	{
		cout << "���޴��飡" << endl;
		return false;
	}
	else
	{
		cout << "���ҳɹ���" << endl;
		cout << "�����"<<"id:" << p->date.id << " ����: " << p->date.name << " ����: " << p->date.author << " �ۼ�: " << p->date.price << endl;
		return true;
	}
}

bool FindBookName(LinkList& L, string name)                       //��������Ϊname����
{
	LinkList p = L;
	while (p->next && name != p->date.name)
	{
		p = p->next;
	}
	if (name != p->date.name)
	{
		cout << "���޴��飡" << endl;
		return false;
	}
	else
	{
		cout << "���ҳɹ���" << endl;
		cout << "�����" << "id:" << p->date.id << " ���� : " << p->date.name << " ����" << p->date.author << " �ۼ� : " << p->date.price << endl;
		return true;
	}
}

bool UpdateBookId(LinkList& L, string id, double new_price)  //�޸����Ϊid��ͼ��۸�Ϊnew_price
{
	LinkList p = L;
	while (p->next && id != p->date.id)
	{
		p = p->next;
	}
	if (id != p->date.id)
	{
		cout << "���޴��飡" << endl;
		return false;
	}
	else
	{
		p->date.price = new_price;
		cout << "IdΪ"<<id<<"����۸��޸ĳɹ���" << endl;
		return true;
	}
}

int CountBook(LinkList& L)//ͳ��ͼ������
{
	LinkList p = L;
	int j = 0;  
	while (p->next != NULL)  
	{
		++j;
		p = p->next;
	}
	cout <<"��ǰͼ��������" << j << endl;
	return j;
}

bool DeleteList(LinkList& L)  //��������
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

void PrintList(LinkList& L)  //��ӡ����
{
	if (L)
	{
		LinkList p = L->next;  
		while (p != NULL) {
			cout << "id:" << p->date.id << " ����:" << p->date.name << " ����: " << p->date.author << " �ۼ�:" << p->date.price << endl;
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
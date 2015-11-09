#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;//调用字符串类
class book
{
public:
	int num;
	float price;
	book *next;
};
book *head = NULL;
//通过字符串类，判断用户输入内容
bool check(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] > '9' || str[i] < '0')&&(str[i]!='.'))
		{
			return false;
		}
		return true;
	}
	
}
book * creat()
{
	book *currentp, *newp;
	newp = new book;
	head = newp;
	currentp = newp;
	cout << "enter the sieral No. [0] means quit." << endl;
	//在此对用户输入做判断
	//cin >> newp->num;
	string str;
	cin >> str;
	while (!check(str))
	{
		cout << "pls enter the No. from 0 to 9. re-enter again." << endl;
		cin >> str;
	}
	newp->num = atoi(str.c_str());
	if (newp->num != 0)
	{
		cout << "enter the price." << endl;
		//在此对用户输入做判断
		//cin >> newp->price;
		cin >> str;
		while (!check(str))
		{
			cout << "pls enter the No. from 0 to 9. re-enter again." << endl;
			cin >> str;
		}
		newp->price = atof(str.c_str());
	}
	else
	{
		delete newp; 
		newp = NULL; 
		currentp = NULL; 
		currentp->next = NULL; 
		head = NULL;
		return head;
	}
	while (newp->num!=0)
	{
		currentp = newp;
		newp = new book;
		cout << "enter the sieral No. [0] means quit." << endl;
		//cin >> newp->num;
		cin >> str;
		while (!check(str))
		{
			cout << "pls enter the No. from 0 to 9. re-enter again." << endl;
			cin >> str;
		}
		newp->num = atoi(str.c_str());
		if (newp->num != 0)
		{
			cout << "enter the price." << endl;
			//cin >> newp->price;
			cin >> str;
			while (!check(str))
			{
				cout << "pls enter the No. from 0 to 9. re-enter again." << endl;
				cin >> str;
			}
			newp->price = atof(str.c_str());
		}
		currentp->next = newp;
	}
	delete newp;
	currentp->next = NULL;
	return head;
}
void showout(book *head)
{
	cout << endl;
	cout << "the information is:\n";
	while (head)
	{
		cout << "serial No.:" << head->num << "\t";
		cout << "price: " << head->price << endl;
		head = head->next;
	}
}
//加入删除功能
void DeleteNode(book *head, int count)
{
	book *temp;
	if (count == head->num)
	{
		temp = head;
		head = head->next;
		::head = head;
		delete temp;
		cout << "delete compelet.\n";
		return;
	}
	while (head)
	{
		if (head->next == NULL)//判断下一个节点是否存在
		{
			cout << "aim node is not exist.\n";
			return;
		}
		if (head->next->num == count)//下一个节点若等于目标
		{
			temp = head->next;
			head->next = temp->next;
			delete temp;
			cout << "delete complete.\n";
			return;
		}
		head = head->next;
	}
	cout << "aim is not exist.\n";
}
//以下为尾插法
void InsertNodeLast(book *head, int count, float price)
{
	book *list = new book;//创建一个新节点
	book*temp=NULL;//保存访问过的节点的地址
	while (head)
	{
		temp = head;//头节点赋值给临时变量
		head = head->next;//下一个节点的地址赋值给head
	}
	//循环结束后，既是链表的末尾
	temp->next=list;
	list->num = count;
	list->price = price;
	list->next = NULL;
}
//以下为头插法
void InsertNodeHead(book *head, int count, float price)
{
	book *list = new book;
	list->num = count;
	list->price = price;
	list->next = head;
	::head = list;
}
void main()
{
	//book *head = NULL;
	int bookcount;
	float bookprice;
	head = creat();
	showout(head);
	cout << "pls enter the delete no.:";
	cin >> bookcount;
	DeleteNode(head, bookcount);
	showout(head);
	cout << "pls enter the new record's serial No.:";
	cin >> bookcount;
	cout << "enter the price: ";
	cin >> bookprice;
	InsertNodeLast(head, bookcount, bookprice);
	showout(head);
	cout << "this record will be insert at 1st line.\n";
	cout << "pls enter the new record's serial No.:";
	cin >> bookcount;
	cout << "enter the price: ";
	cin >> bookprice;
	InsertNodeHead(head, bookcount, bookprice);
	showout(head);
}
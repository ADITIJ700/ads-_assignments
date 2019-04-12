#include <iostream>
#define n 10
using namespace std;
class node
{
	public:
    string name,type,scope;
    int lineno;
    node* next;
    node(){
    	next=NULL;
    	name=type=scope="0";
    	lineno=0;
    }
    friend class symbol;
};
class symbol
{
public:
	void init();
	node *a[n];
	void insert();
	void display();
	void search();
	void deleten();
	void modify();
	int hashing(string);
};
void symbol::init()
{
	for(int i=0;i<n;i++)
		a[i]=NULL;
}
void symbol::insert()
{
	node* p;
	p=new node;
	cout<<"Enter name\n";
	cin>>p->name;
	cout<<"Enter type\n";
	cin>>p->type;
	cout<<"Enter scope\n";
	cin>>p->scope;
	cout<<"Enter line no\n";
	cin>>p->lineno;
	int c=hashing(p->name);
	if(a[c]==NULL)
	{
		a[c]=p;
	}
	else
	{
		node* temp= a[c];
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=p;
	}
}
void symbol::display()
{
	for(int i=0;i<n;i++)
	{
		if(a[i]!=NULL)
		{
			cout<<i<<"   ";
			node* temp= a[i];
			while(temp)
			{
				cout<<temp->name<<"   ";
				temp=temp->next;
			}
			cout<<endl;
		}
	}
}
void symbol::modify()
{
	string p;
	cout<<"Enter name to search\n";
	cin>>p;
	int c=hashing(p);
	node* t=a[c];
	while(t)
	{
		if(t->name == p)
		{
			cout<<"Found at "<<c<<"\n";
			cout<<"Enter type\n";
			cin>>t->type;
			cout<<"Enter scope\n";
			cin>>t->scope;
			cout<<"Enter line no\n";
			cin>>t->lineno;
			return;
		}
		t=t->next;
	}
	if(t==NULL)
		cout<<"Not Found\n";
}
void symbol::search()
{
	string p;
	cout<<"Enter name to search\n";
	cin>>p;
	int c=hashing(p);
	node* t=a[c];
	while(t)
	{
		if(t->name == p)
		{
			cout<<"Found at "<<c<<"\n";
			cout<<"Identifier -> "<<t->name<<endl;
			cout<<"Type -> "<<t->type<<endl;
			cout<<"Scope -> "<<t->scope<<endl;
			cout<<"Line no. -> "<<t->lineno<<endl;
			return;
		}
		t=t->next;
	}
	if(t==NULL)
		cout<<"Not Found\n";
}
void symbol::deleten()
{
	string p;
		cout<<"Enter name to delete\n";
		cin>>p;
		int c=hashing(p);
		node* t=a[c];
		node* q=NULL;
		if(t==NULL)
		{
			cout<<"Not Found\n";
			return;
		}
		if(t->name==p && t->next==NULL)
		{
			delete t;
			a[c]=NULL;
			cout<<"Deleted!!!\n";
			return;
		}
		while(t!=NULL)
		{
			if(t->name == p)
			{
				q->next=t->next;
				delete t;
				cout<<"Deleted!!!\n";
				return;
			}
			q=t;
			t=t->next;
		}
		if(t==NULL)
		{
			cout<<"Not Found\n";
			return;
		}
}
int symbol::hashing(string ch)
{
	int x,l;
		x=0;

		l = ch.length();
		for(int i=0;i<l;i++)
		{
			x=x+int(ch[i]);
		}
		x=x%10;

		return x;
}
int main()
{
	symbol h;
	h.init();
	int c;
	do
		{
			cout<<"1.Input\n2.Display\n3.Search\n4.Delete\n5.Modify\n";
			cin>>c;
			switch(c)
			{
			case 1:
				h.insert();
			break;
			case 2:
				h.display();
			break;
			case 3:
				h.search();
				break;
			case 4:
				h.deleten();
				break;
			case 5:
				h.modify();
				break;
			}
		}while(c!=0);
}


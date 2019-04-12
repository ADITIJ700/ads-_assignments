#include <iostream>
using namespace std;

class hash
{
public:
	string name[10];
	int tel[10];
	int n;
	void input();
	int hashing(string);
	void display();
	void search();
};

void hash::input()
{
	string ch;
	int x;
	cout << "Enter no. of people\n";
	cin >> n;
	for (int i=0; i < n; i++)
	{
		cout<<"Enter name\n";
		 cin>>ch;
		 x=hashing(ch);
		 name[x]=ch;
		 cout<<"Enter phone no.\n";
		 cin>>tel[x];
	}
}

void hash::display()
{
	for(int i=0;i<10;i++)
	{
		cout<<i<<".   ";
		if(tel[i]==0)
			cout<<"0\n";
		else
			cout<<name[i]<<"     "<<tel[i]<<endl;
	}
}
int hash::hashing(string ch)
{
	int x,l;
	x=0;
	l = ch.length();
	for(int i=0;i<l;i++)
	{
		x=x+int(ch[i]);
	}
	x=x%10;
	while(tel[x]!=0)
	{
		x++;
	}
	return x;
}

void hash::search()
{
	string ch;
	int x;
	cout<<"Enter name to search\n";
	cin>>ch;
	x=hashing(ch);
	cout<<"Index-> "<<x-1<<endl;
}
int main()
{
	hash h;
	int c;
	for(int i=0;i<10;i++)
	{
		h.tel[i]=0;
	}
	do
	{
		cout<<"1.Input\n2.Display\n3.Search\n";
		cin>>c;
		switch(c)
		{
		case 1:
			h.input();
		break;
		case 2:
			h.display();
		break;
		case 3:
			h.search();
		}
	}while(c!=0);
}


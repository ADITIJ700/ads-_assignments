//============================================================================
// Name        : file.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
class fileorg
{
	int roll;
	char nam[10],addr[10];
public:
	void accept();
	void display();
	int getroll();
};

void fileorg::accept()
{
	cout<<"Enter Roll no.\n";
	cin>>roll;
	cout<<"Enter Name.\n";
	cin>>nam;
	cout<<"Enter Address\n";
	cin>>addr;
}

int fileorg::getroll()
{
	return roll;
}
void fileorg::display()
{
	cout<<"\n\nRoll no.  ";
	cout<<roll;
	cout<<"\nName  ";
	cout<<nam;
	cout<<"\nAddress  ";
	cout<<addr;
}
void writef()
{
	ofstream outfile;
	outfile.open("stu.dat",ios::out |ios::app);
	fileorg l;
	l.accept();
    outfile.write((char*) &l,sizeof(l));
    outfile.close();
}

void readf()
{
	ifstream infile;
	infile.open("stu.dat",ios::binary);
	fileorg l;
	while(infile.read((char*) &l,sizeof(l)))
	{
			l.display();
	}
	infile.close();
}

void searchf(int n)
{
	ifstream infile;
	infile.open("stu.dat",ios::binary);
	fileorg l;
	while(infile.read((char*) &l,sizeof(l)))
	{
		if(l.getroll()==n)
		{
			l.display();
			break;
		}
	}
}

void deletef(int n)
{
	ofstream outfile;
	outfile.open("tem.dat",ios::out |ios::app);
	ifstream infile;
	infile.open("stu.dat",ios::binary);
	fileorg l;
	while(infile.read((char*) &l,sizeof(l)))
	{
		if(l.getroll()!=n)
		{
			outfile.write((char*) &l,sizeof(l));
		}
	}
	infile.close();
	outfile.close();
	remove("stu.dat");
	rename("tem.dat","stu.dat");
}

int main()
{
	int c,n;
	do
	{
		cout<<"1.Write\n2.Read\n3.Search\n4.Delete\n";
		cin>>c;
		switch(c)
		{
		case 1:
			cout<<"Enter no. of records\n";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				writef();
			}
			break;
		case 2:
			cout<<"Records:-\n";
			readf();
			break;
		case 3:
			cout<<"Enter roll no. to search"<<endl;
			cin>>n;
			searchf(n);
			break;
		case 4:
			cout<<"Enter roll no. to delete"<<endl;
			cin>>n;
			deletef(n);
			break;

		}
	}while(c!=0);
}



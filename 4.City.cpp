
#include <iostream>
#include<queue>
#include<stack>
#define N 50
using namespace std;
class City
{
public:
	int n;
	void input();
	void displayBFS(int);
	void displayDFS(int);
	void display(int);
	string b[N];
	int a[N][N];

};

void City::input()
{

	cout<<"Enter no. cities\n";
		cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter city\n";
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(i==j)
				a[i][j]=0;
			else
			{
				cout<<"Enter the distance between "<<b[i]<<" & "<<b[j]<<":\n";
				cin>>a[i][j];
				a[j][i]=a[i][j];
			}

		}
	}
}

void City::display(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<"\n";
	}
}

void City::displayBFS(int n)
{
	cout<<"******BFS Traversal*******\n";
	int visit[n];
	int ind;
	queue<int> q;
	string st;
	cout<<"Enter the starting city\n";
	cin>>st;
	for(int i=0;i<n;i++)
	{
		visit[i]=0;
		if(st==b[i])
			ind=i;
	}
	visit[ind]=1;
	q.push(ind);
	cout<<b[ind];
	while(!q.empty())
	{
		ind=q.front();
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(visit[i]==0 && a[ind][i]!=0)
			{
				q.push(i);
				visit[i]=1;
			    cout<<" -> "<<b[i];
			}
		}
	}
	cout<<endl;
}

void City::displayDFS(int n)
{
	cout<<"******DFS Traversal*******\n";
		int visit[n];
		int ind;
		stack<int> s;
		string st;
		cout<<"Enter the starting city\n";
		cin>>st;
		for(int i=0;i<n;i++)
		{
			visit[i]=0;
			if(st==b[i])
				ind=i;
		}
		s.push(ind);
		while(!s.empty())
		{
			ind=s.top();
			s.pop();
			if(visit[ind]==0)
			{
				if(b[ind]!=st)
					cout<<" -> "<<b[ind];
				else
					cout<<b[ind];
				visit[ind]=1;
			}
			for(int i=0;i<n;i++)
			{
				if(visit[i]==0 && a[ind][i]!=0)
				{
					s.push(i);
				}
			}

		}
}

int main()
{
	City c;
	int n;
	do
	{
		cout<<"\n1.Input\n2.Display\n3.BFS traversal\n4.DFS traversal\n";
		cin>>n;
		switch(n)
		{
			case 1:
				c.input();
			break;
			case 2:
				c.display(c.n);
			break;
			case 3:
				c.displayBFS(c.n);
			break;
			case 4:
				c.displayDFS(c.n);
			break;
		}
	}while(n!=5);
}


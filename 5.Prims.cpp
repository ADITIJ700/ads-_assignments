#include <iostream>
#define N 50
#define inf 999
using namespace std;
class Prim
{
public:
	int n;
	void input();
	void display();
	void spanning();
	string b[N];
	int a[N][N],t[N][N];
};

void Prim::input()
{
	cout<<"Enter no. of offices\n";
		cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter office\n";
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			t[i][j]=0;
			if(i==j)
				a[i][j]=inf;
			else
			{
				cout<<"Enter the cost for connecting "<<b[i]<<" & "<<b[j]<<":\n";
				cin>>a[i][j];
				if(a[i][j]==0)
					a[i][j]=inf;
				a[j][i]=a[i][j];
			}
		}
	}
}

void Prim::display()
{
	cout<<"   ";
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<"  ";
	}
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<"  ";
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<"\n";
	}
}

void Prim::spanning()
{
	int visit[n],cost,min,ne,x,y;
	for(int i=0;i<n;i++)
	{
		visit[i]=0;
	}
	ne=cost=0;
	visit[0]=1;
	cout<<"Path->\n";
	while(ne<n-1)
	{
		min=inf;
		for(int i=0;i<n;i++)
		{
			if(visit[i]==1)
			{
				for(int j=0;j<n;j++)
				{
					if(visit[j]==0)
					{
						if(min>a[i][j])
						{
							min=a[i][j];
							x=i;
							y=j;
						}
					}
				}
			}
		}
		visit[y]=1;
		cost+=min;
		cout<<b[x]<<" -> "<<b[y]<<"\n";
		t[x][y]=t[y][x]=min;
		ne++;
	}
	cout<<"\nCOST = "<<cost<<"\n";
	cout<<"\nSpanning Tree:>>\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<t[i][j]<<"  ";
		}
		cout<<"\n";
	}	
}

int main()
{
	Prim p;
	int n;
	do
	{
		cout<<"\n1.Input\n2.Display\n3.Spanning Tree\n4.Exit\n";
		cin>>n;
		cout<<"\n";
		switch(n)
		{
			case 1:p.input();
			break;
			case 2:p.display();
			break;
			case 3:p.spanning();
			break;
			case 4:cout<<"Exited!!";
			break;
			default:cout<<"Enter correct choice";
		}
	}while(n!=4);
}


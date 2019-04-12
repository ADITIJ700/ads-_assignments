//============================================================================
// Name        : BTS.cpp
// Author      : Omkar Nagarkar
// Version     :
// Copyright   : Your copyright notice
// Description : Binary Search Tree, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *left;
	node *right;
	friend class bts;
	friend class stack;
	node()
	{
		data=0;
		right=NULL;
		left=NULL;
	}
};

class bts
{
public:
	node *root;
	node* create();
	void insert();
	void display(node*);
	void getMirror(node*);
	void min(node*);
	bool search(node* root,int k);
	void height();
	int cntheight(node* root,int k);
	bts()
	{
		root=NULL;

	}

};

class stack
{
public:
	node* data[50];
	int top;
	stack()
	{
		top=-1;
	}
	void push(node* x)
	{
		top++;
		data[top]=x;
	}

	node* pop()
	{
		node* x;
		x=data[top];
		top--;
		return x;
	}

	int isempty()
	{
		if(top==-1)
		{
			return 1;

		}else
		{
			return 0;
		}
	}

	int isfull()
		{
			if(top==50)
			{
				return 1;

			}else
			{
				return 0;
			}
		}
};

node* bts::create()
{
	node *temp;
	temp=new node;
	cout<<"Enter the data \n";
	cin>>temp->data;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}

void bts::insert()
{
	bts b;
	node* temp;
	temp=b.create();
	if(root==NULL)
	{
		root=temp;
	}
	else{
		node* p;
		p=root;
		while(1)
		{
			if(temp->data<p->data)
			{
				if(p->left==NULL)
				{
				p->left=temp;
				return;
				}else
			{
				p=p->left;
				continue;
			}
			}
			if(temp->data>p->data)
			{
				if(p->right==NULL)
				{
					p->right=temp;
					return;
				}else
				{
					p=p->right;
					continue;
				}
			}

		}
	}
}
void bts::display(node *root)
{
	if(root==NULL)
	{
		return;
	}else
	{
		bts b;

		b.display(root->left);
		cout<<root->data<<" \t";
		b.display(root->right);
	}
}
void bts::getMirror(node* root)
{
	if(root==NULL)
	{
		return;
	}
	bts bs;
	bs.getMirror(root->left);
	bs.getMirror(root->right);
	node* temp=root->left;
	root->left=root->right;
	root->right=temp;
}

void bts::min(node* root)
{
if(root==NULL)
{
	return;
}else
{

	int min=root->data;
	while(root!=NULL)
	{
	if(min>root->data)
		min=root->data;
	root=root->left;
	}
	cout<<"Minimum "<<min<<endl;
}
}

bool bts::search(node* root,int k)
{
	node* temp;
	temp=root;
	if(temp==NULL)
	{
		return 0;
	}else
	{
		if((temp->data)==k)
		{
			return 1;
		}
		else
		{
			if((temp->data)>k)
			{
				return search(temp->right,k);
			}

			if((temp->data)<k)
			{
				return search(temp->left,k);
			}
		}
	}
	return 0;
}
int bts::cntheight(node* root,int k)
{
	int cnt=0;
	node* temp;
	temp=root;
	while(1)
	{
		if(temp->data==k)
		{
			return cnt;

		}else if((temp->data)>k)
		{
			temp=temp->left;
			cnt++;
		}else if((temp->data)<k)
		{
			temp=temp->right;
			cnt++;
		}
	}
}

void bts::height()
{
	int cnt=0;
	bts b;
	int cnt2;
	if(root==NULL)
	{
		cout<<"Tree is empty \n";
	}else
	{
		node *ptr=root;
		stack s;
		while(1)
		{
			while(ptr!=NULL)
			{
				s.push(ptr);
				if((ptr->left==NULL)&&(ptr->right==NULL))
				{
					cnt2=b.cntheight(this->root,ptr->data);
							if(cnt2>cnt)
								cnt=cnt2;
				}
				ptr=ptr->left;
			}
			if(!s.isempty())
			{
				ptr=s.pop();
				ptr=ptr->right;
			}else
				break;
		}
	}
	cout<<"Height of tree is "<<cnt<<endl;
	cout<<"There are "<<(cnt+1)<<"nodes in longest path "<<endl;
}
int main()
{
	bts b;
	int n,a;
	cout<<"Enter the number of elements \n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		b.insert();
	}
	cout<<endl;
	cout<<"Binary Tree: \n";
	b.display(b.root);
	cout<<" \n";
	b.min(b.root);
	b.height();
	b.getMirror(b.root);
	cout<<"Mirror of BTS \n";
	b.display(b.root);

	cout<<" \n Enter a element to search \n";
	cin>>a;

	if(b.search(b.root,a))
	{
		cout<<"Present \n";
	}
	else
	{
		cout<<"Not present \n";
	}



	return 0;
}


/*Output:-

Enter the number of elements 
5
Enter the data 
12
Enter the data 
45
Enter the data 
78
Enter the data 
98
Enter the data 
35

Binary Tree: 
12 	35 	45 	78 	98 	 
Minimum 12
Height of tree is 3
There are 4nodes in longest path 
Mirror of BTS 
98 	78 	45 	35 	12 	 
 Enter a element to search 
78
Present */
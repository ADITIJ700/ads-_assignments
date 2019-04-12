//============================================================================
// Name        : dic.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class node
{
public:
	string word,meaning;
	node *l;
	node *r;

	friend class btree;
	node()
	{
		l=r=NULL;
		word = meaning ="\0";
	}
};

class btree
{
public:
	node *root;
	void insert();
	void disa(node*);
	void disb(node*);
	void deletew(node*,string);
	void update(node*,string);
	node* min(node*);
	btree()
	{
		root =NULL;
	}
};

void btree::insert()
{
	node *temp=new node;
	cout<<"Enter word"<<endl;
	cin>>temp->word;
	cout<<"Enter the meaning"<<endl;
	cin>>temp->meaning;
	if (root == NULL) {
			root = temp;
		} else {
			node *p;
			p = root;
			while (1)
			{
				if (temp->word < p->word)
				{
					if (p->l == NULL)
					{
						p->l = temp;
						return;
					}
					else
					{
						p = p->l;
						continue;
					}
				}
				if (temp->word > p->word)
				{
					if (p->r == NULL)
					{
						p->r = temp;
						return;
					}
					else
					{
						p = p->r;
						continue;
					}
		    }
			}
		}

}

void btree::disa(node* root)
{

	if(root==NULL)
		return;
	else
	{
		btree b;
		b.disa(root->l);
		cout<<root->word<<"    "<<root->meaning<<endl;
		b.disa(root->r);
	}
}

void btree::disb(node* root)
{

	if(root==NULL)
		return;
	else
	{
		btree b;
		b.disb(root->r);
		cout<<root->word<<"    "<<root->meaning<<endl;
		b.disb(root->l);
	}
}

void btree::deletew(node* root,string k)
{
	node* q=new node;;
	node* p=root;
	while(p!=NULL)
	{
		if(k < p->word)
		{
			q=p;
			p=p->l;
		}
		else if(k > p->word)
		{
			q=p;
			p=p->r;
		}
		if(k == p->word)
		{
			//Case 1:
			if(p->l==NULL && p->r==NULL)
			{
				if(q->l==p)
				{
					q->l=NULL;
					delete p;
					return;
				}
				if(q->r==p)
				{
					q->r=NULL;
					delete p;
					return;
				}
			}
			//Case 2:
			else if((p->l==NULL && p->r!=NULL)||(p->l!=NULL && p->r==NULL))
			{
				if(q->r==p)
				{
					q->r=p->r;
					delete p;
					return;
				}
				if(q->r==p)
				{
					q->r=p->r;
					delete p;
					return;
				}
			}
			//Case 3:
			else if(p->l!=NULL && p->r!=NULL)
			{
				q=min(p->r);
				if(q==p->r)
					p->r=NULL;
				p->word = q->word;
				p->meaning = q->meaning;
				delete q;
				return;
			}
		}
	}
	cout<<"Word not found!!!!";
}

node* btree::min(node* root)
{
	node* s=new node;
	while(root->l!=NULL)
	{
		s=root;
		root=root->l;
	}
	s->l=NULL;
	return root;
}
void btree::update(node* root,string k) {
	btree b;
	if (root == NULL)
		return;
	else
	{
		if(root->word==k)
		{
			cout<<"Enter new meaning"<<endl;
			cin>>root->meaning;
			return;
		}
		if(k>root->word){
			return b.update(root->r,k);
		}
		if(k<root->word){
			return b.update(root->l,k);
		}
	}
	cout<<"Word not found"<<endl;
}
int main()
{
	btree b;
	int c,n;
	string k;
    do
    {
    	cout<<"1.Insert"<<endl;
    	cout<<"2.Display Ascending"<<endl;
    	cout<<"3.Delete"<<endl;
    	cout<<"4.Display Descending"<<endl;
    	cout<<"5.Update"<<endl;
    	cout<<"6.Exit"<<endl;
    	cin>>c;
    	switch(c)
    	{
			case 1:
				cout<<"Enter no. of nodes\n";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					b.insert();
				}
			break;
			case 2:
				cout<<"Binary Tree:-"<<endl;
				b.disa(b.root);
			break;
			case 3:
				cout<<"Enter word to be deleted"<<endl;
				cin>>k;
				b.deletew(b.root,k);
				cout<<"Word is deleted..."<<endl;
			break;
			case 4:
				cout<<"Descending Binary Tree:-"<<endl;
				b.disb(b.root);
			break;
			case 5:
				cout<<"Enter word to be updated"<<endl;
				cin>>k;
				b.update(b.root,k);
				cout<<"Updated!!!"<<endl;
			break;
			default:
				c=6;
    	}
    }while(c!=6);
    cout<<"Exited!!!!!";
}

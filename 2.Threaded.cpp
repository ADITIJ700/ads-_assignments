#include <iostream>
#include<stdlib.h>
using namespace std;
class node {
	int data;
public:

	node *left;
	node *right;
	bool rt;
	friend class btree;
	node() {
		data = 0;
		left = NULL;
		right = NULL;
		rt=0;
	}
};
class btree {
public:
	node *root;
	node *temp;
	node* create();
	void insert();
	node* leftmost(node*);
    void disin(node*);
    void convert(node*,node*);
	btree() {
		root = NULL;
		temp=NULL;
	}
};
node* btree::create() {
	node* temp;
	temp = new node;
	cout << "Enter data" << endl;
	cin >> temp->data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void btree::insert() {
	btree b;
	node *temp;
	temp = b.create();
	if (root == NULL) {
		root = temp;
	} else {
		node *p;
		p = root;
		while (1) {
			if (temp->data < p->data) {
				if (p->left == NULL) {
					p->left = temp;
					return;
				} else {
					p = p->left;
					continue;
				}
			}
			if (temp->data > p->data) {
				if (p->right == NULL) {
					p->right = temp;
					return;
				} else {
					p = p->right;
					continue;
				}
			}
		}
	}
}
node* btree::leftmost(node* temp)
{
	while(temp!=NULL&&temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}
void btree::disin(node* temp)
{
	node* cur;
	cur=leftmost(temp);
	while(cur)
	{
		cout<<cur->data<<" ";
		if(cur->rt)
			cur=cur->right;
		else
			cur=leftmost(cur->right);
	}
}
void btree::convert(node *temp,node* prev)
{
	btree b;
	if(temp)
	{
		b.convert(temp->right,prev);
		if(temp->right==NULL&&prev!=NULL)
		{
			temp->right=prev;
			temp->rt=1;
		}
		b.convert(temp->left,temp);
	}
}
int main()
{
	btree b;
	int n;
	cout<<"Enter total number of nodes"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		b.insert();
	}
	cout<<"Threaded Binary Tree"<<endl;
	b.convert(b.root,NULL);
	b.disin(b.root);
}

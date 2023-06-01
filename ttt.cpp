#include<iostream>
#include<string.h>
using namespace std;
struct Node
{
	int ch_count;
	string label ;
	struct Node*child[10];

}*root;
class GT
{
	public:
	void create();
	void display (Node*r1);
	GT()
	{
		root=NULL;

	}

	
};
void GT:: create()
{


int tchapter,i,j;
root=new Node;
cout<<"enter the name of book"<<endl;
cin>>root->label;
cout<<"enter the number of chapters in book "<<endl;
cin>>tchapter;

root->ch_count=tchapter;
for (i=0;i<tchapter;i++)
{
	root->child[i]=new Node;
	cout<<"enter the name of chapter no "<<i+1<<endl;
	cin>>root->child[i]->label;
	cout<<"enter the number of section in chapter"<<root->child[i]->label;
	cin>>root->child[i]->ch_count;

	for (j=0;j<root->child[i]->ch_count;j++)
	{
		root->child[i]->child[j]=new Node;
		cout<<"enter name of section no "<<j+1<<endl;
		cin>>root->child[i]->child[j]->label;


	}
}
}


void GT::display (Node *root)
{
int i,j, tchapter;
if (root!=NULL)
{
	cout<<"tree"<<endl;
	cout<<"book name"<<root->label<<endl;
	tchapter=root->ch_count;
	for (i=0;i<tchapter;i++)
	{
		cout<<"chapter "<<i+1<<root->child[i]->label;
		cout<<"section "<<endl;
		for (j=0;j<root->child[i]->ch_count;j++)
		
		{
			cout<<"section"<<j+1<<":"<<root->child[i]->child[j]->label;
		}
	}

cout<<endl;
cout<<endl;
}
else
{
	cout<<"tree is empty "<<endl;
}
}


int main()
{
	GT g;
	int ch;
	while(1)
	{
		cout<<"1.create "<<endl;
		cout<<"2.display"<<endl;
		cout<<"3.exit"<<endl;
		cin>>ch;
		switch (ch)
		{
			case 1:
			g.create();
			break;
			case 2:
			g.display(root);
			break;
			case 3:
			exit(1);
			default:
			cout<<"invalid input"<<endl;


		}
	} return 0;

}
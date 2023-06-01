# DSA

/*
    A book consists of chapters, chapters consists sections and sections consist of
    subsections. Construct a tree and print the nodes. Find the time and space
    requirements of your method.
*/

#include <iostream>
#include <string.h>

using namespace std;

struct Node
{
     string label;
     int ch_count;
     struct Node *child[10];
} *root;

class GT
{
public:
     void create_tree();
     void display(Node *r1);
     GT()
     {
          root = NULL;
     }
};

void GT ::create_tree()
{
     int tchapters, i, j, k;
     root = new Node;

     cout << "Enter the name of the book: ";
     cin >> root->label;

     cout << "Enter the number of chapters in the book: ";
     cin >> tchapters;

     root->ch_count = tchapters;

     for (i = 0; i < tchapters; i++)
     {
          root->child[i] = new Node;
          cout << "Enter name of chapter no. " << i + 1 << ": ";
          cin >> root->child[i]->label;

          cout << "Enter the number of sections in chapter" << root->child[i]->label << ": ";
          cin >> root->child[i]->ch_count;

          for (j = 0; j < root->child[i]->ch_count; j++)
          {
               root->child[i]->child[j] = new Node;
               cout << "Enter name of section no. " << j + 1 << ": ";
               cin >> root->child[i]->child[j]->label;
          }
     }
}
void GT ::display(Node *root)
{
     int i, j, k, tchapters;

     if (root != NULL)
     {

          cout << "TREE";
          cout << "\nBook title: " << root->label;
          tchapters = root->ch_count;

          for (i = 0; i < tchapters; i++)
          {
               cout << "\n\nChapter " << i + 1 << ": " << root->child[i]->label;
               cout << "\nSections: ";
               for (j = 0; j < root->child[i]->ch_count; j++)
               {
                    cout << "\n -Section " << j + 1 << ": " << root->child[i]->child[j]->label;
               }
          }
          cout << endl;
          cout << endl;
     }
     else
     {
          cout << "Tree is empty" << endl;
     }
     cout << endl;
}

int main()
{
     GT gt;

     int ch;

     while (1)
     {

          cout << "1. Create" << endl;
          cout << "2. Display" << endl;
          cout << "3. Exit" << endl;
          cin >> ch;
          switch (ch)
          {
          case 1:
               gt.create_tree();
               break;
          case 2:
               gt.display(root);
               break;
          case 3:
               exit(1);
          default:
               cout << "Incorrect input";
          }
     }
     return 0;
}
  
  
  
  
  
  /*Title:Construct an expression tree from the given prefix expression eg.
 +--a*bc/def and traverse it using
 post order traversal (non recursive) and then delete the entire tree*/
#include <iostream>
#include <stack>
using namespace std;

// Node class for the expression tree
class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to create an expression tree from prefix notation
Node *createExpressionTree(string prefix)
{
    stack<Node *> s;
    int n = prefix.size();
    for (int i = n - 1; i >= 0; i--)
    {
        char ch = prefix[i];
        if (isdigit(ch) || isalpha(ch))
        {
            Node *node = new Node(ch);
            s.push(node);
        }
        else
        {
            Node *node = new Node(ch);
            node->left = s.top();
            s.pop();
            node->right = s.top();
            s.pop();
            s.push(node);
        }
    }
    return s.top();
}

// Function to traverse the expression tree in post-order
void postorderTraversal(Node *root)
{
    if (root)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
        delete root;
    }
}

int main()
{
    string prefix = "+--a*bc/def";
    Node *root = createExpressionTree(prefix);
    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;
    return 0;
}

  
  dsa 6 practical
  #include<iostream>
#include<queue>
using namespace std;

int adj_mat[50][50]={0,0};
int visited[50]={0};
void dfs(int s,int n,string arr[])
{
     visited[s]=1;
     cout<<arr[s]<<" ";
     for(int i=0;i<n;i++)
     {
        if(adj_mat[s][i] && !visited[i])
            dfs(i,n,arr);
     }
}
int main()
{
   cout<<"enter no.of cities:";
   int n,u;
   cin>>n;
   string cities[n];
   for(int i=0;i<n;i++)
   {
      cout<<"enter the city#"<<i<<"(airport code):";
      cin>>cities[i];
   }
   cout<<"\nyour cities are:"<<endl;
   for(int i=0;i<n;i++)
   {
      cout<<"city#"<<i<<":"<<cities[i]<<endl;
   }
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
          cout<<"enter distance between"
          <<cities[i]<<"and"<<cities[j]<<":";
          cin>>adj_mat[i][j];
          adj_mat[j][i]=adj_mat[i][j];
       }
   }   
   cout<<endl;
   for(int i=0;i<n;i++)
       cout<<"\t"<<cities[i]<<"\t";
   for(int i=0;i<n;i++)
   {
       cout<<"\n"<<cities[i];
       for(int j=0;j<n;j++)
            cout<<"\t"<<adj_mat[i][j]<<"\t";
       cout<<endl;
   }
   cout<<"enter starting vertex:";
   cin>>u;
   cout<<"dfs:";
   dfs(u,n,cities);
   cout<<endl;
   return 0;
}
         
         
         dsa practicle 7
         #include <iostream>
#include <climits>
using namespace std;
template <class T>
class Graph
{
    int **AM, num;
    T *data;

public:
    Graph(int n)
    {
        AM = new int *[n];
        for (int i = 0; i < n; i++)
            AM[i] = new int[n];
        num = n;
        data = new T[n];
        cout << "Enter names of all cities : ";
        for (int i = 0; i < n; i++)
            cin >> data[i];
        cout << "Enter cost if you want to connect cities else enter 0: \n";
        for (int j = 0; j < n; j++)
            cout << data[j] << " ";
        cout << endl;
        for (int i = 0, cost = 0; i < n; i++)
        {
            cout << "Nodes connected to " << data[i] << " :\n";
            for (int j = 0; j < i; j++)
                cout << AM[i][j] << "\t";
            for (int j = i; j < n; j++)
                if (j == i)
                {
                    cout << "0\t";
                    AM[i][j] = AM[j][i] = 0;
                }
                else
                {
                    cin >> cost;
                    AM[i][j] = AM[j][i] = cost;
                }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (AM[i][j] == 0)
                    AM[i][j] = INT_MAX;
    }
    void prims()
    {
        cout << "\nCities that we need to connect:\n";
        int *visited = new int[num](), *distance = new int[num], *from = new int[num](), cost = 0;
        visited[0] = 1;
        for (int i = 0; i < num; i++)
            distance[i] = AM[0][i];
        int u, v;
        for (int count = num - 1; count > 0; count--)
        {
            int min = INT_MAX;
            for (int j = 1; j < num; j++)
                if (visited[j] == 0 && distance[j] < min)
                {
                    v = j;
                    min = distance[j];
                }
            u = from[v];
            cout << data[u] << "==>" << data[v] << "\tcost: " << AM[u][v] << endl;
            visited[v] = 1;
            for (int j = 1; j < num; j++)
                if (visited[j] == 0 && AM[j][v] < distance[j])
                {
                    distance[j] = AM[j][v];
                    from[j] = v;
                }
            cost += AM[u][v];
        }
        cout << "Total cost of connecting all cities : " << cost << endl;
    }
};
int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;
    Graph<string> gr(n);
    gr.prims();
    return 0;
}
dsa practicle 8
         #include<iostream>
using namespace std;
void con_obst(void);
void print(int,int);
float a[20],b[20],wt[20][20],c[20][20];
int r[20][20],n;
int main()
  {
	int i;
	cout<<"\n****** PROGRAM FOR OBST ******\n";
	cout<<"\nEnter the no. of nodes : ";
	cin>>n;cout<<"\nEnter the probability for successful search :: ";
	cout<<"\n————————————————\n";
	for(i=1;i<=n;i++)
	  {
		cout<<"p["<<i<<"]";
		cin>>a[i];
	  }
	cout<<"\nEnter the probability for unsuccessful search :: ";
	cout<<"\n————————————————–\n";
	for(i=0;i<=n;i++)
	  {
		cout<<"q["<<i<<"]";
		cin>>b[i];
	  }
	con_obst();
	print(0,n);
	cout<<endl;
}
void con_obst(void)
{
	int i,j,k,l,min;
	for(i=0;i<n;i++)
	  { //Initialisation
		c[i][i]=0.0;
		r[i][i]=0;
		wt[i][i]=b[i];
		// for j-i=1 can be j=i+1
		wt[i][i+1]=b[i]+b[i+1]+a[i+1];
		c[i][i+1]=b[i]+b[i+1]+a[i+1];
		r[i][i+1]=i+1;
	  }
	c[n][n]=0.0;
	r[n][n]=0;
	wt[n][n]=b[n];
	//for j-i=2,3,4....,n
	for(i=2;i<=n;i++)
	  {
		for(j=0;j<=n-i;j++)
		  {
			wt[j][j+i]=b[j+i]+a[j+i]+wt[j][j+i-1];
			c[j][j+i]=9999;
			for(l=j+1;l<=j+i;l++)
			  {
				if(c[j][j+i]>(c[j][l-1]+c[l][j+i]))
				  {
					c[j][j+i]=c[j][l-1]+c[l][j+i];
					r[j][j+i]=l;
				  }
			  }
			c[j][j+i]+=wt[j][j+i];
		  }
		cout<<endl;
	  }
	cout<<"\n\nOptimal BST is :: ";
	cout<<"\nw[0]["<<n<<"] :: "<<wt[0][n];
	cout<<"\nc[0]["<<n<<"] :: "<<c[0][n];
	cout<<"\nr[0]["<<n<<"] :: "<<r[0][n];
  }
void print(int l1,int r1)
  {
	if(l1>=r1)
		return;
	if(r[l1][r[l1][r1]-1]!=0)
		cout<<"\n Left child of "<<r[l1][r1]<<" :: "<<r[l1][r[l1][r1]-1];
	if(r[r[l1][r1]][r1]!=0)
		cout<<"\n Right child of "<<r[l1][r1]<<" :: "<<r[r[l1][r1]][r1];
	print(l1,r[l1][r1]-1);
	print(r[l1][r1],r1);
	return;
}
         
         dsa practicle 10
         
         
         #include<iostream>
using namespace std;
class Heap
{
	int n;
	int *minheap,*maxheap;
	public:
	void get();
	void displayMin(){cout<<"Minimum marks are :"<<minheap[0]<<endl;}
	void displayMax(){cout<<"Maximum marks are :"<<maxheap[0]<<endl;}
	void upAdjust(bool,int);
};
void Heap::get()
{
	cout<<"Enter number of students."<<endl;
	cin>>n;
	int k;
	minheap=new int[n];
	maxheap=new int[n];
	cout<<"Enter marks of students."<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		minheap[i]=k;
		upAdjust(0,i);
		maxheap[i]=k;
		upAdjust(1,i);
	}
}
void Heap::upAdjust(bool m,int l)
{
	int s;
	if(!m)
	{
		while(minheap[(l-1)/2]<minheap[l])
		{
			s=minheap[l];
			minheap[l]=minheap[(l-1)/2];
			minheap[(l-1)/2]=s;
			l=(l-1)/2;
			if(l==-1)
				break;
		}
	}
	else
	{
		while(maxheap[(l-1)/2]>maxheap[l])
		{
			s=maxheap[l];
			maxheap[l]=maxheap[(l-1)/2];
			maxheap[(l-1)/2]=s;
			l=(l-1)/2;
			if(l==-1)
				break;
		}
	}
}
main()
{
	Heap H;
	H.get();
	H.displayMin();
	H.displayMax();
	return(0);
}
         
         
         
         
         dsa 11
         
         
         #include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student
  {
    typedef struct stud
    {
        int roll;
        char name[10];
        char div;
        char add[10];
    }stud;
    stud rec;
    public:
      void create();
      void display();
      int search();
      void Delete();
  };
void student::create()
  {
    char ans;
    ofstream fout;
    fout.open("stud.dat",ios::out|ios::binary);
    do
      {
        cout<<"\n\tEnter Roll No of Student    : ";
        cin>>rec.roll;
        cout<<"\n\tEnter a Name of Student     : ";
        cin>>rec.name;
        cout<<"\n\tEnter a Division of Student : ";
        cin>>rec.div;
        cout<<"\n\tEnter a Address of Student  : ";
        cin>>rec.add;
        fout.write((char *)&rec,sizeof(stud))<<flush;
        cout<<"\n\tDo You Want to Add More Records: ";
        cin>>ans;
      }while(ans=='y'||ans=='Y');
    fout.close();
  }
void student::display()
  {
    ifstream fin;
    fin.open("stud.dat",ios::in|ios::binary);
    fin.seekg(0,ios::beg);
    cout<<"\n\tThe Content of File are:\n";
    cout<<"\n\tRoll\tName\tDiv\tAddress";
    while(fin.read((char *)&rec,sizeof(stud)))
      {
        if(rec.roll!=-1)
              cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
      }
    fin.close();
  }
int student::search()
  {
    int r,i=0;
    ifstream fin;
    fin.open("stud.dat",ios::in|ios::binary);
    fin.seekg(0,ios::beg);
    cout<<"\n\tEnter a Roll No: ";
    cin>>r;
    while(fin.read((char *)&rec,sizeof(stud)))
      {
        if(rec.roll==r)
          {
            cout<<"\n\tRecord Found...\n";
            cout<<"\n\tRoll\tName\tDiv\tAddress";
            cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
            return i;
          }
        i++;
      }
    fin.close();
    return 0;
  }
void student::Delete()
  {
    int pos;
    pos=search();
    fstream f;
    f.open("stud.dat",ios::in|ios::out|ios::binary);
    f.seekg(0,ios::beg);
    if(pos==0)
      {
        cout<<"\n\tRecord Not Found";
        return;
      }
    int offset=pos*sizeof(stud);
    f.seekp(offset);
    rec.roll=-1;
    strcpy(rec.name,"NULL");
    rec.div='N';
    strcpy(rec.add,"NULL");
    f.write((char *)&rec,sizeof(stud));
    f.seekg(0);
    f.close();
    cout<<"\n\tRecord Deleted";
  }
    
int main()
  {
    student obj;
    int ch,key;
    char ans;
    do
      {
        cout<<"\n\t***** Student Information *****";
        cout<<"\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit";
        cout<<"\n\t..... Enter Your Choice: ";
        cin>>ch;
        switch(ch)
          {
            case 1: obj.create();
                break;
            case 2: obj.display();
                break;
            case 3: obj.Delete();
                break;
            case 4: key=obj.search();
                if(key==0)
                  cout<<"\n\tRecord Not Found...\n";
                break;
            case 5:
                break;
          }
        cout<<"\n\t..... Do You Want to Continue in Main Menu: ";
        cin>>ans;
      }while(ans=='y'||ans=='Y');
return 1;
  }





dsa practicle 12 
         
         
         #include <bits/stdc++.h>
  
#define max 20
using namespace std;
  
// Structure of Employee
struct employee {
    string name;
    long int code;
    string designation;
    int exp;
    int age;
};
  
int num;
void showMenu();
  
// Array of Employees to store the
// data in the form of the Structure
// of the Array
employee emp[max], tempemp[max],
    sortemp[max], sortemp1[max];
  
// Function to build the given datatype
void build()
{
    cout << "Build The Table\n";
    cout << "Maximum Entries can be "
         << max << "\n";
  
    cout << "Enter the number of "
         << "Entries required";
    cin >> num;
  
    if (num > 20) {
        cout << "Maximum number of "
             << "Entries are 20\n";
        num = 20;
    }
    cout << "Enter the following data:\n";
  
    for (int i = 0; i < num; i++) {
        cout << "Name ";
        cin >> emp[i].name;
  
        cout << "Employee ID ";
        cin >> emp[i].code;
  
        cout << "Designation ";
        cin >> emp[i].designation;
  
        cout << "Experience ";
        cin >> emp[i].exp;
  
        cout << "Age ";
        cin >> emp[i].age;
    }
  
    showMenu();
}
  
// Function to insert the data into
// given data type
void insert()
{
    if (num < max) {
        int i = num;
        num++;
  
        cout << "Enter the information "
             << "of the Employee\n";
        cout << "Name ";
        cin >> emp[i].name;
  
        cout << "Employee ID ";
        cin >> emp[i].code;
  
        cout << "Designation ";
        cin >> emp[i].designation;
  
        cout << "Experience ";
        cin >> emp[i].exp;
  
        cout << "Age ";
        cin >> emp[i].age;
    }
    else {
        cout << "Employee Table Full\n";
    }
  
    showMenu();
}
  
// Function to delete record at index i
void deleteIndex(int i)
{
    for (int j = i; j < num - 1; j++) {
        emp[j].name = emp[j + 1].name;
        emp[j].code = emp[j + 1].code;
        emp[j].designation
            = emp[j + 1].designation;
        emp[j].exp = emp[j + 1].exp;
        emp[j].age = emp[j + 1].age;
    }
    return;
}
  
// Function to delete record
void deleteRecord()
{
    cout << "Enter the Employee ID "
         << "to Delete Record";
  
    int code;
  
    cin >> code;
    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            deleteIndex(i);
            num--;
            break;
        }
    }
    showMenu();
}
  
void searchRecord()
{
    cout << "Enter the Employee"
         << " ID to Search Record";
  
    int code;
    cin >> code;
  
    for (int i = 0; i < num; i++) {
  
        // If the data is found
        if (emp[i].code == code) {
            cout << "Name "
                 << emp[i].name << "\n";
  
            cout << "Employee ID "
                 << emp[i].code << "\n";
  
            cout << "Designation "
                 << emp[i].designation << "\n";
  
            cout << "Experience "
                 << emp[i].exp << "\n";
  
            cout << "Age "
                 << emp[i].age << "\n";
            break;
        }
    }
  
    showMenu();
}
  
// Function to show menu
void showMenu()
{
  
    cout << "-------------------------"
         << "Employee"
         << " Management System"
         << "-------------------------\n\n";
  
    cout << "Available Options:\n\n";
    cout << "Build Table         (1)\n";
    cout << "Insert New Entry    (2)\n";
    cout << "Delete Entry        (3)\n";
    cout << "Search a Record     (4)\n";
    cout << "Exit                (5)\n";
  
    int option;
  
    // Input Options
    cin >> option;
  
    // Call function on the bases of the
    // above option
    if (option == 1) {
        build();
    }
    else if (option == 2) {
        insert();
    }
    else if (option == 3) {
        deleteRecord();
    }
    else if (option == 4) {
        searchRecord();
    }
    else if (option == 5) {
        return;
    }
    else {
        cout << "Expected Options"
             << " are 1/2/3/4/5";
        showMenu();
    }
}
  
// Driver Code
int main()
{
  
    showMenu();
    return 0;
}


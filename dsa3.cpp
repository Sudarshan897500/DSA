
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
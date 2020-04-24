#include <iostream>
using namespace std;

struct node
{
    int number;
    struct node *left;
    struct node *right;

};

struct node *root = NULL;

main()
{
    char ch;
    int number,counter = 0;
    struct node *temp;
    void insert_element(struct node *,struct node *);
    void inorder_traversal(struct node *);

    do
    {
      cout<<"Enter the number to be inserted:\n ";
      cin>>number;


        temp = new node;
        temp -> number = number;

        insert_element(root,temp);


      cout<<"Do you want to enter more elements";
      cin>>ch;
    }while(ch == 'Y' || ch == 'y');

    inorder_traversal(root);

}

void insert_element(struct node *parent,struct node *temp)
{
    if(parent == NULL)  //No node is created
    {
        cout<<"1";
        parent = temp;
        parent -> number = temp -> number;
        parent -> left = NULL;
        parent ->right = NULL;

        root = parent;

    } //Root node is added into the tree
    else
    {
        if(temp -> number == parent -> number)
        {
            cout<<"Element already exists\n";
        }
        else if(temp -> number < parent -> number)
        {
            if(parent -> left == NULL )
            {
                parent->left = temp;
                parent->left->number = temp->number;
                temp->left = NULL;
                temp->right = NULL;
            }
            else
                insert_element(parent->left,temp);
        }
        else if(temp -> number > parent -> number)
        {
           if(parent -> right == NULL )
            {
                parent->right = temp;
                parent->right->number = temp->number;
                temp->left = NULL;
                temp->right = NULL;
            }
            else
                insert_element(parent->right,temp);
        }
    }

}

void inorder_traversal(struct node *temp)
{
   if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;

    }
    if (temp != NULL)
    {
        inorder_traversal(temp->left);
        cout<<temp->number<<"  ";
        inorder_traversal(temp->right);
    }


}

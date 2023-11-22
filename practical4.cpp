/*
Beginning with an empty binary search tree, Construct binary search tree by inserting the 
values in the order given. After constructing a binary tree -  
i.   Insert new node 
ii.  Find number of nodes in longest path from root 
iii. Minimum data value found in the tree 
iv.  Change a tree so that the roles of the left and right pointers are swapped at every node 
v.   Search a value
*/

#include<iostream>
#define size 20
using namespace std;

class bintree         //only one fild (data) not like 6th 
{
    public:
    typedef struct node
    {   
        int data;
        struct node *left, *right;
    }node;
    node *root, *New, *temp, *parent;

bintree()
    {
        root = NULL; 
    }   

    void create();
    void display();
    void find();
    void insert(node *, node *);
    void inorder(node *);
    void search(node **, int, node **);
    void longestpathnodes();
    int depth(node *);
    void find_min_value();
    void minValue(node*, int*);
    void mirroring();
    void mirror(node*);
};

void bintree::create()
{
    New = new node;
    New -> left = NULL;
    New -> right = NULL;
    cout<<"\nEnter the element : ";
    cin>>New -> data;
    if(root == NULL)
        root = New;
    else
        insert(root, New);
}

void bintree::insert(node *root,node *New)
{
    if(New-> data < root-> data)
    {
        if(root-> left == NULL)
            root -> left = New;
        else
            insert(root-> left,New);
    }

    if(New-> data > root-> data)
    {
        if(root-> right == NULL)
            root-> right = New;
        else
            insert(root-> right,New);
    }    
}

void bintree:: display()
{
    if(root == NULL)
        cout<<"tree is not created";
    
    else
    {
        cout<<"\nTree is : ";
        inorder(root);
    }
}

void bintree::inorder(node *temp)
{
    if(temp != NULL)
    {
        inorder(temp-> left);
        cout<<" "<<temp-> data;
        inorder(temp -> right);
    }
}

void bintree::find_min_value()
{
    int min = root -> data;
    minValue(root, &min);  //decause we are using integer using pointer?
    cout<<"\nThe minimum value node within a tree is : "<<min;
}

void bintree::minValue(node *temp,int *min) //*min is necessary only min gives false value
{
    if(temp != NULL)
    {
        minValue(temp -> left, min);
        if(temp -> data < *min)
            *min = temp -> data;
        minValue(temp -> right, min);
    }
}

void bintree :: find()
{
    int key;
    cout<<"\nEnter element to search : ";
    cin>>key;

    temp = root;
    search(&temp, key, &parent);
    if(temp == NULL)
        cout<<"\nElement is not present";
    else
        cout<<"\nPerent of node "<<temp -> data<< " is "<< parent -> data;
}

void bintree :: search(node **temp, int key, node **parent)  //** is necessary else we get false values
{
    if(*temp == NULL)
        cout<<endl<<"Tree is not created"<<endl;
    else
    {
        while(*temp != NULL)
        {
            if((*temp) -> data == key)
            {
                cout<<"\nElement "<<(*temp) -> data<<" is present";
                break;
            }
            *parent = *temp;   
            if((*temp)-> data > key)
                *temp = (*temp)-> left;
            else
                *temp = (*temp)-> right;
        }
    }
    return;
}

void bintree :: longestpathnodes()
{
    if(root == NULL)
        cout<<"\nTree is empty!!!";
    else
    {
        int ldepth = depth(root);
        int rdepth = depth(root);

        if(ldepth > rdepth)
            cout<<"\nThe number of nodes on longest path = "<<ldepth + 1;
        else    
            cout<<"\nThe number of nodes on longest path = "<<rdepth + 1;
    }
}

int bintree::depth(node *root)
{
    if(root == NULL)
        return 0;
    else
    {
        int ldepth = depth(root -> left);
        int rdepth = depth(root -> right);

        if(ldepth > rdepth)
            return ldepth;
        else
            return(rdepth + 1);
    }
}

void bintree :: mirroring()
{
    cout <<"\nOrignal tree";
    display();
    mirror(root);
    cout<<"\nTree with swaped nodes";
    display();
    mirror(root);        //Bringing back to original state
}

void bintree :: mirror(node *root)
{
    if(root == NULL)
        return;
    else
    {
        node *temp;

        /* do the subtrees */
		mirror(root ->left);
		mirror(root ->right);

		/* swap the pointers in this node */
		temp = root ->left;
		root->left = root->right;
		root->right = temp;
    }   
}


int main()
{
    int choice;
    char ans = 'N';
    bintree tr;

    cout<<"\n\nProgram for binary search tree\n";

    do
    {
        cout<<"\n\n1: Create";
        cout<<"\n2: Display";
        cout<<"\n3: Longhest path nodes";
        cout<<"\n4: Find minimum value";
        cout<<"\n5: Change tree by swaping";
        cout<<"\n6: Search";
        cout<<"\n\nEnter your choice : ";
        cin>>choice;

        switch (choice)
        {
            case 1:do
            {
                tr.create();
                cout<<"Do you want to enter more(y/n)"<<endl;
                cin>>ans;
            }while(ans == 'y');
                break;
            
            case 2:tr.display();
                break;
            
            case 3:tr.longestpathnodes();
                break;

            case 4:tr.find_min_value();
                break;

            case 5:tr.mirroring();
                break;

            case 6:tr.find();
                break;
        }
    } while (choice != 7);    
}
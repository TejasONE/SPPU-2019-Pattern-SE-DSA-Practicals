/*
Construct  an  expression  tree  from  the  given  prefix  expression  eg.  +--a*bc/def  and 
traverse it using post order traversal (non recursive) and then delete the entire tree. 
*/

#include <iostream>
using namespace std;

class node 
{
public:
    char data;
    node* left, *right;
    node() 
	{
        left = right = NULL;
    }
};


node* place_node(string st, int &i)    //not void 
{
	node* ptr = new node();
	ptr->data=st[i];    //pre order so the data is symblo 
	
	if(ptr->data=='+' || ptr->data=='-' || ptr->data=='*' || ptr->data=='/') 
	{	
		ptr->left = place_node(st,++i);  //increment
		ptr->right = place_node(st,++i);   //increment
	} 
	else 
	{
		return ptr;
	}
	
	return ptr;
}

node* construct_ext(string st)   //not void 
{
	int i = 0; //at zeroth location their will be an operator
	node* root = NULL;      // initial root
	root = place_node(st,i);
	return root;
}

void ascending_order(node* ptr) 
{
    if (ptr == NULL)
        return;
    if(ptr->data=='+' || ptr->data=='-' || ptr->data=='*' || ptr->data=='/') 
	{
    	cout<<'(';
    }
    ascending_order(ptr->left);
    cout << ptr->data;
    ascending_order(ptr->right);
    if(ptr->data=='+' || ptr->data=='-' || ptr->data=='*' || ptr->data=='/') 
	{
    	cout<<')';
    }
}

int main() 
{
	node* root = construct_ext("+--a*bc/def");
	ascending_order(root);
	return 0;
}
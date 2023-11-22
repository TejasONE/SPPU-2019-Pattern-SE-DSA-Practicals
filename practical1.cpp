/* Implement the Heap/Shell sort algorithm implemented in Java/c++ demonstrating heap/shell 
   data structure with modularity of programing language. */  

#include<iostream>
using namespace std;

int data,i,n,j,k;
int a[50];
int temp;

void shellsort(int *a,int n)   //*a or a[]
{
    for(int interval = n/2; interval > 0; interval = interval / 2)
    {
        for(j = interval; j<n; j++)  // j goes to the right (j and interval are at the same position)
        {
            for(k = j - interval; k >= 0; k = k - interval)  // k goes to the left
            {
                if (a[k + interval] >= a[k])
                    break;
                else                    
                    temp = a[k+interval];
                    a[k+interval] = a[k];
                    a[k] = temp;
            }           
        }
    }
}           // for   for   for   if   else.

void display(int *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
    cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    cout<<"How many elements : ";
    cin>>n;

    cout<<"Enter the elements : ";
    for(i=0; i<n; i++)
    {    
        cin>>a[i];
    }

    shellsort(a, n);
    cout<<"Sorted array is : \n";
    display(a, n);
}


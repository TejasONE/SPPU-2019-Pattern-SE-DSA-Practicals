/*
Read  the  marks  obtained  by  students  of  second  year  in  an  online  examination  of 
particular subject. Find out maximum and minimum marks obtained in that subject. Use 
heap data structure. Analyze the algorithm.
*/

/*
In a Min-Heap the key present at the root node must be less than or equal among the keys present at all 
of its children. The same property must be recursively true for all sub-trees in that Binary Tree. 
In a Min-Heap the minimum key element present at the root. 

In a Max-Heap the key present at the root node must be greater than or equal among the keys present at 
all of its children. The same property must be recursively true for all sub-trees in that Binary Tree. 
In a Max-Heap the maximum key element present at the root.
*/
#include<iostream>
using namespace std;

class hp
{
    int heap[20], heap1[20], x, n1, i;

    public:
        hp()
        {
            heap[0]=0; 
            heap1[0]=0;
        } 

        void getdata();
        void insert1(int heap[],int,int);
        void upadjust1(int heap[],int);
        void insert2(int heap1[],int,int);
        void upadjust2(int heap1[],int);
        void minmax();
};

void hp::getdata()
{  
    cout<<"\nenter the no. of students : ";
    cin>>n1;
    
    for(i=0;i<n1;i++)
    {   
        cout<<"\nenter the marks : ";
        cin>>x;
        insert1(heap,x,i);
        insert2(heap1,x,i);
    }
}

void hp::insert1(int heap[20], int x, int i)    //max heap
{

    heap[i] = x;

    upadjust1(heap,i);
}

void hp::upadjust1(int heap[20], int i)    //max heap
{
    int temp;
    while( i>1 && heap[i] > heap[i/2] )
    {
        temp=heap[i];
        heap[i]=heap[i/2];
        heap[i/2]=temp;
        i=i/2;   //reduce
    }
}

void hp::insert2(int heap1[20],int x,int i)
{
    heap1[i] = x;

    upadjust2(heap1,i);
}

void hp::upadjust2(int heap1[20],int i)
{
    int temp1;
    while( i>1 && heap1[i] < heap1[i/2] )
    {
        temp1=heap1[i];
        heap1[i]=heap1[i/2];
        heap1[i/2]=temp1;
        i=i/2;
    }
}

void hp::minmax()
{
    cout<<"\nmax marks : "<<heap[1];
    for(i=0; i < n1; i++)
    {   
        cout<<"\n"<<heap[i];  
    }
    
    cout<<"\nmin marks : "<<heap1[1];
    for(i=0; i < n1; i++)
    {  
        cout<<"\n"<<heap1[i];  
    }
}

int main()
{  
    hp h;
    h.getdata();
    h.minmax();
    return 0;
}
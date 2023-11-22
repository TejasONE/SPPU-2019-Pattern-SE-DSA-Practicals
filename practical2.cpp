/*
Consider telephone book database of N clients. Make use of a hash table implementation 
to  quickly look up client‘s  telephone  number. Make  use  of  two  collision  handling 
techniques and  compare  them  using  number  of  comparisons  required  to  find  a  set  of 
telephone numbers.
*/

#include<iostream>
#include<cmath>
#define MAX 10
using namespace std;

class Hash
{
    private:
        int a[MAX];   // one dimentional array

    public:
        Hash();
        int create(int);
        void linear_probing(int, int);
        void quadratic_probing(int,int);
        display();
};

Hash :: Hash()            //imp
{
    int i;
    for(i=0; i<MAX; i++)
    a[i] = -1;
}

int Hash :: create(int num)
{
    int key;
    key = num % 10;
    return key;
}

void Hash :: linear_probing(int key, int num)
{
    int flag, i, count = 0;
    flag = 0;   //initially zero 

    if(a[key] == -1)
        a[key] = num;

    else
    {
        i = 0;
        while(i<MAX)
        {
            if(a[i] != -1)
            count ++;
            i++;
        }

        if(count == MAX)
        {
            cout<<"Table is full : ";
            display();
            exit(1);
        }

        for(i = key + 1; i<MAX; i++)
            if(a[i]== -1)
            {
                a[i] == num; 
                flag = 1;       // when the ele is entered
                break;
            }

    //From key position to end searched
    //Now we want to check empty lication in the upper part of the array

        for(i=0; i<key && flag == 0; i++)
            if(a[i == -1])
            {
                a[i] = num;
                flag = 1;      // when the ele is entered
                break; 
            }
    }
}

void Hash::quadratic_probing(int key, int num)
{
    int i = 0, position;

    if(a[key] == -1)
    {
        a[key] = num;
    }
    else
    {
        while(i < MAX)
        {
            position = key + (i * i);
            position = position % MAX;

            if(a[position] == -1)
            {
                a[position] = num;
                break;
            }
            i++;
        }
    }
}

int Hash :: display()
{
    int i;
    cout<<"The hash table is : ";
    for(i=0; i<MAX; i++)
    cout<<"\n "<< i <<" "<<a[i];
}

int main()
{
    int num,key,choi;
    char ans;
    Hash h;
    
    cout<<"\nCollision handling";
    do
    {
        cout<<"\nEnter the telephone number : ";
        cin>>num;

        key = h.create(num);

        cout<<"1 : Linear probing\n2 : Quadratic probing\n";
        cin>>choi;

        if(choi == 1)
            {h.linear_probing(key, num);}
        else
            {h.quadratic_probing(key, num);}         //

        cout<<"\nDo you want to continue? (y = 1/n = 0) : ";
        cin>>ans;

    }while(ans == '1');

    h.display();

    return 0;
}
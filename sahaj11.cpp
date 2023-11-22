/*
    Problem Statement:
    Department maintains a student information. The file contains roll number, name,
    division and address. Allow user to add, delete information of student. Display
    information of particular employee. If record of student does not exist an appropriate
    message is displayed. If it is, then the system displays the student details. Use
    sequential file to main the data.
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class EMP_CLASS     
{
    typedef struct EMPLOYEE
    {
        char name[10];
        int emp_id;
        int salary;
    }Rec;
    Rec Records;    //structure object

public:
    void Create();
    void Display();
    // void Update();
    void Delete();
    void Append();
    int Search();
};

void EMP_CLASS::Create()
{
    char ch = 'y';
    ofstream seqfile;
    seqfile.open("EMP.DAT", ios::binary);
    do
    {
        cout << "\n Enter Name: ";
        cin >> Records.name;
        cout << " Enter Emp_ID: ";
        cin >> Records.emp_id;
        cout << " Enter Salary: ";
        cin >> Records.salary;
        seqfile.write(reinterpret_cast<char*>(&Records), sizeof(Records));   //inside the whileloop
        cout << "\nDo you want to add more records? (y/n): ";
        cin >> ch;
    } while (ch == 'y');
    seqfile.close();
}

void EMP_CLASS::Display()
{
    ifstream seqfile;
    seqfile.open("EMP.DAT", ios::binary);
    if (!seqfile)
    {
        cout << "\n File does not exist or cannot be opened.";
        return;
    }
    cout << "\n The Contents of the file are:\n";
    while (seqfile.read(reinterpret_cast<char*>(&Records), sizeof(Records)))
    {
        if (Records.emp_id != -1)
        {
            cout << "\nName: " << Records.name;
            cout << "\nEmp_ID: " << Records.emp_id;
            cout << "\nSalary: " << Records.salary;
            cout << "\n";
        }
    }
    seqfile.close();
}

void EMP_CLASS::Delete()
{
    int id, pos;
    cout << "\n For deletion,";
    fstream seqfile;
    seqfile.open("EMP.DAT", ios::in | ios::out | ios::binary);
    if (!seqfile)
    {
        cout << "\n File does not exist or cannot be opened.";
        return;
    }
    pos = Search();
    if (pos == -1)
    {
        cout << "\n The record is not present in the file";
        seqfile.close();
        return;
    }
    int offset = pos * sizeof(Rec);
    seqfile.seekp(offset);
    strcpy(Records.name, "");
    Records.emp_id = -1;
    Records.salary = -1;
    seqfile.write(reinterpret_cast<char*>(&Records), sizeof(Records));
    seqfile.close();
    cout << "\n The record is deleted!";
}

void EMP_CLASS::Append()
{
    fstream seqfile;
    seqfile.open("EMP.DAT", ios::app | ios::binary);   //append mde
    if (!seqfile)
    {
        cout << "\n File does not exist or cannot be opened.";
        return;
    }
    cout << "\n Enter the record for appending : \n";
    cout << "Name: ";
    cin >> Records.name;
    cout << "Emp_ID: ";
    cin >> Records.emp_id;
    cout << "Salary: ";
    cin >> Records.salary;
    seqfile.write(reinterpret_cast<char*>(&Records), sizeof(Records));
    seqfile.close();
    cout << "\n The record is appended!";
}

int EMP_CLASS :: Search()
{
    ifstream seqfile;
    int id, pos;
    cout << "\n Enter the Emp_ID for searching the record: ";
    cin >> id;
    seqfile.open("EMP.DAT", ios::binary);
    if (!seqfile)
    {
        cout << "\n File does not exist or cannot be opened.";
        return -1;
    }
    pos = -1;
    int i = 0;  //start 
    while (seqfile.read(reinterpret_cast<char*>(&Records), sizeof(Records)))
    {
        if (id == Records.emp_id)
        {
            pos = i;   //end
            break;
        }
        i++;  //increment
    }
    seqfile.close();
    return pos;
}

int main()
{
    EMP_CLASS List;
    char ans = 'y';
    int choice, key;

    do
    {
        cout << "\n             Main Menu             \n";
        cout << "\n 1. Create";
        cout << "\n 2. Display";
        //cout << "\n 3. Update";
        cout << "\n 4. Delete";
        cout << "\n 5. Append";
        cout << "\n 6. Search";
        cout << "\n 7. Exit\n";

        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                List.Create();
                break;
            case 2:
                List.Display();
                break;
            // case 3:
            //     List.Update();
            //     break;
            case 4:
                List.Delete();
                break;
            case 5:
                List.Append();
                break;
            case 6:
                key = List.Search();
                if (key < 0)
                    cout << "\n Record is not present in the file";
                else
                    cout << "\n Record is present in the file";
                break;
            case 7:
                exit(0);
        }

        cout << "\n\n Do you want to go back to the Main Menu? (y/n): ";
        cin >> ans;
    } while (ans == 'y');

    return 0;
}

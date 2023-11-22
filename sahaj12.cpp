/*
Company maintains employee information as employee ID, name, designation and salary. 
Allow  user  to  add,  delete  information  of  employee.  Display  information  of  particular 
employee.  If  employee  does  not  exist  an  appropriate  message  is  displayed.  If  it  is,  then 
the system displays the employee details. Use index sequential file to maintain the data.
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class EMP_CLASS
{
    struct EMPLOYEE
    {
        char name[10];
        int emp_id;
        int salary;
    } Records;

    struct INDEX
    {
        int emp_id;
        int position;
    } Ind_Rec;

public:
    void Create();
    void Display();
    //void Update();
    void Delete();
    void Append();
    void Search();
};

void EMP_CLASS::Create()
{
    int i = 0;
    char ch = 'y';
    fstream seqfile;
    fstream indexfile;

    seqfile.open("EMP.DAT", ios::out | ios::binary);
    indexfile.open("IND.DAT", ios::out | ios::binary);

    do
    {
        cout << "\nEnter Name: ";
        cin >> Records.name;
        cout << "Enter Emp_ID: ";
        cin >> Records.emp_id;
        cout << "Enter Salary: ";
        cin >> Records.salary;

        seqfile.write(reinterpret_cast<char *>(&Records), sizeof(Records));
        Ind_Rec.emp_id = Records.emp_id;
        Ind_Rec.position = i;  //positoin from 0
        indexfile.write(reinterpret_cast<char *>(&Ind_Rec), sizeof(Ind_Rec));

        i++;

        cout << "\nDo you want to add more records? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    seqfile.close();
    indexfile.close();
}

void EMP_CLASS::Display()
{
    fstream seqfile;
    fstream indexfile;

    seqfile.open("EMP.DAT", ios::in | ios::binary);
    indexfile.open("IND.DAT", ios::in | ios::binary);

    if (!seqfile || !indexfile)
    {
        cout << "\nError opening file!";
        return;
    }

    cout << "\nThe contents of the file are:\n";

    while (indexfile.read(reinterpret_cast<char *>(&Ind_Rec), sizeof(Ind_Rec)))   //read is befour
    {
        if (Ind_Rec.emp_id != -1)
        {
            //seqfile.seekg(Ind_Rec.position * sizeof(Records));//ind_rec in seqfile
            seqfile.read(reinterpret_cast<char *>(&Records), sizeof(Records));

            cout << "\nName: " << Records.name;
            cout << "\nEmp_ID: " << Records.emp_id;
            cout << "\nSalary: " << Records.salary;
            cout << "\n";
        }
    }

    seqfile.close();
    indexfile.close();
}

/*
void EMP_CLASS::Update()
{
    int id, pos = -1;
    cout << "\nFor updation,";
    cout << "\nEnter the Emp_ID for searching: ";
    cin >> id;

    fstream seqfile;
    fstream indexfile;

    seqfile.open("EMP.DAT", ios::in | ios::out | ios::binary);
    indexfile.open("IND.DAT", ios::in | ios::out | ios::binary);

    if (!seqfile || !indexfile)
    {
        cout << "\nError opening file!";
        return;
    }

    while (indexfile.read(reinterpret_cast<char *>(&Ind_Rec), sizeof(Ind_Rec)))
    {
        if (id == Ind_Rec.emp_id)
        {
            pos = Ind_Rec.position;
            break;
        }
    }

    if (pos != -1)
    {
        pos = pos * sizeof(Records);
        seqfile.seekp(pos);
        seqfile.read(reinterpret_cast<char *>(&Records), sizeof(Records));

        cout << "\nName: " << Records.name;
        cout << "\nEmp_ID: " << Records.emp_id;
        cout << "\nSalary: " << Records.salary;

        cout << "\n\nEnter new details:\n";
        cout << "\nEnter Name: ";
        cin >> Records.name;
        cout << "Enter Salary: ";
        cin >> Records.salary;

        seqfile.seekp(pos);
        seqfile.write(reinterpret_cast<char *>(&Records), sizeof(Records));
    }
    else
    {
        cout << "\nRecord not found!";
    }

    seqfile.close();
    indexfile.close();
}*/

void EMP_CLASS::Delete()
{
    int id, pos = -1;
    cout << "\nFor deletion,";
    cout << "\nEnter the Emp_ID for searching: ";
    cin >> id;

    fstream seqfile;
    fstream indexfile;

    seqfile.open("EMP.DAT", ios::in | ios::out | ios::binary);
    indexfile.open("IND.DAT", ios::in | ios::out | ios::binary);

    if (!seqfile || !indexfile)
    {
        cout << "\nError opening file!";
        return;
    }

    while (indexfile.read(reinterpret_cast<char *>(&Ind_Rec), sizeof(Ind_Rec)))
    {
        if (id == Ind_Rec.emp_id)
        {
            pos = Ind_Rec.position;
            break;
        }
    }

    if (pos != -1)
    {
        pos = pos * sizeof(Records);
        seqfile.seekp(pos);
        seqfile.read(reinterpret_cast<char *>(&Records), sizeof(Records));

        cout << "\nName: " << Records.name;
        cout << "\nEmp_ID: " << Records.emp_id;
        cout << "\nSalary: " << Records.salary;

        Records.emp_id = -1; // Mark as deleted
        Ind_Rec.emp_id = -1;

        seqfile.seekp(pos);
        seqfile.write(reinterpret_cast<char *>(&Records), sizeof(Records));

        cout << "\nRecord deleted!";
    }
    else
    {
        cout << "\nRecord not found!";
    }

    seqfile.close();
    indexfile.close();
}

void EMP_CLASS::Append()
{
    char ch = 'y';
    fstream seqfile;
    fstream indexfile;

    seqfile.open("EMP.DAT", ios::app | ios::binary);
    indexfile.open("IND.DAT", ios::app | ios::binary);

    if (!seqfile || !indexfile)
    {
        cout << "\nError opening file!";
        return;
    }

    do
    {
        cout << "\nEnter Name: ";
        cin >> Records.name;
        cout << "Enter Emp_ID: ";
        cin >> Records.emp_id;
        cout << "Enter Salary: ";
        cin >> Records.salary;

        seqfile.write(reinterpret_cast<char *>(&Records), sizeof(Records)); // in main file
        Ind_Rec.emp_id = Records.emp_id;
        Ind_Rec.position = -1; // Append records are marked with -1 position
        indexfile.write(reinterpret_cast<char *>(&Ind_Rec), sizeof(Ind_Rec)); // in index file 

        cout << "\nDo you want to add more records? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    seqfile.close();
    indexfile.close();
}

void EMP_CLASS::Search()
{
    int id, pos = -1;
    cout << "\nEnter the Emp_ID for searching: ";
    cin >> id;

    fstream seqfile;
    fstream indexfile;

    seqfile.open("EMP.DAT", ios::in | ios::binary);
    indexfile.open("IND.DAT", ios::in | ios::binary);

    if (!seqfile || !indexfile)
    {
        cout << "\nError opening file!";
        return;
    }

    while (indexfile.read(reinterpret_cast<char *>(&Ind_Rec), sizeof(Ind_Rec)))
    {
        if (id == Ind_Rec.emp_id)
        {
            pos = Ind_Rec.position;  //read position from index file and read in seqfile
            break;
        }
    }

    if (pos != -1)
    {
        pos = pos * sizeof(Records);
        seqfile.seekg(pos);
        seqfile.read(reinterpret_cast<char *>(&Records), sizeof(Records));

        cout << "\nName: " << Records.name;
        cout << "\nEmp_ID: " << Records.emp_id;
        cout << "\nSalary: " << Records.salary;
    }
    else
    {
        cout << "\nRecord not found!";
    }

    seqfile.close();
    indexfile.close();
}

int main()
{
    EMP_CLASS emp;
    int choice;

    do
    {
        cout << "\n*** EMPLOYEE DATABASE ***";
        cout << "\n1. Create";
        cout << "\n2. Display";
        //cout << "\n3. Update";
        cout << "\n4. Delete";
        cout << "\n5. Append";
        cout << "\n6. Search";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                emp.Create();
                break;

            case 2:
                emp.Display();
                break;

            //case 3:
            //    emp.Update();
            //    break;

            case 4:
                emp.Delete();
                break;

            case 5:
                emp.Append();
                break;

            case 6:
                emp.Search();
                break;

            case 7:
                cout << "\nExiting...";
                break;

            default:
                cout << "\nInvalid choice!";
        }
    } while (choice != 7);

    return 0;
}

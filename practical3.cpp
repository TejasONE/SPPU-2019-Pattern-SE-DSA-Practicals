/*
implempnt all the functions of a dictionary(ADT) using hashing and handel collision using linked list. 
data :set of (key, value)pairs , keys are mapped to value, keys must be comparable ,keys must be unique, 
str=andard operations: insert(key, value), find(key), delete(key)
*/ 

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Data 
{
    char name[30];
    char meaning[30];
    Data *next;
};

class HashTable 
{
private:
    static const int TABLE_SIZE = 10;
    Data* table[TABLE_SIZE];

public:
    HashTable() 
    {
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
            table[i] = nullptr;   //fill every INDEX with nullptr
        }
    }

    int hashFunction(const char* key) 
    {
        int sum = 0;
        for (int i = 0; key[i] != '\0'; i++) //key is name
        {
            sum = sum + key[i]; // add one one later
        }
        return sum % TABLE_SIZE;
    }

    void insert(const char* key, const char* value) 
    {
        int index = hashFunction(key);
        Data* newNode = new Data;
        strncpy(newNode->name, key, 29);     //The strncpy() function copies count characters of string2 to string1
        strncpy(newNode->meaning, value, 29);
        //newNode->name[29] = '\0';
        //newNode->meaning[29] = '\0';

        if (table[index] == nullptr) 
        {
            table[index] = newNode;
        } 
        else //collision
        {
            Data* currentNode = table[index];  //go further from that index
            while (currentNode->next != nullptr) 
            {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }

    Data* search(const char* key) 
    {
        int index = hashFunction(key);
        Data* currentNode = table[index];

        while (currentNode != nullptr) 
        {
            if (strcmp(currentNode->name, key) == 0) 
            {
                return currentNode;
            }
            currentNode = currentNode->next;
        }

        return nullptr;
    }

    void remove(const char* key) 
    {
        int index = hashFunction(key);
        Data* currentNode = table[index];
        Data* previousNode = nullptr;

        while (currentNode != nullptr) 
        {
            if (strcmp(currentNode->name, key) == 0) 
            {
                if (previousNode == nullptr) 
                {
                    table[index] = currentNode->next;
                } 
                else 
                {
                    previousNode->next = currentNode->next;
                }
                delete currentNode;
                return;
            }
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }

    void display() 
    {
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
            Data* currentNode = table[i];
            while (currentNode != nullptr) 
            {
                cout << currentNode->name << ": " << currentNode->meaning << std::endl;
                currentNode = currentNode->next;
            }
        }
    }

    ~HashTable() 
    {
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
            Data* currentNode = table[i];
            while (currentNode != nullptr) 
            {
                Data* temp = currentNode;
                currentNode = currentNode->next;
                delete temp;
            }
        }
    }
};

int main() 
{
    HashTable dictionary;
    int choice;
    char key[30], value[30];

    while (true) 
    {
        cout << "\n\nEnter your choice:\n";
        cout << "1. Insert a word and its meaning\n";
        cout << "2. Find the meaning of a word\n";
        cout << "3. Delete a word\n";
        cout << "4. Display the dictionary\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter the word: ";
                cin >> key;
                cout << "Enter the meaning: ";
                cin >> value;
                dictionary.insert(key, value);
                break;
            case 2:
                cout << "Enter the word to find its meaning: ";
                cin >> key;
                {
                    Data* result = dictionary.search(key);
                    if (result != nullptr) 
                    {
                        cout << "Meaning: " << result->meaning << std::endl;
                    } 
                    else 
                    {
                        cout << "Word not found in the dictionary." << std::endl;
                    }
                }
                break;
            case 3:
                cout << "Enter the word to delete: ";
                cin >> key;
                dictionary.remove(key);
                break;
            case 4:
                dictionary.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

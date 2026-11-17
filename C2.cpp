
#include <iostream>
using namespace std;

int table[10];

void insert(int k)
{
    int i = k % 10;

    for(int j = 0; j < 10; j++)
    {
        int p = (i + j) % 10;

        if(table[p] == -1 || table[p] == -2)
        {
            table[p] = k;
            cout << "Inserted";
            return;
        }
    }

    cout << "Table full";
}

void search(int k)
{
    int i = k % 10;

    for(int j = 0; j < 10; j++)
    {
        int p = (i + j) % 10;

        if(table[p] == -1)
            break;

        if(table[p] == k)
        {
            cout << "Found";
            return;
        }
    }

    cout << "Not found";
}

void deleteKey(int k)
{
    int i = k % 10;

    for(int j = 0; j < 10; j++)
    {
        int p = (i + j) % 10;

        if(table[p] == -1)
            break;

        if(table[p] == k)
        {
            table[p] = -2;
            cout << "Deleted";
            return;
        }
    }

    cout << "Not found";
}

void display()
{
    for(int i = 0; i < 10; i++)
    {
        if(table[i] >= 0)
            cout << i << " : " << table[i] << endl;
        else
            cout << i << " : Empty" << endl;
    }
}

int main()
{
    for(int i = 0; i < 10; i++)
        table[i] = -1;

    int ch, k;

    do
    {
        cout << "\n1.Insert 2.Search 3.Delete 4.Display 5.Exit\n";
        cin >> ch;

        if(ch >= 1 && ch <= 3)
        {
            cout << "Enter key: ";
            cin >> k;
        }

        if(ch == 1) insert(k);
        else if(ch == 2) search(k);
        else if(ch == 3) deleteKey(k);
        else if(ch == 4) display();

    } while(ch != 5);

    return 0;
}


#include <iostream>
using namespace std;

struct Node
{
    int roll, marks;
    string name;
    Node* next;
};

Node* head = NULL;

void add()
{
    Node* n = new Node;

    cout << "Enter Roll No, Name and Marks: ";
    cin >> n->roll >> n->name >> n->marks;

    n->next = NULL;

    if(head == NULL)
        head = n;
    else
    {
        Node* t = head;
        while(t->next != NULL)
            t = t->next;

        t->next = n;
    }
}

void display()
{
    Node* t = head;

    while(t != NULL)
    {
        cout << t->roll << " "
             << t->name << " "
             << t->marks << endl;

        t = t->next;
    }
}

void search()
{
    int r;
    cout << "Enter Roll No: ";
    cin >> r;

    Node* t = head;

    while(t != NULL)
    {
        if(t->roll == r)
        {
            cout << t->roll << " "
                 << t->name << " "
                 << t->marks;
            return;
        }

        t = t->next;
    }

    cout << "Student not found";
}

void update()
{
    int r;
    cout << "Enter Roll No: ";
    cin >> r;

    Node* t = head;

    while(t != NULL)
    {
        if(t->roll == r)
        {
            cout << "Enter new Name and Marks: ";
            cin >> t->name >> t->marks;
            cout << "Record updated";
            return;
        }

        t = t->next;
    }

    cout << "Student not found";
}

void deleteRecord()
{
    int r;
    cout << "Enter Roll No: ";
    cin >> r;

    Node *t = head, *prev = NULL;

    while(t != NULL && t->roll != r)
    {
        prev = t;
        t = t->next;
    }

    if(t == NULL)
        cout << "Student not found";
    else
    {
        if(prev == NULL)
            head = t->next;
        else
            prev->next = t->next;

        delete t;
        cout << "Record deleted";
    }
}

void sort()
{
    Node *i, *j;
    int r, m;
    string n;

    for(i = head; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->marks > j->marks)
            {
                r = i->roll;
                i->roll = j->roll;
                j->roll = r;

                m = i->marks;
                i->marks = j->marks;
                j->marks = m;

                n = i->name;
                i->name = j->name;
                j->name = n;
            }
        }
    }

    cout << "Records sorted by marks";
}

int main()
{
    int ch;

    do
    {
        cout << "\n1.Add  2.Delete  3.Update";
        cout << "\n4.Search  5.Sort  6.Display  7.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1: add(); break;
            case 2: deleteRecord(); break;
            case 3: update(); break;
            case 4: search(); break;
            case 5: sort(); break;
            case 6: display(); break;
            case 7: cout << "Exiting"; break;
            default: cout << "Invalid choice";
        }

    } while(ch != 7);

    return 0;
}

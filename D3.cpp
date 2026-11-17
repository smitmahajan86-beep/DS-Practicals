
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void display(Node* root)
{
    if(root != NULL)
    {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

void search(Node* root, int value)
{
    if(root == NULL)
        cout << "Value not found";
    else if(root->data == value)
        cout << "Value found";
    else if(value < root->data)
        search(root->left, value);
    else
        search(root->right, value);
}

Node* findMin(Node* root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int value)
{
    if(root == NULL)
        return root;

    if(value < root->data)
        root->left = deleteNode(root->left, value);

    else if(value > root->data)
        root->right = deleteNode(root->right, value);

    else
    {
        if(root->left == NULL)
            return root->right;

        else if(root->right == NULL)
            return root->left;

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main()
{
    Node* root = NULL;
    int choice, value;

    do
    {
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Search";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insert(root, value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                root = deleteNode(root, value);
                break;

            case 3:
                cout << "BST: ";
                display(root);
                break;

            case 4:
                cout << "Enter value: ";
                cin >> value;
                search(root, value);
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 5);

    return 0;
}


#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<string> undoStack, redoStack;
    string doc = "", change;
    int ch;

    do
    {
        cout << "\n1.Make Change";
        cout << "\n2.Undo";
        cout << "\n3.Redo";
        cout << "\n4.Display";
        cout << "\n5.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                undoStack.push(doc);
                redoStack = stack<string>();

                cout << "Enter new text: ";
                cin.ignore();
                getline(cin, change);

                doc = doc + change;
                break;

            case 2:
                if(!undoStack.empty())
                {
                    redoStack.push(doc);
                    doc = undoStack.top();
                    undoStack.pop();
                }
                else
                    cout << "Nothing to undo\n";
                break;

            case 3:
                if(!redoStack.empty())
                {
                    undoStack.push(doc);
                    doc = redoStack.top();
                    redoStack.pop();
                }
                else
                    cout << "Nothing to redo\n";
                break;

            case 4:
                cout << "Document: " << doc << endl;
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(ch != 5);

    return 0;
}

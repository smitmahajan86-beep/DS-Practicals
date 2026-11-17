
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<string> q;
    string event, name;
    int ch;

    do
    {
        cout << "\n1. Add Event";
        cout << "\n2. Process Event";
        cout << "\n3. Display Events";
        cout << "\n4. Cancel Event";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Enter event: ";
                cin.ignore();
                getline(cin, event);
                q.push(event);
                cout << "Event added";
                break;

            case 2:
                if(!q.empty())
                {
                    cout << "Processed: " << q.front();
                    q.pop();
                }
                else
                    cout << "Queue is empty";
                break;

            case 3:
                if(q.empty())
                    cout << "No pending events";
                else
                {
                    queue<string> temp = q;

                    while(!temp.empty())
                    {
                        cout << temp.front() << endl;
                        temp.pop();
                    }
                }
                break;

            case 4:
                cout << "Enter event to cancel: ";
                cin.ignore();
                getline(cin, name);

                {
                    queue<string> temp;
                    bool found = false;

                    while(!q.empty())
                    {
                        if(q.front() == name && !found)
                            found = true;
                        else
                            temp.push(q.front());

                        q.pop();
                    }

                    q = temp;

                    if(found)
                        cout << "Event cancelled";
                    else
                        cout << "Event not found";
                }
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(ch != 5);

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

struct Bucket
{
    int depth = 1;
    vector<int> keys;
};

int gd = 1;
vector<Bucket*> dir(2);

int hashKey(int k)
{
    return k & ((1 << gd) - 1);
}

void insert(int k)
{
    Bucket* b = dir[hashKey(k)];

    for(int x : b->keys)
        if(x == k) { cout << "Exists"; return; }

    if(b->keys.size() < 2)
    {
        b->keys.push_back(k);
        cout << "Inserted";
        return;
    }

    if(b->depth == gd)
    {
        int n = dir.size();
        for(int i = 0; i < n; i++)
            dir.push_back(dir[i]);
        gd++;
    }

    Bucket* nb = new Bucket;
    nb->depth = b->depth + 1;
    b->depth++;

    int bit = 1 << (b->depth - 1);

    for(int i = 0; i < dir.size(); i++)
        if(dir[i] == b && (i & bit))
            dir[i] = nb;

    vector<int> temp = b->keys;
    b->keys.clear();

    for(int x : temp) insert(x);
    insert(k);
}

void search(int k)
{
    Bucket* b = dir[hashKey(k)];

    for(int x : b->keys)
        if(x == k) { cout << "Found"; return; }

    cout << "Not found";
}

void deleteKey(int k)
{
    Bucket* b = dir[hashKey(k)];

    for(int i = 0; i < b->keys.size(); i++)
        if(b->keys[i] == k)
        {
            b->keys.erase(b->keys.begin() + i);
            cout << "Deleted";
            return;
        }

    cout << "Not found";
}

int main()
{
    for(int i = 0; i < 2; i++)
        dir[i] = new Bucket;

    int ch, k;

    do
    {
        cout << "\n1.Insert 2.Search 3.Delete 4.Exit\n";
        cin >> ch;

        if(ch >= 1 && ch <= 3)
        {
            cout << "Enter key: ";
            cin >> k;
        }

        if(ch == 1) insert(k);
        else if(ch == 2) search(k);
        else if(ch == 3) deleteKey(k);

    } while(ch != 4);

    return 0;
}


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int graph[5][5] = {
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,0,1},
    {0,1,0,0,0},
    {0,0,1,0,0}
};

int visited[5] = {0};

void DFS(int v)
{
    cout << char(v + 'A') << " ";
    visited[v] = 1;

    for(int i = 0; i < 5; i++)
        if(graph[v][i] == 1 && visited[i] == 0)
            DFS(i);
}

int main()
{
    vector<int> adj[5];

    adj[0] = {1,2};
    adj[1] = {0,2,3};
    adj[2] = {0,1,4};
    adj[3] = {1};
    adj[4] = {2};

    cout << "DFS: ";
    DFS(0);

    for(int i = 0; i < 5; i++)
        visited[i] = 0;

    queue<int> q;
    q.push(0);
    visited[0] = 1;

    cout << "\nBFS: ";

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        cout << char(v + 'A') << " ";

        for(int i : adj[v])
        {
            if(visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}

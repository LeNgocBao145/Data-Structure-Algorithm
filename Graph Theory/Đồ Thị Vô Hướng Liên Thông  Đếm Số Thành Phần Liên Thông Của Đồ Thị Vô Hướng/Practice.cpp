#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& adjacent, bool visited[], int n)
{
    cout << n << " ";

    visited[n] = true;

    for(int i = 0; i < adjacent[n].size(); i++)
    {
        if(visited[adjacent[n][i]] == false)
        {
            DFS(adjacent, visited, adjacent[n][i]);
        }
    }
}

//True connected graph
// 10 10
// 1 2
// 2 3 
// 2 4
// 3 6 
// 3 7 
// 6 7
// 3 8
// 5 8
// 8 9
// 5 10

//False connected graph
// 10 8
// 1 2
// 2 3 
// 2 4
// 3 6
// 3 7
// 6 7
// 5 8
// 8 9

void connectedGraph()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacent(n + 1);

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
       adjacent[x].push_back(y);
       adjacent[y].push_back(x);
    }

    bool visited[n] = {false};

    int count = 0;

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            count++;
            cout << "Connected Graph " << count << ": ";
            DFS(adjacent, visited, i);
            cout << endl;
        }
    }

    cout << endl;

    cout << "Quantity of connected graph: " << count;
}

int main()
{
    connectedGraph();
    return 0;
}
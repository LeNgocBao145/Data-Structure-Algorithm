#include <iostream>
#include <vector>

using namespace std;

// 9 10
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 5 8
// 6 7
// 8 9
// 9 3

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

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacent(m);

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
       adjacent[x].push_back(y);
    }

    bool visited[n] = {false};
    DFS(adjacent, visited, 1);
    return 0;
}
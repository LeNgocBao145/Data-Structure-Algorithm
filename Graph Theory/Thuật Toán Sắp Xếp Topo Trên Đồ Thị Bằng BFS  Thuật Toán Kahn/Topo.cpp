#include <iostream>
#include <vector>

using namespace std;

//Topo Algorithm

void DFS(vector<vector<int>>& adjacent, bool visited[], vector<int>& topo, int v)
{
    visited[v] = true;

    for(int i = 0; i < adjacent[v].size(); i++)
    {
        if(!visited[adjacent[v][i]])
        {
            DFS(adjacent, visited, topo, adjacent[v][i]);
            topo.push_back(adjacent[v][i]);
        }
    }
}

// 7 7 
// 1 2 
// 1 6
// 2 3
// 2 4
// 3 5
// 4 5
// 7 6

void sortTopo()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> adjacent(n + 1);
    bool* visited = new bool[n + 1];
    fill(visited, visited + n + 1, 0);

    vector<int> topo;

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adjacent[x].push_back(y);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            DFS(adjacent, visited, topo, i);
            topo.push_back(i);
        }
    }


    for(int i = topo.size() - 1; i >= 0; i--)
    {
        cout << topo[i] << " ";
    }

    delete[] visited;
}

int main()
{
    sortTopo();
    return 0;
}
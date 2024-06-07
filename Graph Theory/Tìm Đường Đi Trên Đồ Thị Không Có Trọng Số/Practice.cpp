#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>>& adjacent, bool visited[], int parent[], int u)
{
    visited[u] = true;

    for(int i = 0; i < adjacent[u].size(); i++)
    {
        if(!visited[adjacent[u][i]])
        {
            parent[adjacent[u][i]] = u;
            DFS(adjacent, visited, parent, adjacent[u][i]);
        }
    }
}

void BFS(vector<vector<int>>& adjacent, bool visited[], int parent[], int u)
{
    queue<int> nums;
    nums.push(1);
    visited[1] = true;

    while(!nums.empty())
    {

        int v = nums.front();
        nums.pop();
        visited[v] = true;

        for(int i = 0; i < adjacent[v].size(); i++)
        {
            if(!visited[adjacent[v][i]])
            {
                nums.push(adjacent[v][i]);
                visited[adjacent[v][i]] = true;
                parent[adjacent[v][i]] = v;
            }
        }
    }
}

//Non-route graph
// 10 8
// 1 2
// 2 3
// 2 4
// 3 6
// 3 7
// 5 8
// 6 7
// 8 9

//Route graph
// 10 10
// 1 2
// 2 3
// 2 4
// 3 6
// 3 7
// 6 7
// 7 5
// 5 8
// 5 10
// 8 9
// 1 8



//Find a way from s to t in a graph
void findWayPath()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacent(n + 1);

    bool *visited = new bool[n + 1];
    int *parent = new int[n + 1];

    fill(parent, parent + n + 1, 0);
    fill(visited, visited + n + 1, 0);

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjacent[x].push_back(y);
        //adjacent[y].push_back(x);
    }

    int s, t;
    cin >> s >> t;

    BFS(adjacent, visited, parent, s);

    if(!visited[t])
    {
        cout << "There is no path from s to t" << endl;
    }
    else
    {
        vector<int> path;

        while(s != t)
        {

            path.push_back(t);

            t = parent[t];
        }

        path.push_back(s);
        reverse(path.begin(), path.end());

        for(int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }

        cout << endl;
    }

    delete[] parent;
    delete[] visited;
}

int main()
{
    findWayPath();

    return 0;
}
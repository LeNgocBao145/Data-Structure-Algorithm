#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 10 11
// 1 2
// 1 3
// 1 10
// 2 4
// 3 5  
// 3 6
// 5 8
// 5 10
// 6 7
// 7 3
// 8 9


void DFS(vector<vector<int>>& adjacent, queue<int> nums, bool visited[])
{
    while(!nums.empty())
    {
        int u = nums.front();
        cout << u << " ";
        nums.pop();

        for(int i = 0; i < adjacent[u].size(); i++)
        {
            if(!visited[adjacent[u][i]])
            {
                nums.push(adjacent[u][i]);
                visited[adjacent[u][i]] = true;
            }
        }
    }
}

int main()
{
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacent(n + 1);

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
       adjacent[x].push_back(y);
       //adjacent[y].push_back(x);
    }

    bool visited[n] = {false};
    
    queue<int> nums;

    nums.push(1);
    visited[1] = true;
    DFS(adjacent, nums, visited);
    
    return 0;
}
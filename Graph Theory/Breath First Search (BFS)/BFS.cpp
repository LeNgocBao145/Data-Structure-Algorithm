#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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


void BFS(vector<vector<int>>& adjacent, queue<int> nums, bool visited[])
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

//sort value before add to queue
void advBFS(vector<vector<int>>& adjacent, queue<int> nums, bool visited[])
{
    while(!nums.empty())
    {
        int u = nums.front();
        cout << u << " ";
        nums.pop();
        vector<int>sortNum;

        for(int i = 0; i < adjacent[u].size(); i++)
        {
            if(!visited[adjacent[u][i]])
            {
                sortNum.push_back(adjacent[u][i]);
                //nums.push(adjacent[u][i]);
                visited[adjacent[u][i]] = true;
            }
        }

        sort(sortNum.begin(), sortNum.end());

        for(int i = 0; i < sortNum.size(); i++)
        {
            nums.push(sortNum[i]);
        }
    }
}

// 7 13
// 1 2
// 1 3
// 1 5
// 1 4
// 2 3
// 2 6
// 3 7
// 3 4
// 3 5
// 3 6
// 4 5
// 4 7
// 7 6

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
       adjacent[y].push_back(x);
    }

    bool visited[n] = {false};
    
    queue<int> nums;

    nums.push(5);
    visited[5] = true;
    advBFS(adjacent, nums, visited);
    
    return 0;
}
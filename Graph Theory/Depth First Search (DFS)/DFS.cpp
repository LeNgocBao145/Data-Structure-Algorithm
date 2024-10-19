#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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

//Output: 1 2 4 3 6 7 5 8 9

// 6 8
// 1 2
// 1 4
// 1 5
// 2 3
// 2 5
// 3 5
// 4 5
// 3 6


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

//Using stack (more efficient)

void advDFS(vector<vector<int>>& adjacent, int n)
{
    stack<int> nums;
    nums.push(n);
    vector<int> ans;
    vector<bool> visited(n, false);

    while(!nums.empty())
    {
        int tmp = nums.top();
        nums.pop();
        if(!visited[tmp])
        {       
            ans.push_back(tmp);
            visited[tmp] = true;
            vector<int> sortNum;
            for(int i = 0; i < adjacent[tmp].size(); i++)
            {
                sortNum.push_back(adjacent[tmp][i]);
            }

            sort(sortNum.begin(), sortNum.end());

            for(int i = sortNum.size() - 1; i >= 0; i--)
            {
                nums.push(sortNum[i]);
            }
        }
    }

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
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
    //DFS(adjacent, visited, 1);
    advDFS(adjacent, 1);
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

//Kahn Algorithm

// 7 7 
// 1 2 
// 1 6
// 2 3
// 2 4
// 3 5
// 4 5
// 7 6

//Output: 1 7 2 6 3 4 5

void Kahn()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> adjacent(n + 1);
    
    int seque[n + 1];
    fill(seque, seque + n + 1, 0);

    queue<int> kahn;

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adjacent[x].push_back(y);
        seque[y]++;
    }

    vector<int> nums;

    for(int i = 1; i <= n; i++)
    {
        if(seque[i] == 0)
        {
            kahn.push(i);
        }
    }


    while(!kahn.empty())
    {
        int v = kahn.front();
        kahn.pop();
        nums.push_back(v);

        for(int i = 0; i < adjacent[v].size(); i++)
        {
            seque[adjacent[v][i]]--;
            if(seque[adjacent[v][i]] == 0)
            {
                kahn.push(adjacent[v][i]);
            }
        }
    }

    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    
}

int main()
{
    Kahn();
    return 0;
}
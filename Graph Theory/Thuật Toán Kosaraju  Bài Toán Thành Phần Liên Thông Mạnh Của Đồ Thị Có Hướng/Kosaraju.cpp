#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//B1: Goi thuat toan DFS tren do thi ban dau va luu thu tu duyet cac dinh vao 1 stack
//B2: Xay dung do thi lat nguoc cua do thi ban dau: Transpose graph
//B3: Lan luot pop cac dinh trong stack o buoc 1 va goi thuat toan DFS de liet ke cac thanh phan lien thong manh
//  Strongly Connected Component
//  O(2 * (V + E))

void DFS1(vector<vector<int>>& adjacent, bool visited[], stack<int>& copy, int v)
{
    visited[v] = true;

    for(int i = 0; i < adjacent[v].size(); i++)
    {
        if(!visited[adjacent[v][i]])
        {
            DFS1(adjacent, visited, copy, adjacent[v][i]);
        }
    }

    copy.push(v);
}

void DFS2(vector<vector<int>>& r_adjacent, bool visited2[], int v)
{
    visited2[v] = true;

    cout << v << " ";

    for(int i = 0; i < r_adjacent[v].size(); i++)
    {
        if(!visited2[r_adjacent[v][i]])
        {
            DFS2(r_adjacent, visited2, r_adjacent[v][i]);
        }
    }

}

//#1
// 8 9
// 1 2
// 2 3
// 3 4
// 4 1
// 3 5 
// 5 6
// 6 7
// 7 8
// 8 6

//#2
// 5 3
// 1 2
// 2 3
// 4 5

//#3
// 8 10
// 1 2
// 2 3
// 3 1
// 2 4
// 4 5
// 5 6
// 6 4
// 6 7
// 7 8
// 8 6

// 6 7
// 1 2
// 2 3
// 3 1
// 3 4
// 4 5
// 5 6
// 6 4


void findStronglyConnectedComponent()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> adjacent(n + 1);
    vector<vector<int>> r_adjacent(n + 1);

    stack<int> copy;

    bool visited[n + 1] = {false};
    bool visited2[n + 1] = {false};

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adjacent[x].push_back(y);
        r_adjacent[y].push_back(x);

    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            DFS1(adjacent, visited, copy, i);
        }
    }

    while(!copy.empty())
    {
        int u = copy.top();
        copy.pop();

        if(!visited2[u])
        {
           DFS2(r_adjacent, visited2, u);
           cout << endl;
        }

    
    }
}

int main()
{
    findStronglyConnectedComponent();
    return 0;
}
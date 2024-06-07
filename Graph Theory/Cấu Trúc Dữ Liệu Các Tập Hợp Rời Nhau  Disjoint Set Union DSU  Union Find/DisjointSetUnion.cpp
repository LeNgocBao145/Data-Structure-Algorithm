#include <iostream>
#include <vector>

using namespace std;

void make_set(vector<vector<int>>& adjacent, int n, int m, int size[], int parent[])
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int v, int parent[])
{
    if(v == parent[v])
    {
        return v;
    }

    return parent[v] = find(parent[v], parent);
}

bool Union(int a, int b, int parent[], int size[])
{
    a = find(a, parent);
    b = find(b, parent);

    if(a == b)
    {
        return false;
    }

    if(a != b)
    {
        if(size[a] < size[b])
        {
            swap(a, b);
        }

        parent[b] = a;

        size[a] += size[b];
    }

    return true;
}

int main()
{
    int n, m;

    cin >> n >> m;

    int size[n + 1];
    int parent[n + 1];

    vector<vector<int>> adjacent[n + 1];

     for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjacent[x].push_back(y);
        
    }

    return 0;
}
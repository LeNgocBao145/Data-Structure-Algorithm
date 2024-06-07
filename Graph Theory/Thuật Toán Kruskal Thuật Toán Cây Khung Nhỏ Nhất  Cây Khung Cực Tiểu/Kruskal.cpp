
// 6 9
// 1 2 12
// 1 3 4
// 2 3 1
// 2 4 5
// 2 5 3
// 3 5 2
// 4 5 3
// 4 6 10
// 5 6 8

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int u, v;
    int m;
};

void make_set(int n, int size[], int parent[])
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

bool cmp(edge a, edge b)
{
    return a.m < b.m;
}

void kruskal()
{
    int n, m;

    cin >> n >> m;

    int size[1000];
    int parent[1000];

    

    make_set(n, size, parent);

    vector<edge> canh;
    vector<edge> mst;

    for(int i = 0; i < m; i++)
    {
        int u, v, m;
        cin >> u >> v >> m;
        canh.push_back({u, v, m});
    }

    int ans = 0;
    sort(canh.begin(), canh.end(), cmp);

    for(int i = 0; i < m; i++)
    {
        if(mst.size() == n - 1)
        {
            break;
        }

        edge e = canh[i];

        if(Union(e.u, e.v, parent, size))
        {
            mst.push_back(e);
            ans += e.m;
        }
    }

    if(mst.size() == n - 1)
    {
        cout << "MST: " << ans << endl;
        for(int i = 0; i < mst.size(); i++)
        {
            cout << mst[i].u << " " << mst[i].v << " " <<  mst[i].m << endl;
        }
    }else
    {
        cout << "Khong ton tai cay khung cuc tieu" << endl;
    }
}

int main()
{
    kruskal();

    return 0;
}

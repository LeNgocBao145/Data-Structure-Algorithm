#include <iostream>
#include <vector>
#include <climits>
#include <queue>


using namespace std;

struct edge{
    int x, y;
    int w;
};

//PRIM 
//Thuật Toán PRIM Tìm Cây Khung Cực Tiểu
//Thuật Toán Cây Khung Nhỏ Nhất

//B1: Khởi tạo
//  Vmst = {u};
//  v = v \ {u}
//  MST = NULL; d = 0

//B2: Lặp
// while(v != NULL)
//  e = (x, y)
//  cạnh ngắn nhất giữa x và y với x thuộc v và y thuộc Vmst
//  MST = MST + (e)
//  d = d + d(e)
//  Vmst = Vmst + {x}
//  v = v \ {x}

//B3: Trả về KQ

// 6 9
// 1 2 9
// 1 3 4
// 2 3 1
// 2 4 5
// 2 5 3
// 3 5 2
// 4 5 3
// 4 6 10
// 5 6 8

// Output:
// 18
// 3 1 4
// 2 3 1
// 5 3 2
// 4 5 3
// 6 5 8

void input(vector<vector<pair<int, int>>>& adj, int n, int m)
{

    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

//Cách bình thường không tối ưu

void prim(int u)
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    input(adj, n, m);
    bool exist[n] = {false};
    //  exist[i] = true thì i thuộc Vmst
    //  exist[i] = false thì i thuộc v

    vector<edge> MST;
    int d = 0;  //khai bao tong do dai
    exist[u] = true;
    
    while(MST.size() < n - 1)
    {
        int min_w = INT_MAX;
        int X, Y;

        for(int i = 1; i <= n; i++)
        {
            if(exist[i])
            {
                for(int j = 0; j < adj[i].size(); j++)
                {
                    int first = adj[i][j].first;
                    int edge2 = adj[i][j].second;

                    if(exist[first] == false && edge2 < min_w)
                    {
                        min_w = edge2;
                        Y = i;
                        X = first;
                    }
                }
            }
        }

        MST.push_back({X, Y, min_w});
        d += min_w;
        exist[X] = true;
    }

    cout << d << endl;

    for(edge it : MST)
    {
        cout << it.x << " " << it.y << " " << it.w << endl;
    }

}

// 8 15
// 1 2 5
// 1 4 3
// 1 3 2
// 2 3 1
// 3 4 4 
// 2 6 4 
// 3 7 2
// 4 8 3
// 3 6 3
// 6 7 1
// 7 8 4
// 3 5 6
// 5 8 2
// 4 5 1
// 5 7 5

// 9 12
// 2 0 2
// 2 3 5
// 3 0 4
// 7 5 3
// 5 3 2
// 5 8 5
// 5 6 1
// 3 4 1
// 0 4 6
// 8 6 4
// 6 4 3
// 4 1 4

void advancedPRIM()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj2(n + 1);

    input(adj2, n, m);
    bool exist[n + 1] = {false};
    //  exist[i] = true thì i thuộc Vmst
    //  exist[i] = false thì i thuộc v

    vector<edge> MST;
    int res = 0;  //khai bao tong do dai
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    int d[n + 1];

    for(int i = 1; i <= n; i++)
    {
        d[i] = INT_MAX;
    }
    
    int parent[n + 1];
    Q.push({0, 1});

    while(!Q.empty())
    {
        pair<int, int> top = Q.top();
        Q.pop();

        int root = top.second;
        int dis = top.first;

        cout << root << " " << dis << endl;

        if(!exist[root])
        {
            res += dis;
            exist[root] = true;

            if(root != 1)
            {
                MST.push_back({root, parent[root], dis});
            }

            for(int i = 0; i < adj2[root].size(); i++)
            {
                int roof = adj2[root][i].first;
                int edge = adj2[root][i].second;

                cout << roof << " " << edge << endl;

                if(!exist[roof] && edge < d[roof])
                {
                    
                    Q.push({edge, roof});
                    d[roof] = edge;
                    parent[roof] = root;
                }
            }
        }
    }

    cout << res << endl;

    for(edge it : MST)
    {
        cout << it.x << " " << it.y << " " << it.w << endl;
    }
}

void primLord(int u)
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    input(adj, n + 1, m);
    bool* exist = new bool[n + 1];
    fill(exist, exist + n + 1, false);
    //  exist[i] = true thì i thuộc Vmst
    //  exist[i] = false thì i thuộc v

    //vector<edge> MST;
    vector<int> MST;
    int d = 0;  //khai bao tong do dai
    exist[u] = true;
    MST.push_back(u);
    
    while(MST.size() < n)
    {
        int min_w = INT_MAX;
        int X, Y;

        for(int i = 1; i <= n; i++)
        {
            if(exist[i])
            {
                for(int j = 0; j < adj[i].size(); j++)
                {
                    int first = adj[i][j].first;
                    int edge2 = adj[i][j].second;

                    if(exist[first] == false && edge2 < min_w)
                    {
                        min_w = edge2;
                        Y = i;
                        X = first;
                    }
                }
            }
        }

        //MST.push_back({X, Y, min_w});
        MST.push_back(X);
        d += min_w;
        exist[X] = true;
    }

    cout << d << endl;

    // for(edge it : MST)
    // {
    //     cout << it.x << " " << it.y << " " << it.w << endl;
    // }

    for(auto x : MST)
    {
        cout << x << " ";
    }
}

int main()
{
    
    //primLord(1);

    //prim();
    advancedPRIM();

    return 0;
}

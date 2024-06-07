//Dijkstra Algorithm

//1. Set the distance to the source to 0 and the distance to the remaining 
//vertices to infinity

//2. Set the current vertex to the source

//3. Flag the current vertex as visited.

//4. For all vertices adjacent to the current vertex, set the distance from the source to the adjacent vertex equal to the minimum 
//of its present distance and the sum of the weight of the edge from the current vertex to the adjacent vertex and the distance from 
//the source to the current vertex.

//5. From the set of unvisited vertices, arbitrarily set one as the new current vertex, provided that there exists an edge to it 
//such that it is the minimum of all edges from a vertex in the set of visited vertices to a vertex in the set of unvisited vertices. 
//To reiterate: The new current vertex must be unvisited and have a minimum weight edge from a visited vertex to it. This can be done 
//trivially by looping through all visited vertices and all adjacent unvisited vertices to those visited vertices, keeping the vertex 
//with the minimum weight edge connecting it.

//6. Repeat steps 3-5 until all vertices are flagged as visited.

//Relaxation: d[v] = min(d[v], d[u] + length(u, v))

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// 6 8
// 1 2 7
// 1 3 12
// 2 3 2
// 2 4 9
// 3 5 10
// 4 6 1
// 5 4 4 
// 5 6 5


void input(vector<vector<pair<int, int>>>& adj, int m)
{
    for(int i = 0; i < m; i++)
    {
        int x, y, m;
        cin >> x >> y >> m;
        adj[x].push_back({y, m});
        //adj[y].push_back(x);
    }
}

void dijkstra(int u, int end)
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> d(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);

    d[u] = 0;

    input(adj, m);
    vector<int> parent(n + 1);
    parent[u] = u;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    Q.push({0, u});
    int count = 0;

    while(!Q.empty())
    {
        pair<int, int> top = Q.top();
        Q.pop();

        int point = top.second;
        int dis = top.first;


        if(!visited[point])
        {
            visited[point] = true;
            for(int i = 0; i < adj[point].size(); i++)
            {
                int bot = adj[point][i].first;
                int canh = adj[point][i].second;

                //cout << bot << " " << canh << endl;

                if(d[bot] > d[point] + canh)
                {
                    d[bot] = d[point] + canh;
                    Q.push({d[bot], bot});
                    parent[bot] = point;
                }
            }
        }

        count++;
    }

    //cout << count << endl;
    vector<int> path;
    
    cout << d[end] << endl;

    while(1)
    {
       
        path.push_back(end);

        if(u == end)
        {
            break;
        }

        end = parent[end];
    }

    reverse(path.begin(), path.end());

    for(int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }

    cout << endl;

    for(int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }

}

int main()
{
    dijkstra(1, 6);
    return 0;
}
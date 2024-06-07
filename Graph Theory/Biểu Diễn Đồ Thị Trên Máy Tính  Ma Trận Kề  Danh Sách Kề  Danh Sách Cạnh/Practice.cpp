#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;

//Transform adjacent list to adjacent matrix

// 5 9
// 1 2
// 1 3
// 1 4
// 2 3
// 2 4 
// 2 5
// 3 4 
// 3 5 
// 4 5 


void convertEdgeListToAdjacentMatrix()
{
    //n la so dinh va m la so canh
    int n, m;

    cin >> n >> m;

    int** arr = new int*[n + 1];

    for(int i = 0; i < n + 1; i++)
    {
        arr[i] = new int[n + 1];
        //fill(arr[i], arr[i] + n + 1, 0);
        memset(arr[i], 0, (n + 1) * sizeof(arr[i]));
    }
    

    for(int i = 0; i < m; i++)
    {
        int x, y;

        cin >> x >> y;

        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    for(int i = 0; i < n + 1; i++)
    {
        delete[] arr[i];
    }

    delete arr;
}

void convertEdgeListToAdjacentList()
{
    //n la so dinh va m la so canh
    int n, m;

    cin >> n >> m;

    int** arr = new int*[n + 1];

    for(int i = 0; i < n + 1; i++)
    {
        arr[i] = new int[n + 1];
    }
    
    vector<vector<int>> table(n + 1);

    for(int i = 0; i < m; i++)
    {
        int x, y;

        cin >> x >> y;

       table[x].push_back(y);
       table[y].push_back(x);
    }

    for(int i = 1; i < table.size(); i++)
    {
        for(int j = 0; j < table[i].size(); j++)
        {
            cout << table[i][j] << " ";
        }

        cout << endl;
    }
}

void convertAdjacentMatrixToEdgeList()
{
    int n;

    cin >> n;

    int** arr = new int*[n];

    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(arr[i][j] == 1)
            {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete arr;
}

void convertAdjacentListToEdgeList()
{
    int n;

    cin >> n;

    cin.ignore();

    string line;
    
    string num;

    vector<vector<int>> tmp(n);

    for(int i = 0; i < n; i++)
    {
        getline(cin, line);
        istringstream ss(line);
        while(ss >> num)
        {
            tmp[i].push_back(stoi(num));
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < tmp[i].size(); j++)
        {
            if(i + 1 < tmp[i][j])
            {
                cout << i + 1 << " " << tmp[i][j] << endl;
            }
        }
    }
}

int main()
{
    convertAdjacentListToEdgeList();
    
    return 0;
}
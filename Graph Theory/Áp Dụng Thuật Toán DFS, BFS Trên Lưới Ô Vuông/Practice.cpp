#include <iostream>
#include <queue>

using namespace std;

void DFS(char** matrix, int n, int m, int dx[], int dy[], int i, int j)
{
    cout << i << " " << j << endl;

    matrix[i][j] = 'o';

    for(int k = 0; k < 4; k++)
    {
        int row = i + dy[k];
        int col = j + dx[k];

        if(row >= 0 && row < n && col >= 0 && col < m)
        {
            if(matrix[row][col] == 'x')
            {
                DFS(matrix, n, m, dx, dy, row, col);
            }
        }
    }
}

void BFS(char** matrix, int n, int m, int dx[], int dy[], int i, int j)
{
    queue<pair<int, int>> nums;
    nums.push({i, j});
    matrix[i][j] = 'o';
    cout << i << " " << j << endl;

    while(!nums.empty())
    {
        pair<int, int> u = nums.front();
        nums.pop();

        for(int k = 0; k < 4; k++)
        {
            int row = u.first + dy[k];
            int col = u.second + dx[k];

            if(row >= 0 && row < n && col >= 0 && col < m)
            {
                if(matrix[row][col] == 'x')
                {
                    nums.push({row, col});
                    cout << row << " " << col << endl;
                    matrix[row][col] = 'o';
                }
            }
        }
    }
}

// 6 6
// x x x o o o
// o o x o o o
// o x x x x o
// o o o o o x
// x x o x o x
// x o x x o x

void countGraph()
{
    int n, m;
    cin >> n >> m;

    char** matrix = new char*[n];

    for(int i = 0; i < n; i++)
    {
        matrix[i] = new char[m];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int count = 0;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            
            if(matrix[i][j] == 'x')
            {
                count++;
                cout << "Ma tran thu " << count << ": " << endl;
                BFS(matrix, n, m, dx, dy, i, j);
            }
        }
    }

    cout << count << endl;

    for(int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int main()
{
    countGraph();
    return 0;
}
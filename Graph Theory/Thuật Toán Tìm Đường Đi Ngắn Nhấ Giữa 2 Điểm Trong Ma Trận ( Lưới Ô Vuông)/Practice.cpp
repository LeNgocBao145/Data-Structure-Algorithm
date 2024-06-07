#include <iostream>
#include <queue>

using namespace std;

//o la co duong di
//x la khong co duong di

// 6 6
// A o o x o o
// o x o o o o
// o x o o o o
// o o o o x x
// B o o o x o
// o o o x x x 

int n, m, s, t, x, y;

char arr[6][6];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int dis[100][100];

bool DFS(int i, int j)
{
    cout << i << " " << j << endl;

    if(arr[i][j] == 'B')
    {
        return true;
    }

    arr[i][j] = 'x';

    for(int k = 0; k < 4; k++)
    {
        int row = i + dy[k];
        int col = j + dx[k];

        if(row >= 0 && row < n && col >= 0 && col < m && arr[row][col] != 'x')
        {
            if(DFS(row, col))
            {
                return true;
            }
        }
    }

    return false;

}

//Tim duong di

bool BFS1(int i, int j)
{
    queue<pair<int, int>> nums;
    nums.push({i, j});
    cout << i << " " << j << endl;

    if(arr[i][j] == 'B')
    {
        return true;
    }

    arr[i][j] = 'x';

    while(!nums.empty())
    {
        pair<int, int> u = nums.front();
        nums.pop();


        for(int k = 0; k < 4; k++)
        {
            int row = u.first + dy[k];
            int col = u.second + dx[k];

            if(row >= 0 && row < n && col >= 0 && col < m && arr[row][col] != 'x')
            {
                cout << row << " " << col << endl;

                if(arr[row][col] == 'B')
                {
                    return true;
                }

                nums.push({row, col});
                arr[row][col] = 'x';
            }
        }
    }

    return false;
}

void input()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            if(arr[i][j] == 'A')
            {
                s = i;
                t = j;
            }
        }
    }
}

void findPath()
{
    

    input();

    if(BFS1(s, t))
    {
        cout << "YES" << endl;

    }else
    {
        cout << "NO" << endl;
    }
    
}

//Tim buoc di toi thieu (Su dung BFS)

void BFS2(int i, int j)
{
    queue<pair<int, int>> nums;
    nums.push({i, j});
    cout << i << " " << j << endl;

    if(arr[i][j] == 'B')
    {
        return;
    }

    arr[i][j] = 'x';

    while(!nums.empty())
    {
        pair<int, int> u = nums.front();
        nums.pop();


        for(int k = 0; k < 4; k++)
        {
            int row = u.first + dy[k];
            int col = u.second + dx[k];

            if(row >= 0 && row < n && col >= 0 && col < m && arr[row][col] != 'x')
            {
                cout << row << " " << col << endl;

                dis[row][col] = dis[u.first][u.second] + 1;

                if(arr[row][col] == 'B')
                {
                    return;
                }

                nums.push({row, col});
                arr[row][col] = 'x';
            }
        }
    }

}

void findMinPath()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            if(arr[i][j] == 'A')
            {
                s = i;
                t = j;
            }else if (arr[i][j] == 'B')
            {
                y = i;
                x = j;

            }
        }
    }

    BFS2(s, t);
    
    cout << dis[y][x] << endl;
}

int main()
{
    findMinPath();

    return 0;
}
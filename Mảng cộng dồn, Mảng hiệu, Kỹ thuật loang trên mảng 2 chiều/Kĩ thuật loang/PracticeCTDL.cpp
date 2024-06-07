#include <iostream>

using namespace std;

//Mảng cộng dồn

//  8 8 
//  1 1 0 0 0 1 1 1
//  1 0 0 0 1 1 1 1 
//  0 1 1 1 0 0 1 0 
//  1 1 1 1 0 1 1 0
//  1 1 1 1 1 0 1 1 
//  1 0 0 1 0 1 0 1
//  0 0 0 0 1 0 1 0
//  1 1 0 0 0 1 0 1

void input(int** arr, int** prefix, int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] + arr[i][j] - prefix[i - 1][j - 1];
        }
    }

}

void output1()
{
    int n, m;
    cin >> n >> m;

    int** arr = new int* [n + 1];

    for (int i = 0; i <= n; i++)
    {
        arr[i] = new int[m + 1];
    }

    int** prefix = new int* [n + 1];

    for (int i = 0; i <= n; i++)
    {
        prefix[i] = new int[m + 1];
    }

    input(arr, prefix, n, m);

    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    cout << prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1] << endl;
}

//Kĩ thuật loang trên mảng 2 chiều

//Cho mảng 2 chiều kích thước n x m tìm kiếm số hòn đảo

void expansion(int** arr, int i, int j, int n, int m)
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    arr[i][j] = 0;

    for(int k = 0; k < 4; k++)
    {
        int row = i + dy[k];
        int col = j + dx[k];

        if(row >= 0 && row < n && col >=0 && col < m)
        {
            if(arr[row][col] == 1)
            {
                expansion(arr, row, col, n, m);
            }
        }
    }
}

void findIsland()
{
    int n, m;
    cin >> n >> m;

    int** arr = new int*[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int count = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 1)
            {
                count++;
                expansion(arr, i, j, n, m);
            }
        }
    }

    cout << count << endl;
}

int main()
{
    findIsland();

    return 0;
}
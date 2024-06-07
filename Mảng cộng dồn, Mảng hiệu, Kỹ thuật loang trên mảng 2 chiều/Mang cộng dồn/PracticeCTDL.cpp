#include <iostream>

using namespace std;

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

//  8 8 
//  1 1 0 0 0 1 1 1
//  1 0 0 0 1 1 1 1 
//  0 1 1 1 0 0 1 0 
//  1 1 1 1 0 1 1 0
//  1 1 1 1 1 0 1 1 
//  1 0 0 1 0 1 0 1
//  0 0 0 0 1 0 1 0
//  1 1 0 0 0 1 0 1

int main()
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

    return 0;
}
//Cây Chỉ Số Nhị Phân (Fenwick Tree) là một cấu trúc dữ liệu 
//giúp thực hiện các truy vấn cập nhật và truy vấn tổng trên mảng một cách hiệu quả. 
//Fenwick Tree giúp giảm độ phức tạp của cả truy vấn cập nhật và truy vấn tổng xuống O(logN) so với O(N) 
//của cách thông thường là Segment Tree.

#include <iostream>

using namespace std;

int n, a[100005], BIT[100005];
void update(int pos, int val)
{
    while(pos <= n)
    {
        BIT[pos] += val;
        pos += pos & -pos;
    }
}

//Query the sum of the element from 1 to pos in array
int query(int pos)
{
    int res = 0;
    while(pos > 0)
    {
        res += BIT[pos];
        pos -= pos & -pos;
    }
    return res;
}

// Cho mảng A[] có N phần tử, nhiệm vụ của bạn là thực hiện Q truy vấn thuộc 1 trong 2 dạng sau:

// Tăng phần tử ở chỉ số u giá trị v
// Tính tổng các phần tử trong đoạn từ [l, r]
// Đầu vào

// Dòng 1 gồm N và Q
// Dòng 2 là N phần tử trong mảng A[]
// Dòng 3 mô tả truy vấn thuộc dạng 1 u v hoặc 2 l r

// Giới hạn

// 1 <= N, Q <= 2.10^5
// 1 <= A[i], v <= 10^9
// 1 <= l <= r <= N
// 1 <= u <= N

//Input:
// 6 8
// 10 3 2 3 10 5
// 2 2 5
// 1 2 9
// 2 3 6
// 2 1 3
// 2 3 5
// 1 5 7
// 1 3 8
// 2 1 3

// Output:

// 18
// 20
// 24
// 15
// 32

int main()
{
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }

    while (q--) {
        int tt, x, y;
        cin >> tt >> x >> y;

        if (tt == 1)
        {
            update(x, y);
        }
        else
        {
            cout << query(y) - query(x - 1) << endl;
        }
    }

    return 0;
}
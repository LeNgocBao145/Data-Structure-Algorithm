#include <iostream>

using namespace std;    
const int maxN = 200000;
int n, a[maxN], t[4*maxN];

//Build the segment tree
// v - current node
// Left node - 2 * v
// Right node - 2 * v + 1
void build(int v, int left, int right)
{
    if(left == right)
    {
        t[v] = a[left]; // leaf
    }else
    {
        int mid = (left + right) / 2;
        build(v*2, left, mid);
        build(v*2 + 1, mid + 1, right);
        t[v] = t[v*2] + t[v*2 + 1];
    }
}

//Update segment tree
void update(int v, int left, int right, int pos, int new_val)
{
    if(left == right)
    {
        t[v] = new_val;
    }else
    {
        int mid = (left + right) / 2;
        if(pos <= mid)
        {
            update(v*2, left, mid, pos, new_val);
        }else
        {
            update(v*2 + 1, mid + 1, right, pos, new_val);
        }
        t[v] = t[v*2] + t[v*2 + 1];
    }
}

long long query(int v, int left, int right, int l, int r)
{
    if(l > r)
    {
        return 0;
    }
    if(l == left && r == right)
    {
        return t[v];
    }

    int mid = (left + right) / 2;

    //Chia đoạn [l, r] thành 2 phần [l, mid] và [mid + 1, r]
    //để tính tổng các phần tử trong đoạn [l, r]
    return query(v*2, left, mid, l, min(r, mid)) + query(v*2 + 1, mid + 1, right, max(l, mid + 1), r);
}

// [Range query]. Bài 3. Sum Queries 2

// Cho mảng A[] có N phần tử, nhiệm vụ của bạn là thực hiện Q truy vấn thuộc 1 trong 2 dạng sau:

// Gán phần tử ở chỉ số u thành số v
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

//Đầu ra
//Kết quả cho từng truy vấn 

// Input
// 5 3
// 1 1 1 1 1
// 1 3 2
// 2 2 2 
// 2 3 4

//Output


int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    for(int i = 1; i < n; i++)
    {
        cout << t[i] << " ";
    }

    return 0;
}
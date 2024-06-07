#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Bulbs Problem
//Giving N bulbs, either on (1) or off (0)
//Turning on i(th) bulbs causes all remaining bulbs on the right to flip
//Find min num of switches to turn all the bulbs on
//Constraints:
//- 1 <= N <= 1e^5
//- A[i] = {0, 1}

//Test case: 0 1 0 1 1 0 1 1

int bulbs(vector<int>& A)
{
    int n = A.size();
    int cost = 0;

    for(int i = 0; i < n; i++)
    {
        if(cost % 2 != 0)
        {
            if(A[i] == 0)
            A[i] = 1;
            else
            A[i] = 0;
        }

        if(A[i] == 0)
        {
            cost++;
        }
    }

    return cost;
}

//Highest Product
//Giving an array of N intergers
//Find the highest product by multiplying 3 elements
//Constraints: 3 <= N <= 5*e^5

//Test case: [-5, -2, -1, 0, 0, 3, 4, 5]
//           [-5, -2, -1, 0, 0, 1, 1, 5]

//Solution 1: Take the highest 3 elements
//Solution 2: Take 2 negative & 1 positive

int highestProduct(vector<int>& A)
{
    sort(A.begin(), A.end());
    int n = A.size();

    int rank1 = A[n - 1] * A[0] * A[1];
    int rank2 = A[n - 1] * A[n - 2] * A[n - 3];

    return max(rank2, rank1);
}

//Disjoint intervals
//Given a list of intervals: [start, end]
//Find the length of the maximal set of mutually disjoint intervals
//Constraints:
//- 1 <= N <= 1e^5
//- 1 <= A[i][0] <= A[i][1] <= 1e^9



int main()
{
    vector<int> A;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }

    //cout << bulbs(A) << endl;

    // for(int i = 0; i < n; i++)
    // {
    //     cout << A[i] << " ";
    // }
    cout << highestProduct(A);
    return 0;
}
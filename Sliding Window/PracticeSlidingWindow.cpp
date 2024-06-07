#include <iostream>
#include <set>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

//Cửa sổ trùng nhau 1
bool checkCoincident()
{
    multiset<int> num;
    int n, k;
    cin >> n >> k;

    int arr[1000];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < k; i++)
    {
        num.insert(arr[i]);
    }

    for(auto x : num)
    {
        cout << x << " ";
    }

    cout << endl;

    for(auto x : num)
    {
        if(num.count(x) >= 2)
        {
           return true;
        }
    }

    for(int i = k; i < n; i++)
    {
        num.erase(arr[i - k]);
        num.insert(arr[i]);

        for(auto x : num)
        {
            if(num.count(x) >= 2)
            {
              return true;
            }
        }
    }

    return false;
}

//Cửa sổ trùng nhau 2
//Check if there is any window with k size that has 2 particles which their minus equal or higher than t 
bool checkCoincident2()
{
    int n, k, t;
    cin >> n >> k >> t;

    int arr[1000];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    multiset<int> ans;
    ans.insert(arr[0]);

    for(int i = 1; i < k; i++)
    {
       
        if(abs(arr[i] - arr[i - 1]) <= t)
        {
            return true;
        }else{
            ans.insert(arr[i]);
        }
    }

    for(int i = k; i < n; i++)
    {
        if(abs(arr[i] - arr[i - 1]) <= t)
        {
            return true;
        }else{
            ans.erase(arr[i - k]);
            ans.insert(arr[i]);
        }

        // ans.erase(arr[i - k]);
        // ans.insert(arr[i]);
    }

    return false;
}

int main()
{
    int n, x;
    cin >> n;
    //cin >> n >> x;
    // vector<int> arr(n);
    multiset<int> ms;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ms.insert(x);
    }

    //auto ans = lower_bound(arr.begin(), arr.end(), x);

    for(auto x : ms)
    {
        cout << x << " ";
    }

    cout << endl;

    ms.erase(ms.find(5));

    for(auto x : ms)
    {
        cout << x << " ";
    }

    cout << distance(ms.begin(), ms.find(5)) << endl;

    return 0;
}
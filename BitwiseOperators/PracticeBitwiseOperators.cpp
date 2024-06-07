#include <iostream>
#include <vector>

using namespace std;

void convertDecimalToBinary(long long num)
{
    for(int i = 31; i >= 0; i--)
    {
        if(num & (1 << i))
        {
            cout << "1";
        }else
        {
            cout << "0";
        }
    }
}



//Sinh tất cả tập con của 1 mảng

void printAllSubsets(int* arr, int n)
{
    int check = 0;

    for(int i = 0; i < n; i++)
    {
        check += (1 << i);
    }

    for(int i = 0; i <= check; i++)
    {
        cout << "{ ";
        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << "} ";
    }
    
}

//There are n apples with known weights. You will devide  these apples into 2 group so that the difference between 2 group is minimal
long long findMinRangeWeight(vector<int> &num)
{
    int n = num.size();

    long long check = 0;

    for(int i = 0; i < n; i++)
    {
        check += (1 << i);
    }

    long long sum1 = 0, sum2 = 0;

    long long ans = num[0];
    long long final = 0;

    for(int i = 0; i <= check; i++)
    {
        sum1 = 0;
        sum2 = 0;
        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j))
            {
                sum1 += num[j];
            }else
            {
                sum2 += num[j];
            }
        }

        if(abs(sum1 - sum2) < ans)
        {
            final = i;
            ans = abs(sum1 - sum2);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(final & (1 << i))
        {
            cout << "1" << " ";
        }else
        {
            cout << "0" << " ";
        }
    }

    cout << endl;

    return ans;
}

int main()
{
    vector<int> num = {3, 6, 15, 16, 21};
    cout << findMinRangeWeight(num);
    return 0;
}
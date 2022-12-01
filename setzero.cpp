#include <bits/stdc++.h>
using namespace std;

void setzeros(vector<vector<int>> &arr)
{
    int mainarr = arr.size();
    int smlarr = arr[0].size();
    vector<int> arr1(mainarr, -1), arr2(smlarr, -1);
    for (int i = 0; i < mainarr; i++)
    {
        for (int j = 0; j < smlarr; j++)
        {
            if (arr[i][j] == 0)
            {
                arr1[i] = 0;
                arr2[j] = 0;
            }
        }
    }
    for (int a = 0; a < mainarr; a++)
    {
        for (int b = 0; b < smlarr; b++)
        {
            if (arr1[a] == 0 || arr2[b] == 0)
            {
                arr[a][b] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 2, 3}, {9, 0, 0}, {5, 6, 7}};
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    setzeros(arr);
    cout << "\n";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// temp = {1,3}
// {1,3}{2,4}{3,6} = {1,6}
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    vector<int> temp = {arr[0][0], arr[0][1]};
    for (int x = 1; x < n; x++)
    {
        if (temp[1] > arr[x][0])
        {
            temp[1] = max(temp[1], arr[x][1]);
        }
        else
        {
            ans.push_back(temp);
            temp[0] = arr[x][0];
            temp[1] = arr[x][1];
        }
    }
    ans.push_back(temp);

    return ans;
}
int main()
{
    vector<vector<int>> arr;
    int temp;
    cin >> temp;
    for (int x = 0; x < temp; x++)
    {
        vector<int> q(2);
        cin >> q[0] >> q[1];
        arr.push_back(q);
    }

    vector<vector<int>> ans = merge(arr);

    for (int x = 0; x < temp; x++)
    {
        for (int i = 0; i < 2; i++)
        {
            cout << ans[x][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
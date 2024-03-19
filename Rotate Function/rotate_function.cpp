#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int func(vector<int> &nums)
{
    int n = nums.size();
    vector<int> rev = nums;
    reverse(rev.begin(), rev.end());

    int res = 0, pre = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        res += (i * nums[i]);
        sum += nums[i];
    }
    pre = res;

    int rotate = 1, j = 0;
    while (rotate < n)
    {
        int temp = pre;
        temp = pre + sum - (n * rev[j]);
        j++;

        res = max(res, temp);
        pre = temp;
        rotate++;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << func(v);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    freopen("errorf.txt", "w", stderr);
#endif

    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}
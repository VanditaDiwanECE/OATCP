#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

 
void solve()
{
    int M = 1e9 + 7;
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        if (v[0][i] == '.')
        {
            dp[0][i] = 1;
        }
        else
        {
            break;
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] == '.')
        {
            dp[i][0] = 1;
        }
        else
        {
            break;
        }
    }
 
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (v[i][j] == '.')
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
            }
        }
    }
 
    cout << dp[n - 1][n - 1];
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
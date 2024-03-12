#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
void solve(vector<long long> dp)
{
    int n;
    cin >> n;
    cout << dp[n] << endl;
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    freopen("errorf.txt", "w", stderr);
#endif
    int n = 1e6 + 1;
    int M = 1e9 + 7;
    vector<long long> dp(n+1,1);
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    for(int i=6;i<=1e6;++i){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]+dp[i-4] + dp[i-5] + dp[i-6]) % M;
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve(dp);
    }
    return 0;
}
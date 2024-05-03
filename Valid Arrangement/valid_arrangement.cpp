#include <bits/stdc++.h>

using namespace std;
void euler(unordered_map<int, stack<int>> &adj, vector<vector<int>> &ans, int curr)
{
    auto &stk = adj[curr];
    while (!stk.empty())
    {
        int nei = stk.top();
        stk.pop();
        euler(adj, ans, nei);
        // postorder
        ans.push_back({curr, nei});
    }
}
vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
{
    int m = pairs.size();
    // Eulerian Path
    unordered_map<int, stack<int>> adj;
    unordered_map<int, int> in;
    unordered_map<int, int> out;
    // reserve spaces for unordered_map may help in runtime.
    adj.reserve(m);
    in.reserve(m);
    out.reserve(m);
    for (int i = 0; i < m; i++)
    {
        int u = pairs[i][0], v = pairs[i][1];
        in[v]++;
        out[u]++;
        adj[u].push(v);
    }
    // find the starting node
    int start = -1;
    for (auto &p : adj)
    {
        int i = p.first;
        if (out[i] - in[i] == 1)
            start = i;
    }
    if (start == -1)
    {
        // Eulerian Circuit -> start at any node
        start = adj.begin()->first;
    }
    vector<vector<int>> ans;
    euler(adj, ans, start);
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{

    int n;
    cin >> n;
    vector<vector<int>> vp(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vp[i].push_back(x);
        vp[i].push_back(y);
    }
    vector<vector<int>> ans = validArrangement(vp);
    cout << "\n";
    if (ans.size() != n)
    {
        cout << "No valid arrangement found !"
             << "\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i][0] << " " << ans[i][1] << "\n";
        }
    }
}
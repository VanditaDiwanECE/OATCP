#include<bits/stdc++.h>
using namespace std;

int f(vector<int>& v) {
    int res = 0;
    for (int i = 0; i < 31; i++) {
        int cnt = 0;

        for (int j = 0; j < v.size(); j++) {
            if (v[j] & (1 << i))cnt++;
        }

        res += (cnt * (v.size() - cnt));
    }

    return res;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    cout << f(v) << endl;
    return 0;
}
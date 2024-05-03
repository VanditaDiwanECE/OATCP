#include<bits/stdc++.h>
using namespace std;

int f(vector<int>& v, int k) {
    int res = 0;
    long long r = 0;
    for (int i : v) {
        while (r + 1 < i) {
            r = r + (r + 1);
            res++;
            if (r >= k) break;
        }
        r = r + i;
        if (r >= k) break;
    }
    while (r < k) {
        r = r + (r + 1);
        res++;
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    int k; cin >> k;

    cout << f(v, k) << endl;
    return 0;
}

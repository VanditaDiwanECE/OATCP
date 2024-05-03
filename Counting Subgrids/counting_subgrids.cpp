#include <bits/stdc++.h>
using namespace std;

#define ll long long int
bitset<3001> b[3001];

int f(int x) {
    return x * (x - 1);
}

int main() {
    int n;cin >> n;

    ll ans;

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans += f((b[i] & b[j]).count());

    cout << (ans / 2) << endl;
}
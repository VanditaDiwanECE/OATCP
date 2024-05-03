#include<bits/stdc++.h>
using namespace std;

string f(string s, int k) {
    if (s.size() == k)
        return "0";

    string res;
    vector<char> v;

    for (int i = 0; i < s.size(); ++i) {
        while (k > 0 && !v.empty() && v.back() > s[i]) {
            v.pop_back(); k--;
        }
        v.push_back(s[i]);
    }

    while (k-- > 0)  v.pop_back();

    for (const char c : v) {
        if (c == '0' && res.empty())
            continue;
        res += c;
    }

    return res.empty() ? "0" : res;
}

int main() {
    string s; cin >> s;
    int k; cin >> k;
    cout << f(s, k) << endl;
    return 0;
}
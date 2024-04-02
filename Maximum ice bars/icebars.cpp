#include "bits/stdc++.h"
#define ll long long
#define srv(v) sort(v.begin(), v.end())
#define fo(i, a, b) for (ll i = a; i < b; i++)
#define str string
#define sz size()
#define dv(v) vector<ll> v
#define ds(s) set<ll> s
#define dm(mp) map<ll, ll> mp
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    ll n;
    cin >>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    ll price, i=0;
    cin>>price;
    while(i<n && price>0){
        if(price<v[i]) break;
        price-=v[i];
        i++;
    }
    cout<<i<<'\n';
}
#include <bits/stdc++.h>

#define el '\n'
#define forn(i, n) for(int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) x.size()

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const ll inf = 1e18;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, m;
    cin >> n >> k >> m;
    map<string, int> mp;
    string s;
    forn(i, n){
        cin >> s;
        mp[s] = i;
    }
    vll cst(n);
    forn(i, n)cin >> cst[i];
    vll grp(k, inf);
    map<int, int> mgrp;
    forn(i, k){
        int szs;
        cin >> szs;
        forn(j, szs){
            int ind;
            cin >> ind;
            --ind;
            mgrp[ind] = i;
            grp[i] = min(grp[i], cst[ind]);
        }
    }
    ll ans = 0;
    forn(i, m){
        cin >> s;
        ans += grp[mgrp[mp[s]]];
    }
    cout << ans << el;
}
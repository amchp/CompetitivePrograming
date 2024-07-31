#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; ++i)
#define el '\n'
#define d(x) cerr << #x << ' ' << x << el;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    forn(i, n){
        int v;
        cin >> v;
        ++mp[v];
    }
    for(auto& [key, v] : mp)if(v != k)cout << key << el;
}
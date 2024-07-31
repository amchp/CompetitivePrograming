#include<bits/stdc++.h>
#define el '\n'
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define d(x) cout << #x << ' ' << x << el;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int inf = 1e9;

int main(){
    int n, c;
    cin>>n>>c;
    vl a(n);
    forn(i, n)cin >> a[i];
    vl pre(n, 0);
    pre[0] = a[0];
    for1(i, n - 1)pre[i] = max(pre[i - 1] - c, 0LL) + a[i];
    int mni = -1;
    ll mn = inf;
    forn(i, n){
        ll val = pre[i] / c;
        if(i + val < n && val < mn){
            mni = i;
            mn = val;
        }
    }
    if(mni == -1)cout << "impossible" << el;
    else cout << mni << el;
    return 0;
}
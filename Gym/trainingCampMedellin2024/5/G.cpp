#include <bits/stdc++.h>

#define forn(i, n) for(ll i = 0; i < n; ++i)
#define el '\n'
#define for1(i, n) for(ll i = 1; i <= n; ++i)
#define fore(i, l, r) for(ll i = l; i <= r; ++i)
#define d(x) cerr << #x << ' ' << x << el;
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

void sol(){
    ll n;
    cin >> n;
    map<pll, ll> pts;
    map<ll, ll> rws, cols;
    forn(i, n){
        ll r, c, w;
        cin >> r >> c >> w;
        --r, --c;
        pts[{r, c}] = w;
        rws[r] += w;
        cols[c] += w;
    }
    vector<pll> vrws, vcols;
    for(auto& [r, w] : rws){
        vrws.pb({w, r});
    }
    for(auto& [c, w] : cols){
        vcols.pb({w, c});
    }
    sort(all(vcols), greater<pll>());
    queue<ll> q, qq;
    forn(i, sz(vrws))q.push(i);
    ll ans = 0;
    ll jnd = 0;
    while(!q.empty() && jnd < sz(vcols)){
        swap(q, qq);
        while(!qq.empty()){
            ll ind = qq.front();
            qq.pop();
            pll idx = {vrws[ind].se, vcols[jnd].se};
            if(!pts.count(idx)){
                ans = max(ans, vrws[ind].fi + vcols[jnd].fi);
                continue;
            }
            ans = max(ans, vrws[ind].fi + vcols[jnd].fi - pts[idx]);
            q.push(ind);
        }
        ++jnd;
    }
    cout << ans << el;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t = 1;
    while(t--){
        sol();
    }
}
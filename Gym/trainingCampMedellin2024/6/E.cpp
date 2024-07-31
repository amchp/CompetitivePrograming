#include <bits/stdc++.h>


#define pb push_back
#define sz(x) x.size()
#define forn(i, n) for(ll i = 0; i < n; ++i)
#define for1(i, n) for(ll i = 1; i <= n; ++i)
#define fore(i, l, r) for(ll i = l; i <= r; ++i)
#define el '\n'
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define db(x) cerr << #x << ' ' << x << el;

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

const ll mx = 1e18;
ll bi, b1, lr;

int query(ll x){
    cout << "? " << x << endl;
    int dgt;
    cin >> dgt;
    return dgt;
}

bool getpow(ll mid){
    ll qry = 1LL;
    forn(_, bi){
        if(qry > mx / mid)return false;
        qry = qry*mid;
    }
    if(qry > mx / (mid -1))return false;
    qry *= (mid - 1);
    if(qry>mx-lr)return false;
    qry += lr;
    int cb = query(qry);
    return b1 == cb;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> bi;
    ll l = 0, r = 1e18 + 1;
    while(l + 1 < r){
        ll mid = l + (r - l) / 2;
        int cb = query(mid);
        if(bi < cb)r = mid;
        else l = mid;
    }
    lr = r;
    // db(lr);
    b1 = bi + 1;
    l = 1, r = 2024;
    while(l + 1 < r){
        ll mid = l + (r - l) / 2;
        if(getpow(mid))l = mid;
        else r = mid;
    }
    ll base = r;
    ll ans = 1LL*(pow(base, bi)) - lr;
    cout << "! " << ans << ' ' << base << endl;
}
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


ll res(ll x){
    if(x <= 0)return 0;
    ll n = 32 - __builtin_clz(x);
    string s;
    forn(i, n){
        bool one = x & (1 << i);
        if(one)s.pb('1');
        else s.pb('0');
    }
    reverse(all(s));
    ll ans = 0;
    ll e = (n + 1)/ 2;
    for1(i, n - 1){
        ans += 1LL << ((max(i - 2, 0LL) + 1) / 2);
    }
    for1(i, e - 1){
        if(s[i] == '1'){
            ans += 1LL << (((n - 2*(i + 1)) + 1) / 2);
        }
    }
    string eq = s;
    forn(i, e){
        ll op = n - 1 - i;
        eq[op] = s[i];
    }
    ll eqv = 0;
    forn(i, sz(eq)){
        ll pw = n - 1 - i;
        if(eq[i] == '1')eqv += (1 << pw);
    }
    ans += eqv <= x;
    return ans;
}

void sol(){
    ll a, b;
    cin >> a >> b;
    cout << res(b) - res(a - 1) << el;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // res(1000);
    ll t;
    cin >> t;
    while(t--){
        sol();
    }
}
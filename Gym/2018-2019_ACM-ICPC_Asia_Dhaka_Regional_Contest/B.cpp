#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define fored(i, l, r) for(int i = r; i >= l; --i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define el '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define db(x) cerr<<#x<<" "<<x<<el
#define sz(x) x.size()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef array<int,2> v2;

ll fact[15];

ll binpow(ll b, int e){
    ll ans = 1;
    for(;e;b = b*b, e /= 2){
        if(e&1)ans = ans*b;
    }
    return ans;
}

ll C(int n, int r){
    if(n < r)return 0;
    return fact[n]/(fact[r]*fact[n - r]);
}

ll sm(ll x){
    return x*(x + 1) / 2LL;
}

ll cnt(ll x){
    string sx = to_string(x);
    ll n = sz(sx);
    ll ans = 0;
    ll inveq = 0;
    forn(i, n){
        ll di = sx[i] - '0';
        ll cant = n - i;
        // = inv =
        ans += di*inveq*binpow(10, cant - 1);
        forn(j, i){
            ll dj = sx[j] - '0';
            // = inv <
            ans += max((di - 1) - dj, 0LL)*binpow(10, cant - 1);
            // = inv o
            ans += (9 - dj)*binpow(10, cant - 2)*(cant - 1)*di;
            inveq += di > dj;
        }
        // < inv o
        ans += (cant - 1LL)*(sm(8) - sm(8 - (di - 1)))*binpow(10, cant - 2);
        // o inv o
        ans += 45LL*binpow(10, cant - 3)*(di)*C(cant - 1LL, 2);
    }
    ans += inveq;
    return ans;
}

ll sol(){
    ll l, r;
    cin >> l >> r;
    return cnt(r) - cnt(l - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    for1(i, 14){
        fact[i] = fact[i - 1] * i;
    }
    int t;
    cin >> t;
    // db(50);
    forn(i, t){
        cout << "Case " << i + 1 << ": " << sol() << el;
    }
    // freopen("bf.txt", "r", stdin);
    // freopen("dif.txt", "w", stdout);
    // for1(i, 1e4){
    //     ll fans;
    //     cin >> fans;
    //     ll dans = cnt(i);
    //     if(fans != dans){
    //         cout << i << ' ';
    //         cout << fans << ' ' << dans << el;
    //     }
    // }
    // cout << el;
}
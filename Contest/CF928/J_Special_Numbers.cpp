#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define el '\n'
#define pb push_back
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i,l,r ) for(int i = l; i<= r; ++i)
#define ford(i, n) for(int i = (int)n - 1; i >= 0; --i)
#define sz(a) (int) a.size()
#define fi first
#define se second
#define d(x) cerr << #x << ' ' << x << el
#define all(x) x.begin(), x.end()
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef __int128_t i128;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef array<ll, 7> a7;

const int mod = 1e9 + 7;

struct mint{
    ll x;
    mint(): x(0){}
    mint(ll x): x(x){}
    mint operator+(mint b){
        ll ans = x + b.x;
        if(ans >= mod)ans -= mod;
        return mint(ans);
    }
    mint operator-(mint b){
        ll ans = x - b.x;
        if(ans < 0)ans += mod;
        return mint(ans);
    }
    mint operator*(mint b){
        return 1LL*x*b.x%mod;
    }
};

ll cnts[4];
ll trans[10][4];
map<a7, mint> dp;
string l, r, cr;

mint go(a7 st){
    if(st[0] == sz(cr)){
        if(st[2] == 1)return 0; 
        forn(i, 4){
            if(st[i + 3] != cnts[i])return 0;
        }
        return 1;
    }
    if(dp.count(st))return dp[st];
    mint& ans = dp[st];
    ans = 0;
    ll e = !st[1] ? 9 : cr[st[0]] - '0';
    if(st[2]){
        a7 cur = st;
        ++cur[0];
        cur[1] = false;
        ans = ans + go(cur);
    }
    forn(i, e + 1){
        if(i == 0 && st[2]){
            continue;
        }
        a7 cur = st;
        ++cur[0];
        cur[1] = st[1] && i == e;
        cur[2] = false;
        forn(j, 4){
            cur[j + 3] += trans[i][j];
            cur[j + 3] = min(cur[j + 3], cnts[j]);
        }
        ans = ans + go(cur);
    }
    return ans;
}

mint binpow(mint b, ll e){
    mint ans = 1;
    for(; e; b = b * b, e /= 2){
        if(e&1)ans = ans * b;
    }
    return ans;
}

mint inv(mint x){
    return binpow(x, mod - 2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll k;
    cin >> k >> l >> r;
    vector<ll> primes = {2, 3, 5, 7};
    ll tk = k;
    forn(i, 4){
        ll& p = primes[i];
        while(tk % p == 0){
            ++cnts[i];
            tk /=p;
        }
    }
    if(tk != 1){
        cout << 0 << el;
        return 0;
    }
    forn(i, 4){
        trans[0][i] = cnts[i];
    }
    for1(i, 9){
        int ti = i;
        forn(j, 4){
            ll& p = primes[j];
            while(ti % p == 0){
                trans[i][j]++;
                ti /= p;
            }
        }
    }
    cr = r;
    a7 st = {0, 1, 1, 0, 0, 0, 0};
    mint rans = go(st);
    dp.clear();
    cr = l;
    mint lans = go(st);
    i128 cl = 1;
    ford(i, sz(l)){
        char& c  = l[i];
        cl *= (c - '0');
    }
    mint ans = rans - ((lans) - mint(cl % k == 0));
    cout << ans.x << el;
}
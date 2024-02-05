#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for(int i = n - 1; i >= 0; --i)
#define fored(i, l, r) for(int i = (int)r; i >= (int)l; --i)
#define el '\n'
#define d(x) cerr << #x << ' ' << x << el

using namespace std;

typedef vector<int> vi;

const int mod = 1e9 + 7;

int add(int a, int b){
    int ans = a + b;
    if(ans >= mod)ans -= mod;
    return ans;
}

int sbt(int a, int b){
    int ans = a - b;
    if(ans < 0)ans += mod;
    return ans;
}

int mlt(int a, int b){
    return 1LL*a*b%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi fact(n + 1);
    fact[0] = 1;
    for1(i, n){
        fact[i] = mlt(i,fact[i - 1]);
    }
    vi a(k);
    int sm = 0;
    forn(i, k){
        cin >> a[i];
        sm += a[i];
        // cout << a[i] << ' ';
    }
    // cout << el;
    int po = n - sm;
    if(sm == n){
        cout << 0 << el;
        return 0;
    }
    vi pre(k);
    forn(i, k){
        pre[i] = a[i] + (i != 0 ? pre[i - 1] : 0);
    }
    int ans = fact[n];
    int res = 0;
    int ind = 0;
    // d(po);
    fored(i, po, n - 1){
        int rgt = n - i;
        // d(i);
        if(pre[ind] <= rgt){
            res = pre[ind];
            ++ind;
        }
        // d(res);
        // d(fact[res]*po);
        if(res != 0)ans = sbt(ans, mlt(po,fact[res]));
    }
    cout << ans << el;
}
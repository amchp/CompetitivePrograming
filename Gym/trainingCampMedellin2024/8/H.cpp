#include <bits/stdc++.h>

#define el '\n'
#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pb push_back
#define sz(x)(int) x.size()
#define fi first
#define se second
#define db(x) cerr << #x << ' ' << x << el

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef array<int, 3> v3;
typedef vector<ii> vii;
const int nax = 7e2 + 100, kax = 20;
const int mod = 998244353;

const int MOD[] = {1001864327,1001265673}, N = 3e6;
const ii BASE(257, 367), ZERO(0,0), ONE(1,1);
inline int add(int a, int b, int mod){return a+b>=mod ? a+b-mod:a+b;}
inline int sbt(int a, int b, int mod){return a-b<0 ?a-b+mod:a-b;}
inline int mul(int a, int b, int mod){return 1LL*a*b%mod;}
const ll operator!(const ii a){return (ll(a.fi)<<32)|a.se;}
inline ii operator+(const ii &a, const ii &b){
    return {add(a.fi, b.fi, MOD[0]), add(a.se, b.se, MOD[1])};
}
inline ii operator-(const ii &a, const ii &b){
    return {sbt(a.fi, b.fi, MOD[0]), sbt(a.se, b.se, MOD[1])};
}
inline ii operator*(const ii &a, const ii &b){
    return {mul(a.fi, b.fi, MOD[0]), mul(a.se, b.se, MOD[1])};
}
ii base[N]{ONE};
void prepare(){for1(i,N-1)base[i] = base[i-1] * BASE;}

template<class type> 
struct hashing{
    vii ha;
    hashing(){}
    hashing(type &t):ha(sz(t)+1, ZERO){
        for(int i = sz(t) - 1; i >= 0; --i) ha[i] = ha[i+1] * BASE + ii{t[i], t[i]};
    }
    ii query(int l, int r){return ha[l] - ha[r+1] * base[r-l+1];}
};
vector<v3> g[nax];
vi dp[nax];
string A;
hashing<string> hashes;
int vis[nax];
bool lessthan(v3 a, v3 b){
    int x = 0;
    int siz = min(a[1] - a[0], b[1] - b[0]);
    // db(siz);
    // db(31-__builtin_clz(siz));
    for(int po = 31-__builtin_clz(siz); siz && po && a[0] <= a[1] && b[0] <= b[1]; po>>=1){
        if(a[0] + po <= a[1] && b[0]+po <= b[1] && hashes.query(a[0], a[0] + po) == hashes.query(b[0], b[0] + po)){
            // db(po);
            a[0] += po+1, b[0] += po+1;
        }
    }
    // db(a[0]), 
    // db(a[1]), 
    // db(b[0]), 
    // db(b[1]); 
    return a[1] < a[0] || (b[0] <= b[1] && A[a[0]] < A[b[0]]);
}
vi cur;
void go(int u){
    db(u);
    vis[u] = true;
    sort(all(g[u]), [&](v3 a, v3 b){
        return lessthan(a,b);
    });
    cur.pb(u);
    dp[u] = cur;
    for(auto& [l ,r, v]: g[u]){
        if(!vis[v]){
            go(v);
        }
    }
    cur.pop_back();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prepare();
    int n, m, d, s;
    cin>>n>>m>>d>>s;
    cin>>A;
    --s;
    hashes = hashing<string>(A);
    forn(i,m){
        int u, v, l, siz;
        cin>>u>>v>>l>>siz;
        --u,--v,--l;
        int r = l + siz - 1;
        g[u].pb({l, r, v});
    }

    // db(lessthan({1,2,1}, {0,2,1}));
    // db(lessthan({0,2,1}, {1,2,1}));
    // db((hashes.query(1,2) == hashes.query(3,4)));
    // db(lessthan({2,3,1}, {3,4,1}));
    go(s);
    forn(i,n){
        cout<<sz(dp[i])<<el;
        for(int x : dp[i])
            cout<<x<<" ";
        cout<<el;
    }
}

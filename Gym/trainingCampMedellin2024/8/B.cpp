#include <bits/stdc++.h>

#define el '\n'
#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x)(int) x.size()

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

const ll inf = 1e17;
const int N=1e5+10, K = 20;
ll st[N][K+1];

struct RMQ{
    ll neutro = -inf;
    inline ll oper(ll a, ll b){
        return a<b?a:b;
    }
    RMQ(vll&a){
        forn(i,sz(a)) st[i][0] = a[i];
        for1(j,K-1)
            forn(i,sz(a)-(1<<j) + 1)
                st[i][j] = oper(st[i][j-1], st[i+ (1<<(j-1))][j-1]);
    }
    ll query(int l,int r){
        if(l>r) return neutro;
        int j = 31- __builtin_clz(r-l+1);
        return oper(st[l][j], st[r-(1<<j) + 1][j]);
    }
};

ll sum (vll & pref, int l,int r){
    return pref[r] - (l > 0 ? pref[l-1] : 0);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,c;
    cin>>n>>c;
    vector<ll>a(n+1, inf);
    forn(i,n)cin>>a[i];
    vector<ll> pref = a;
    for1(i,n-1) pref[i] = pref[i-1] + pref[i];
    RMQ rmq(a);
    vector<ll> dp(n+1, inf);
    dp[0] = 0;
    forn(i,n){
        if(i+c <= n)
            dp[i+c] = min(dp[i] - rmq.query(i, i+c-1) + sum(pref,i, i+c-1), dp[i+c]);
        dp[i+1] = min(dp[i+1], dp[i] + a[i]);
    }
    cout<<dp[n]<<el;
}
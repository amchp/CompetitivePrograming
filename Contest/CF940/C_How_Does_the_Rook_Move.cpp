#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const int inf = 1e9;
const int nax = 3e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

const int mod = 1e9 + 7;

struct mint{
    int x;
    mint(){}
    mint(int x): x(x){}
    mint operator+(mint b){
        int ans = x + b.x;
        if(ans >= mod)ans -= mod;
        return ans;
    }
    mint operator*(mint b){
        return 1LL*x*b.x%mod;
    }
};

mint fact[nax];

mint binpow(mint b, int e){
    mint ans = 1;
    for(; e; b = b*b, e /= 2){
        if(e & 1)ans = ans * b;
    }
    return ans;
}

mint inv(mint x){
    return binpow(x, mod - 2);
}

mint C(int n, int r){
    if(n < r)return 0;
    return fact[n]*inv(fact[r]*fact[n - r]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    fact[0] = 1;
    for1(i, nax - 1){
        fact[i] = fact[i - 1] * i;
    }
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        forn(i, k){
            int u, v;
            cin >> u >> v;
            if(u == v)--n;
            else n -= 2;
        }
        mint ans = 0;
        vector<mint> dp(n + 1);
        dp[0] = 1;
        for(int i = 2; i <= n; i += 2){
            dp[i] = dp[i - 2]*(i-1);
            ans = ans + dp[i]*C(n, i)*binpow(2, i / 2);
        }
        cout << (ans+1).x << el;
    }
}
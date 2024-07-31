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
const int nax = 5e3+200;
const ld pi = acos(-1);
const ld eps= 1e-9;
const int mod = 998244353;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct mint{
    int x;
    mint(): x(0){}
    mint(ll x): x(x % mod){}
    mint operator+(mint b){
        int ans = x + b.x;
        if(ans >= mod)ans -= mod;
        return ans;
    }
    mint operator-(mint b){
        int ans = x - b.x;
        if(ans < 0)ans += mod;
        return ans;
    }
    mint operator*(mint b){
        return 1LL*x*b.x%mod;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n;
    cin >> n;
    vi a(n);
    forn(i, n)cin >> a[i];
    sort(all(a));
    vector<vector<mint>> dp(n + 1, vector<mint>(nax));
    dp[0][0] = 1;
    vector<mint> pre(nax + 1);
    mint ans = 0;
    forn(i, n){
        forn(j, nax){
            dp[i + 1][j] = dp[i + 1][j] + dp[i][j];
            if(j - a[i] >= 0){
                dp[i + 1][j] = dp[i + 1][j] + dp[i][j - a[i]];
            }
            if(j <= 2*a[i]){
                if(j < a[i])continue;
                ans = ans + dp[i][j - a[i]]*a[i];
            }else{
                ans = ans + dp[i][j - a[i]]*((j + 1)/2);
            }
        }
    }
    cout << ans.x << el;
}
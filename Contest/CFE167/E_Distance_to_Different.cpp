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
#define db(x) cout<< #x<< " " << x<<el
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
const int nax = 2e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;
const int mod = 998244353;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct mint{
    ll x;
    mint(): x(0){}
    mint(ll x): x(x){}
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
};

int n, k;
mint dp[nax][12];
mint sm[12];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    cin >> n >> k;

    dp[0][0] = 1;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;

    sm[0] = 1;
    sm[1] = 2;
    sm[2] = 1;
    fore(j, 3, k)sm[j] = 0;
    
    fore(i, 3, n){
        fored(j, 1, k){
            dp[i][j] = sm[j - 1];
            if(j == k)dp[i][j] = dp[i][j] + sm[j];

            dp[i][j] = dp[i][j] - dp[i - 2][j - 1];
            if (j == k) dp[i][j] = dp[i][j] - dp[i - 2][j];

            sm[j] = sm[j] + dp[i][j];
        }
    }

    mint ans = 0;
    for(int i = 0; i < n; ++i){
        // db(i);
        // db(dp[i][k - 1].x);
        // db(dp[i][k].x);
        ans = ans + dp[i][k - 1];
        ans = ans + dp[i][k];
    }
    cout << ans.x << el;
}
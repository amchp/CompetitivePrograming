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
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;
const int mod = 1e9 + 7;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct mint{
    int x;
    mint(): x(0){}
    mint(ll x) : x(x % mod){}
    mint operator+(mint b){
        int ans = x + b.x;
        if(ans >= mod)ans -= mod;
        return ans;
    }
    mint operator*(mint b){
        return 1LL*x*b.x%mod;
    }
};

int trans(int x){
    return x + 7200;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    queue<ii> q;
    mint dp[801][14401];
    fore(j, -9, 9){
        if(j == 0)continue;
        int tj = trans(j);
        dp[0][tj] = 9 - abs(j);
    }
    forn(n, 800){
        forn(diff, 14401){
            fore(j, -9, 9){
                if(diff + j < 0 || diff + j >= 14401)continue;
                if(j == 0)continue;
                dp[n + 1][diff + j] = dp[n + 1][diff + j] + mint(10-abs(j))*dp[n][diff];
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n - 1][0].x << el;
    }
}
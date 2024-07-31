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


const ll inf = 1e18;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        int n, m, k, dis;
        cin >> n >> m >> k >> dis;
        vector<vi> mtx(n, vi(m));
        forn(i, n){
            forn(j, m)cin >> mtx[i][j];
        }
        vector<vll> dp(n, vll(m));
        forn(i, n){
            map<ll, int> mp;
            dp[i][m - 1] = 1;
            ++mp[1];
            int st = max(0, m - dis - 2);
            fored(j, st, m - 2){
                dp[i][j] = (*mp.begin()).fi + mtx[i][j] + 1;
                ++mp[dp[i][j]];
            }
            ford(j, st){
                ll val = dp[i][j + dis + 2];
                --mp[val];
                if(mp[val] == 0)mp.erase(val);
                dp[i][j] = (*mp.begin()).fi + mtx[i][j] + 1;
                ++mp[dp[i][j]];
            }
        }
        ll ans = inf;
        ll cans = 0;
        forn(i, k)cans += dp[i][0];
        ans = min(ans, cans);
        fore(i, k, n - 1){
            cans += dp[i][0];
            cans -= dp[i - k][0];
            ans = min(ans, cans);
        }
        cout << ans << el;
        // forn(i, n){
        //     forn(j, m)cout << dp[i][j] << ' ';
        //     cout << el;
        // }
    }
}
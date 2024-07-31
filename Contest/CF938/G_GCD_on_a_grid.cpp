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
const int nax = 110;
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
        int n, m;
        cin >> n >> m;
        vector<vi> brd(n, vi(m));
        vi facts;
        forn(i, n){
            forn(j, m)cin >> brd[i][j];
        }
        int num = brd[0][0];
        for(int i = 1; i*i <=num; ++i){
            if(num % i == 0){
                facts.pb(i);
                int j = num / i;
                if(j != i)facts.pb(j);
            }
        }
        sort(all(facts));
        int f = sz(facts);
        // forn(i, f)cout << facts[i] << ' ';
        // cout << el;
        vector<vector<vector<bool>>> dp(
            n, 
            vector<vector<bool>>(
                m, 
                vector<bool>(
                    f,
                    false
                )
            )
        );
        forn(i, f){
            dp[0][0][i] = true;
        }
        forn(i, n){
            forn(j, m){
                forn(k, f){
                    if(i != 0){
                        dp[i][j][k] = dp[i][j][k] || ((dp[i - 1][j][k]) && (brd[i][j] % facts[k] == 0));
                    }
                    if(j != 0){
                        dp[i][j][k] = dp[i][j][k] || ((dp[i][j - 1][k]) && (brd[i][j] % facts[k] == 0));
                    }
                }
                
            }
        }
        int ans = 1;
        forn(i, f){
            if(dp[n - 1][m - 1][i])ans = max(ans, facts[i]);
        }
        cout << ans << el;
    }

}
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

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, fk;
    cin >> n >> fk;
    int pld = (fk + 1) / 2;
    int od = fk&1;
    vector<vector<vi>> dp(
        pld + 1,
        vector<vi>(
            n, 
            vi(n, inf)
        )
    );
    string s;
    cin >> s;
    forn(i, n){
        forn(j, n){
            dp[0][i][j] = 0;
        }
    }
    if(od){
        forn(i, n){
            fore(j, i, n - 1){
                dp[1][i][j] = 0;
            }
        }
    }else{
        forn(i, n){
            fore(j, i + 1, n - 1){
                dp[1][i][j] = s[i] != s[j];
            }
        }
    }
    for1(k, pld){
        fore(szs, 2, n - 1){
            forn(i, n - szs){
                int j = i + szs;
                dp[k][i][j] = min({
                    dp[k][i + 1][j],
                    dp[k][i][j - 1],
                    dp[k - 1][i + 1][j - 1] + (s[i] != s[j])
                });
            }
        }
    }
    int ans = inf;
    forn(i, n){
        fore(j, i, n - 1){
            ans = min(ans, dp[pld][i][j]);
        }
    }
    cout << ans << el;
}
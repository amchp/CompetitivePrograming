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
const int nax = 110;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

ld dp[nax][nax][nax];

ld sol(int n, int m, int k){
    if(n == 0 || m == 0)return 0;
    ld& ans = dp[n][m][k];
    if(ans != -1)return ans;
    ld p1 = ld(n) / (n + m);
    ld p2 = ld(m) / (n + m);
    ans = p1*sol(n - 1, m, max(0, k - 1)) + p2*sol(n, m - 1, k + 1);
    if(!k)ans += p1*n;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n;
    cin >> n;
    forn(i, n + 10){
        forn(j, n + 10){
            forn(k, n + 10){
                dp[i][j][k] = -1;
            }
        }
    }
    cout << sol(n, n, 0);
}
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
const int nax = 5001;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int dp[nax][nax];
vi a;

int sol(int ind, int alc){
    if(ind >= sz(a))return 0;
    int& ans = dp[ind][alc];
    if(ans != -1)return ans;
    ans = sol(ind + 1, alc + 1) + 1;
    if(a[ind] <= alc){
        ans = min(ans, sol(ind + 1, alc - a[ind]));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        a.clear();
        int n;
        cin >> n;
        map<int, int> mp;
        forn(i, n){
            int v;
            cin >> v;
            ++mp[v];
        }
        for(auto& [v, cnt] : mp){
            // cout << v << ' ' << cnt << el;
            a.pb(cnt);
        }
        forn(i, sz(a) + 1){
            forn(j, sz(a)){
                dp[i][j] = -1;
            }
        }
        cout << sol(0, 0) << el;
    }
}
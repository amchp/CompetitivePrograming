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
typedef array<int, 3> a3;

const int inf = 1e9 + 100;
const int nax = 1e6+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int n;
ll s;
vector<a3> a;
ll dp[nax];

ll sol(int ind){
    if(ind == -1)return 0;
    ll& ans = dp[ind];
    if(ans != -1)return ans;
    ans = 0;
    auto& [r, l, c] = a[ind];
    int nxt = lower_bound(all(a), a3{l, -inf, -inf}) - a.begin() - 1;
    d(ind);
    d(nxt);
    ans = max(ans, sol(ind - 1));
    ans = max(ans, sol(nxt) + 1LL*c*(r - l + 1));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    cin >> n >> s;
    a.resize(n);
    forn(i, n){
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    }
    sort(all(a));
    forn(i, n)cout << a[i][0] << ' ';
    cout << el;
    forn(i, n)dp[i] = -1;
    ll ans = sol(n - 1);
    cout << ans << el;
}
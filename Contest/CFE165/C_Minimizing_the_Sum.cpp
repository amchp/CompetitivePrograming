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

int n, k;
int a[nax];
ll dp[nax][11];
ll pre[nax];
const int N = 3e5 + 10, K = 20;  //K  has to satisfy K> log nax + 1
ll st[N][K];
struct RMQ{
  ll neutro = 1e18;
  inline ll oper(ll a, ll b){ return a < b ? a : b; }
  RMQ(){}
  RMQ(vi& a){
    forn(i, sz(a)) st[i][0] = a[i];
    for1(j, K-1)
      forn(i, sz(a) - (1 << j) + 1)
        st[i][j] = oper(st[i][j-1], st[i + (1 << (j-1))][j-1]);
  }
  ll query(int l, int r){
    if(l > r) return neutro;
    int j = 31 - __builtin_clz(r-l+1);
    return oper(st[l][j], st[r - (1 << j) + 1][j]);
  }
};

RMQ rmq;

ll sol(int ind, int op){
    if(ind >= n)return 0;
    ll& ans = dp[ind][op];
    if(ans != -1)return ans;
    ans = 0;
    forn(i, op + 1){
        if(ind + i >= n)break;
        int l = ind;
        int r = ind + i;
        ll ism = pre[r] - (l != 0 ? pre[l - 1] : 0);
        ll mn = rmq.query(l, r);
        ll fsm = ism - mn*(r - l + 1);
        ans = max(ans, sol(ind + i + 1, op - i) + fsm);
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
        cin >> n >> k;
        vi ca(n);
        forn(i, n){
            cin >> a[i];
            ca[i] = a[i];
        }
        pre[0] = a[0];
        rmq = RMQ(ca);
        for1(i, n - 1){
            pre[i] = pre[i - 1] + a[i];
        }
        forn(i, n){
            forn(j, k + 1){
                dp[i][j] = -1;
            }
        }
        ll ans = sol(0, k);
        cout << pre[n - 1] - ans << el;
    }
}
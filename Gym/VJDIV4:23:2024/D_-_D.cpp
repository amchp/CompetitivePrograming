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
    int n, m;
    cin >> n >> m;
    vll edist(n + 1, 0);
    vi a(m);
    forn(i, m){
        cin >> a[i];
        --a[i];
    }
    ll ans = 0;
    forn(i, m - 1){
        int u = min(a[i], a[i + 1]), v = max(a[i], a[i + 1]);
        int d1, d2;
        d1 = v - u;
        d2 = u + (n - v);
        if(d1 <= d2){
            edist[u] += d2 - d1;
            edist[v] -= d2 - d1;
            ans += d1;
        }else{
            edist[0] += d1 - d2;
            edist[u] -= d1 - d2;
            edist[v] += d1 - d2;
            edist[n] -= d1 - d2;
            ans += d2;
        }
    }
    // d(ans);
    ll pre = 0;
    ll mn = inf;
    forn(i, n){
        pre += edist[i];
        edist[i] = pre;
        // d(edist[i]);
        mn = min(mn, edist[i]);
    }
    ans += mn;
    cout << ans << el;
}
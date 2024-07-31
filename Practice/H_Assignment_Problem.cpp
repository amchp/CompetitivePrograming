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
typedef ll ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;

const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

const ld inf = 1e18; // To Maximize set "inf" to 0, and negate costs
inline bool zero(ld x){ return x == 0; } // For Integer/LL --> change to x == 0
struct Hungarian{
  int n; vector<vll> c;
  vi l, r, p, sn;  vll ds, u, v;
  Hungarian(int n): n(n), c(n, vll(n, inf)), l(n, -1), r(n, -1), p(n), sn(n), ds(n), u(n), v(n){}
  void set_cost(){ forn(i, n) forn(j, n) cin >> c[i][j]; }
  ld assign() {
    set_cost();
        forn(i, n) u[i] = *min_element(all(c[i]));
        forn(j, n){ 
    v[j] = c[0][j] - u[0]; 
    for1(i, n-1) v[j] = min(v[j], c[i][j] - u[i]);
    }
        int mat = 0;
        forn(i, n) forn(j, n) if(r[j] == -1 && zero(c[i][j] - u[i]  -v[j])){
    l[i] = j,  r[j] = i, ++mat; break;
    }
        for(; mat < n; ++mat){
    int s = 0, j = 0, i;
    while(l[s] != -1) ++s;
    forn(k, n) ds[k] = c[s][k] - u[s] - v[k];
    fill(all(p), -1),  fill(all(sn), 0);
    while(1){
        j = -1;
        forn(k, n) if(!sn[k] && (j == -1 || ds[k] < ds[j])) j = k;
        sn[j] = 1,  i = r[j];
        if(i == -1) break;
        forn(k, n) if(!sn[k]){
        auto n_ds = ds[j] + c[i][k] - u[i] - v[k];
        if(ds[k] > n_ds) ds[k] = n_ds,  p[k] = j;
        }
    }
    forn(k, n) if(k != j && sn[k]){
        auto dif = ds[k] - ds[j];
        v[k] += dif, u[r[k]] -= dif;
    } 
    u[s] += ds[j];
    while(p[j] >= 0) r[j] = r[p[j]],  l[r[j]] = j,  j = p[j];
    r[j] = s,  l[s] = j;
        }
        ld val = 0;
    forn(i, n) val += c[i][l[i]];
        return val;
    }
  void print_assignment(){ forn(i, n) cout << i+1 << " " << l[i]+1 << el; }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n;
    cin >> n;
    Hungarian hgrn = Hungarian(n);
    hgrn.set_cost();
    ll ans = hgrn.assign();
    cout << ans << el;
    hgrn.print_assignment();
}
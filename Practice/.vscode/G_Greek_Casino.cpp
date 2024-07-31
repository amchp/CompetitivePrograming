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
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct frac{
    ll num, dem;
    frac(){}
    frac(int num, int dem): num(num), dem(dem){
        simplify();
    }
    void simplify(){
        int g = __gcd(num, dem);
        num /= g;
        dem /= g;
    }
    frac operator+(frac b){
        ll lc = lcm(dem, b.dem);
        ll anum = num * (lc / dem) + b.num *(lc / b.dem);
        return frac(anum, lc);
    }
    frac operator-(frac b){
        ll lc = lcm(dem, b.dem);
        ll anum = num * (lc / dem) - b.num *(lc / b.dem);
        return frac(anum, lc);
    }
    frac operator*(frac b){
        ll anum = num*b.num;
        ll adem = dem*b.dem;
        return frac(anum, adem);
    }
    frac operator/(frac b){
        ll anum = num*b.dem;
        ll adem = b.num*dem;
        return frac(anum, adem);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n;
    cin >> n;
    vi a(n + 1);
    int sm = 0;
    for1(i, n){
        cin >> a[i];
        sm += a[i];
    }
    vector<vi> divs(n + 1);
    for1(i, n){
        for(int j = 1; j*j <= i; ++j){
            if(i % j == 0){
                int oj = i / j;
                divs[i].pb(j);
                if(j != oj)divs[i].pb(oj);
            }
        }
        sort(all(divs[i]));
    }
    vector<frac> st(n + 1);
    vi stc(n + 1);
    vi tc(n + 1);
    vi ntc(n + 1);
    for1(i, n){
        for(int& div : divs[i]){
            int oi = i / div;
            stc[i] += a[div];
            if(i != div){
                tc[div] += a[i];
            }
            if(div != 1 && __gcd(div, oi) == 1){
                tc[div] += a[oi];
            }
        }
        st[i] = frac(stc[i], sm);
    }
    for1(i, n){
        // cout << tc[i] << ' ';
        ntc[i] = sm - stc[i] - tc[i];
    }
    // cout << el;
    vector<frac> ans(n + 1, frac(0, 1));
    for1(i, n / 2)ans[i] = frac(1, 1);
    fored(i, 1, n){
        ans[i] = ans[i] + (st[i]/(frac(1, 1) - st[i]));
        // d(i);
        // d(ans[i].num);
        // d(ans[i].dem);
        for(int& div : divs[i]){
            if(div == i)continue;
            // d(sm);
            // d(stc[div]);
            // d(ntc[div]);
            frac cnd = frac(a[i], sm - stc[div] - ntc[div]);
            // d(cnd.num);
            // d(cnd.dem);
            ans[div] = ans[div] + cnd*ans[i];
            // d(div);
            // d(ans[div].num);
            // d(ans[div].dem);
            if(div != 1 && __gcd(div, i / div) == 1){
                ans[div] = ans[div] + frac(a[i / div], sm - stc[div] - ntc[div])*ans[i];
            }
        }
    }
    cout << ans[1].num / ld(ans[1].dem) << el;
}
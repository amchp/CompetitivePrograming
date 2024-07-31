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

ll lv, rv, val;
vll func;

ll f(int x){
    ll ttl = func[x] + val;
    ll ans = max(abs(ttl - lv), abs(ttl - rv));
    return ans;
}

ll ternary_search(int l, int r){
    while(r - l >= 10){
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        ll f1 = f(m1), f2 = f(m2);
        if(f1 > f2)l = m1;
        else r = m2;
    }
    ll ans = inf;
    fore(i, l, r){
        ans = min(ans, f(i));
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
        int n, m, nk;
        cin >> n >> m >> nk;
        vll a(n), dif(m);
        func = vll(nk);
        vector<pll> da(n - 1);
        forn(i, n)cin >> a[i];
        forn(i, m)cin >> dif[i];
        forn(i, nk)cin >> func[i];
        sort(all(func));
        for1(i, n - 1){
            da[i - 1].fi = a[i] - a[i - 1];
            da[i - 1].se = i;
        }
        sort(all(da), greater<pll>());
        lv = a[da[0].se - 1];
        rv = a[da[0].se];
        ll ans = da[0].fi;
        forn(i, m){
            val = dif[i];
            int st = lower_bound(all(func), lv - val) - func.begin();
            int e = upper_bound(all(func), rv - val) - func.begin();
            e = max(0, e - 1);
            ans = min(ans, ternary_search(st, e));
        }
        if(n > 2)ans = max(ans, da[1].fi);
        cout << ans << el;
    }
}
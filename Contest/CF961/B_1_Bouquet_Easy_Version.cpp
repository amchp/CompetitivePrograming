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
    int t;
    cin >> t;
    while(t--){
        int n;
        ll m;
        cin >> n >> m;
        vector<pll> a(n);
        forn(i, n){
            cin >> a[i].fi;
        }
        forn(i, n)cin >> a[i].se;
        sort(all(a));
        ll ans = 0;
        forn(i, n){
            ll num = m / a[i].fi;
            ans = max(ans, a[i].fi*min(num, a[i].se));
        }
        forn(i, n - 1){
            ll num = min(m / a[i].fi, a[i].se);
            ll dif = m - num*a[i].fi;
            ll num2 = min(a[i + 1].se, dif / a[i + 1].se);
            ll dif2 = dif - num2*a[i + 1].se;
            ll shf = min(num, a[i + 1].se - num2);
            ans = max(ans, m - max(0LL, dif2 - shf));
        }
        cout << ans << el;
    }
}
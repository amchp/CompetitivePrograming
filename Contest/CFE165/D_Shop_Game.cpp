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
typedef array<ll, 3> a3;


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
        int n, k;
        cin >> n >> k;
        vll a(n), b(n);
        forn(i, n)cin >> a[i];
        forn(i, n)cin >> b[i];
        vector<ii> gr;
        forn(i, n){
            if(a[i] < b[i]){
                gr.pb({b[i], i});
            }
        }
        sort(all(gr), greater<ii>());
        ll bl = 0;
        map<ll, int> bc;
        forn(i, min(sz(gr), k)){
            bl += a[gr[i].se];
            ++bc[a[gr[i].se]];
        }
        ll ag = 0;
        fore(i, k, sz(gr) - 1){
            ag += b[gr[i].se] - a[gr[i].se];
        }
        ll ans = max(0LL, ag - bl);
        fore(i, k, sz(gr) - 1){
            if(k != 0){
                ll val = (*bc.rbegin()).fi;
                bl -= val;
                bl += a[gr[i].se];
                --bc[val];
                if(bc[val] == 0)bc.erase(val);
                ++bc[a[gr[i].se]];
            }
            ag -= b[gr[i].se] - a[gr[i].se];
            ans = max(ans, ag - bl);
        }
        cout << ans << el;
    }
}
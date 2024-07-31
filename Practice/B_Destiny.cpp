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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, q;
    cin >> n >> q;
    vi a(n);
    vi mp(n + 1);
    vi over;
    forn(i, n){
        cin >> a[i];
        ++mp[a[i]];
        if(mp[a[i]] == 400)over.pb(a[i]);
    }
    forn(i, n)mp[a[i]] = 0;
    vector<vi> pre(sz(over), vi(n + 1));
    for1(i, n){
        forn(j, sz(over)){
            pre[j][i] = over[j] == a[i - 1];
            pre[j][i] += pre[j][i - 1];
        }
    }
    forn(_, q){
        int l, r, k;
        cin >> l >> r >> k;
        int tam = r - l + 1;
        int trsh = tam / k;
        // d(trsh);
        int ans = inf;
        if(tam < 2000){
            --l;
            --r;
            fore(i, l, r){
                ++mp[a[i]];
            }
            fore(i, l, r){
                // d(a[i]);
                if(mp[a[i]] > trsh)ans = min(a[i], ans);
                mp[a[i]] = 0;
            }
            
        }else{
            forn(i, sz(over)){
                int num = pre[i][r] - pre[i][l - 1];
                if(num > trsh)ans = min(over[i], ans);
            }
        }
        if(ans != inf)cout << ans << el;
        else cout << "-1" << el;
    }
}
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
#define db(x) cerr<< #x<< " " << x<<el
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

int n, sq;
vi a;
vector<vi> gt;

int calc_nxt(int lvl, int cur, int x){
    assert(lvl <= sq);
    vi& vec = gt[lvl];
    int pos = lower_bound(all(vec), cur) - vec.begin();
    if(x - 1 > sz(vec) - 1 - pos){
        return n;
    }
    return vec[pos + x - 1] + 1;
}

bool sol(int i, int x){
    int cur = 0;
    int lvl = 1;
    while(cur <= i){
        cur = calc_nxt(lvl, cur, x);
        ++lvl;
    }
    --lvl;
    return a[i] >= lvl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int q;
    cin >> n >> q;
    a = vi(n);
    sq = ceil(sqrt(n)) + 9;
    forn(i, n){
        cin >> a[i];
    }
    vector<vi> dp(sq + 1, vi());
    for1(k, sq){
        int lvl = 1;
        int cnt = 0;
        forn(i, n){
            if(a[i] >= lvl)++cnt;
            if(cnt == k){
                cnt = 0;
                ++lvl;
                dp[k].pb(i + 1);
            }
        }
    }
    gt = vector<vi>(sq + 1, vi());
    for1(lvl, sq){
        forn(i, n){
            if(a[i] >= lvl)gt[lvl].pb(i);
        }
    }
    while(q--){
        int i, x;
        cin >> i >> x;
        --i;
        if(x <= sq){
            int lvl = upper_bound(all(dp[x]), i) - dp[x].begin() + 1;
            if(a[i] >= lvl)cout << "YES" << el;
            else cout << "NO" << el;
            continue;
        }
        if(sol(i, x)){
            cout << "YES" << el;
        }else{
            cout << "NO" << el;
        }
    }
}
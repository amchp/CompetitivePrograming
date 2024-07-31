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

int p[nax];
int szs[nax];

int find(int x){
    if(x == p[x])return x;
    return p[x] = find(p[x]);
}

bool merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)return false;
    if(szs[u] > szs[v])swap(u, v);
    p[u] = v;
    szs[v] += szs[u];
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n;
    cin >> n;
    vi a(n);
    vector<vi> mp(nax);
    int mx = 0;
    forn(i, n){
        cin >> a[i];
        mx = max(mx, a[i]);
        mp[a[i]].pb(i);
    }
    forn(i, n){
        p[i] = i;
        szs[i] = 1;
    }
    int cmp = 0;
    vll ans(mx + 1);
    vll dp(mx + 1);
    ans[mx] = 1;
    dp[0] = 0;
    vector<bool> alive(n, false);
    fored(at, 2, mx){
        for(int& i : mp[at]){
            alive[i] = true;
            int mgs = 0;
            if(i > 0 && alive[i - 1])
                mgs += merge(i - 1, i);
            if(i < n - 1 && alive[i + 1])
                mgs += merge(i, i + 1);
            if(mgs == 0)++cmp;
            if(mgs == 2)--cmp;
        }
        int cur = mx - (at - 1);
        dp[cur] = cmp;
        ans[at - 1] += 1;
        for(; cur > 0; cur -= (at - 1)){
            ans[at - 1] += dp[cur];
        }
    }
    cout << el;
    for1(i, mx){
        cout << ans[i] << ' ';
    }
    cout << el;
}
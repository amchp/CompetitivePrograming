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

void adddp(vii& vec, int l, int r){
    if(sz(vec)){
        int lst = vec.back().se;
        if(l - 1 <= lst)vec.back().se = max(lst, r);
        else vec.pb({l, r});
    }else{
        vec.pb({l, r});
    }
};

vii dp[(1 << 18) + 100];

void merge(int ind, int jnd, int knd){
    vii& vic = dp[ind], vjc = dp[jnd];
    int i = 0, j = 0;
    while(i < sz(vic) && j < sz(vjc)){
        auto& [li, ri] = vic[i];
        auto& [lj, rj] = vjc[j];
        if(vic[i] < vjc[j]){
            adddp(dp[knd], li, ri);
            ++i;
        }else{
            adddp(dp[knd], lj, rj);
            ++j;
        }
    }
    while(i < sz(vic)){
        auto& [li, ri] = vic[i];
        adddp(dp[knd], li, ri);
        ++i;
    }
    while(j < sz(vjc)){
        auto& [lj, rj] = vjc[j];
        adddp(dp[knd], lj, rj);
        ++j;
    }
};

void sol(){
    int n, c, k;
    cin >> n >> c >> k;
    string s;
    cin >> s;
    vector<vi> mp(c);
    forn(i, n){
        mp[s[i] - 'A'].pb(i);
    }
    int ed = 1 << c;
    forn(i, ed){
        dp[i].clear();
    }
    int ans = c;
    forn(i, c){
        vii& vec = dp[(1 << i)];
        for(int& ind : mp[i]){
            adddp(vec, max(0, ind - (k - 1)), ind);
        }
        if(vec == vii{{0, n - 1}})ans = min(ans, 1);
    }
    for1(bt, ed - 1){
        int cnt = __popcount(bt);
        if(cnt == 1)continue;
        // db(bt);
        int lst = 31 - __builtin_clz(bt);
        int jnd = 1 << lst;
        int ind = bt ^ jnd;
        merge(ind, jnd, bt);
        // db(sz(dp[bt]));
        // for(auto& [l, r] : dp[bt])cout << l << ' ' << r << el;
        // cout << "#####" << el;
        if(dp[bt] == vii{{0, n - 1}})ans = min(ans, cnt);
    }
    cout << ans << el;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}
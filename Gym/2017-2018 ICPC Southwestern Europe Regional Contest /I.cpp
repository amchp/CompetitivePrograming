#include <bits/stdc++.h>
#define el '\n'
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r)for(int i = l; i <= (int)r; ++i)
#define fored(i, l, r)for(int i = r; i >= (int)l; --i)
#define all(a) a.begin(), a.end()
#define d(x) cerr<<#x<<" "<<x<<el
#define sz(x) x.size()
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef array<int, 4> a4;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int nax = 1010;

int n, m;
int dp[nax][10][10];
vi ladd[nax], jar[nax];
vector<vi> pref;

int calc_pref(int lvl, int l, int r){
    return pref[lvl][r] - (l > 0 ? pref[lvl][l - 1] : 0);
}

bool valid(int l1, int r1, int l2, int r2, int lvl){
    int l = max(l1, l2);
    int r = min(r1, r2);
    return l > r || calc_pref(lvl, l, r) == 0;
}

a4 intervals(int lvlp, int lvl1, int lvl2, int ind1, int ind2){
    int pos1 = ladd[lvl1][ind1], pos2 = ladd[lvl2][ind2];
    int l = min(pos1, pos2), r = max(pos1, pos2);
    int oil = upper_bound(all(jar[lvlp]), l) - jar[lvlp].begin() - 1;
    int oir = lower_bound(all(jar[lvlp]), r) - jar[lvlp].begin();
    int ovl = oil >= 0 ? jar[lvlp][oil] : l;
    int ovr = oir < sz(jar[lvlp]) ? jar[lvlp][oir] : r;
    return a4{l, r, ovl, ovr};
}

int go(int lvl, int d1, int u2){
    if(lvl == n)return 0;
    int &v = dp[lvl][d1][u2];
    if(v != -1)return v;
    // cerr << lvl << ' ' << d1 << ' ' << u2 << el;
    int nfl = sz(ladd[lvl]);
    auto [cl, cr, col, cor] = intervals(lvl, lvl - 1, lvl - 1, d1, u2);
    v = calc_pref(lvl, col, cor);
    forn(d2,nfl){
        forn(u1,nfl){
            auto [l1, r1, lo1, ro1] = intervals(lvl, lvl - 1, lvl, d1, d2);
            auto [l2, r2, lo2, ro2] = intervals(lvl, lvl, lvl - 1, u1, u2);
            if(!valid(l1, r1, l2, r2, lvl))continue;
            int sm = calc_pref(lvl, lo1, ro1) + calc_pref(lvl, lo2, ro2);
            int l = max(lo1, lo2), r = min(ro1, ro2);
            if(l <= r)sm -= calc_pref(lvl, l, r);
            v = max(v, sm + go(lvl + 1, d2, u1));
        } 
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.precision(21);
    cin >> n >> m;
    pref = vector<vi>(n, vi(m));
    forn(i,2*n){
        string lvl;
        cin>>lvl;
        if(!(i & 1)){
            forn(j,m){
                char c = lvl[j];
                if(c != '-'){
                    pref[i / 2][j] = c - '0';
                    jar[i / 2].pb(j);
                }
                pref[i / 2][j] += j != 0 ? pref[i / 2][j - 1] : 0;
                // cout << pref[i / 2][j] << ' ';
            }
            // cout << el;
        }else{
            forn(j,m){
                char c = lvl[j];
                if(c == '|') ladd[i / 2].pb(j);
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    int nfl = sz(ladd[0]);
    int ans = 0;
    forn(i,nfl){
        forn(j,nfl){
            ans = max(ans, go(1, i, j));
        }
    }
    cout << ans << el;
}
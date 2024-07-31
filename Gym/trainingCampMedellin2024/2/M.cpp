#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define ford(i, n) for(int i = (int)n - 1; i >= 0; --i)
#define el '\n'
#define all(x) x.begin(), x.end()
#define d(x) cerr<<#x<<" "<<x<<el
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
const ll inf = 2e18;

ii operator+(ii a, ii b){return {a.fi + b.fi, a.se + b.se};}
ii operator-(ii a, ii b){return {a.fi - b.fi, a.se - b.se};}
void sol(){
    int n, q;
    cin >> n >> q; 
    unordered_map<int, unordered_map<int, vi>> pre, suf;
    string s;
    cin >> s;
    vector<ii> prevec(n), sufvec(n);
    forn(i, n){
        char& c = s[i];
        if(c == 'U')prevec[i] = {0, 1};
        if(c == 'D')prevec[i] = {0, -1};
        if(c == 'L')prevec[i] = {-1, 0};
        if(c == 'R')prevec[i] = {1, 0};
    }
    forn(i, n)sufvec[i] = prevec[i];

    pre[0][0].pb(-1);
    pre[prevec[0].fi][prevec[0].se].pb(0);
    for1(i, n - 1){
        prevec[i] = prevec[i] + prevec[i - 1];
        pre[prevec[i].fi][prevec[i].se].pb(i);
    }

    ford(i, n - 1){
        sufvec[i] = sufvec[i] + sufvec[i + 1];
    }
    forn(i, n){
        suf[sufvec[i].fi][sufvec[i].se].pb(i);
    }

    forn(_, q){
        ll x, y, l, r;
        cin >> x >> y >> l >> r;
        --l;
        --r;
        ii X = {x, y};
        vi& vec = pre[x][y];
        auto it = lower_bound(all(vec), l);
        auto it2 = upper_bound(all(vec), r);
        if(it != vec.begin() || it2 != vec.end()){
            cout << "YES" << el;
            continue;
        }
        ii st = {0, 0};
        if(l > 0)st = prevec[l - 1];
        ii sf = {0, 0};
        if(r < n - 1)sf = sufvec[r + 1];
        ii target = X - st + sf;
        vi& vec2 = suf[target.fi][target.se];
        auto it3 = upper_bound(all(vec2), r);
        if(it3 != vec2.begin()){
            --it3;
            if(l <= (*it3)){
                cout << "YES" << el;
                continue;
            }
        }
        cout << "NO" << el;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
}
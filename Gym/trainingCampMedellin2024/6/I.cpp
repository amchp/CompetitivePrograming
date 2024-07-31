#include <bits/stdc++.h>

#define pb push_back
#define sz(x) x.size()
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i <= r; ++i)
#define el '\n'
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define db(x) cerr << #x << ' ' << x << el;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<ii> sol(){
    int n; cin>>n;
    int k=(n*(n*n+1))/2;
    vector<vi> a(n, vi(n));
    forn(i, n){
        forn(j, n)cin >> a[i][j];
    }
    vector<ii> rws, cols;
    forn(i, n){
        int sm = 0;
        forn(j, n)sm += a[i][j];
        if(sm != k)rws.pb({sm, i});
    }
    forn(j, n){
        int sm = 0;
        forn(i, n){
            sm += a[i][j];
        }
        if(sm != k)cols.pb({sm, j});
    }
    if(sz(rws) == 2 && sz(cols) == 2){
        sort(all(rws));
        sort(all(cols));
        return {{rws[0].se, cols[0].se}, {rws[1].se, cols[1].se}};
    }
    if(sz(rws) == 2){
        int sm1 = rws[0].fi;
        int r1 = rws[0].se;
        auto [sm2, r2] = rws[1];
        int ans = -1;
        forn(j, n){
            int nsm1 = sm1 - a[r1][j] + a[r2][j];
            int nsm2 = sm2 + a[r1][j] - a[r2][j];
            if(nsm1 == k && nsm1 == nsm2){
                ans = j;
                break;
            }
        }
        assert(ans != -1);
        return {{r1, ans}, {r2, ans}};
    }
    assert(sz(cols) == 2);
    auto [sm1, c1] = cols[0];
    auto [sm2, c2] = cols[1];
    int ans = -1;
    forn(i, n){
        int nsm1 = sm1 - a[i][c1] + a[i][c2];
        int nsm2 = sm2 + a[i][c1] - a[i][c2];
        if(nsm1 == k && nsm1 == nsm2){
            ans = i;
            break;
        }
    }
    assert(ans != -1);
    return {{ans, c1}, {ans, c2}};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ii> ans = sol();
    sort(all(ans));
    forn(i, 2)cout << ans[i].fi + 1 << ' ' << ans[i].se + 1 << el;
}
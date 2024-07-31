#include <bits/stdc++.h>

#define el '\n'
#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x)(int) x.size()
#define fi first
#define se second
#define db(x) cerr << #x << ' ' << x << el

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int inf = 2e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> pts(n);
    forn(i, n){
        cin >> pts[i].se >> pts[i].fi;
    }
    sort(all(pts), greater<ii>());
    ll ans = 0;
    ll abv = 0;
    int st = 0;
    map<int, int> cnt;
    for1(i, n - 1){
        if(pts[i - 1].fi != pts[i].fi){
            fore(j, st, i - 1){
                ++cnt[pts[j].se];
                ++abv;
            }
            st = i;
        }
        ans += abv - cnt[pts[i].se];
    }
    cout << ans << el;
}
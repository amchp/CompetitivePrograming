#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 2e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n;
ii seg[nax];

bool sol(int m){
    ii cur = {0, 0};
    forn(i, n){
        if(cur.se < seg[i].fi){
            if(cur.se + m < seg[i].fi)return false;
            cur.fi = seg[i].fi;
            cur.se = min(cur.se + m, seg[i].se);
        }else if(cur.fi > seg[i].se){
            if(cur.fi - m > seg[i].se)return false;
            cur.fi = max(seg[i].fi, cur.fi - m);
            cur.se = seg[i].se;
        }else{
            cur.fi = max(cur.fi - m, seg[i].fi);
            cur.se = min(cur.se + m, seg[i].se);
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        forn(i, n){
            cin >> seg[i].fi >> seg[i].se;
        }
        int l = -1;
        int r = 1e9 + 100;
        while(l + 1 < r){
            int m = l + (r - l) / 2;
            if(sol(m)){
                r = m;
            }else{
                l = m;
            }
        }
        cout << r << el;
    }
}

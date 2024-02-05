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
typedef __int128_t i128;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct circle{
    i128 x, y, r;
    int ind;
    circle(){}
    circle(int x, int y, int r, int i): x(x), y(y), r(r), ind(i){}
    bool operator<(circle& o){
        i128 t = o.x;
        i128 s = o.y;
        i128 c = r - o.r;
        i128 ls = i128(4)*(x*x + y*y)*(t*t + s*s);
        i128 rs = (x*x + y*y + t*t + s*s - c*c);
        rs = rs*rs;
        return rs < ls;
    }
};

bool compare(int m, circle crater){
    i128 x2 = crater.x * crater.x;
    i128 y2 = crater.y * crater.y;
    i128 r2 = crater.r * crater.r;
    i128 m2 = i128(m)*i128(m);
    i128 ls = i128(4)*m*r2*(x2+y2);
    i128 rs = m*x2 + m*y2 + m*r2 - i128(1e6);
    rs = rs*rs;
    return ls > rs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    vector<ii> m(n);
    forn(i, n){
        cin >> m[i].fi;
        m[i].se = i + 1;
    }
    sort(all(m), greater<ii>());
    int k;
    cin >> k;
    vector<circle> craters(k);
    forn(i, k){
        int x, y, r;
        cin >> x >> y >> r;
        craters[i] = circle(x, y, r, i + 1);
    }
    sort(all(craters));
    int j = 0;
    vector<ii> ans;
    forn(i, n){
        if(j >= k)break;
        if(!compare(m[i].fi, craters[j]))continue;
        ans.pb({m[i].se, craters[j].ind});
        ++j;
    }
    cout << sz(ans) << el;
    for(auto& [i, j] : ans){
        cout << i << ' ' << j << el;
    }
}

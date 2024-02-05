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
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {-1, -1, 1, 1};
int dc[] = {-1, 1, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int x1, y1;
        int x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        set<ii> k1;
        forn(i, 4){
            int dx = x1 + a*dr[i];
            int dy = y1 + b*dc[i];
            k1.insert({dx, dy});
        }
        forn(i, 4){
            int dx = x1 + b*dr[i];
            int dy = y1 + a*dc[i];
            k1.insert({dx, dy});
        }
        int ans = 0;
        set<ii> seen;
        forn(i, 4){
            int dx = x2 + a*dr[i];
            int dy = y2 + b*dc[i];
            if(k1.count({dx, dy}))seen.insert({dx, dy});
        }
        forn(i, 4){
            int dx = x2 + b*dr[i];
            int dy = y2 + a*dc[i];
            if(k1.count({dx, dy}))seen.insert({dx, dy});
        }
        cout << sz(seen) << el;
    }
}

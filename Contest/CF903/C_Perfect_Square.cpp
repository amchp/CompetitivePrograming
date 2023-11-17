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

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> mt(n);
        forn(i, n)cin >> mt[i];
        vector<vi> visited(n, vi(n, 0));
        ll ans = 0;
        forn(i, n){
            forn(j, n){
                if(visited[i][j])continue;
                vector<char> ch;
                visited[i][j] = true;
                ch.pb(mt[i][j]);
                int cI = j;
                int cJ = n - i - 1;
                while(cI != i || cJ != j){
                    // cout << cI << ' ' << cJ << ", ";
                    visited[cI][cJ] = true;
                    ch.pb(mt[cI][cJ]);
                    int tmp = cJ;
                    cJ = n - cI - 1;
                    cI = tmp;
                }
                // cout << el;
                // forn(i, sz(ch))cout << ch[i] << ' ';
                // cout << el;
                sort(all(ch));
                forn(i, sz(ch) - 1){
                    ans += ch.back() - ch[i];
                }
            }
        }
        cout << ans << el;
    }
}

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
        int n, m, k;
        cin >> n >> m >> k;
        int loop = k - ((n - 1) + (m - 1));
        if(loop < 0 || loop % 2 == 1){
            cout << "NO" << el;
            continue;
        }
        cout << "YES" << el;
        vector<vector<char>> gridh(n, vector<char>(m - 1, 'R'));
        vector<vector<char>> gridv(n - 1, vector<char>(m, 'R'));
        bool color = false;
        for(int i = 0; i < m - 1; ++i){
            if(color)gridh[0][i] = 'B';
            color = !color;
        }
        for(int i = 0; i < n - 1; ++i){
            if(color)gridv[i][m - 1] = 'B';
            color = !color;
        }
        color = true;
        for1(i, n - 2){
            if(color)gridv[i][0] = 'B';
            color = !color;
        }
        forn(i, m - 1){
            if(color)gridh[n - 1][i] = 'B';
            color = !color;
        }
        gridv[0][0] = 'B';
        gridv[0][1] = 'B';
        forn(i, n){
            forn(j, m - 1){
                cout << gridh[i][j] << ' ';
            }
            cout << el;
        }
        forn(i, n - 1){
            forn(j, m){
                cout << gridv[i][j] << ' ';
            }
            cout << el;
        }
    }
}

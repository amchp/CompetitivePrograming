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
        vector<vi> grid(n, vi(n));
        int fis = -1;
        int fjs = -1;
        forn(i, n){
            forn(j, n){
                char c;
                cin >> c;
                grid[i][j] = c - '0';
                if(grid[i][j]){
                    fis = i;
                    fjs = j;
                }
            }
        }
        vector<ii> mxs(4, {fis, fjs});
        forn(i, n){
            forn(j, n){
                if(grid[i][j] == 1){
                    if(-mxs[0].fi - mxs[0].se < -i -j){
                        mxs[0] = {i, j};
                    }
                    if(-mxs[1].fi + mxs[1].se < -i + j){
                        mxs[1] = {i, j};
                    }
                    if(+mxs[2].fi - mxs[2].se < i - j){
                        mxs[2] = {i, j};
                    }
                    if(mxs[3].fi + mxs[3].se < i + j){
                        mxs[3] = {i, j};
                    }
                }
            }
        }
        // forn(i, 4){
        //     cout << mxs[i].fi << ' ' << mxs[i].se << el;
        // }
        if(
            mxs[0].fi == mxs[1].fi && 
            mxs[0].se == mxs[2].se && 
            mxs[2].fi == mxs[3].fi && 
            mxs[1].se == mxs[3].se
        ){
            cout << "SQUARE" << el;
        }else{
            cout << "TRIANGLE" << el;
        }
    }
}

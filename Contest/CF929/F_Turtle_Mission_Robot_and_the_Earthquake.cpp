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

int dr[] = {1, 0};
int dc[] = {0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vi> a(n, vi(m));
        forn(i, n){
            forn(j, m){
                cin >> a[i][j];
                // cout << a[i][j] << ' ';
            }
            // cout << el;
        }
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<ii> q;
        q.push({0, 0});
        vis[0][0] = true;
        int lvl = 1;
        bool end = false;
        int ans = -1;
        while(!q.empty()){
            int e = sz(q);
            // d(lvl);
            forn(_, e){
                ii p = q.front();
                q.pop();
                int i = p.fi;
                int j = p.se;
                // d(i);
                // d(j);
                forn(k, 2){
                    int ni = (i + dr[k]) % n;
                    int nj = j + dc[k];
                    int rni = (ni + lvl + n) % n;
                    int rni2 = (ni + lvl - 1 + n) % n;
                    // cout << rni2 << ' ' << nj << el;
                    if(k == 0 && a[rni2][nj])continue;
                    if(!a[rni][nj] && !vis[ni][nj]){
                        // cout << "pass" << el;
                        if(nj == m - 1){
                            // cout << ni << ' ' << nj << el;
                            // d(rni);
                            ans = lvl + min(ni + 1, n - 1 - ni);
                            end = true;
                            break;
                        }
                        vis[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
                // cout << el;
                if(end)break;
            }
            if(end)break;
            ++lvl;
        }
        cout << ans << el;
    }
}

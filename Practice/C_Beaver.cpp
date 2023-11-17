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
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<vi> pointer(sz(s) + 1);
    int ind = 0;
    forn(i, n){
        string ss;
        cin >> ss;
        forn(j, sz(s) - sz(ss) + 1){
            if(s.substr(j,sz(ss)) == ss){
                pointer[j].pb(ind);
                pointer[j + sz(ss)].pb(ind);
                ind++;
            }
        }
    }
    vector<bool> visited(ind, false);
    int p1 = 0, p2 = 0;
    int ans = 0;
    int aInd = 0;
    while(p2 <= sz(s)){
        for(int v : pointer[p2]){
            // d(p2);
            // d(v);
            while(visited[v]){
                for(int vv : pointer[p1]){
                    visited[vv] = false;
                }
                p1++;
            }
            visited[v] = true;
        }
        if(ans < p2 - p1){
            ans = p2 - p1;
            aInd = p1;
        }
        p2++;
    }
    cout << ans << ' ' << aInd << el;
}

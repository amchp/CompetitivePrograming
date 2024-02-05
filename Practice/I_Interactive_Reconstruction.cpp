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
    int n;
    cin >> n;
    int n2 = floor(log2(n - 1)) + 1;
    // d(n2);
    vi leafs(n);
    vector<vi> neighbors(n2, vi(n));
    cout << "QUERY ";
    forn(i, n){
        cout << '1';
    }
    cout << el;
    cout << endl;
    forn(i, n)cin >> leafs[i];
    forn(i, n2){
        cout << "QUERY ";
        forn(j, n){
            if(j & (1 << i))cout << '1';
            else cout << '0';
        }
        cout << el;
        cout << endl;
        forn(j, n)cin >> neighbors[i][j];
    }
    // forn(i, n){
    //     cout << leafs[i] << ' '; 
    // }
    // cout << el;
    // forn(i, n2){
    //     forn(j, n)cout << neighbors[i][j] << ' ';
    //     cout << el;
    // }
    queue<int> clq;
    forn(i, n){
        if(leafs[i] == 1)clq.push(i);
    }
    set<ii> ans;
    while(!clq.empty()){
        int cur = clq.front();
        clq.pop();
        if(leafs[cur] == 0)continue;
        int prt = 0;
        forn(i, n2){
            if(neighbors[i][cur] == 1){
                prt += (1 << i);
            }
        }
        ans.insert({min(cur + 1, prt + 1), max(cur + 1, prt + 1)});
        --leafs[prt];
        if(leafs[prt] == 1)clq.push(prt);
        --leafs[cur];
        forn(i, n2){
            if(neighbors[i][cur] == 1)--neighbors[i][cur];
            if(cur & (1 << i)){
                --neighbors[i][prt];
            }
        }
    }
    assert(sz(ans) == n - 1);
    cout << "ANSWER" << el;
    for(auto& [u, v]: ans)cout << u << ' ' << v << el;
}

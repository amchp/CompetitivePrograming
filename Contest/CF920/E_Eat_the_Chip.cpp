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

int sol(){
    int n, m;
    cin >> n >> m;
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    if(xb - xa + 1 <= 1)return 0;
    if((xb - xa + 1) & 1){
        if(ya == yb)return -1;
        int rn;
        if(ya < yb){
            rn = yb - 1;
        }else{
            rn = m - yb;
        }
        int df = (xb - xa) / 2;
        if(rn <= df)return -1;
        return 0;
    }else{
        if(abs(ya - yb) <= 1)return 1;
        int rn;
        if(yb < ya){
            rn = ya - 1;
        }else{
            rn = m - ya;
        }
        int df = (xb - xa + 1) / 2;
        if(rn <= df)return 1;
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int ans = sol();
        if(ans == 1)cout << "Alice" << el;
        if(ans == 0)cout << "Draw" << el;
        if(ans == -1)cout << "Bob" << el;
    }
}

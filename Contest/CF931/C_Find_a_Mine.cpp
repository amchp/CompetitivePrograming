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

int qstn(int x, int y){
    cout << "? " << x << ' ' << y << endl;
    int mt;
    cin >> mt;
    return mt;
}

void resp(int x, int y){
    cout << "! " << x << ' ' << y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int d1 = qstn(1, 1);
        if(d1 == 0){
            resp(1, 1);
            continue;
        }
        int ldgx = min(n, 1 + d1);
        int ldgy = 1 + max(0, (d1 + 1) - n);
        int d2 = qstn(ldgx, ldgy);
        if(d2 == 0){
            resp(ldgx, ldgy);
            continue;
        }
        int udgx = 1 + max(0, (d1 + 1) - m);
        int udgy = min(m, 1 + d1);
        int d3 = qstn(udgx, udgy);
        if(d3 == 0){
            resp(udgx, udgy);
            continue;
        }
        // assert(!((d2 & 1) && (d3 & 1)));
        int px = udgx + (d3 / 2);
        int py = udgy - (d3 / 2);
        int px2 = ldgx - (d2 / 2);
        int py2 = ldgy + (d2 / 2);
        if((d3 & 1) == 1){
            swap(px, px2);
            swap(py, py2);
        }
        int d4 = qstn(px, py);
        // assert(d3 == d2 && d4 == 0);
        // assert(!((d3 & 1) || (d2 & 1)) || d4 == 0);
        if(d4 == 0){
            resp(px, py);
        }else{
            resp(px2, py2);
        }
    }
}

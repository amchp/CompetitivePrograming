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

int px, py;
int ax, ay;
int bx, by;

ld dist(int x1, int y1, int x2, int y2){
    ll difX = ((ll)x1 - x2);
    ll difY = ((ll)y1 - y2);
    return sqrt(difX*difX + difY*difY);
}

bool sol(ld light){
    if(dist(ax, ay, 0, 0) <= light){
        if(dist(ax, ay, px, py) <= light)return true;
        if(dist(bx, by, px, py) <= light && dist(ax, ay, bx, by) <= 2*light)return true;
    }
    if(dist(bx, by, 0, 0) <= light){
        if(dist(bx, by, px, py) <= light)return true;
        if(dist(ax, ay, px, py) <= light && dist(ax, ay, bx, by) <= 2*light)return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        cin >> px >> py;
        cin >> ax >> ay;
        cin >> bx >> by;
        ld l = -1;
        ld r = 1e9;
        while(l + eps < r){
            ld mid = l + (r - l) / 2;
            if(sol(mid)){
                r = mid;
            }else{
                l = mid;
            }
        }
        cout << r << el;
    }
}

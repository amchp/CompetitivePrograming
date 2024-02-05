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


int n;
int szs;
set<int> s;
ll x, y;
ll num = 0;

void sol(int cur){
    if(num != 0 && num <= n){
        s.insert(num);
    }
    if(cur >= szs){
        return;
    }
    num += 1LL*x*pow(10, cur);
    sol(cur + 1);
    num -= 1LL*x*pow(10, cur);
    num += 1LL*y*pow(10, cur);
    sol(cur + 1);
    num -= 1LL*y*pow(10, cur);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n;
    szs = ceil(log10(n)) + 1;
    // d(szs);
    forn(i, 10){
        forn(j, 10){
            num = 0;
            x = i;
            y = j;
            sol(0);
        }
    }
    // for(int v : s){
    //     cout << v << ' ';
    // }
    // cout << el;
    cout << s.size() << el;
}

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
const int nax = 100;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n, m;
int a[nax];
int b[nax];

void move1(){
    if(a[0] >= b[m - 1])return;
    swap(a[0], b[m - 1]);
}

void move2(){
    if(b[0] >= a[n - 1])return;
    swap(b[0], a[n - 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> n >> m >> k;
        forn(i, n)cin >> a[i];
        forn(i, m)cin >> b[i];
        sort(a, a + n);
        sort(b, b + m);
        ll ans = 0;
        if(k == 1){
            move1();
            forn(i, n)ans += a[i];
        }else if(k % 2){
            move1();
            sort(a, a + n);
            sort(b, b + m);
            move2();
            sort(a, a + n);
            sort(b, b + m);
            move1();
            forn(i, n)ans += a[i];
        }else{
            move1();
            sort(a, a + n);
            sort(b, b + m);
            move2();
            forn(i, n)ans += a[i];
        }
        cout << ans << el;
    }
}

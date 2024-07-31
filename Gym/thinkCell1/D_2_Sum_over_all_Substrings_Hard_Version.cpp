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
int a[nax];

ll sol(int l, int r, int c){
    int fans = 0;
    int na = r - l + 1;
    vi ans(na, 0);
    fore(i, l, r){
        int ind = i - l;
        if(a[i] == 1){
            if(ans[ind] == 1 || (ind > 0 && ans[ind - 1] == 1))continue;
            ++fans;
            if(ind < na - 1)ans[ind + 1] = 1;
            else ans[ind] = 1;
        }
    }
    return fans;
}

ll solf(int l, int r, int c){
    x
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        forn(i, n){
            char c;
            cin >> c;
            a[i] = c - '0';
        }
        ll ans = 0;
        forn(i, n){
            int l = i - 4;
            int r = i + 4;
            if(l <= 0){
                
            }
        }
        cout << ans << el;
        // cout << "####" << el;
    }
}

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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vi rotation(n, 0);
        vi l(k), r(k);
        forn(i, k)cin >> l[i];
        forn(i, k)cin >> r[i];
        int q;
        cin >> q;
        forn(i, q){
            int x;
            cin >> x;
            int ind = upper_bound(all(l), x) - l.begin();
            ind--;
            int a = min(x, l[ind] + r[ind] - x);
            int b = max(x, l[ind] + r[ind] - x);
            a--;
            b--;
            rotation[a]++;
            rotation[b]++;
            // cout << a << ' ' << b << el;
        }
        int ind = 0;
        bool rot = 0;
        forn(i, n){
            if(r[ind] < i + 1)ind++;
            rot = rot ^ (rotation[i] & 1);
            // d(i);
            // cout << rot << el;
            if(rot){
                int op = l[ind] + (r[ind] - (i + 1)) - 1;
                if(i >= op)continue;
                swap(s[i], s[op]);
            }
        }
        cout << s << el;
    }
}

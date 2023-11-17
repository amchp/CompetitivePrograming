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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vi dpl(n);
        vi dpr(n);
        dpl[0] = s[0] == '0' ? 0 : -1;
        for1(i, n - 1){
            dpl[i] = s[i] == '0' ? i : dpl[i - 1];
        }
        dpr[n - 1] = s[n - 1] == '1' ? n - 1 : n;
        fored(i, 0, n - 2){
            dpr[i] = s[i] == '1' ? i : dpr[i + 1];
        }
        set<ii> ans;
        forn(i, q){
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int lg = dpr[l];
            int rg = dpl[r];
            if(lg >= rg){
                ans.insert({-1, -1});
            }else{
                ans.insert({lg, rg});
            }
        }
        cout << ans.size() << el;
    }
}

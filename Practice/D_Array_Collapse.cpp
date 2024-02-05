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
const int mod = 998244353;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int add(int a, int b){
    int ans = a + b;
    if(ans >= mod)ans -= mod;
    return ans;
}

int sbt(int a, int b){
    int ans = a - b;
    if(ans < 0)ans += mod;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        forn(i, n)cin >> a[i];
        int prest = 0;
        vi dpsum(n + 1);
        dpsum[0] = 0;
        stack<int> st;
        forn(i, n){
            while(!st.empty() && a[st.top()] > a[i]){
                prest = sbt(prest, sbt(dpsum[st.top() + 1], dpsum[st.top()]));
                st.pop();
            }
            int ad = st.empty();
            int pos = !st.empty() ? st.top() : 0;
            st.push(i);
            // d(prest);
            dpsum[i + 1] = add(sbt(dpsum[i], dpsum[pos + !ad]), ad);
            dpsum[i + 1] = add(dpsum[i + 1], prest);
            prest = add(prest, dpsum[i + 1]);
            dpsum[i + 1] = add(dpsum[i + 1], dpsum[i]);
        }
        // for1(i, n){
        //     cout << dpsum[i] - dpsum[i - 1]  << ' ';
        // }
        // cout << el;
        int mn = inf;
        int ans = 0;
        ford(i, n){
            mn = min(mn, a[i]);
            if(a[i] == mn)ans = add(ans, sbt(dpsum[i + 1], dpsum[i]));
        }
        cout << ans << el;
    }
}

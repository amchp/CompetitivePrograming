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
    vi a(n);
    forn(i, n){
        cin >> a[i];
    }
    vl pre(n);
    pre[0] = a[0];
    for1(i, n - 1){
        pre[i] = pre[i - 1] + a[i];
    }
    stack<ii> st;
    st.push({a[0], 0});
    ll ans = 0;
    for1(i, n - 1){
        int mx = 0;
        while(!st.empty() && st.top().fi < a[i]){
            if(mx < st.top().fi){
                int ind = st.top().se;
                ans = max(ans, 1LL*(i - ind - 1)*min(a[i], st.top().fi) - (pre[i - 1] - pre[ind]));
            }
            mx = max(mx, st.top().fi);
            st.pop();
        }
        if(!st.empty() && mx < st.top().fi){
            int ind = st.top().se;
            ans = max(ans, 1LL*(i - ind - 1)*min(a[i], st.top().fi) - (pre[i - 1] - pre[ind]));
        }
        st.push({a[i], i});
    }
    cout << ans << el;
}

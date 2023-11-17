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
    int n, q;
    cin >> n >> q;
    vi a(n);
    vi cnt(n + 1, 0);
    forn(i, n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    vi nums;
    vector<vi> pre;
    for1(i, n){
        if(cnt[i] > 200){
            nums.pb(i);
            pre.pb(vi(n + 1, 0));
            for1(j, n)pre.back()[j] += pre.back()[j - 1] + (i == a[j - 1]);
        }
    }
    vi ans(q, -1);
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        int th = (r - l + 1) / k;
        if(r - l + 1 >= 1000){
            forn(i, sz(pre)){
                if(pre[i][r + 1] - pre[i][l] > th){
                    ans = nums[i];
                    break;
                }
            }
            cout << ans << el;
        }else{
            cnt = vi(n + 1, 0);
            fore(i, l, r){
                cnt[a[i]]++;
                if(cnt[a[i]] > th){
                    if(ans == -1)ans = a[i];
                    else ans = min(ans, a[i]);
                }
            }
            cout << ans << el;
        }
    }
}

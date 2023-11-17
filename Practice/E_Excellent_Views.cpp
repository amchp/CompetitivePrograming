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
    vector<ii> sA(n);
    forn(i, n){
        cin >> a[i];
        sA[i] = {a[i], i};
    }
    set<int> mx;
    mx.insert(-inf);
    mx.insert(inf);
    vi ans(n + 1);
    sort(all(sA), greater<ii>());
    for(auto &[val, i] : sA){
        auto it = mx.lower_bound(i);
        int right = (*it);
        it--;
        int left = (*it);
        int lL = max(left + (i - left) / 2 + 1, 0);
        int lR = i;
        int rL = i + 1;
        int rR = min(right - (right - i) / 2, n);
        if(lL < lR){
            ans[lL]++;
            ans[lR]--;
        }
        if(rL < rR){
            ans[rL]++;
            ans[rR]--;
        }
        mx.insert(i);
    }
    int pre = 0;
    forn(i, n){
        // d(ans[i]);
        pre += ans[i];
        cout << pre << ' ';
    }
    cout << el;
}

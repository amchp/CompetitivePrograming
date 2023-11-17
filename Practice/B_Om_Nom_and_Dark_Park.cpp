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

int n, mx;
ll ans = 0;
int a[2048];
vector<ll> arr[4096];
int szs = (1 << (n + 1)) - 2;

void dfs(int i){
    if(i >= szs)return
    dfs(2*i);
    dfs(2*i + 1);
    for(int v : arr[2*i]){
        arr[i].pb(v + a[i]);
    }
    for(int v : arr[2*i + 1]){
        arr[i].pb(v + a[i]);
    }
}

void dfs2(int i, int k){
    if(arr[i].back() + k < mx){
        ans += mx - (arr[i].back() + k);
        k += mx - (arr[i].back() + k);
    }
    dfs2(2*i, k);
    dfs2(2*i + 1, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n;
    for1(i, szs){
        cin >> a[i];
    }
    dfs(1);
    for1(i, szs){
        sort(all(arr[i]));
    }
    mx = arr[szs].back();
    dfs2(1, 0);
    
}

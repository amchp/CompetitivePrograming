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

int k;

void sol(int st, int n){
    vi a(n);
    fore(i, st, n){
        cout << "? " << i <<  endl;
        cin >> a[i - st];
    }
    forn(i, n){
        if(a[(i - 1 + n) % n] < k && a[i] == k && a[(i + 1) % n] > k){
            cout << "! " << (st + i) << endl;
            return;
        }
    }
    assert(false);
}

void sol2(int n){
    int st = 1;
    int mv = 1;
    while(st + mv <= n){
        cout << "? " << st << endl;
        int v;
        cin >> v;
        if(v < k){
            break;
        }
        if(st < 3 && v > k){
            if(st == 1)cout << "! " << n << el;
            else cout << "! " << st - 1 << el;
            return;
        }
        st += mv;
        mv++;
    }
    sol(st, min(n, st + mv + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n >> k;
    cout << "? 1" << endl;
    int v;
    cin >> v;
    if(n < 1000)sol(1, n);
    else sol2(n);
}

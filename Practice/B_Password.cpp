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

// O(|s|)
vi z_function(string &s){
    int n = s.size();
    vi z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; ++i)
    {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            x = i, y = i + z[i], z[i]++;
    }
    return z;
}

string sol(){
    string s;
    cin >> s;
    vi z = z_function(s);
    set<int> seen;
    int n = sz(s);
    for1(i, n - 1){
        if(i + z[i] == n){
            auto it = seen.lower_bound(z[i]);
            if(it != seen.end())return s.substr(i, z[i]);
            seen.insert(z[i]);
        }else{
            seen.insert(z[i]);
        }
    }
    return "Just a legend";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cout << sol() << el;
}

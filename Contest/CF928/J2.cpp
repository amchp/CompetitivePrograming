#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define el '\n'
#define pb push_back
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i,l,r) for(int i = l; i<= r; ++i)
#define ford(i, n) for(int i = (int)n - 1; i >= 0; --i)
#define sz(a) (int) a.size()
#define fi first
#define se second
#define d(x) cerr << #x << ' ' << x << el
#define all(x) x.begin(), x.end()
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef __int128_t i128;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef array<ll, 7> a7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll k, l, r;
    cin >> k >> l >> r;
    ll zeros = 0, nzeros = 0;
    fore(i, l, r){
        string st = to_string(i);
        bool z = false;
        ll x = 1;
        for(char& c : st){
            if(c == '0')z = true;
            x *= c - '0';
        }
        // cout << x << ' ';
        if(x % k == 0){
            if(z)zeros++;
            else nzeros++;
        }
    }
    cout << el;
    cout << zeros + nzeros << el;
    cout << nzeros << ' ' << zeros << el;
}
// (rans - lans).x 9212
// (rz - (lz - mint(cl % k == 0))).x 13547
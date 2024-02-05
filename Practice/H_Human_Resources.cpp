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

map<string, vector<string>> vs;
vector<string> ans;
string B;
vector<string> message;

void dfs(string& s){
    ans.pb(s);
    B.push_back('0');
    for(string& hs : vs[s]){
        dfs(hs);
    }
    B.push_back('1');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    string s;
    cin >> s;
    if(s == "ENCODE"){
        cin >> s;
        s.pop_back();
        string cs = s;
        string fs = s;
        while(cin >> s){
            if(s[sz(s) - 1] == ':'){
                s.pop_back();
                cs = s;
                continue;
            }
            vs[cs].push_back(s);
        }
        dfs(fs);
        for(string& s : ans){
            cout << s << el;
        }
        cout << B << el;
    }else{
        while(cin >> s){
            message.pb(s);
            // cout << s << el;
        }
        B = message.back();
        message.pop_back();
        vector<vi> sons(sz(message));
        int mprt = 0;
        stack<int> prt;
        for(char& c : B){
            // cout << c << el;
            if(c == '0'){
                if(!prt.empty()){
                    sons[prt.top()].push_back(mprt);
                }
                prt.push(mprt);
                ++mprt;
            }else{
                prt.pop();
            }
        }
        forn(i, sz(sons)){
            vi& sns = sons[i];
            // cout << sz(sns) << el;
            if(sz(sns))cout << message[i] << ": ";
            for(int& son : sns){
                cout << message[son] << ' ';
            }
            if(sz(sns))cout << el;
        }
    }
}

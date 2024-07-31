#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cerr<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    unordered_map<char, int> chrs = {{'F', 0}, {'U', 1}, {'T', 2}};
    vector<vector<vector<char>>> logicGates = {
        {
            {'F', 'F', 'F'},
            {'F', 'U', 'U'},
            {'F', 'U', 'T'}
        },
        {
            {'F', 'U', 'T'},
            {'U', 'U', 'T'},
            {'T', 'T', 'T'}
        },
        {
            {'T', 'T', 'T'},
            {'U', 'T', 'T'},
            {'F', 'U', 'T'}
        },
        {
            {'T', 'F', 'F'},
            {'F', 'T', 'F'},
            {'F', 'F', 'T'}
        },
    };
    unordered_set<string> st;
    queue<string> q;
    vector<string> svars = {"FFFUUUTTT", "FUTFUTFUT"};
    for(string& s : svars){
        q.push(s);
        st.insert(s);
    }
    for(vector<vector<char>>& logicGate : logicGates){
        svars.pb("");
        string& s = svars.back();
        for(vector<char>& vec : logicGate){
            for(char& ch : vec)s.pb(ch);
        }
        q.push(s);
        st.insert(s);
    }
    while(!q.empty()){
        // if(sz(st) == 1944)break;
        string s1 = q.front();
        q.pop();
        for(vector<vector<char>>& logicGate : logicGates){
            for(string s2 : st){
                string ns = string(9, 'U');
                forn(i, 9){
                    ns[i] = logicGate[chrs[s1[i]]][chrs[s2[i]]];
                }
                if(!st.count(ns)){
                    st.insert(ns);
                    q.push(ns);
                }
            }
        }
    }
    
    int n;
    cin >> n;
    forn(i, n){
        string s(9, 'U');
        forn(j, 9)cin >> s[j];
        if(st.count(s))cout << "definable" << el;
        else cout << "undefinable" << el;
    }
}
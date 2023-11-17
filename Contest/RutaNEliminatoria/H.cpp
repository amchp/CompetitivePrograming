#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = l; i < (int)r; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define el '\n'
#define d(x) cout << #x << ' ' << x << el;
#define sz(x) (int)x.size()

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int n, p, s;
vector<string> topics;
set<int> st;
map<int, set<int>> prohibited;
vector<int> cAns;

void sol(int ind){
    if(cAns.size() == s){
        forn(i, sz(cAns)){
            if(i == sz(cAns) - 1)cout << topics[cAns[i]];
            else cout << topics[cAns[i]] << ' ';
        }
        cout << el;
        return;
    }
    if(ind == n)return;
    set<int>& mp = prohibited[ind];
    bool nA = false;
    for(int v : mp){
        if(st.count(v)){
            nA = true;
            break;
        }
    }
    if(!nA){
        st.insert(ind);
        cAns.pb(ind);
        sol(ind + 1);
        cAns.pop_back();
        st.erase(ind);
    }
    sol(ind + 1);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for1(tt, t){
        st.clear();
        topics.clear();
        prohibited.clear();
        cAns.clear();
        cin >> n >> p >> s;
        forn(i, n){
            string s;
            cin >> s;
            topics.push_back(s);
        }
        forn(i, n){
            forn(j, sz(topics[i])){
                topics[i][j] = toupper(topics[i][j]);
            }
        }
        sort(all(topics), [&](string& a, string& b){
            if(sz(a) == sz(b))return a < b;
            return sz(a) > sz(b);
        });
        forn(i, p){
            string s1, s2;
            cin >> s1 >> s2;
            forn(j, sz(s1)){
                s1[j] = toupper(s1[j]);
            }
            forn(j, sz(s2)){
                s2[j] = toupper(s2[j]);
            }
            int ind1 = -1, ind2 = -1;
            forn(j, n){
                if(ind1 == -1 && s1 == topics[j])ind1 = j;
                if(ind2 == -1 && s2 == topics[j])ind2 = j;
            }
            prohibited[ind1].insert(ind2);
            prohibited[ind2].insert(ind1);
        }
        cout << "Set " << tt << ':' << el;
        sol(0);
        cout << el;
    }
}
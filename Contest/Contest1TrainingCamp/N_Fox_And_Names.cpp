#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>
#include <tuple>


// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


vector<vi> g(26, vi(26)); // adjacency list of graph
vector<bool> visited(26, false);
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
        if (!visited[g[v][i]])
            dfs(g[v][i]);
    }
    ans.push_back(v);
}

void topological_sort() {
    for (int i = 0; i < 26; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    vector<vector<string> > v(n);
    char cur;
    bool pass = true;
    for(int i = 0; i < n; ++i){
        cin >> s;
        if(i != 0 && cur != s.at(i)){
            g[cur - 'a'].push_back(s.at(i) - 'a');
        }
        cur = s.at(i);
        v[s.at(0) - 'a'].push_back(s);
    }
    // for(int i = 0; i < 26; ++i){
    //     for(int j = 0; j < v[i].size() - 1; ++j){
    //         for(int k = 0; k < v[i][j].length(); ++k){
    //             if(k >= v[i][j+1].length()){
    //                 pass = false;
    //                 goto failed;
    //             }
    //             if(v[i][j].at(k) != v[i][j+1].at(k)){
    //                 g[v[i][j].at(k) - 'a'].push_back(v[i][j+1].at(k) - 'a');
    //             }
    //         }
    //     }
    // }
    // failed:
    if(!pass)cout << "Impossible" << el;
    topological_sort();
    for(int i = 0 ; i < ans.size(); ++i){
        cout << (char)(ans[i]+'a');
    }
    cout << el;
}
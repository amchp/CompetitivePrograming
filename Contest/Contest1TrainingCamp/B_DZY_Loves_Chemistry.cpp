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

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second > b.second);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, v, vv, d;
    cin >> n >> m;
    vector<pi> vec(n+1, make_pair(0, 0));
    vector<vi> graph(n+1, vector<int>(n+1, 0));
    for(int i = 1; i < n+1; ++i){
        vec[i].first = i;
    }
    for(int i = 0; i < m; ++i){
        cin >> v >> vv;
        graph[v][vv] = 1;
        graph[vv][v] = 1;
        vec[v].second++;
        vec[vv].second++;
    }
    sort(vec.begin(), vec.end(), sortbysec);
    d = 1;
    vi poured;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < poured.size(); ++j){
            if(graph[vec[i].first][poured[j]] == 1){
                d *= 2;
                break;
            }
        }
        poured.push_back(vec[i].first);
    }
    cout << d << el;
}
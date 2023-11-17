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

// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    map<string, int> m;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> s;
        if(m[s] == 0){
            cout << "OK" << endl;
            m[s]++;
        }else{
            cout << s << m[s] << el;
            m[s]++;
        }
    }
    
}
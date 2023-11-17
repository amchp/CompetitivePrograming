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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    string s;
    
    bool pass;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(26, 0);
        cin.ignore();
        for(int i = 0; i < n; ++i){
            getline(cin, s);
            for(int j = 0; j < s.length(); ++j){
                v[s.at(j) - 'a']++;
            }
        }
        pass = true;
        for(int i = 0; i < 26; ++i){
            
            if(v[i] % n != 0){
                pass = false;
                break;
            }
        }
        if(pass)cout << "YES" << el;
        else cout << "NO" << el;
    }

}
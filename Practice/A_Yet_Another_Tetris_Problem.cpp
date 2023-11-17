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

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9 

#define el '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        string ans = "YES";
        cin >> n;
        int h[n];
        m = 0;
        for(int i = 0; i < n; ++i){
            cin >> h[i];
            m = max(m, h[i]);
        }
        for(int i = 0; i < n; ++i){
            if(h[i] != m  and i != n -1 and h[i] == h[i + 1])i++;
            else if(h[i] == m);
            else{
                ans = "NO";
                break;
            }
        }
        cout << ans << endl;
    }
}
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
        int n;
        cin >> n;
        string s, e;
        bool pass = false;
        getchar();
        getline(cin, s);
        for(int i = 0; i <= 4; ++i){
            e = s.substr(0,i) + s.substr(n - 4 + i);
            if(e == "2020"){
                pass = true;
                break;
            }
        }
        stop:
        if(pass) cout << "YES" << el;
        else cout << "NO" << el;
    }
}
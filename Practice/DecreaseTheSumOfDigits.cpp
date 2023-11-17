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
        long long n, s, sum, total;
        cin >> n >> s;
        string sN;
        sN = to_string(n);
        sum = 1;
        total = 0;
        int i = -1;
        while(sum <= s){
            i++;
            sum += sN.at(i) - '0';
        }
        total = pow(10, sN.length() - i) - n;
        cout << total << el;
    }
}
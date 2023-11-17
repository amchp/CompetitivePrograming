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

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9

#define el '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, k;
        cin >> a >> b >> k;
        int ai[k], bi[k];
        int sum = 0; 
        for(int i = 0; i < k; ++i)cin >> ai[i];
        for(int i = 0; i < k; ++i)cin >> bi[i];
        for(int i = 0; i < k; ++i){
            for(int j = i+1; j < k; ++j){
                if(ai[i] != ai[j] && bi[i] != bi[j]) sum++;
            }
        }
        cout << sum << el;
    }
}
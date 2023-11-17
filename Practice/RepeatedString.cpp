#include <iostream>

using namespace std;

int main(){
    string s, ss;
    long n; 
    int a = 0, ae = 0;
    getline(cin, s);
    getline(cin, ss);
    n = stol(ss);
    for(int i = 0; i < s.length(); ++i) if(s.at(i) == 'a') a++;
    if(n % s.length() == 0) cout << (a*n/(s.length())) << endl;
    else{
        for(int i = 0; i < (n % s.length()); ++i)if(s.at(i) == 'a') ae++;
        cout << (a*(n - (n % s.length()))/s.length() + ae) << endl;
    }
}
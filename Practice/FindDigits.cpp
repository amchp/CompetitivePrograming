#include <iostream>

using namespace std;

int main(){
    int t, n, count;
    string s;
    cin >> t;
    while(t--){
        cin >> n;
        s = to_string(n);
        int digits[s.length()];
        count = 0;
        for(int i = 0; i < s.length(); ++i){
            digits[i] = s.at(i) - '0';
            if(digits[i] != 0 && n % digits[i] == 0)count++;
        }
        cout << count << endl;
    }
}
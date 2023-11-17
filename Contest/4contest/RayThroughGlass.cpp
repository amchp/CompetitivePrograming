#include <iostream>

using namespace std;

int main(){
    string s;
    int num, sum, last, cur;
    getline(cin, s);
    
    while(!s.empty())
    {
        sum = 0, last = 1, cur = 1;
        num = stoi(s);
        for(int i = 0; i <= num; ++i){
            sum += last;
            last = cur;
            cur = sum;
        }
        cout << sum << endl;
        getline(cin, s);
    }
}

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>

using namespace std;

int main(int argc, char** argv) {
    
    int n;
    int cont = 0;
    vector<int> v;
    v.reserve(10000);
    long int median;
    string s;
    getline(cin, s);
    while( !s.empty()){
        n = stoi(s);
        
        //cout << "digitou: "<<n<< endl;
        cont ++;
        v.push_back(n);
        if( (cont%2) != 0){
            auto m = v.begin() + v.size()/2;
            nth_element(v.begin(), m, v.end());
            median = (long int) *m;
            //cout << "impar" << endl;
        }else{
            //cout << "par" << endl;
            auto m = v.begin() + v.size()/2;
            nth_element(v.begin(), m, v.end());
            int v1 = *m;
            m--;
            nth_element(v.begin(), m, v.end());
            int v2 = *m;
            //cout << "v1: " << v1 << " v2: " << v2 << endl;
            median = (long int) v1 + v2;
            median = median / 2;
        }

        cout << median << endl;
        getline(cin, s);        
    } 
        
    return 0;
}


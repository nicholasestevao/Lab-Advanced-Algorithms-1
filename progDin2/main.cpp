
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

int minimo_moedas(int v, int nm, int * m, int * memo){
    
    if( v == 0){
        return 0;
    }else if(memo[v] != -1){
        return memo[v];
    }
    int minimo = 99999999;
    for(int i = nm-1; i>=0; i--){
        int v_temp;
        if(v - m[i] >= 0){
            v_temp =  minimo_moedas(v - m[i], nm, m, memo);
        }else{
            v_temp = 99999999;
        }
        if(v_temp < minimo){
            minimo = v_temp;
        }
    }
    //cout << "minimo para " << v<< " eh "<< minimo +1 << endl;
    memo[v] = minimo +1;
    return minimo + 1;
}


int main(int argc, char** argv) {
    int t;
    int v;
    int nm;
    cin >> t;

    for(int i = 0; i<t; i++){
        cin >> v;
        cin >> nm;
        int * m = (int *) malloc(sizeof(int)*nm);
        int * memo = (int *) malloc(sizeof(int)*(v+1));
        for(int j = 0; j< nm; j++){
            int k;
            cin >> k;
            m[j] = k;
        }

        for(int j = 0; j<=v; j++){
            memo[j] = -1;
        }


        cout << minimo_moedas(v, nm, m, memo) << endl;
        free(memo);
        free(m);

    }
    
    return 0;
}


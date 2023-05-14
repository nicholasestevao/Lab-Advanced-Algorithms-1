
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int max_paginas(int * precos, int * npaginas, int tam, int precos_max, int ** memo){
    if(tam == 0){
        memo[0][0] = 0;
        return 0;
    }

    if(memo[tam-1][precos_max] != -1){
        return memo[tam-1][precos_max];
    }

    if(precos_max < precos[tam-1]){
        return memo[tam-1][precos_max] = max_paginas(precos, npaginas, tam-1, precos_max, memo);
    }

    int m1 = max_paginas(precos, npaginas, tam -1, precos_max, memo);
    int m2 = max_paginas(precos, npaginas, tam-1, precos_max - precos[tam-1], memo) + npaginas[tam-1];

    return  memo[tam-1][precos_max] = max(m1,m2);

}

int main(int argc, char** argv) {
    int n;
    int x;
    cin >> n;
    cin >> x;
    int * precos = (int *) malloc(sizeof(int) * n);
    int * npaginas = (int *) malloc(sizeof(int) * n);

    int ** memo = (int **) malloc(sizeof(int *) * n);
    for(int i = 0; i< n; i++){
        memo[i] = (int *) malloc(sizeof(int) * (x+1));
    }
    for(int i = 0; i< n; i++){
        for(int j = 0; j<=x; j++){
            memo[i][j] = -1;
        }
    }

    for(int i = 0; i< n; i++){
        cin >> precos[i];
    }
    for(int i = 0; i< n; i++){
        cin >> npaginas[i];
    }

    cout << max_paginas(precos, npaginas, n, x, memo) << endl;
    
    return 0;
}


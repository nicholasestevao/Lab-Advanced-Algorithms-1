
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

void nroCaminhos(int *** m, char *** t, int n){
    for(int i = 0; i< n; i++){
        for(int j = 0; j<n; j++){
            if((*t)[i][j] != '*'){
                if(i< n-1){
                    (*m)[i+1][j] += ((*m)[i][j])%((int) pow(10, 9)+7);
                }
                if(j< n-1){
                    (*m)[i][j+1] += ((*m)[i][j])%((int) pow(10, 9)+7);
                }
            }
        }
    }

}



int main(int argc, char** argv) {
    int n;
    cin >> n;
    int ** memo = (int **) malloc(sizeof(int*)*(n));
    char ** tabuleiro = (char **) malloc(sizeof(char*)*(n));
    for(int i = 0; i< n; i++){
        memo[i] = (int *) malloc(sizeof(int)*n);
        tabuleiro[i] = (char *) malloc(sizeof(char)*n);
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j< n; j++){
            char c;
            cin >> c;
            tabuleiro[i][j] = c;
            memo[i][j] = 0;
        }
    }
    memo[0][0] = 1;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j< n; j++){
            //cout << tabuleiro[i][j] << " ";
        }
        //cout << endl;
    }
    nroCaminhos(&memo, &tabuleiro, n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j< n; j++){
            //cout << memo[i][j] << " ";
        }
        //cout << endl;
    }
    cout << memo[n-1][n-1] << endl;
    return 0;
}


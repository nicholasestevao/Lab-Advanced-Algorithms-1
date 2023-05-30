
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <cmath>
#include <math.h>

#define DELTA 1
#define ALPHA 1


using namespace std;

int alfa(char a, char b){
    return (!(a==b))*ALPHA;
}

int opt(char * s1, char * s2, int i, int j, int ** memo){


    if(i == 0){
        return j*DELTA;
    }
    if(j==0){
        return i*DELTA;
    }

    if(memo[i-1][j-1] != -1){
        return memo[i-1][j-1];
    }

    

    return memo[i-1][j-1] = min(
        alfa(s1[i-1], s2[j-1]) + opt(s1,s2, i-1,j-1, memo),
        min(DELTA + opt(s1,s2, i-1, j, memo), DELTA + opt(s1,s2, i, j-1, memo))
    );

}

int main(int argc, char** argv) {
    char * x = (char *) malloc(sizeof(char)*5010);
    char * y = (char *) malloc(sizeof(char)*5010);
    
    scanf("%s", x);
    scanf("%s", y);
    int tx = strlen(x);
    int ty = strlen(y);
    int ** memo = (int **) malloc(sizeof(int *)*tx);
    for(int i = 0; i< tx; i++){
        memo[i] = (int *) malloc(sizeof(int)*ty);
    }

    for(int i = 0; i< tx; i++){
        for(int j = 0; j< ty; j++){
            memo[i][j] = -1;
        }
    }

    //cout << x << tx << endl;
    //cout << y << ty << endl;

    cout << opt(x,y, tx, ty, memo) << endl;
    free(x);
    free(y);
    for(int i = 0; i< tx; i++){
        free(memo[i]);
    }
    free(memo);
    
    return 0;
}


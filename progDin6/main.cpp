
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <cmath>
#include <math.h>

using namespace std;

string opt(char * s1, char * s2, int i, int j, string ** memo){
    if(i == 0 || j == 0){
        return "";
    }

    if(memo[i-1][j-1] != "1"){
        return memo[i-1][j-1];
    }

    if(s1[i-1] == s2[j-1]){
        //caracteres em i e j sao iguais
        return memo[i-1][j-1] = opt(s1,s2, i-1, j-1, memo) + s1[i-1];
    }else{
        string res1 = opt(s1,s2, i-1, j, memo);
        string res2 = opt(s1,s2, i, j-1, memo);
        if(res1.length() >= res2.length()){
            return memo[i-1][j-1] = res1;
        }else{
            return memo[i-1][j-1] = res2;
        }
    }

}

int main(int argc, char** argv) {
    char * x = (char *) malloc(sizeof(char)*5010);
    char * y = (char *) malloc(sizeof(char)*5010);
    
    scanf("%s", x);
    scanf("%s", y);
    int tx = strlen(x);
    int ty = strlen(y);
    string ** memo = (string **) malloc(sizeof(string *)*tx);
    for(int i = 0; i< tx; i++){
        memo[i] = (string *) malloc(sizeof(string)*ty);
    }

    for(int i = 0; i< tx; i++){
        for(int j = 0; j< ty; j++){
            memo[i][j] = "1";
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


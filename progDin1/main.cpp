
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>  

using namespace std;

int buscar_pos_int(int intervalo, int atual, int * dias, int n){
    int pos = atual;
    int dia_atual = dias[atual];
    while(pos <n && dias[pos] - dia_atual <= intervalo){
        pos++;
    }
    //cout << "Posicao: "<< pos<<endl;
    return pos;

}

int valor_minimo_a_partir_da_pos(int dia_atual, int total_dias, int precos[3], int * dias, int * memo){
    int v1, v2,v3;
    if(dia_atual == total_dias){
        return 0;
    }
    int pos1 = buscar_pos_int(1,dia_atual, dias, total_dias);
    if(pos1 != dia_atual){
        if(memo[pos1] != -1){
            v1 = precos[0] + memo[pos1];
        }else{
            v1 = precos[0] + valor_minimo_a_partir_da_pos(pos1, total_dias, precos, dias, memo);
        }
        
       // cout << "da pra comprar ingresso 1 dia, total: \t" << v1 <<endl;
    }

    int pos2 = buscar_pos_int(7,dia_atual, dias, total_dias);
    if(pos2 != dia_atual){
        if(memo[pos2] != -1){
            v2 = precos[1] + memo[pos2];
        }else{
            v2 = precos[1] + valor_minimo_a_partir_da_pos(pos2, total_dias, precos, dias, memo);
        }
        //cout << "da pra comprar 7 dia, total: \t" << v2 <<endl;
    }
    int pos3 = buscar_pos_int(30,dia_atual, dias, total_dias);
    if(pos3 != dia_atual){
        if(memo[pos3] != -1){
            v3 = precos[2] + memo[pos3];
        }else{
            v3 = precos[2] + valor_minimo_a_partir_da_pos(pos3, total_dias, precos, dias, memo);
        }
          //cout << "da pra comprar 30 dias, total: \t" << v3 <<endl;
    }

    int res = min(v1, min(v2,v3));
    memo[dia_atual] = res;
    //cout << "Valor minimo a partir da pos: "<< dia_atual << ":\t " << res << endl;

    return res;
}


int main(int argc, char** argv) {
    int n;
    int v[3];

    cin >> n >> v[0] >> v[1] >> v[2];
    int *dias = (int *) malloc(sizeof(int)*n);
    int *memo = (int *) malloc(sizeof(int)*n);

    for(int i = 0; i<n; i++){
       int k;
       cin >> k;
       dias[i] = k;
       memo[i] = -1;
    }

    cout << valor_minimo_a_partir_da_pos(0, n, v, dias, memo) << endl;
    
    return 0;
}


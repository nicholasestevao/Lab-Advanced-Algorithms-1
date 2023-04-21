
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <queue>

#define MAX_STR 10

using namespace std;

struct par{
    int x; // i
    int y; // j
};


void busca_largura(int**** campo, queue<par>* fila,  int l, int c){
    while(!(*fila).empty()){
        par atual = (*fila).front();
        if((*campo[0])[atual.x][atual.y] == 1){
            //cout << " entrou ";
            if(atual.x-1 >=0 && (*campo)[0][atual.x - 1 ][atual.y] == 1 && (*campo)[2][atual.x - 1 ][atual.y] == 3){
                par prox;
                prox.x = atual.x - 1;
                prox.y = atual.y;
                (*fila).push(prox);
               // cout << "oi";
                (*campo)[2][prox.x][prox.y] = 5; // pintando o vertice de cinza
                if((*campo)[1][atual.x -1][atual.y] > (*campo)[1][atual.x][atual.y] + 1){
                    (*campo)[1][atual.x - 1 ][atual.y] = (*campo)[1][atual.x][atual.y] + 1;
                    //cout << "achou caminho x -1";
                }
                
            }
            if(atual.x+1 < l && (*campo)[0][atual.x + 1 ][atual.y] == 1 && (*campo)[2][atual.x + 1 ][atual.y] == 3){
                par prox;
                prox.x = atual.x + 1;
                prox.y = atual.y;
                (*fila).push(prox);
                //cout << "oi";
                (*campo)[2][prox.x][prox.y] = 5; // pintando o vertice de cinza
                if((*campo)[1][atual.x +1][atual.y] > (*campo)[1][atual.x][atual.y] + 1){
                    (*campo)[1][atual.x + 1 ][atual.y] = (*campo)[1][atual.x][atual.y] + 1;
                    //cout << "achou caminho x +1";
                }
            }
            if(atual.y-1 >=0 && (*campo)[0][atual.x][atual.y - 1] == 1 && (*campo)[2][atual.x][atual.y - 1] == 3){
                par prox;
                prox.x = atual.x;
                prox.y = atual.y - 1;
                (*fila).push(prox);
                //cout << "oi";
                (*campo)[2][prox.x][prox.y] = 5; // pintando o vertice de cinza
                if((*campo)[1][atual.x][atual.y -1] > (*campo)[1][atual.x][atual.y] + 1){
                    (*campo)[1][atual.x][atual.y - 1] = (*campo)[1][atual.x][atual.y] + 1;
                    //cout << "achou caminho y -1";
                }
            }
            if(atual.y+1 < c && (*campo)[0][atual.x][atual.y + 1] == 1 && (*campo)[2][atual.x][atual.y + 1] == 3){
                par prox;
                prox.x = atual.x;
                prox.y = atual.y + 1;
                (*fila).push(prox);
                //cout << "oi";
                (*campo)[2][prox.x][prox.y] = 5; // pintando o vertice de cinza
                if((*campo)[1][atual.x][atual.y + 1] > (*campo)[1][atual.x][atual.y] + 1){
                    (*campo)[1][atual.x][atual.y + 1] = (*campo)[1][atual.x][atual.y] + 1;
                    //cout << "achou caminho y +1";
                }
            }

            (*campo)[2][atual.x][atual.y] = 5; // pintando o vertice de preto
            (*fila).pop();
            //cout << (*fila).size() << endl;
        }
    }
    
}

void restaurar_campo(int **** campo_original, int **** campo, int l, int c){
    for(int i = 0; i< l; i++){
        for(int j = 0; j< c; j++){
            (*campo)[0][i][j] = (*campo_original)[0][i][j];
            (*campo)[1][i][j] = (*campo_original)[1][i][j];
            (*campo)[2][i][j] = (*campo_original)[2][i][j];
        }
    }
}


int main(int argc, char** argv) {
    int l,c;
    cin >> l >> c;
    //int campo[3][l][c];
    int *** campo;
    campo = (int ***) malloc(sizeof(int **)*3);
    for(int k = 0; k< 3; k++){
        campo[k] = (int **) malloc(sizeof(int *)*l);
        for(int i = 0; i< l; i++){
            campo[k][i] = (int *) malloc(sizeof(int)*c);
        }
    }

    int *** campo_original;
    campo_original = (int ***) malloc(sizeof(int **)*3);
    for(int k = 0; k< 3; k++){
        campo_original[k] = (int **) malloc(sizeof(int *)*l);
        for(int i = 0; i< l; i++){
            campo_original[k][i] = (int *) malloc(sizeof(int)*c);
        }
    }
    
    // indice 0 -> mapa original
    // indice 1 -> caminho minimo
    // indice 2 -> cor do vertice
            // 3 -> branco
            // 4 -> cinza
            // 5 -> preto

    //cout << l << " " << c << endl;
    getchar();
    string s;
    for(int i = 0; i < l; i++){
        getline(cin, s);
        for(int j = 0; j < c; j++){
            if( j< (int) s.length()){
                campo[0][i][j] = s.at(2*j) - 48;
                campo[1][i][j] = 999999;
                campo[2][i][j] = 3;

                campo_original[0][i][j] = s.at(2*j) - 48;
                campo_original[1][i][j] = 999999;
                campo_original[2][i][j] = 3;
                
            }
        }
    }
    /*cout << endl;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cout << campo[0][i][j] << " ";
        }
        cout << endl;
    }*/

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(campo[0][i][j] == 0){
                // tem uma mina em i j
                if(i-1 >=0){
                    campo[0][i-1][j] = 2;
                    campo_original[0][i-1][j] = 2;
                }
                if(i+1 < l){
                    campo[0][i+1][j] = 2;
                    campo_original[0][i+1][j] = 2;
                }
                if(j-1 >=0){
                    campo[0][i][j-1] = 2;
                    campo_original[0][i][j-1] = 2;
                }
                if(j+1 < c){
                    campo[0][i][j+1] = 2;
                    campo_original[0][i][j+1] = 2;
                }

            }
        }
    }

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(campo[0][i][j] == 2){
                campo[0][i][j] = 0;
                campo_original[0][i][j] = 0;
            }
        }
    }

    /*cout << endl;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cout << campo[0][i][j] << " ";
        }
        cout << endl;
    }*/

    /*par ** vetor_antecessores = (par **) malloc(sizeof(par*) * l);
    for(int i=0; i<l; i++){
        vetor_antecessores[i] = (par *) malloc(sizeof(par)* c);
    }*/

    int custo_minimo = 999999;

    for( int i = 0; i < l; i++){
        if(campo[0][i][0] == 1){
            // fazer busca em largura a partir de i0
            //cout << "Iteracao " << i << endl;
            queue<par> fila;
            par p;
            p.x = i;
            p.y = 0;
            campo[1][i][0] = 0;
            campo[2][i][0] = 4;
            fila.push(p);
            busca_largura(&campo, &fila, l, c);
            /*cout << endl;
            for(int i = 0; i < l; i++){
                for(int j = 0; j < c; j++){
                    cout << campo[1][i][j] << "\t";
                }
                cout << endl;
            }
            cout << endl;
            for(int i = 0; i < l; i++){
                for(int j = 0; j < c; j++){
                    cout << campo[2][i][j] << "\t";
                }
                cout << endl;
            }*/

            int menor = 9999999;
            for(int i = 0; i< l; i++){
                if(campo[1][i][c-1] < menor){
                    menor = campo[1][i][c-1];
                }
            }

            if(menor < custo_minimo){
                custo_minimo = menor;
            }
            

            restaurar_campo(&campo_original, &campo, l, c);
        }else{
            // tem mina entao nao precisa buscar
        }
    }

    if(custo_minimo != 999999){
        cout << "Comprimento da rota = " << custo_minimo << endl;
    }else{
        cout << "Nao ha caminho valido" << endl;
    }
    
    

    return 0;
}


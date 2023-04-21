
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>

#define MAX_STR 10

using namespace std;


void adicionar_espaco_rec(char * str,  int tam, int tam_max){
    if(tam == tam_max){
        return;
    }else if(str[tam - 2] != ' '){
        // se a penultima letra nao eh espaco
        str[tam + 1] = '\0';
        str[tam] = str[tam - 1];
        str[tam - 1] = ' ';
        cout << str << endl;
        adicionar_espaco_rec(str,tam +1, tam_max);
    }else{
        //cout << "else" << endl;
        // se tem espaco na penultima letra (tam - 2)
        int i = 4;
        while(tam - i >= 0 && str[tam - i] == ' '){
            i +=2;
        }
        //cout << i ;
        // adicionar espaco na posicao tam - i + 1 e remover todos os outros 
        int cont = 0;
        for(int j = tam - i + 3; j <=tam; j++){
            if(str[j] == ' '){
                for(int k=j; k<= tam - 1; k++){
                    str[k] = str[k+1];
                }
                cont++;
            }
        }
        //cout << tam << endl;
        
        str[tam - i + 2] = str[tam - i + 1];
        str[tam - i + 1] = ' ';
        tam -=cont;
        cout << str << endl;
        adicionar_espaco_rec(str,tam, tam_max);
    }

}

int main(int argc, char** argv) {

    string s;
    
    getline(cin, s);
    while(s.length() != 0){
        cout << s << endl;
        char * str = (char *) malloc(sizeof(char) * MAX_STR);
        strcpy(str, s.c_str());
        int tam = s.length();
        adicionar_espaco_rec(str, tam, tam + tam -1);

        cout <<  endl;
        getline(cin, s);
    }

    return 0;
}


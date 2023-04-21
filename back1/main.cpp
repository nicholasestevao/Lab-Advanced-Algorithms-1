
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>


using namespace std;

int main(int argc, char** argv) {

    int  k;
    char * s = (char *) malloc(sizeof(char)*15);
    scanf("%s", s);
    while(s[0] != '\0'){

        //cout << "_" <<s << "_"<< endl;
        cin >>  k;
        //cout << "k: "<< k << endl;

        for(int i = 0; i<k; i++){
            int maior = s[i];
            int pos_maior = i;
            for(int j= (int) strlen(s) - 1; j>= i ; j--){
                if(s[j] > maior){
                    maior = s[j];
                    pos_maior = j;
                }
            }
            if( pos_maior != i){
                //realiza troca
                int temp = s[i];
                s[i] = maior;
                s[pos_maior] = temp;
            }
        }
        cout << s << endl;
        free(s);
        s = (char *) malloc(sizeof(char)*15);
        char c = ' ';
        int p = 0;
        c = getchar();
        c = getchar();
        while(c != ' ' && c != '\n' && c != EOF){
            s[p] = c;
            p++;
            c = getchar();
        }
        //scanf("%s", s);
    }

    return 0;
}


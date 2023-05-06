
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int contar_noites(vector<int> * v, int cam_max){
    int num_noites = 0;
    int passo = 0;

    for(int i = 0 ; i < (int) (*v).size() -1 ; i++){
        if((*v).at(i) + passo <= cam_max){
            passo += (*v).at(i); //anda mais um trecho
        }else{
            if(passo > cam_max){
                //cout << "Erro: caminho menor do que a distancia" << endl;
                return -1;
            }else{
                num_noites++;
                //cout << "Caminha "<< passo << " ate o camping " << i - 1 << " (i : " << i << " )"<< endl;
                passo = (*v).at(i);
            }
            
        }
    }
    if(passo <= cam_max){
        if((*v).back() + passo <= cam_max){
            // eh possivel andar ate o destino
            //cout << "(3) Caminha "<< (*v).back() + passo << " ate o destino"<< endl;
            return num_noites;
        }else{
            // passo ja eh menor do que o cam max mas nao da pra andar ate o destino
            if((*v).back() <= cam_max){
                //cout << "(2) Caminha "<< passo << " ate o camping " << (*v).size() -2  << endl;
                num_noites++;
                return num_noites;
            }else{
                //cout << "Erro: ultimo trecho maior do que a distancia maxima permtida" << endl;
                return -1;
            }
        }
    }else{
        //cout << "Erro: caminho menor do que a distancia" << endl;
        return -1;
    }
    
}



int main(int argc, char** argv) {
    vector<int> v;

    while(! cin.eof()){
        int n, k;
        cin >> n >> k;
        
        v.reserve(n + 1);

        int dist_total = 0;

        for(int i = 0; i<=n; i++){
            int l;
            cin >> l;
            dist_total += l;
            v.push_back(l);
        }

        int num_noites = -1;
        int max_cam = dist_total;
        int min_cam = 0;
        
        int max_cam_ant = dist_total;

        int meio = (min_cam + max_cam)/2; 

        while((max_cam - min_cam) > 1 ){
            meio = floor((min_cam + max_cam)/2.0);
            
            num_noites = contar_noites(&v,meio);
            
            if(num_noites > k || num_noites == -1 ){ // mais noites do que preciso => andar mais
                min_cam = meio;
            }
            if(num_noites <= k && num_noites != -1 ){ // menos noites do que preciso => andar menos
               
                max_cam_ant = meio;
                max_cam = meio;
            }
        }

        cout << max_cam_ant  << endl;
        
        

        v.clear();
   }
    
    return 0;
}


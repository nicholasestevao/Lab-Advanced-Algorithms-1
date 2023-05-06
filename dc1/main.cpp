
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
    
    int n = 0;
    cin >> n;
    vector<int> v;
    v.reserve(n);

    for(int i = 0; i<n; i++){
        int k;
        cin >> k;
        v.push_back(k);
    }

    /*for(int i = 0; i<n; i++){
        cout << v[i] << endl;
    }*/
    //cout << "length: "<< v.size() << endl;

    int tam = ceil(log2(n));
    int ** m = (int **) malloc(sizeof(int *)* n);
    for(int i = 0; i<n; i++){
        m[i] = (int *) malloc(sizeof(int)* tam);
    }

    for(int i = 0; i< n; i++){
        for(int j = 0; (1 << j) <= n; j++){
            m[i][j] = -1;
        }
    }

    //construir a matriz
    //primeira coluna trivial
    for(int i = 0; i<n; i++){
        m[i][0] = i; //indice do elemento de menor valor no intervalo i a i
    }
    for(int j = 1; (1 << j) <= n; j++){
        for(int i = 0; i + (1<<j) - 1 < n; i++){
            //int num = i + (1 << (j-1));
            //cout << "comparando: " << m[i][j-1] << " (" << i << " "<< j-1<< ") com " << m[i + (1 << (j-1))][j-1] << " (" << num << " " << j-1 << ")" << endl;
            if(v.at(m[i][j-1]) <= v.at(m[i + (1 << (j-1))][j-1])){
                m[i][j] = m[i][j-1];
            }else{
                m[i][j] = m[i + (1 << (j-1))][j-1];
            }
        }
    }

    /*for(int i = 0; i< n; i++){
        for(int j = 0; (1 << j) <= n; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }*/

    // consultas
    int q = 0;
    cin >> q;
    for(int i = 0; i< q; i++){
        int l,r;
        cin >> l;
        cin >> r;

        if( l == r){
            cout << v.at(m[l][0]) << endl;
        }else{
            int k = floor(log2(r-l+1));
            //cout << endl;
            //cout << "k: "<< k << endl;
            //cout << "m: " << l << " " << k << endl;
            //cout << "m: " << r - ((int) pow(2,k)) +1 << " " << k << endl;
            
            int ind1 = m[l][k];
            int ind2 = m[r - ((int) pow(2,k))+1][k]; 
            if(v.at(ind1) < v.at(ind2)){
                cout << v.at(ind1) << endl;
            }else{
                cout << v.at(ind2) << endl;
            }
        }
    }



    
    return 0;
}


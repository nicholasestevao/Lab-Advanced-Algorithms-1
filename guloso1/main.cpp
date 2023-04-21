
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <string.h>


using namespace std;

struct reg{
    int num;
    bool operator<(const reg &r) const{
        if(num < r.num){
            return false;
        }else{
            return true;
        }
    }
};


int main(int argc, char** argv) {
    
    int nhomem, nmulher = 0;
    int cont =1;
    
    cin >> nhomem;
    cin >> nmulher;

    while(nhomem != 0 && nmulher != 0){
        priority_queue<reg> qh;

        for(int i=0; i<nhomem; i++){
            reg dado;
            cin >> dado.num;
            qh.push(dado);
        }

        for(int i=0; i<nmulher; i++){
            int dado;
            cin >> dado;
        }

        cout << "Case " << cont << ": ";
        if(nhomem <= nmulher){
            cout << "0" << endl;
        }else{
            cout << nhomem - nmulher << " " << qh.top().num << endl;
        }
        
        cin >> nhomem;
        cin >> nmulher;
        cont++;
        

    }
    
    return 0;
}


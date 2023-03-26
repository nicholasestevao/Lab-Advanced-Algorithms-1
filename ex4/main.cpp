
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

struct reg{
    int id;
    int period;
    int next_ocurrence;
    bool operator<(const reg &r) const{
        if(next_ocurrence < r.next_ocurrence){
            return false;
        }else if(next_ocurrence == r.next_ocurrence){
            if(id < r.id){
                return false;
            }else{
                return true;
            }
        }else{
            return true;
        }
    }
};


int main(int argc, char** argv) {
    
    string str;
    reg r;

    getline(cin, str);
    char * temp = (char *) calloc(sizeof(char), 100);

    priority_queue<reg> q;

    while(str.at(0) != '#'){
        strcpy(temp, str.c_str());
        strtok(temp, " ");
        r.id = stoi(strtok(NULL, " "));

        strcpy(temp, strtok(NULL, " "));
        r.period = stoi(temp);

        r.next_ocurrence = r.period;

        //cout << "dados: "<< r.id << " " << r.period << endl;

        q.push(r);
        getline(cin, str);
    } 

    int n;
    cin >> n;
    int i = 0;

    while(i< n){    
            cout << q.top().id /*<< "  (" << q.top().next_ocurrence << ")" */ << endl;
            r = q.top();
            q.pop();
            r.next_ocurrence += r.period;
            q.push(r);
        
        i++;
    
    }

    /*int tam = q.size();
    for(int i =0; i< tam; i++ ){
        cout << q.top().id << " " << q.top().period << " " << q.top().next_ocurrence << endl;
        q.pop();
    }*/
    
    return 0;
}


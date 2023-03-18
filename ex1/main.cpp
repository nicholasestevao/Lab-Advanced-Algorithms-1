
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv) {

    int n_cases;
    cin >> n_cases;
    for(int i=0; i<n_cases; i++){
        int n, m;
        cin >> n;
        cin >> m;
        queue<int> q;
        priority_queue<int> pq;
        for(int j=0; j< n; j++){
            int v;
            cin >> v;
            q.push(v);
            pq.push(v);
        }
        int cont = 0;
        while( !(m==0 && q.front() == pq.top())){
            int job_priority = q.front();
            /*cout << "Prioridade primeiro: " << job_priority;
            cout << " (maxima: " << pq.top() << ")" << endl;
            cout << "M antes: " << m;*/
            if(job_priority == pq.top()){ // se primeiro job tem prioridade maxima -> é impresso
                q.pop();
                pq.pop();
                cont++;
                (m>0)? m-- : m =q.size()-1;
            }else{ //se o primeiro job nao tem prioridade maxima -> move para o final
                q.pop();
                q.push(job_priority);
                (m>0)? m-- : m =q.size()-1;
            } 
            /*cout << " depois: " << m << endl;
            cout << "tam: " << q.size() << " cont: " << cont << endl;*/
        }
        cont ++;
        cout << cont << endl;
        while(!q.empty()){
            q.pop();
        }
        while(!pq.empty()){
            pq.pop();
        }
        
    }

    return 0;
}


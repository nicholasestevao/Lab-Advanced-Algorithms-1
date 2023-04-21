
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <string.h>


using namespace std;

struct reg{
    int job_id;
    float time;
    float fine;
    bool operator<(const reg &r) const{
        // f1*t1 < f2*t2
        if(fine*r.time < r.fine*time){
            return true;
        }else if(fine*r.time == r.fine*time){
            if(job_id < r.job_id){
                return false;
            }else{
                return true;
            }
        }else{
            return false;
        }
    }
};


int main(int argc, char** argv) {
    
    int ncases = 0;
    
    cin >> ncases;
    string s;
    getline(cin, s);

    for(int i = 0; i< ncases; i++){
        if(i> 0){
            cout << endl;
        }
        int num_jobs = 0;
        cin >> num_jobs;
        priority_queue<reg> q;
        for(int j = 0; j< num_jobs; j++){
            reg r;
            r.job_id = j+1;
            cin >> r.time;
            cin >> r.fine;
            q.push(r);
        }

        for(int i=0; i<num_jobs; i++){
            cout << q.top().job_id << " ";
            q.pop();
        }
        cout << endl;

        

    }
    
    return 0;
}


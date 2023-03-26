
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdexcept>

using namespace std;

struct projeto{
    string nome;
    int num_inscritos;
    bool operator<(const projeto &proj) const{
        if(num_inscritos < proj.num_inscritos){
            return true;
        }else if(num_inscritos == proj.num_inscritos){
            if(nome.compare(proj.nome) > 0){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
};

bool find_student_remove(map<string, set<string>> *m, string s, string proj_atual, set<string> *forbidden_students){
    bool achou = false;
    map<std::string, set<string>>::iterator it = (*m).begin();
    set<string>::iterator its = (*forbidden_students).begin();

    for(int i = 0; i< (*m).size(); i++){
        //cout << (it->second).size() << endl;
        if((it->second).find(s) != (it->second).end()){ // achou em alguma lista
            if((it->first).compare(proj_atual) != 0){
                /*char * temp = (char *) malloc(sizeof(char)*100);
                strcpy(temp, s.c_str());
                string fs = temp;*/
                (*forbidden_students).insert(s);
                //cout << "Achou " << s << " em " << it->first << ". Nao inseriu em : " << proj_atual << endl; 
                //cout<< "removeu " << (it->second).erase(s) << endl;
                (it->second).erase(s);
                set<string>::iterator its = (it->second).begin();
                for(int j = 0; j< (it->second).size(); j++){
                    //cout << *its << " ";
                    its++;
                }
                //cout << endl;
                
                achou = achou || true;
            }
            
        }
        if((*forbidden_students).find(s) != (*forbidden_students).end()){
                //cout << "achou estudante proibido " << s << endl;
                achou = achou || true;
            }
        it++;
    }
    return achou; 
}

int main(int argc, char** argv) {
    
    string s;
    getline(cin, s);

    map<string, set<string>> m;
    char * proj_atual = (char *) calloc(sizeof(char),100);

    set<string> forbidden_students;

    while(!s.empty() && s[0] != '0'){
        if(s[0] != '1'){
            if(s[0] < 96){
            // cout << "Projeto: " << s.c_str();                
                strcpy(proj_atual, s.c_str());
                set<string> empty_set;
                m[proj_atual] = empty_set;
            }else{
                //cout << "Aluno (" << proj_atual << "): ";
                bool res_busca = find_student_remove(&m, s, proj_atual, &forbidden_students);
               // cout << "res: " << res_busca << " " << s<< endl;
                if(!res_busca){
                    m[proj_atual].insert(s.c_str());
                }

            }
            //cout << s << endl;
        }else{
            priority_queue<projeto> q;
            map<std::string, set<string>>::iterator it = m.begin();
            for(int i = 0; i< m.size(); i++){
                projeto p;
                //cout << it->first;
                for(int j = 0; j< (it->first).length(); j++){
                    //cout << (it->first).c_str()[j] << "_(" << j << ")_";
                    if((it->first).c_str()[j] == '\n'){
                        //cout << "encontrou quebra em " << j << endl;
                    }
                }
                char * temp = (char *) malloc(sizeof(char)*100);
                strcpy(temp, (it->first).c_str());
                temp[(it->first).length()-1] = '\0';            
                p.nome = temp;
                p.num_inscritos = (it->second).size();
                q.push(p);
                it++;
            }

            

            int tam = q.size();
            for(int i= 0; i<tam; i++){
                cout << q.top().nome << " " << q.top().num_inscritos << endl;
                q.pop();
            }
            m.clear();
            free(proj_atual);
            proj_atual = (char *) calloc(sizeof(char),100);
        }       
        
        getline(cin, s);   
    } 
    
   /* map<std::string, set<string>>::iterator it = m.begin();
    for(int i = 0; i< m.size(); i++){
        cout << (it->first);
        cout << (it->second).size() << endl;
        set<string>::iterator its = (it->second).begin();
        for(int j = 0; j< (it->second).size(); j++){
            cout << *its << " ";
            its++;
        }
        cout << endl;
        it++;
    }*/

    priority_queue<projeto> q;
    map<std::string, set<string>>::iterator it = m.begin();
    for(int i = 0; i< m.size(); i++){
        projeto p;
        //cout << it->first;
        p.nome = it->first;
        p.num_inscritos = (it->second).size();
        q.push(p);
        it++;
    }

    int tam = q.size();
    for(int i= 0; i<tam; i++){
        cout << q.top().nome<< " " << q.top().num_inscritos << endl;
        q.pop();
    }
    return 0;
}


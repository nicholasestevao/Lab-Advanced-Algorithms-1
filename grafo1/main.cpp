
#include <cstdlib>
#include <iostream>

#include  <queue>
#include <list>
#include <vector>
#include <map>
#include <limits>

using namespace std;

typedef struct aresta{
    long custo;
    int verticeA;
    int verticeB;
} aresta;

typedef struct vertice{
    int indice;
    int num_arestas;
    aresta * arestas;

} vertice;

typedef struct grafo{
    int num_vertices;
    vertice * vertices;
} grafo;

typedef struct par{
    long custo;
    int vertice;
    bool operator<(const par &p) const{return (custo > p.custo);}
}par;

void djikstra(int inicio, grafo *g, long * dist){
    priority_queue<par> adjacentes;
    par p;
    p.custo = 0;
    p.vertice = inicio;
    adjacentes.push(p);
    dist[inicio] = 0;

    while(!adjacentes.empty()){
        par p_u = adjacentes.top();
        int u = p_u.vertice;
        adjacentes.pop();
        for(int v = 0; v< (g->vertices)[u].num_arestas; v++){
            if(dist[u] > dist[(g->vertices)[u].arestas[v].verticeB]){
                continue;
            }
            if(dist[u] + (g->vertices)[u].arestas[v].custo < dist[(g->vertices)[u].arestas[v].verticeB]){
                dist[(g->vertices)[u].arestas[v].verticeB] = dist[u] + (g->vertices)[u].arestas[v].custo;
                par p_v;
                p_v.custo = dist[(g->vertices)[u].arestas[v].verticeB];
                p_v.vertice = (g->vertices)[u].arestas[v].verticeB;
                adjacentes.push(p_v);
            }
        }
    }

}


int main(int argc, char** argv) {
    // n cities m roads q queries
    int n, m, q;
    cin >> n >> m >> q;
    grafo g;
    g.num_vertices = n;
    g.vertices = (vertice *) malloc(sizeof(vertice)*n);
    for(int i = 0; i< n; i++){
        g.vertices[i].indice = i;
        g.vertices[i].num_arestas = 0;
        g.vertices[i].arestas = (aresta *) malloc(sizeof(aresta)*n);
    }
    for(int i = 0; i< m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g.vertices[a-1].arestas[g.vertices[a-1].num_arestas].custo = c;
        g.vertices[a-1].arestas[g.vertices[a-1].num_arestas].verticeA = a-1;
        g.vertices[a-1].arestas[g.vertices[a-1].num_arestas].verticeB = b-1;
        (g.vertices[a-1].num_arestas)++;

        g.vertices[b-1].arestas[g.vertices[b-1].num_arestas].custo = c;
        g.vertices[b-1].arestas[g.vertices[b-1].num_arestas].verticeA = b-1;
        g.vertices[b-1].arestas[g.vertices[b-1].num_arestas].verticeB = a-1;
        (g.vertices[b-1].num_arestas)++;
    }

    /*for(int i = 0; i< n; i++){
        cout << "Vertice: "<< g.vertices[i].indice +1<< endl;
        cout << "Num arestas: "<<  g.vertices[i].num_arestas << endl;
        for(int j = 0; j< g.vertices[i].num_arestas; j++){
            cout << g.vertices[i].arestas[j].verticeA +1<< " " << g.vertices[i].arestas[j].verticeB +1<< ": " << g.vertices[i].arestas[j].custo << endl;
        }  
    }*/

    map<pair<int,int>, long> memo;
    long * dist = (long *) malloc(sizeof(long)*n); // posicao i armazena distancia ao vertice i
 
    for(int i = 0; i< q; i++){
        int a, b;
        cin >> a >> b;
        if((memo.count(pair<int,int>(a-1,b-1)) > 0)){
            cout << memo[pair<int,int>(a-1,b-1)] << endl;
        }else if(memo.count(pair<int,int>(b-1,a-1)) > 0){
            cout << memo[pair<int,int>(b-1,a-1)] << endl;
        }else{
            for(int i = 0; i< n; i++){
                dist[i] = 9999999999;
            }
            djikstra(a-1,&g,dist);
            cout << ((dist[b-1] != 9999999999)?dist[b-1]:-1) << endl;
            for(int j = 0; j<n; j++){
                if(dist[j] != 9999999999){
                    pair<int,int> p = pair<int,int>(a-1,j);
                    memo.insert(pair<pair<int,int>,int>(p, dist[j]));
                    pair<int,int> q = pair<int,int>(j,a-1);
                    memo.insert(pair<pair<int,int>,int>(q, dist[j]));
                }
            }
        }
    }
    return 0;
}


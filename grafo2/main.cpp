
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
    int visitado;
    aresta * arestas;

} vertice;

typedef struct grafo{
    int num_vertices;
    vertice * vertices;
} grafo;

typedef struct par_vert_custo{
    int vertice;
    int custo;
    bool operator<(const par_vert_custo &p) const{
        if(custo < p.custo)
            return false;
        return true;
    }
} par_vert_custo;



int prim(int inicio, grafo g){
    int cont_visitados= 0;
    priority_queue<par_vert_custo> fila;
    int custo = 0;
    par_vert_custo p1;
    p1.vertice = inicio;
    p1.custo = 0;
    fila.push(p1);
    

    while(!fila.empty()){
        par_vert_custo p = fila.top();
        int u = p.vertice;
        fila.pop();

        if((g.vertices)[u].visitado == 0){
            custo += p.custo;
            (g.vertices)[u].visitado = 1;
            cont_visitados++;
            //cout << "Visitou " << u +1<< endl;
        }
        
        for(int v = 0; v< (g.vertices)[u].num_arestas; v++){
            if((g.vertices)[(g.vertices)[u].arestas[v].verticeB].visitado == 0){
                par_vert_custo p2;
                p2.vertice = (g.vertices)[u].arestas[v].verticeB;
                p2.custo = (g.vertices)[u].arestas[v].custo;
                //cout << "Colocou na fila: "<< (g->vertices)[u].arestas[v].verticeB +1<< endl;
                fila.push(p2);
            }
        }
    }
    //cout << "visitou "<< cont_visitados << endl;
    return (cont_visitados == g.num_vertices)?custo:-1;

}


int main(int argc, char** argv) {
    // n cities m roads 
    int n, m;
    cin >> n >> m;
    grafo g;
    g.num_vertices = n;
    g.vertices = (vertice *) malloc(sizeof(vertice)*n);
    for(int i = 0; i< n; i++){
        g.vertices[i].indice = i;
        g.vertices[i].visitado = 0;
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

    int res = prim(0, g);
    if(res != -1){
        cout << res << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}


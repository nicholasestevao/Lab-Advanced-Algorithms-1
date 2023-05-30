
#include <cstdlib>
#include <iostream>

#include  <queue>
#include <list>
#include <vector>
#include <map>
#include <limits>

using namespace std;

typedef struct aresta{
    int verticeA;
    int verticeB;
} aresta;

typedef struct vertice{
    int indice;
    int num_arestas;
    int visitado;
    int cor;
    aresta * arestas;

} vertice;

typedef struct grafo{
    int num_vertices;
    vertice * vertices;
} grafo;



int bipartido(int inicio, grafo g, int cont_visitados){
    queue<aresta> fila;
    aresta a1;
    a1.verticeA = inicio;
    a1.verticeB = inicio;
    (g.vertices)[inicio].visitado = 1;
    (g.vertices)[inicio].cor = 1;
    fila.push(a1);
    
    while(!fila.empty()){
        aresta p = fila.front(); //aresta de u para v
        int u = p.verticeA;
        int v = p.verticeB;
        fila.pop();

        if((g.vertices)[v].visitado == 0){
            (g.vertices)[v].visitado = 1;
            (g.vertices)[v].cor = ((g.vertices)[u].cor == 1)?2:1;
            cont_visitados++;
            //cout << "Visitou " << v+1<< endl;
        }else{//ja foi visitado
            if(v != inicio && (g.vertices)[u].cor == (g.vertices)[v].cor){
                //cout << u +1 << " e " << v +1<< " com mesma cor"<< endl;
                return -1;
            }
        }
        
        for(int k = 0; k< (g.vertices)[v].num_arestas; k++){
            if((g.vertices)[(g.vertices)[v].arestas[k].verticeB].visitado == 0){
                aresta p2;
                p2.verticeA = v;
                p2.verticeB = (g.vertices)[v].arestas[k].verticeB;
                //cout << "Colocou na fila: "<< (g.vertices)[v].arestas[k].verticeB +1<< endl;
                fila.push(p2);
            }
        }
    }
    
    while(cont_visitados != g.num_vertices){
        int indice = -1;
        for(int i = 0; i< g.num_vertices; i++){
            if(g.vertices[i].visitado == 0){
                indice = i;
                break;
            }
        }
        if(indice != -1){
            bipartido(indice, g, cont_visitados);
            //cout << "rodou de novo " << flag_rodou<< endl;
        }else{
            break;
        }
    }
    //cout << "visitou "<< cont_visitados << endl;
    return (cont_visitados == g.num_vertices)?0:-1;

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
        g.vertices[i].cor = -1;
        g.vertices[i].arestas = (aresta *) malloc(sizeof(aresta)*n);
    }
    for(int i = 0; i< m; i++){
        int a, b;
        cin >> a >> b;
        g.vertices[a-1].arestas[g.vertices[a-1].num_arestas].verticeA = a-1;
        g.vertices[a-1].arestas[g.vertices[a-1].num_arestas].verticeB = b-1;
        (g.vertices[a-1].num_arestas)++;

        g.vertices[b-1].arestas[g.vertices[b-1].num_arestas].verticeA = b-1;
        g.vertices[b-1].arestas[g.vertices[b-1].num_arestas].verticeB = a-1;
        (g.vertices[b-1].num_arestas)++;
    }

    /*for(int i = 0; i< n; i++){
        cout << "Vertice: "<< g.vertices[i].indice +1<< endl;
        cout << "Num arestas: "<<  g.vertices[i].num_arestas << endl;
        for(int j = 0; j< g.vertices[i].num_arestas; j++){
            cout << g.vertices[i].arestas[j].verticeA +1<< " " << g.vertices[i].arestas[j].verticeB +1<<  endl;
        }  
    }*/

    bipartido(0, g, 0);
    int teste = -1;
    for(int i = 0; i< g.num_vertices; i++){
        if(g.vertices[i].visitado == 0){
            teste = i;
            break;
        }
    }
    if(teste == -1){
        for(int i = 0; i< n; i++){
            cout << g.vertices[i].cor << " ";
        }
        cout << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }

    for(int i = 0; i< n; i++){
        free(g.vertices[i].arestas);
    }
    free(g.vertices);

    return 0;
}


/*
    Ejemplo de álgoritmo de mochila
    Constanza Gómez Sánchez A01026717
    Viernes 27 de marzo de 2020
*/
#include <iostream>
#include <vector>

using namespace std;

class Servicio{
    public:
    int cliente, camino, tiempo;
    Servicio(){
    }
    Servicio(int nClient, int tRoad, int tExec){
        cliente = nClient;
        camino = tRoad;
        tiempo = tExec;
    }
};

class Fontanero{
    public:
    void organizar(vector<Servicio> lista, int maxClientes){
        //ordeno el vector para organizar las ordenes
        for(int i=0; i<maxClientes; ++i){
            for(int j=0; j<maxClientes-1; ++j){
                if(lista.at(j).camino>lista.at(j+1).camino){
                    Servicio temp = lista.at(j);
                    lista.at(j) = lista.at(j+1);
                    lista.at(j+1) = temp;
                }
            }
        }
        //imprime los resultados
        cout<<"La forma en la que va a dar el servicio es el siguiente: "<<endl;
        cout<<"No. Cliente,         Tiempo de llegada,      Tiempo de reparación"<<endl;
        for(int i=0; i<maxClientes; ++i){
            cout<<lista.at(i).cliente<<",                   "<<lista.at(i).camino<<",                             "<<lista.at(i).tiempo<<endl;
        }
    }

};

int main(){
    int maxClientes = 10;
    vector<Servicio> lista;
    for(int i=0; i<maxClientes; ++i){
        Servicio agregar(i+1, rand()%30+1, 30);
        //siempre se va a tardar 30min en las reparaciones
        lista.push_back(agregar);
    }
    //inicio al Fontanro
    Fontanero f;
    f.organizar(lista, maxClientes);
}


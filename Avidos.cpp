/*
    Ejemplo de álgoritmo de mochila
    Constanza Gómez Sánchez A01026717
    Viernes 27 de marzo de 2020
*/
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Elementos{
    public:
    int peso, beneficio;
    Elementos(){
    }
    Elementos(int benefit, int weight){
        beneficio = benefit;
        peso = weight;
    }
};

class Mochila{
    public:
    void insertar(vector<Elementos> cosas, int n, int pesoMochila){
        //ordeno el vector para encontrar el mejor beneficio
        for(int i=0; i<n; i++){
            for(int j=0; j<n-1; j++){
                if(cosas.at(j).beneficio>cosas.at(j+1).beneficio){
                    Elementos temp = cosas.at(j);
                    cosas.at(j) = cosas.at(j+1);
                    cosas.at(j+1) = temp;
                }
            }
        }
        /*cout<<"ordenado"<<endl;
        for(int i=0; i<n; ++i){
            cout<<cosas.at(i).beneficio<<","<<cosas.at(i).peso;
            cout<<endl;
        }*/
        //agrega elementos a la mochila por su valor
        vector<Elementos> final;
        int agregado = 0;
        int cont = 0;
        for(int i=0; i<cosas.size(); ++i){
            int temp = agregado+cosas.at(i).peso;
            if(agregado<=pesoMochila){
                Elementos agregar(cosas.at(i));
                final.push_back(agregar);
                agregado=temp;
            }
        }
        //imprime los elementos en la mochila
        cout<<"Los objetos que se metieron a la mochila:"<<endl;
        for(int i=0; i<final.size(); ++i){
            cout<<final.at(i).beneficio<<","<<final.at(i).peso;
            cout<<endl;
        }
    }
};

int main(){
    //indico la cantidad de elementos y el peso de la mochila
    int n = 10;
    int pesoMochila = 25;
    //inserto un númeor aleatorio de beneficio y peso
    vector<Elementos> cosas;
    srand((unsigned)time(NULL));
    for(int i=0; i<n; ++i){
        Elementos objetoP(rand()%20+1 , rand()%10+1);
        cosas.push_back(objetoP);
    }
    //inicio la mochila
    Mochila m;
    m.insertar(cosas, n, pesoMochila);
}
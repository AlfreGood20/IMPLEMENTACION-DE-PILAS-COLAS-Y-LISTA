#include <iostream>

struct Nodo{
    int dato;
    Nodo* siguiente;

    Nodo(int dato): dato(dato):siguiente(nullptr){}
};

class Cola{
    Nodo* frente=nullptr;
    Nodo* ultimo=nullptr;

    public:
        Cola(){}
        ~Cola(){
            while(!empty()){
                dequeue();
            }
        }

        void enqueue(int valor){
            Nodo* nuevo=new Nodo(valor);

            if(empty()){
                frente=nuevo;
                ultimo=nuevo;
                return;
            }

            ultimo->siguiente=nuevo;
            ultimo=nuevo; //PUNTAR AL ULTIMO ELEMENTO
        }

        int dequeue(){
            if(empty()){
                //MENSAJE 
                return -1;
            }

            Nodo* temporal=frente;
            int valor=temporal->dato;
            frente=frente->siguiente;

            delete temporal;

            return valor;
        }

        int front(){
            if(empty()){
                // MENSAJE
                return -1;
            }

            return frente->dato;
        }
};

class Pila{

    Nodo* tope=nullptr;

    public:
        Pila(){}
        ~Pila(){
            while(!empty()){
                pop();
            }
        }

        void push(int valor){
            Nodo* nuevo=new Nodo(valor);
            nuevo->siguiente=tope;
            tope=nuevo;
        }

        int pop(){
            if(empty()){
                //MENSAJE
                return -1;
            }

            Nodo* temporal=tope;
            int valor=temporal->dato;

            tope=tope->siguiente;

            delete temporal;

            return valor;
        }

        int top(){
            if(empty()){
                //MENSAJE
                return -1;
            }

            return tope->dato;
        }

        bool empty(){
            return tope==nullptr;
        }
};

class Lista{
    Nodo* cabeza=nullptr;

    public:
        Lista(){}
        ~Lista(){
            while(!empty()){
                remove_front();
            }
        }

        void push_front(int valor){
            Nodo* nuevo=new Nodo(valor);

            if(empty()){
                cabeza=nuevo;
            }

            nuevo->siguiente=cabeza;
            cabeza=nuevo;
        }

        void push_back(int valor){
            Nodo* nuevo=new Nodo(valor);

            if(empty()){
                cabeza=nuevo;
                return;
            }

            Nodo* ultimo=cabeza; 
            while(ultimo->siguiente != nullptr){ //HASTA QUE ENCONTRAR EL ULTIMO
                ultimo=ultimo->siguiente;
            }

            ultimo->siguiente=nuevo;
        }

        int erase(int i){
            int tamaño=size();

            if(i>tamaño || empty() || i<=0){
                //
                return -1;
            }

            if(i==1){
                return cabeza->dato;
            }

            Nodo* anterior=cabeza;
            for(int j=1;j<(i-1);j++){
                anterior=anterior->siguiente;
            }

            Nodo* borrar=anterior->siguiente;
            int valor=borar->dato;
            anterior->siguiente=borrar->siguiente;

            delete borrar;

            return encontrado->dato;
        }

        bool empty(){
            return cabeza==nullptr;
        }


        int size(){
            int contador=0;

            Nodo* recorrer=cabeza;
            while(recorrer != nullptr){
                contador++;
                recorrer=recorrer->siguiente;
            }
            return contador;
        }

};



int main(){
    return 0;
}
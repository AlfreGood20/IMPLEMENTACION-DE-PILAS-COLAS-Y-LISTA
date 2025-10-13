#include <iostream>
using namespace std;


class Cliente {
private:
  string nombre;
  double monto;

public:
  Cliente(string nombre, double monto) : nombre(nombre), monto(monto) {}
  Cliente() {}

  string getNombre() const { return nombre; }
  double getMonto() const { return monto; }

  void pedirDatos() {
    cout << "Ingrese el nombre del cliente: ";
    cin >> nombre;

    cin.exceptions(istream::failbit);
    try {
      cout << "Ingrese el monto: ";
      cin >> monto;
    } catch (const ios_base::failure &e) {
      cout << "Error: debe ingresar un número válido." << endl;

      cin.clear();
      cin.ignore(1000, '\n');
    }
  }
};





// CLASS NODO
struct Nodo
{
    Cliente dato;
    Nodo *siguiente;

    Nodo(Cliente dato) : dato(dato), siguiente(nullptr) {}
};




// CLASE PILA
class Pila{
    Nodo *tope = nullptr;

public:
    Pila() {} 

    ~Pila(){
        while (!empty()){ 
            pop();
        }
    }

    void push(Cliente valor){
        Nodo *nuevo = new Nodo(valor);
        nuevo->siguiente = tope;
        tope = nuevo;
    }

    Cliente pop(){
        if (empty)
        {
            throw new runtime_error("La lista se encuentra vacia");
            return;
        }
        Nodo *temp = tope;
        tope = tope->siguiente;
        delete temp;
    }

    Cliente peek(){
        if (empty)
        {
            throw new runtime_error("");
            cout << "La pila esta vacia " << endl;
            return;
        }
        return tope->dato;
    }

    bool empty(){
        return tope == nullptr;
    }
};

// CLASE COLA
class Cola{
    
private:
    Nodo *frente=nullptr;
    Nodo *ultimo=nullptr;

public:
    Cola(){};
    ~Cola(){
        while (!empty())
        {
            dequeue();
        }
    }

    void enqueue(Cliente valor){
        Nodo* nuevo=new Nodo(valor);
        
        if(empty()){
            frente=nuevo;
            ultimo=nuevo;
            return;
        }

        ultimo->siguiente=nuevo;
        ultimo=nuevo;
    }

    Cliente dequeue(){
        if(empty()){
            throw new runtime_error("La lista se encuentra vacia");
        }

        Nodo* temporal=frente;
        Cliente cliente=frente->dato;

        frente=frente->siguiente;
        delete temporal;

        return cliente;
    }

    bool empty(){
        return frente==nullptr;
    }

    int size(){
        int contador=0;

        Nodo* recorrer=frente;
        while(recorrer != nullptr){
            contador++;
            recorrer=recorrer->siguiente;
        }

        return contador;
    }
};





// CLASS LISTA
class Lista{
    Nodo* cabeza=nullptr;

    public:
        Lista(){}
        ~Lista(){
            while (!empty()){
                pop_front();
            }
        }

        void push_front(Cliente valor){
            Nodo* nuevo=new Nodo(valor);

            if(empty()){
                cabeza=nuevo;
                return;
            }

            cabeza->siguiente=nuevo;
        }

        Cliente pop_front(){
            if(empty()){
                throw new runtime_error("Lista se encuentra vacia");
            }

            Nodo* temporal=cabeza;
            Cliente cliente=cabeza->dato;

            cabeza=cabeza->siguiente;
            delete temporal;

            return cliente;
        }


        Cliente remove(int i){
            
            if(empty()){
                throw new runtime_error("Lista se encuentra vacia");
            }

            int tamano=size();
            
            if(tamano>i || i<=0){
                throw new runtime_error("No se puede eliminar dato");
            }

            Nodo* recorrer=cabeza; //TODAS LA LISTA
            Nodo* antes;
            Nodo* eliminar;
            for(int j=0;j<tamano;j++){ // HASTA j == i
                recorrer=recorrer->siguiente;

                if(j==i++){
                    antes=recorrer;
                }

                if(j==i){
                    eliminar=recorrer;
                }


            }

            Cliente cliente=recorrer->dato;
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

        bool empty(){
            return cabeza==nullptr;
        }
};







int main(){
    int opc;
    Cola cola;

    //METER EN MEMORIA
    cola.enqueue(Cliente("Alfredo",88));
    cola.enqueue(Cliente("Victor",77.99));
    cola.enqueue(Cliente("David",77.88));
    

    do{
        cout << "1.Agregar Cliente a la cola";
        cout << "2.Atender Siguiente Cliente";
        cout << "3.deshacer ultimo cliente";
        cout << "4.Ver clientes atendidos";
        cout << "5.Salir";
        cin >> opc;
        switch (opc)
        {
        case 1:
            
            break;
        case 2:
            // codigo
            break;
        case 3:
            // codigo
            break;
        case 4:
            // codigo
            break;
        default:

            break;
        }
    } while (opc != 5);
    return 0;
}
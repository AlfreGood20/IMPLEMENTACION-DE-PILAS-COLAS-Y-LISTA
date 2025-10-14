#include <iostream>
#include <stdexcept>
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

struct Nodo{
    Cliente dato;
    Nodo *siguiente;

    Nodo(Cliente dato) : dato(dato), siguiente(nullptr) {}
};

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
        if (empty())
        {
            throw runtime_error("La pila se encuentra vacia\n");
        }
        Nodo *temp = tope;
        Cliente cliente=temp->dato;

        tope = tope->siguiente;
        delete temp;

        return cliente;
    }

    Cliente peek(){
        if (empty())
        {
            throw runtime_error("La pila esta vacia\n");
        }
        return tope->dato;
    }

    bool empty(){
        return tope == nullptr;
    }
};


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
            throw runtime_error("La lista se encuentra vacia\n");
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

            nuevo->siguiente=cabeza;
            cabeza=nuevo;
        }

        Cliente pop_front(){
            if(empty()){
                throw runtime_error("Lista se encuentra vacia\n");
            }

            Nodo* temporal=cabeza;
            Cliente cliente=cabeza->dato;

            cabeza=cabeza->siguiente;
            delete temporal;

            return cliente;
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

        void todosClientes(){
            if(empty()){
                cout<<"No hay clientes atendidos"<<endl;
                return;
            }

            int contador=0;
            cout<<"\nLista: "<<endl;
            Nodo* recorrer=cabeza;
            while (recorrer != nullptr){
                contador++;
                Cliente cliente=recorrer->dato;
                cout<<contador<<".-"<<" Nombre: "<<cliente.getNombre()<<" Monto: $"<<cliente.getMonto()<<endl;
                recorrer=recorrer->siguiente;
            }
        }
};

int main(){
    int opc;
    
    Cola cola;
    Lista lista;
    Pila pila;
    cola.enqueue(Cliente("Alfredo",88));
    cola.enqueue(Cliente("Victor",77.99));
    cola.enqueue(Cliente("David",77.88));
    cola.enqueue(Cliente("Jose",3.1416));
    cola.enqueue(Cliente("Emili",66));

    do{
        cout << "\n1.Agregar Cliente a la cola"<<endl;
        cout << "2.Atender Siguiente Cliente"<<endl;
        cout << "3.Cantidad de clientes que fueron atendidos"<<endl;
        cout << "4.Ver clientes atendidos"<<endl;
        cout << "5.Desacer Cliente atendido"<<endl;
        cout << "6.Salir\n"<<endl; 

        try{
            cout<<"Ingrese opcion: ";
            if(!(cin>>opc)){
                throw runtime_error("Debe ingresar un numero valido");
            }
        }catch(const runtime_error& e){
            cout<<"ERROR: "<< e.what()<<endl;
        }
        switch (opc){
            case 1: {
                Cliente cliente;
                cliente.pedirDatos();
                cola.enqueue(cliente);
                break;
            }
            case 2:{
                try {
                    Cliente cliente = cola.dequeue();
                    lista.push_front(cliente);
                    pila.push(cliente);
                    cout<<"\nCliente atendido: ";
                    cout << "Nombre: " << cliente.getNombre()<<" monto: $"<<cliente.getMonto()<<"\n";
                } catch(const runtime_error& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
 
            case 3:{
                cout<<"\nFueron atendidos: "<<lista.size()<<" clientes\n";
                break;
            }

            case 4:{
                lista.todosClientes();
                break;
            }
            case 5:{
                try{
                    Cliente cliente = pila.pop();
                    cola.enqueue(cliente);
                    cout<<"cliente desecho: "<< cliente.getNombre()<<" con un monto de: $"<<cliente.getMonto()<<endl;
                    break;
                }catch(const runtime_error& e){
                    cout << "Error: " << e.what() << endl;
                }
            }
            
            default:
            cout<<"OPCION INVALIDA. INTENTE DE NUEVO ";
            break;
        }
    } while (opc != 6);
    return 0;
}
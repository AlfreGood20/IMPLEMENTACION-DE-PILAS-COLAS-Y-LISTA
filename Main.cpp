#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>
using namespace std;

// CLASS NODO
struct Nodo {
  Cliente dato;
  Nodo *siguiente;

  Nodo(Cliente dato) : dato(dato), siguiente(nullptr) {}
};

// CLASE PILA
class Pila {
  Nodo* tope = nullptr;

  public:
    Pila(){} //CONTRUCTOR

    ~Pila(){
      while(!empty()){ // DESTRUCTOR
        pop();
      }
    }
  
    void push(Cliente valor) {
      Nodo* nuevo=new Nodo(valor);
      nuevo->siguiente=tope;
      tope = nuevo;
    }
    
    void pop (){
      if(empty){
        throw new runtime_error("");
      }

    }

    Cliente peek(){

    }
    
    bool empty(){
      return tope==nullptr;
    }
}


// CLASE COLA
class cola {
private:
  Nodo *frente;
  Nodo *final;

public:
  cola() : frente(nullptr), final(nullptr) {}
  ~cola() {
    while (!estaVacia()) {
      dequeue();
    }
  }

  void enqueue(Cliente valor){
    Nodo* nuevo= new Nodo(valor);
    final->siguiente=nuevo;

  }

  void dequeue(){

  }

};

// CLASS LISTA


// CLASE CLIENTE
class Cliente {
private:
  string nombre;
  double monto;

public:
  Cliente(string nam, double mon) : nombre(nam), monto(mon) {}
  if (nam.empty()) throw invalid_argument("NO SE PUEDE DEJAR VACIO");

  string GetNombre() const { return nombre; }
  double GetMonto() const { return monto; }

  void mostrar() const {
    cout << "Cliente: " << nombre << " con un monto a pagar de:  " << monto;
  }
};

string PNombre(){
  string nombre;
  cout<<"IIngrese el nombre del cliente";
  cin>>nombre;
  if(cin.fai)
}

double PMonto() {
  double monto;
  cout << "Ingrese monto del cliente: ";
  cin >> monto;

  if (cin.fail()) {
    cin.clear();
    cin.ignore(numerics_limits<streamsize>::max(), '\n');
    cout<<"DEBES INGRESAR SOLO NUMEROS, INTENTA DE NUEVO";
    continue;
  }
  cin.ignore(numerics_limits<streamsize>::max(), '\n');
  return monto;
};



int main() {
  int opc;
  do {
    cout << "1.Agregar Cliente a la cola";
    cout << "2.Atender Siguiente Cliente";
    cout << "3.deshacer ultimo cliente";
    cout << "4.Ver clientes atendidos";
    cout << "5.Salir";
    cin >> opc;
    switch (opc) {
    case 1:
      /* code */
      cout << "HOla mundo gei";
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
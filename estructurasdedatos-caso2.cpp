
//Caso 2 EDD

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Parametro {
  //clase Parametro
  //para representar parametro que puede ser creado y asignado a un dispositivo
  //especifico a traves del vector de parametros de dicho dispositivo
  public:
    string caracteristica;
    int value;

  Parametro(string caract, int valor) {
      //el constructor
      this->caracteristica = caract;
      this->value = valor;
  }
};


class Accion {
  //clase Accion
  
  public:
    string nombre; //nombre de la accion, por ejemplo "apagar"
    vector<Parametro> que_modifica; //vector de parametros que modifica la accion

  Accion(string name) {
      //el constructor
      this->nombre = name;
  }
  //metodo que agrega parametro que modifica al vector de la accion actual
  void add_parametro(Parametro param) {
      this->que_modifica.push_back(param);
  }
  void ejecutar(string operador, Parametro modificar, int operando) {
      //metodo para ejecutar la accion
      //el metodo toma un operador "+" ejemplo
      //una instancia de tipo Parametro que cambiará
      //y un valor operando para modificar el parametro
      for(int i = 0; i < this->que_modifica.size(); i++) {
          //iteramos en la lista de parametros que modifica la accion
          if(operador == "+") {
              //hay que revisar cual se desea que sea la modificacion al valor del parametro
              this->que_modifica[i].value = this->que_modifica[i].value + operando;
              cout << modificar.caracteristica << " incrementad@ en: " << operando << endl;
              cout << "El valor actual es: " << this->que_modifica[i].value << endl;
              //en caso de de se desee aumentar un parametro se brinda un signo mas y el valor
          } else if(operador == "-") {
              //en caso de que sea una decrementación lo que se desea modificar en el parametro
              this->que_modifica[i].value = this->que_modifica[i].value - operando;
              cout << modificar.caracteristica << " decrementad@ en: " << operando << endl;
              cout << "El valor actual es: " << this->que_modifica[i].value << endl;
          } else if(operador == "*") {
              //en caso de que sea una multiplicacion
              this->que_modifica[i].value = this->que_modifica[i].value * operando;
              cout << modificar.caracteristica << " multiplicad@ por: " << operando << endl;
              cout << "El valor actual es: " << this->que_modifica[i].value << endl;
          } else if(operador == "/") {
              //en caso de que se quiera realizar una división al valor del parametro
              this->que_modifica[i].value = this->que_modifica[i].value / operando;
              cout << modificar.caracteristica << " dividido@ entre: " << operando << endl;
              cout << "El valor actual es: " << this->que_modifica[i].value << endl;
            }
          }
      }
};



class Dispositivo {
  //clase Dispositivo

  public:
    vector<Accion> las_acciones; // vector donde se ponen las acciones del dispositivo actual
    string type;  //este representa el tipo de dispositivo que se crea
    int id_cuarto;  //este representa el numero de cuarto
    string name_disp; //este es para el nombre del dispositivo

  Dispositivo(string type, int id_room, string nombre_disp) {
      //el constructor
      this->type = type; 
      this->id_cuarto = id_room; 
      this->name_disp = nombre_disp; 
     
  }
  void add_accion(Accion action) {
      //metodo que agrega accion que hace el dispositivo
      this->las_acciones.push_back(action);
  }
  
};



class Cuarto {
  //clase Cuarto
  
  public:
    int id_of_room; //identificador del cuarto
    vector<Dispositivo> cuartovec; //vector de dispositivos en una habitacion especifica

  Cuarto(int id) {
      //el constructor
      this->id_of_room = id;
  }
  //metodo que agrega dispositivo al cuarto actual
  void add_dispositivo(Dispositivo dispo) {
      this->cuartovec.push_back(dispo);
  }
};


class Casa {
  //clase Casa
  
  public:
    //representa la casa de un cliente
    vector<Cuarto> house; //vector de habitaciones en la casa

  //metodo que agrega cuarto a la casa
  void add_room(Cuarto newroom) {
      this->house.push_back(newroom);
  }
};



int main() {
    //Estos son ejemplos de la creación de instancias
    //Tanto los parametros como las acciones como los dispositivos son completamente configurables
    //El usuario puede crear cualquier tipo de dispositivo con cualquier accion 
    //con cualquier parametro y colocarlo en cualquier habitación configurandolo asi:
    
    Parametro newparam = Parametro("Energia",0);   //creando parametro 
    Accion newaccion = Accion("Apagar");    //creando accion 
    Accion newaccion2 = Accion("Encender");  //creando accion 
    
    newaccion.add_parametro(newparam);    //asignando parametro a la accion 
    newaccion2.add_parametro(newparam);   //asignando parametro a la accion 
    
    Dispositivo newdisp = Dispositivo("Bombillo", 0, "Luz interna");   //creando dispositivo
    newdisp.add_accion(newaccion);       //asignando las acciones creadas previamente al dispositivo
    newdisp.add_accion(newaccion2);
    
    Cuarto newcuarto = Cuarto(0);    //creando cuarto 
    newcuarto.add_dispositivo(newdisp);    //agregando dispositivo al cuarto 
    
    Casa newhouse = Casa();        //crear la casa que es el conjunto de todos los cuartos
    newhouse.add_room(newcuarto);  //añadir cuarto a la casa 
    
    newaccion2.ejecutar("+", newparam, 1);   //ejecutando accion encender
    
    newaccion2.ejecutar("+", newparam, 6);   //ejecutando accion encender de nuevo
    
    
    //ESTA ES UNA DEMOSTRACIÓN, PRUEBE A AGREGAR LOS DISTINTOS TIPOS DE DISPOSITIVOS QUE DESEE
    
  return 0;
}

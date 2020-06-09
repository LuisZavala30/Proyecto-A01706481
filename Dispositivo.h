// Proyecto Domotica
/* Luis Angel Zavala Robles
    A01706481
*/


#ifndef DISPOSITIVO_H_
#define DISPOSITIVO_H_

#include <iostream>
#include <sstream>

using namespace std;

class Dispositivo{   //CLASE ABSTRACTA

    //Variables protected que seran heredadas
    protected:
        string tipo;
        int id;
        bool status;
        string ubicacion;

    //Declaro metodos publicos y constructores.
    public:
        Dispositivo(); //Constructor por default
        Dispositivo(string tipo_, int id_, string ubicacion_); //Constructor
        virtual void encender() = 0;    //Metodo Abstracto encender sera sobreescrito
        virtual void apagar() = 0;      //Metodo Abstracto apagar sera sobreescrito

        string get_tipo(){return tipo;} //Getter tipo
        int get_id(){return id;}  //Getter id
        bool get_status(){return status;}   //Getter status
        string get_ubicacion(){return ubicacion;}  //Getter ubicacion
        void set_status(bool s); //Setter status
};

Dispositivo::Dispositivo()
{
    tipo = "";
    id = 0;
    status = false;
    ubicacion = "NA";
}
Dispositivo::Dispositivo(string tipo_, int id_, string ubicacion_)
{
    tipo = tipo_;
    id = id_;
    status = false;
    ubicacion = ubicacion_;
}

void Dispositivo::set_status(bool s)
{
    status = s;
}

//Subclase que hereda de Dispositivo
class Foco : public Dispositivo{

    //Variables privadas de clase Foco
    private:
        int potencia;
        int tiempo_uso;
        float gasto;

    //Metodos  publicos y constructores.
    public:
        Foco(): Dispositivo(){   //Constructor por default
                potencia = 100;
                tiempo_uso = 0;
                gasto = 0.0;
        }

        Foco(string tipo_, int id_, string ubicacion_, int potencia_):Dispositivo(tipo_, id_, ubicacion_){  //Constructor
            potencia = potencia_;
            tiempo_uso = 0;
            gasto = 0.0;
        }

        void encender();
        void apagar();
        float calcular_gasto();


};


 /** encender codifica un mensaje para enviar al controlador
  *  en posteriores versiones.
  *  Ademas modifica el status respectivo a 1
  *  @param
  *  @return
  */
void Foco :: encender(){
    stringstream mensaje;
    mensaje << id<<"-ON";

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Foco Encendido..."<<endl;
    status=true;

}

 /** apagar codifica un mensaje para enviar al controlador
  *  en posteriores versiones.
  *  Ademas modifica el status del dispositivo a 0
  *  @param
  *  @return
  */

void Foco :: apagar(){
    stringstream mensaje;
    mensaje << id<<"-OFF";

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente. Ademas se recibira
        el tiempo que duro encendido para modificar tiempo_uso*/

    cout <<"Foco Apagado..."<<endl;
    status = false;
}


 /** calcular_gasto realiza el coste de energia utilizada por el dispositivo foco
  *  mediante la multiplicacion del tiempo de uso por potencia.
  *  @param
  *  @return float con el gasto.
  */


float Foco :: calcular_gasto(){
    float gasto = tiempo_uso * potencia;
    return gasto;

}

//Subclase que hereda de Dispositivo
class Aire : public Dispositivo{

    //Variable privada de clase Aire
    private:
        int temperatura;

    //Metodos publicos y constructores de clase Aire
    public:
        Aire():Dispositivo(){  //Constructor por default
            temperatura = 20;
        }

        Aire(string tipo_, int id_, string ubicacion_, int temperatura_) : Dispositivo(tipo_, id_, ubicacion_) {  //Constructor
            temperatura = temperatura_;
        }
        void encender();
        void apagar();
        void subir_temp(int grados);
        void bajar_temp(int grados);

        int get_temp(){return temperatura;}


};

 /** encender codifica un mensaje para enviar al controlador
  *  en posteriores versiones.
  *  Ademas modifica el status del dispositivo a 1
  *  @param
  *  @return
  */
void Aire :: encender(){

    stringstream mensaje;
    mensaje << id<<"-ON-"<<temperatura;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Aire Encendido..."<<endl;
    status=true;

}

 /** apagar codifica un mensaje para enviar al controlador
  *  en posteriores versiones.
  *  Ademas modifica el status del dispositivo a 0
  *  @param
  *  @return
  */

void Aire :: apagar() {
    stringstream mensaje;
    mensaje << id<<"-OFF-"<<temperatura;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Aire Apagado..."<<endl;
    status=false;

}


 /** subir_temp codifica un mensaje para enviar al controlador
  *  en posteriores versiones.
  *  Ademas le suma a la variable temperatura la cantidad de grados indicada
  *  @param int de grados a subir
  *  @return
  */

void Aire :: subir_temp(int grados) {

    stringstream mensaje;
    mensaje << id<<"-ST-"<<temperatura + grados;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Temperatura subida..."<<endl;
    temperatura = temperatura + grados;


}


 /** bajar_temp codifica un mensaje para enviar al controlador
  *  en posteriores versiones.
  *  Ademas le resta a la variable temperatura la cantidad de grados indicada
  *  @param int de grados a bajar
  *  @return
  */

void Aire :: bajar_temp(int grados) {
    stringstream mensaje;
    mensaje << id<<"-BT-"<<temperatura - grados;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Temperatura bajada..."<<endl;
    temperatura = temperatura - grados;
}


//Subclase que hereda de Dispositivo
class Ventilador : public Dispositivo{
    private:
        string velocidad;  // Slow, Medium, High

    public:
        Ventilador():Dispositivo(){   //Constructor por Default
            velocidad = "Slow";
        }

        Ventilador(string tipo_, int id_, string ubicacion_, string velocidad_) : Dispositivo(tipo_, id_, ubicacion_) {  // Constructor

            velocidad = velocidad_;
        }
        void encender();
        void apagar();
        void modificar_vel(string vel);
        string get_vel(){return velocidad;}
};

 /** encender codifica un mensaje para enviar al controlador
  *  en posteriores versiones.
  *  Ademas modifica el status del dispositivo a 1
  *  @param
  *  @return
  */

void Ventilador :: encender(){
    stringstream mensaje;
    mensaje << id<<"-ON-"<<velocidad;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Ventilador Encendido..."<<endl;
    status=true;

}

 /** apagar codifica un mensaje para enviar al controlador
  *  en posteriores versiones.
  *  Ademas modifica el status del dispositivo a 0
  *  @param
  *  @return
  */

void Ventilador :: apagar(){
    stringstream mensaje;
    mensaje << id<<"-OFF-"<<velocidad;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Ventilador Apagado..."<<endl;
    status=false;

}

 /** modificar_vel codifica un mensaje que en
  *  posteriores versiones se enviara al controlador.
  *  Ademas modifica la variable velocidad con el string indicado
  *  @param string con nueva velocidad
  *  @return
  */

void Ventilador :: modificar_vel(string vel){
    stringstream mensaje;
    mensaje << id <<"-M-"<<vel;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/
    cout <<"\nVelocidad Modificada.."<<endl;
    velocidad = vel;
}


#endif

// Proyecto Domotica
/* Luis Angel Zavala Robles
    A01706481
*/


#ifndef DISPOSITIVO_H_
#define DISPOSITIVO_H_

#include <iostream>
#include <sstream>



using namespace std;

class Dispositivo{   //Clase padre

    //Variables protected de la instancia que seran heredadas
    protected:
        string tipo;
        int id;
        bool status;
        string ubicacion;

    //Declaro metodos publicos y constructores.
    public:
        Dispositivo();
        Dispositivo(int _id); //Constructor
        Dispositivo(string _tipo, int _id, string _ubicacion); //Constructor
        void encender();    //Metodo encender sera sobreescrito
        void apagar();      //Metodo apagar sera sobreescrito

        string get_tipo(){return tipo;} //Getter tipo
        int get_id(){return id;}  //Getter id
        bool get_status(){return status;}   //Gettet status
        string get_ubicacion(){return ubicacion;}  //Getter ubicacion

        void set_status(bool s);
};
Dispositivo::Dispositivo(){
    tipo="NA";
    id = 1000;
    status = false;
    ubicacion ="NA";
}
Dispositivo::Dispositivo(int _id)
{
    tipo = "NA";
    id = _id;
    status = false;
    ubicacion = "NA";
}
Dispositivo::Dispositivo(string _tipo, int _id, string _ubicacion)
{
    tipo = _tipo;
    id = _id;
    status = false;
    ubicacion = _ubicacion;
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
        Foco(int _id): Dispositivo(_id){   //Constructor
                potencia = 100;
                tiempo_uso = 0;
                gasto = 0;
        }

        Foco(string _tipo, int _id, string _ubicacion, int _potencia):Dispositivo(_tipo, _id, _ubicacion){  //Constructor
            potencia = _potencia;
            tiempo_uso = 0;
            gasto = 0;
        }

        void encender();
        void apagar();
        float calcular_gasto();


};

void Foco :: encender(){
    stringstream mensaje;
    mensaje << id<<"-ON";

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Encendiendo..."<<endl;
    status=true;

}

void Foco :: apagar(){

    stringstream mensaje;
    mensaje << id<<"-OFF";

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Apagando..."<<endl;
    status = false;
}

float Foco :: calcular_gasto(){
    float gasto = tiempo_uso * potencia;   //Nota: Aun se esta ideando en base a que se modificara la variable tiempo_uso
    return gasto;

}

//Subclase que hereda de Dispositivo
class Aire : public Dispositivo{

    //Variable privada de clase Aire
    private:
        int temperatura;

    //Metodos publicos y constructores de clase Aire
    public:
        Aire(int _id):Dispositivo(_id){  //Constructor
            temperatura = 20;
        }

        Aire(string _tipo, int _id, string _ubicacion, int _temperatura) : Dispositivo(_tipo, _id, _ubicacion) {  //Constructor
            temperatura = _temperatura;
        }
        void encender();
        void apagar();
        void subir_temp(int grados);
        void bajar_temp(int grados);


};


void Aire :: encender(){

    stringstream mensaje;
    mensaje << id<<"-ON-"<<temperatura;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Encendido..."<<endl;
    status=true;

}

void Aire :: apagar() {
    stringstream mensaje;
    mensaje << id<<"-OFF-"<<temperatura;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Apagado..."<<endl;
    status=false;

}

void Aire :: subir_temp(int grados) {

    stringstream mensaje;
    mensaje << id<<"-ST-"<<temperatura + grados;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Temperatura subida..."<<endl;
    temperatura = temperatura + grados;


}

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
        Ventilador(int _id):Dispositivo(_id){
            velocidad = "Slow";
        }

        Ventilador(string tip, int numID, string ubi, string vel) : Dispositivo(tip, numID, ubi) {
            velocidad = vel;
        }
        void encender();
        void apagar();
        void modificar_vel(string vel);
};

void Ventilador :: encender(){
    stringstream mensaje;
    mensaje << id<<"-ON-"<<velocidad;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Encendiendo..."<<endl;
    status=true;

}

void Ventilador :: apagar(){
    stringstream mensaje;
    mensaje << id<<"-OFF-"<<velocidad;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Apagado..."<<endl;
    status=false;

}

void Ventilador :: modificar_vel(string vel){
    stringstream mensaje;
    mensaje << id <<"-M-"<<vel;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/
    cout <<"\nModificado.."<<endl;
    velocidad = vel;
}


#endif

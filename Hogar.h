// Proyecto Domotica
// Luis Angel Zavala Robles
// A01706481


/* Esta clase define objetos de tipo Dispositivo y realiza diversas operaciones
 generales sobre ellos*/

#ifndef HOGAR_H_
#define HOGAR_H_

#include <iostream>

#include "Dispositivo.h" //clase de mi proyecto


using namespace std;


class Hogar {
//Variables privadas de clase Hogar
    private:
        Dispositivo *disp[100];  //Apuntador para  usar polimorfismo
        string nombre;
        int num;

//Metodos publicos y constructor de la clase
    public:

        Hogar(){        //Constructor por default
            nombre = "";
            num=0;
        }

        Hogar(string nombre_){    // Constructor
            nombre = nombre_;
            num = 0;
        }

        void mostrar_dispositivos();
        void encender_todos();
        void apagar_todos();
        void calc_gasto_total();
        void agregar_foco(int id_, int potencia_, string ubicacion_);
        void agregar_aire (int id_, int temperatura_, string ubicacion_);
        void agregar_ventilador(int id_, string velocidad_, string ubicacion_);

        int get_num(){return num;}
        Dispositivo** get_disp(){return disp;}



};

/** mostrar_dispositivos imprime todos los dispositivos agregados
 *  con su respectiva informacion dependiendo  el tipo de dispositivo
 *  @param
 *  @return
 */
void Hogar :: mostrar_dispositivos(){

    for (int i=0 ; i<num ; i++)

    {
        if(disp[i]->get_tipo() == "Foco")
        {
            cout <<"\nDispositivo: " << disp[i]->get_tipo() << "\nId: "<<disp[i]->get_id() <<"\nStatus: "<<disp[i]->get_status()<<
            "\nUbicacion: "<<disp[i]->get_ubicacion()<< endl;
        }

        else if(disp[i]->get_tipo() == "Aire")
        {
            cout <<"\nDispositivo: " << disp[i]->get_tipo() << "\nId: "<<disp[i]->get_id() <<"\nStatus: "<<disp[i]->get_status()<<
            "\nUbicacion: "<<disp[i]->get_ubicacion()<<"\nTemperatura: "<< dynamic_cast<Aire*>(disp[i])->get_temp()<<endl;
        }
        else
        {
            cout <<"\nDispositivo: " << disp[i]->get_tipo() << "\nId: "<<disp[i]->get_id() <<"\nStatus: "<<disp[i]->get_status()<<
            "\nUbicacion: "<<disp[i]->get_ubicacion()<<"\nTemperatura: "<< dynamic_cast<Ventilador*>(disp[i])->get_vel()<<endl;

        }

    }
}

/** encencer_todos codifica un mensaje que en posteriores
 *  versiones se enviara al controlador.
 *  Ademas modifica el status de todos los dispositivos
 *  guardados en disp[] a true.
 *  @param
 *  @return
 */
void Hogar :: encender_todos(){

    stringstream mensaje;
    mensaje <<"ALL-ON-"<<nombre;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Todos Encendidos..."<<endl;

    for (int i=0 ; i<num ; i++)
    {

        disp[i]->set_status(true);

    }

}

/** apagar_todos codifica un mensaje que en posteriores
 *  versiones se enviara al controlador.
 *  Ademas modifica el status de todos los dispositivos
 *  guardados en disp[] a false.
 *  @param
 *  @return
 */

void Hogar :: apagar_todos(){

    stringstream mensaje;
    mensaje <<"ALL-OFF-"<<nombre;

    /*La variable mensaje se enviara al hardware mediante un protocolo de transmision por definir.
        En el hardware se va decodificar y se realizara la accion correspondiente*/

    cout <<"Todos Apagados..."<<endl;

    for (int i=0 ; i<num ; i++)
    {

        disp[i]->set_status(false);

    }
}


 /** calc_gasto_total realiza la suma de los gastos de todos
  *  los focos presentes en disp[] haciendo llamada al metodo
  *  calcular_gasto de cada foco.
  *  @param
  *  @return
  */
void Hogar :: calc_gasto_total() {
    float gasto_total;

    for (int i=0 ; i<num ; i++)
    {
        if(disp[i]->get_tipo()== "Foco")
        {
           gasto_total = gasto_total + dynamic_cast<Foco*>(disp[i])->calcular_gasto();
        }
    }

    cout << "El gasto total al dia de hoy es: "<< gasto_total;
}

/** agregar_foco crea un objeto Foco y lo agrega
 *  a arreglo de dispositivos disp[] en la posicion
 *  num a la cual posteriormente se le suma 1.
 *  @param int id del foco, int potencia del foco, string  ubicacion
 *  @return
 */
void Hogar :: agregar_foco (int id_, int potencia_, string ubicacion_){

    disp[num] =  new Foco("Foco", id_, ubicacion_, potencia_);  //Objeto creado en tiempo de ejecucion (Polimorfismo)
    cout<<"\nFoco Agregado"<<endl;
    num++;
}


/** agregar_aire crea un objeto Aire y lo agrega
 *  a arreglo de dispositivos disp[] en la posicion
 *  num a la cual posteriormente se le suma 1.
 *  @param int id del aire, int temperatura del aire, string  ubicacion
 *  @return
 */
void Hogar :: agregar_aire (int id_, int temperatura_, string ubicacion_){

    disp[num] = new Aire("Aire", id_, ubicacion_, temperatura_);  //Objeto creado en tiempo de ejecucion (Polimorfismo)
    cout<<"\nAire Agregado"<<endl;
    num++;
}

/** agregar_ventilador crea un objeto Ventilador y lo agrega
 *  a arreglo de dispositivos disp[] en la posicion
 *  num a la cual posteriormente se le suma 1.
 *  @param int id del ventilador, string velocidad del ventilador, string ubicacion
 *  @return
 */
void Hogar :: agregar_ventilador(int id_, string velocidad_, string ubicacion_){

    disp[num] = new Ventilador("Ventilador", id_ , ubicacion_, velocidad_); //Objeto creado en tiempo de ejecucion (Polimorfismo)
    cout<<"\nVentilador Agregado"<<endl;
    num++;

}

#endif

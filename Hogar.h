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

        Hogar(string _nombre){
            nombre = _nombre;
            num = 0;
        }

        void mostrar_dispositivos();
        void encender_todos();
        void apagar_todos();
        void calc_gasto_total();
        void agregar_foco(int _id, int _potencia, string _ubicacion);
        void agregar_aire (int _id, int _temperatura, string _ubicacion);
        void agregar_ventilador(int _id, string _velocidad, string _ubicacion);

        int get_num(){return num;}
        Dispositivo** get_disp(){return disp;}



};


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


void Hogar :: agregar_foco (int _id, int _potencia, string _ubicacion){

    disp[num] =  new Foco("Foco", _id, _ubicacion, _potencia);  //Objeto creado en tiempo de ejecucion (Polimorfismo)
    cout<<"\nFoco Agregado"<<endl;
    num++;
}

void Hogar :: agregar_aire (int _id, int _temperatura, string _ubicacion){

    disp[num] = new Aire("Aire", _id, _ubicacion, _temperatura);  //Objeto creado en tiempo de ejecucion (Polimorfismo)
    cout<<"\nAire Agregado"<<endl;
    num++;
}

void Hogar :: agregar_ventilador(int _id, string _velocidad, string _ubicacion){

    disp[num] = new Ventilador("Ventilador", _id , _ubicacion, _velocidad); //Objeto creado en tiempo de ejecucion (Polimorfismo)
    cout<<"\nVentilador Agregado"<<endl;
    num++;

}

#endif

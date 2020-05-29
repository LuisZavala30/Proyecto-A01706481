//Proyecto Domotica
// Luis Angel Zavala Robles
// A01706481

/* Proyecto para realizar pruebas de ciertos dispositivos de domotica con base en
    los requerimientos del usuario. Es parte del software de un proyecto integral*/

#include <iostream>
#include "Dispositivo.h" // Clase de mi proyecto
#include "Hogar.h" // Clase de mi proyecto

int main(){
    Dispositivo** d;
    int opcion;

    Hogar Casa1("Casa1");
    Casa1.agregar_aire(1,24,"Sala");
    Casa1.agregar_foco(2,70,"Recamara");
    Casa1.agregar_ventilador(3, "Slow", "Cocina");

    int num = Casa1.get_num();
    d = Casa1.get_disp();


    //Trabajar con Aire ID=1
    for(int i=0; i<num ; i++)
    {
        if(d[i]->get_id() == 1)
        {
            d[i]->encender();
            dynamic_cast<Aire*>(d[i])->subir_temp(3);
            dynamic_cast<Aire*>(d[i])->bajar_temp(1);
        }
    }

    //Trabajar con foco ID=2
    for(int i=0; i<num ; i++)
    {
        if(d[i]->get_id() == 2)
        {
            d[i]->encender();
        }
    }

     //Trabajar con Ventilador ID=3
    for(int i=0; i<num ; i++)
    {
        if(d[i]->get_id() == 3)
        {
            d[i]->encender();
            dynamic_cast<Ventilador*>(d[i])->modificar_vel("Medium");
        }
    }

    Casa1.mostrar_dispositivos();









}


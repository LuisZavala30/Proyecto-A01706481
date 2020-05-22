//Proyecto Domotica
// Luis Angel Zavala Robles
// A01706481

/* Proyecto para realizar pruebas de ciertos dispositivos de domotica con base en
    los requerimientos del usuario. Es parte del software de un proyecto integral*/

#include <iostream>
#include "Dispositivo.h" // Clase de mi proyecto
#include "Hogar.h" // Clase de mi proyecto




int main(){

    cout<<"PRUEBA DE FUNCIONAMIENTO HASTA EL MOMENTO CON LA IMPLEMENTACION DE HERENCIA, SOBREESCRITURA Y SOBRECARGA\n";
    cout<<"LA VERSION FINAL CONTARA CON INTERFAZ GRAFICA PARA UN FUNCIONAMIENTO MAS DINAMICO"<<endl;

    Hogar Casa1("Casa1");
    cout<<"1-Test agregar_foco: ";
    Casa1.agregar_foco(1,70,"Recamara");

    cout<<"\n2-Test agregar_aire: ";
    Casa1.agregar_aire(2,24,"Sala");

    cout<<"\n3-Test agregar_ventilador: ";
    Casa1.agregar_ventilador(3,"Slow","Jardin");

    cout<<"\n4-Test apagar_focos: ";
    Casa1.apagar_focos();

    cout<<"\n5-Test encender_focos: ";
    Casa1.encender_focos();

    cout<<"\n6-Test mostrar_dispositivos: \n";
    Casa1.mostrar_dispositivos();


}

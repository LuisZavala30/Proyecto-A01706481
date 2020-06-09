//Proyecto Domotica
// Luis Angel Zavala Robles
// A01706481

/* Proyecto para realizar pruebas de ciertos dispositivos de domotica con base en
    los requerimientos del usuario. Es parte del software de un proyecto integral*/

#include <iostream>
#include "Dispositivo.h" // Clase de mi proyecto
#include "Hogar.h" // Clase de mi proyecto

using namespace std;


int main(){
    Dispositivo** d;
    int opcion,opcion2,total,id,temp,pot;
    string vel,ubi;

    Hogar Casa1("Casa1");
    Casa1.agregar_aire(1,24,"Sala");
    Casa1.agregar_foco(2,70,"Recamara");
    Casa1.agregar_ventilador(3, "Slow", "Cocina");
    d = Casa1.get_disp();
    total = Casa1.get_num();
    while(opcion != 9)
    {
        cout<<"\n---------------DISPOSITIVOS ACTUALES----------"<<endl;
        Casa1.mostrar_dispositivos();

        cout<<"\n1-Encender\n2-Apagar\n3-Modificar Velocidad (Ventiladores)"<<endl;
        cout<<"4-Subir Temp (Aires\n5-Bajar Temp\n6-Encender todos\n7-Apagar todos\n8-Agregar Dispositivo\n9-Salir"<<endl;
        cout<<"Seleccionar opcion ";
        cin>>opcion;


        switch(opcion)
        {
            case 1:
                cout<<"\nId del dispositivo a encender "<<endl;
                cin>>id;

                for(int i=0; i<total ; i++){

                    if(d[i]->get_id()==id)
                    {
                        d[i]->encender();
                    }
                }

                break;

            case 2:
                cout<<"\nId del dispositivo a apagar "<<endl;
                cin>>id;

                for(int i=0; i<total ; i++){

                    if(d[i]->get_id()==id)
                    {
                        d[i]->apagar();
                    }
                }

                break;

            case 3:
                cout<<"\nId del ventilador a modificar "<<endl;
                cin>>id;

                for(int i=0 ; i<total; i++)
                {
                    if(d[i]->get_id()==id)
                    {
                        if(d[i]->get_tipo() != "Ventilador")
                        {
                            cout<<"SOLO VENTILADORES!!!!!"<<endl;
                        }

                        else{
                                cout<<"Escribe velocidad deseada (Slow, Medium, High) : ";
                                cin>>vel;
                                for(int i=0; i<total ; i++){
                                    if(d[i]->get_id()==id)
                                    {
                                        dynamic_cast<Ventilador*>(d[i])->modificar_vel(vel);
                                    }
                                }
                        }
                    }
                }


                break;

            case 4:
                cout<<"\nId del Aire a modificar "<<endl;
                cin>>id;

                for(int i=0 ; i<total; i++)
                {
                    if(d[i]->get_id()==id)
                    {
                        if(d[i]->get_tipo() != "Aire")
                        {
                            cout<<"SOLO AIRES!!!!!"<<endl;
                        }

                        else{
                                cout<<"Escribe grados a subir : ";
                                cin>>temp;
                                dynamic_cast<Aire*>(d[i])->subir_temp(temp);
                            }
                    }
                }
                break;

            case 5:
                cout<<"\nId del Aire a modificar "<<endl;
                cin>>id;

                for(int i=0 ; i<total; i++)
                {
                    if(d[i]->get_id()==id)
                    {
                        if(d[i]->get_tipo() != "Aire")
                        {
                            cout<<"SOLO AIRES!!!!!"<<endl;
                        }

                        else{
                                cout<<"Escribe grados a bajar : ";
                                cin>>temp;
                                dynamic_cast<Aire*>(d[i])->bajar_temp(temp);
                            }
                        }
                }


                break;

            case 6:
                Casa1.encender_todos();
                break;
            case 7:
                Casa1.apagar_todos();
                break;

            case 8:
                cout<<"\n1-Foco\n2-Aire\n3-Ventilador"<<endl;
                cout<<"Tipo de dispositivo a agregar ";
                cin>>opcion2;
                switch(opcion2)
                {
                    case 1:
                        cout<<"Id: ";
                        cin>>id;
                        cout<<"Potencia: ";
                        cin>>pot;
                        cout<<"Ubicacion: ";
                        cin>>ubi;
                        Casa1.agregar_foco(id,pot,ubi);

                        break;

                    case 2:
                        cout<<"Id: ";
                        cin>>id;
                        cout<<"Temperatura: ";
                        cin>>temp;
                        cout<<"Ubicacion: ";
                        cin>>ubi;
                        Casa1.agregar_aire(id,temp,ubi);
                        break;

                    case 3:
                        cout<<"Id: ";
                        cin>>id;
                        cout<<"Velocidad: ";
                        cin>>vel;
                        cout<<"Ubicacion: ";
                        cin>>ubi;
                        Casa1.agregar_ventilador(id,vel,ubi);
                        break;

                    default:
                        cout<<"Numero fuera de opcion"<<endl;
                        break;
                }
                d = Casa1.get_disp();
                total=Casa1.get_num();
                break;

            default:
                cout<<"Numero fuera de opcion"<<endl;
                break;

        }
    }








}


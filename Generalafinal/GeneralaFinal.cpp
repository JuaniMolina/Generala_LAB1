#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string.h>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

#include "FuncionesGeneralaMeister3.0.h"
#include "windows.h"

int main (){
    hidecursor();
    system("color 1B");
    bool MODO=false; /// MODO ALEATORIO(TRUE) O MANUAL (FALSE).
    const int T=3; /// VARIABLE PARA EL NUMERO DE RONDAS.
    int max_puntos=0, min_rondas=0;/// VARIABLES UTILIZADAS PARA LA PUNTUACION MAXIMA.
    char max_name[20]="------" , max_name1[100]="------";



    GENERALA();

    while(true){ ///HACE QUE SIEMPRE VUELVA AL MENU PRINCIPAL.
        bool GeneralaServida=false, empate;
        bool GeneralaServidaJug1=false ,GeneralaServidaJug2=false;
        int ContRonda=0, AcumPtos=0, AcumPtos2=0;
        int opcion;
        MenuPrincipal(); ///FUNCION QUE MUESTRA EL MENU CON LAS OPCIONES.
        locate(1,20);
            cout << "OPCION: ";
            cin >> opcion;
            cin.ignore();
        system("cls");

        switch(opcion){


            case 1: { /// MODO 1 JUGADOR
                char nombre[20];
                    Bienvenidx1JUG();
                    cin>>nombre;
                    Jugada(T,MODO,GeneralaServida,nombre,AcumPtos,ContRonda);

                     ///COMPRUEBA EL PUNTAJE FINAL SI ES GENERALA SERVIDA O TERMINO EL TOTAL DE RONDAS.
                    comprobacionfinal(GeneralaServida,ContRonda,AcumPtos,nombre);

                    ///ANALIZA SI EL PUNTAJE OBTENIDO ES EL PUNTAJE MAXIMO
                    max_name[20]=comprobacion_maximo_JG1(ContRonda,AcumPtos,min_rondas,max_puntos,nombre,max_name, empate);


                }
                break;
           case 2: { /// MODO 2 JUGADORES
                char nombre1[20],nombre2[20];

                Bienvenidx2JUGS();
                NOMBREJG1();
                locate(38,7);
                cin>>nombre1;
                NOMBREJG2();
                locate(38,12);
                cin>>nombre2;
                locate(1,20);
                system("pause");
                system("cls");


                Jugada2jgs(T, MODO,GeneralaServida,nombre1,nombre2,AcumPtos,AcumPtos2,ContRonda,GeneralaServidaJug1,GeneralaServidaJug2);


                ///Si se cumple generala servida...
                if(GeneralaServida==true){
                    if(GeneralaServidaJug1==true && GeneralaServidaJug2==true){
                        Empate();

                        ///Si las rondas son menores que el record y...
                        if(ContRonda<min_rondas || min_rondas==0){

                            ///1)Igualan en puntos
                            if(AcumPtos==AcumPtos2){
                                empate=true;
                                min_rondas=ContRonda;
                                max_puntos=AcumPtos;
                                strcpy(max_name, nombre1);
                                strcpy(max_name1,nombre2);
                                NuevoRecord();
                            }

                            ///2)JUG1 tiene mas puntos que JUG2
                            else{

                                if(AcumPtos>AcumPtos2){
                                    min_rondas=ContRonda;
                                    max_puntos=AcumPtos;
                                    strcpy(max_name, nombre1);
                                    NuevoRecord();
                                    empate=false;
                                }

                                ///3)JUG2 tiene mas puntos que JUG1
                                else{
                                    min_rondas=ContRonda;
                                    max_puntos=AcumPtos2;
                                    strcpy(max_name, nombre2);
                                    NuevoRecord();
                                    empate=false;

                                }
                            }
                        }

                        ///Si las rondas son iguales al record..
                        else{
                            if(ContRonda==min_rondas || min_rondas==0){

                                ///Empatan en puntos superando al record.. nuevo record
                                if(AcumPtos==AcumPtos2 && AcumPtos>max_puntos){
                                    empate=true;
                                    min_rondas=ContRonda;
                                    max_puntos=AcumPtos;
                                    strcpy(max_name, nombre1);
                                    strcpy(max_name1,nombre2);
                                    NuevoRecord();
                               }

                               ///JUG1 supera al JUG2 y al record..nuevo record
                               else{

                                    if(AcumPtos>AcumPtos2 && AcumPtos>max_puntos){

                                        min_rondas=ContRonda;
                                        max_puntos=AcumPtos;
                                        strcpy(max_name, nombre1);
                                        NuevoRecord();
                                        empate=false;
                                    }

                                    ///JUG2 supera al JUG1 y al record..nuevo record
                                    else{
                                        if(AcumPtos2>AcumPtos && AcumPtos2>max_puntos){
                                            min_rondas=ContRonda;
                                            max_puntos=AcumPtos2;
                                            strcpy(max_name, nombre2);
                                            NuevoRecord();
                                            empate=false;
                                        }
                                    }
                               }
                            }
                        }
                    }
                    ///Si JUG1 hace servida y JUG2 no la hace..
                    if(GeneralaServidaJug1==true && GeneralaServidaJug2==false){
                        cartelgenerala(nombre1,AcumPtos,ContRonda);

                        ///Si las rondas son menores al record
                        if(ContRonda<min_rondas || min_rondas==0){
                                min_rondas=ContRonda;
                                max_puntos=AcumPtos;
                                strcpy(max_name, nombre1);
                                NuevoRecord();
                                empate=false;
                        }

                        ///Si las rondas son iguales pero los puntos son mayores al record
                        else{
                            if(ContRonda==min_rondas){
                                if(AcumPtos>max_puntos){
                                min_rondas=ContRonda;
                                max_puntos=AcumPtos;
                                strcpy(max_name, nombre1);
                                NuevoRecord();
                                empate=false;
                                }
                            }
                        }
                    }

                    ///Idem pero si JUG2 hace servida y JUG1 no la hace
                    if(GeneralaServidaJug1==false && GeneralaServidaJug2==true){
                        cartelgenerala(nombre2,AcumPtos2,ContRonda);
                        if(ContRonda<min_rondas || min_rondas==0){
                                min_rondas=ContRonda;
                                max_puntos=AcumPtos2;
                                strcpy(max_name, nombre2);
                                NuevoRecord();
                                empate=false;
                        }
                        else{
                            if(ContRonda==min_rondas){
                                    if(AcumPtos2>max_puntos){
                                    min_rondas=ContRonda;
                                    max_puntos=AcumPtos2;
                                    strcpy(max_name, nombre2);
                                    NuevoRecord();
                                    empate=false;
                                    }
                                }

                        }
                    }


                }///Cierra "if" de si se cumple generala servida.

                ///Si NO se cumple grala servida..

                else{    ///<<<---MUESTRA PUNTAJE DE LOS DOS JUGADORES Y QUIEN FUE EL GANADOR.
                    Puntajefinal(nombre1,AcumPtos,ContRonda);
                    Puntajefinal(nombre2,AcumPtos2,ContRonda);

                ///Si igualan en puntos, empate
                if(AcumPtos==AcumPtos2){
                    Empate();
                    ///Si las rondas son menores que el record..nuevo record
                    if(ContRonda<min_rondas || min_rondas==0){
                            empate=true;
                            min_rondas=ContRonda;
                            max_puntos=AcumPtos;
                            strcpy(max_name, nombre1);
                            strcpy(max_name1,nombre2);
                            NuevoRecord();


                    }
                    ///Si las rondas son iguales al record, pero los puntos son mayores al record..nuevo record
                    else{
                        if((ContRonda==min_rondas || min_rondas==0)&&(AcumPtos>max_puntos)){
                            empate=true;
                            min_rondas=ContRonda;
                            max_puntos=AcumPtos;
                            strcpy(max_name, nombre1);
                            strcpy(max_name1,nombre2);
                            NuevoRecord();
                        }

                    }
                }

                ///Si no igualan en puntos, no hay empate
                else{
                    if(AcumPtos>AcumPtos2){/// Si JUGADOR 1 tiene mas puntos que JUGADOR 2
                        ganador2jugadores(nombre1,AcumPtos,ContRonda);
                        if(ContRonda<min_rondas || min_rondas==0){///y si las rondas son menores al record..nuevo record
                            min_rondas=ContRonda;
                            max_puntos=AcumPtos;
                            strcpy(max_name, nombre1);
                            NuevoRecord();
                            empate=false;
                        }
                        ///Si las rondas son iguales al record, pero los puntos son mayores al record..nuevo record
                        else{
                            if(ContRonda==min_rondas || min_rondas==0){
                                if(AcumPtos>max_puntos){
                                   min_rondas=ContRonda;
                                    max_puntos=AcumPtos;
                                    strcpy(max_name, nombre1);
                                    NuevoRecord();
                                    empate=false;
                                }
                            }
                        }
                    }///Cierra if de jugador 1

                    else{///Si JUGADOR 2 tiene mas puntos que JUGADOR 1
                        ganador2jugadores(nombre2,AcumPtos2,ContRonda);
                        if(ContRonda<min_rondas || min_rondas==0){
                            min_rondas=ContRonda;
                            max_puntos=AcumPtos2;
                            strcpy(max_name, nombre2);
                            NuevoRecord();
                            empate=false;
                        }
                        else{
                            if(ContRonda==min_rondas || min_rondas==0){
                                if(AcumPtos2>max_puntos){
                                    min_rondas=ContRonda;
                                    max_puntos=AcumPtos2;
                                    strcpy(max_name, nombre2);
                                    NuevoRecord();
                                    empate=false;
                                }
                            }
                        }
                    }
                }///Cierra else de jugador 2

                }///Cierra else de si NO se cumple generala servida


        }/// FIN DOS JUGADORES
                break;

            case 3: { /// PUNTAJES MAXIMOS
                if(empate==false){
                    MaxPtosSimple(max_name,min_rondas,max_puntos);
                }
                else{
                    MaxPtosEmpate(max_name,max_name1,min_rondas,max_puntos);
                }

            }
                break;
            case 4: { /// SALIR DEL JUEGO
                Saludo();
                return 0;
                }
                break;
            default:{/// OPCION INCORRECTA
                locate(22,12);
                cout<<"INGRESASTE UNA OPCION INCORRECTA."<<endl;
                locate(1,23);
                system("pause");
                system("cls");
                }
                break;
                }///switch
            }
}

#ifndef FUNCIONESGENERALA_H_INCLUDED
#define FUNCIONESGENERALA_H_INCLUDED
#include "windows.h"
#include "rlutil.h"
/**FUNCIONES**/

void TirarDados(int VecDados[5], bool AZAR){ ///TIRAR DADOS

    if(AZAR==true){
    srand(time(NULL));
    for(int i=0; i<5; i++){
        VecDados[i]=(rand()%6)+1;}}
    else{
        for(int i=0; i<5; i++){
            cin >> VecDados[i];
            cout << endl;}}

}


void MostrarDados(int VecDados[5]){ ///MOSTRAR DADOS

    cout << "DADOS: " << endl<< endl<< endl;
    cout << endl;

    for(int i=0; i<5; i++){
   cout << "|" << VecDados[i] << "|" << "\t";}

}


void TirarDados2(int VecDados2[], int T){ ///FUNCION UTILIZADA PARA VOLVER A TIRAR DADOS EN CASO DE QUE EL USUARIO LO DECIDA


    srand(time(NULL));
    for(int i=0; i<T; i++){
        VecDados2[i]=(rand()%6)+1;}

}


void CargarVectorCambio(int VecCambio[], int T){///FUNCION UTILIZADA PARA VOLVER A TIRAR DADOS EN CASO DE QUE EL USUARIO LO DECIDA

    int i;

    for(i=0; i<T; i++){
       cout << "DADO #"; cin >> VecCambio[i];
       cout << endl;}
}


void CambiarDados(int VecDados[], int VecDados2[], int VecIndices[] , int T){///FUNCION QUE REEMPLAZA DADOS SELECCIONADOS POR EL USUARIO

    int i, f;

    for(i=0; i<5; i++){

        for(f=0; f<T; f++){

            if(VecIndices[f]-1==i){
                VecDados[i]=VecDados2[f];}}}

}



///FUNCIONES PARA PUNTAJE/COMBINACIONES




///JUEGOS
int VerificacionGENERALA(int VecDados[5]){

    int ContIguales=1;

    for(int i=0; i<5; i++){
        if(i!=4){
            if(VecDados[i]==VecDados[i+1]){ContIguales++;}
                }
            }

    if(ContIguales==5){
            if(VecDados[1]==0){
                return 0;}
            else{
                return 50;}}
    else{return 0;}

}


int VerificacionPOKER(int VecDados[5]){
    int ContIguales=0, aux;
    for(int i=0; i<5; i++){
        if(VecDados[i]==VecDados[i+1]){
            aux=VecDados[i];}
        }
    for(int i=0; i<5; i++){
        if(VecDados[i]==aux){ContIguales++;}
     }

    if(ContIguales==4){return 40;}
    else{return 0;}

}


int VerificacionFULL(int vec[5]){
    int aux=0, aux2=0, ContIguales=0, ContIguales2=0,total;
    for(int i=0; i<5; i++){
        for(int k=0;k<5;k++){
            if(vec[i]== vec[k]){
                if(aux==0 || vec[i]== aux){
                    aux=vec[i];
                }
                else{
                    if(aux2 ==0 || vec[i]== aux2){
                        aux2 = vec[i];
                    }
                }
            }
        }

    }
    for(int i=0; i<5; i++){
        if(vec[i]== aux){
            ContIguales++;
        }
    }
    for(int i=0; i<5; i++){
        if(vec[i]== aux2){
            ContIguales2++;
        }
    }
    total=ContIguales2+ContIguales;
    if(total==5){
        return 30;
    }
    else{
        return 0;
    }

}




int VerificacionESCALERA(int VecDados[5]){

///ordena el vector de menor a mayor
int aux, c=1;

for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
                if(VecDados[i]>VecDados[j]){
                aux=VecDados[i];
                VecDados[i]=VecDados[j];
                VecDados[j]=aux;
                }
            }///FOR j
        }///FOR i

///verifica si es estrictamente creciente
for (int i=0; i<5; i++){
        if(VecDados[i]==VecDados[i+1]-1){
            c++;}}

if(c==5){return 25;}
else{return 0;}


}



///NUMEROS
int VerificacionDeSEIS(int VecDados[5]){

    int ContSeis=0;

    for(int i=0; i<5; i++){

        if(VecDados[i]==6){ContSeis++;}
        }

        return ContSeis*6;
}


int VerificacionDeCINCO(int VecDados[5]){

    int ContCinco=0;

    for(int i=0; i<5; i++){

        if(VecDados[i]==5){ContCinco++;}
        }

        return ContCinco*5;
}


int VerificacionDeCUATRO(int VecDados[5]){

    int ContCuatro=0;

    for(int i=0; i<5; i++){

        if(VecDados[i]==4){ContCuatro++;}
        }

        return ContCuatro*4;
}


int VerificacionDeTRES(int VecDados[5]){

    int ContTres=0;

    for(int i=0; i<5; i++){

        if(VecDados[i]==3){ContTres++;}
        }

        return ContTres*3;
}


int VerificacionDeDOS(int VecDados[5]){

    int ContDos=0;

    for(int i=0; i<5; i++){

        if(VecDados[i]==2){ContDos++;}
        }

        return ContDos*2;
}


int VerificacionDeUNOS(int VecDados[5]){

    int ContUno=0;

    for(int i=0; i<5; i++){

        if(VecDados[i]==1){ContUno++;}
        }

        return ContUno;
}



///FUNCIONES BUSCO MAYOR PUNTAJE Y ACUMULO

void CargarVectorPuntos(int Vec[10], int GENERALA, int POKER, int FULL, int ESCALERA, int SEIS, int CINCO, int CUATRO, int TRES, int DOS, int UNO){


  Vec[0]=GENERALA;
  Vec[1]=POKER;
  Vec[2]=FULL;
  Vec[3]=ESCALERA;
  Vec[4]=SEIS;
  Vec[5]=CINCO;
  Vec[6]=CUATRO;
  Vec[7]=TRES;
  Vec[8]=DOS;
  Vec[9]=UNO;




}


int BuscarPuntosMax(int Vec[]){

    int Mayor, i;

for(i=0; i<10; i++){


if(i==0 || Vec[i]>Mayor){
    Mayor=Vec[i];}

    }

    return Mayor;
}




///MENSAJES

void MuestraRondaTiroPuntos(int ContRonda, int ContTiros, int AcumPtosX){

                cout << "\t\t   ---------------------------------------" << endl;
                cout << "\t\t  | RONDA " << ContRonda << " - TIRO " << ContTiros  << " - PUNTOS TOTALES: " << AcumPtosX << "  |" << endl;
                cout << "\t\t   ---------------------------------------" << endl;
                cout << endl;


}


void entreturnos (char nombre[30], int puntos, int rondas){

    cout<<endl<<endl<<endl;
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t   RONDA "<<rondas<<endl<<endl<<endl;
    cout<<"         -------------------------------------------------------------"<<endl<<endl;
    cout<<"\t\t\t  TURNO DE: "<<nombre<<" CON: " <<puntos<<" PUNTOS"<<endl<<endl;
    cout<<"         -------------------------------------------------------------"<<endl;
    cout<<endl<<endl<<endl<<endl;
    cout<<endl<<endl<<endl<<endl;
    Sleep(2000);
    system("cls");

}


void ganador2jugadores(char nombre[30],int puntos,int rondas){
    locate(30,9);
    cout<< "--------------------" ;
    locate(30,11);
    cout<< "   FELICITACIONES   " ;
    locate(37,13);
    cout<<nombre;
    locate(30,15);
    cout<< "--------------------" ;
    Sleep(2000);
    system("cls");

    locate(30,9);
    cout<< "---------------------" ;
    locate(30,11);
    cout<< "   G A N A S T E     " ;
    locate(30,13);
    cout<< "    LA  PARTIDA      " ;
    locate(30,15);
    cout<< "---------------------" ;
    Sleep(2000);
    system("cls");

    locate(30,9);
    cout<< "--------------------";
    locate(30,11);
    cout<< "   CON "<<puntos<<" PUNTOS";
    locate(30,13);
    cout<< "    EN "<<rondas<<" RONDAS";
    locate(30,15);
    cout<< "--------------------" ;
    locate(1,23);
    Sleep(2000);
    system("cls");




}


void cartelgenerala(char nombre[30],int puntos, int rondas){
    locate(30,9);
    cout<< "--------------------";
    locate(30,12);
    cout<< " GENERALA  SERVIDA  ";
    locate(30,15);
    cout<< "--------------------";
    Sleep(2000);
    system("cls");

    locate(30,9);
    cout<< "--------------------";
    locate(30,11);
    cout<< "   FELICITACIONES   ";
    locate(37,13);
    cout<<nombre;
    locate(30,15);
    cout<< "--------------------";
    Sleep(2000);
    system("cls");


    locate(30,9);
    cout<< "---------------------" ;
    locate(30,11);
    cout<< "   G A N A S T E     " ;
    locate(30,13);
    cout<< "    LA  PARTIDA      " ;
    locate(30,15);
    cout<< "---------------------" ;
    Sleep(2000);
    system("cls");

    locate(30,9);
    cout<< "--------------------";
    locate(30,11);
    cout<< "   CON "<<puntos<<" PUNTOS";
    locate(30,13);
    cout<< "    EN "<<rondas<<" RONDAS";
    locate(30,15);
    cout<< "--------------------" ;
    locate(1,23);
    Sleep(2000);
    system("cls");

}


void MenuPrincipal(){
    cout << "\t\t -------------------------------------------" << endl;
    cout << "\t\t| BIENVENIDX A GENERALA 2.0 - UTN - PACHECO |" << endl;
    cout << "\t\t -------------------------------------------" << endl;
    cout << endl << endl;


    cout << "\t\t    SELECCIONE UNA OPCION PARA COMENZAR: " << endl << endl<<endl;
    cout << endl << endl;
    cout << "\t\t        1. NUEVO JUEGO 1 JUGADOR. " << endl;
    cout << "\t\t        2. NUEVO JUEGO 2 JUGADORES." << endl;
    cout << "\t\t        3. MAXIMA PUNTUACION." << endl;
    cout << "\t\t        4. SALIR DEL JUEGO." << endl<<endl<<endl;

}


void Puntajefinal(char nombre[30],int puntos, int rondas){

    locate(30,9);
    cout << "--------------------" ;
    locate(38,11);
    cout <<nombre;
    locate(30,13);
    cout << "  PUNTAJE FINAL: " ;
    locate(47,13);
    cout<< puntos ;
    locate(30,15);
    cout << "  RONDAS       : " ;
    locate(47,15);
    cout<< rondas ;
    locate(30,17);
    cout << "--------------------" ;
    Sleep(2000);
    system("cls");

}


void NuevoRecord (){
    locate(30,9);
    cout<< "---------------------" ;
    locate(30,11);
    cout<< "      N U E V O      " ;
    locate(30,13);
    cout<< "     R E C O R D     " ;
    locate(30,15);
    cout<< "---------------------" ;
    Sleep(2000);
    system("cls");
}

void Empate (){
    locate(30,9);
    cout<< "---------------------" ;
    locate(30,12);
    cout<< "     E M P A T E     " ;
    locate(30,15);
    cout<< "---------------------" ;
    Sleep(2000);
    system("cls");
}


void GENERALA (){
    cout<<endl;
    cout<<"  ######   ######## ##    ## ######## ########     ###    ##          ###    "<<endl;
    cout<<" ##    ##  ##       ###   ## ##       ##     ##   ## ##   ##         ## ##   "<<endl;
    cout<<" ##        ##       ####  ## ##       ##     ##  ##   ##  ##        ##   ##  "<<endl;
    cout<<" ##   #### ######   ## ## ## ######   ########  ##     ## ##       ##     ## "<<endl;
    cout<<" ##    ##  ##       ##  #### ##       ##   ##   ######### ##       ######### "<<endl;
    cout<<" ##    ##  ##       ##   ### ##       ##    ##  ##     ## ##       ##     ## "<<endl;
    cout<<"  ######   ######## ##    ## ######## ##     ## ##     ## ######## ##     ## 2.0"<<endl;
    cout<<" ------------------------------------------------------------------------------"<<endl;
    cout<<" By FELI - FRAN - JUANCITO";
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<endl<<endl<<endl;
    system("pause");
    system("cls");


}


void Saludo(){
    locate(30,9);
    cout<< "---------------------";
    locate(30,11);
    cout<< "    G R A C I A S    ";
    locate(30,13);
    cout<< "      POR JUGAR      ";
    locate(30,15);
    cout<< "---------------------" ;
    Sleep(1800);
    system("cls");
}

void PartidaDe(char nombre[20]){
 cout << "\t\t\t\t Partida de " << nombre << "\t\t" << endl;
                    cout << endl << endl;
}


void ContinuarTirando(){

cout << "CONTINUAR TIRANDO? S/N: ";


}


void Bienvenidx1JUG(){
cout << "\t\t  ----------------------------------------" << endl;
                cout << "\t\t | Bienvenidx al modo de juego: 1 JUGADOR |" << endl;
                cout << "\t\t  ----------------------------------------" << endl<<endl<<endl;
                cout << endl;

                cout << "\t\tPor favor, ingrese su nombre antes de comenzar: "<<endl<<endl;
                cout << "\t\t\t\t    ";

}


void MaxPtosSimple(char max_name[20], int min_rondas, int max_puntos){
    locate(15,9);
    cout<<"      -------------------------------------------------------------" ;
    locate(23,11);
    cout<<"   MAXIMA PUNTUACION: "<<max_name <<" CON: "<< min_rondas <<" RONDAS Y " << max_puntos <<" PUNTOS";
    locate(15,13);
    cout<<"      -------------------------------------------------------------" ;
    locate(1,22);
    system("pause");
    system("cls");


}


void MaxPtosEmpate(char max_name[20],char max_name1[20], int min_rondas, int max_puntos){
    locate(15,9);
    cout<<"      -------------------------------------------------------------" ;
    locate(23,11);
    cout<<"   MAXIMA PUNTUACION: "<<max_name<<" Y "<<max_name1  <<" CON: "<< min_rondas<<" RONDAS Y " << max_puntos <<" PUNTOS";
    locate(15,13);
    cout<<"      -------------------------------------------------------------" ;
    locate(1,22);
    system("pause");
    system("cls");


}



void Bienvenidx2JUGS(){
    locate(5, 1);
    cout << "\t\t  ------------------------------------------" << endl;
    cout << "\t\t | Bienvenidx al modo de juego: 2 JUGADORES |" << endl;
    cout << "\t\t  ------------------------------------------" << endl<<endl<<endl;
    cout << endl;
}

void NOMBREJG1(){
    locate(19, 5);
    cout << "Por favor, ingrese el nombre del Jugador 1: "<<endl<<endl;
    cout << "    ";

}

void NOMBREJG2(){
    locate(19, 10);
    cout << "Por favor, ingrese el nombre del Jugador 2: "<<endl<<endl;
    cout << "    ";


}

/// funciones para simplificar el main del jugador 1 y 2

bool Jugada( const int T, bool MODO, bool& GeneralaServida, char nombre[20], int& AcumPtos, int& ContRonda){

                system("cls");

                /// VARIABLE QUE GUARDA LOS PUNTOS CUANDO SE HACE UN JUEGO DE NUMEROS
                int ptos1, ptos2, ptos3, ptos4, ptos5, ptos6, ptosGenerala, ptosPoker, ptosFull, ptosEscalera, VecPuntos[9], MayorPtos;
                /// CONTADOR DE RONDAS

                /// VECTOR QUE SERÁ EVALUADO
                int v[5];
                /// ACUMULADOR DE PUNTOS

                /// VARIABLE QUE DETERMINA EL TAMAÑO DEL NUEVO VECTOR ALEATORIO QUE SE GENERARÁ
                int t;
                /// VARIABLES CHAR SI(S) O NO(N) QUE INGRESA EL USUARIO PARA CONTINUAR TIRANDO O DEJAR DE TIRAR
                char Respuesta, Respuesta2;







            ///ABRO CICLO WHILE PARA EJECUTAR "T" RONDAS
            while(ContRonda<T && GeneralaServida==false){
                ContRonda++;
                int ContTiros=1; ///CONTADOR DE TIROS

                entreturnos(nombre, AcumPtos, ContRonda);

                ///ABRO CICLO PARA EJECUTAR 3 TIROS
                while(ContTiros<3){



                    cout << "\t\t\t\t Partida de " << nombre << "\t\t" << endl;
                    cout << endl << endl;

                    MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);

                    TirarDados(v, MODO);

                    MostrarDados(v);

                    cout << endl << endl<< endl<< endl;


                    ///VERIFICA SI SALIO GENERALA SERVIDA EN EL PRIMER TIRO, DE SER ASI, LA VARIABLE BOOLEANA "GeneralaServida" SE CONVIERTE EN TRUE,
                    ///Y "ContTiros" SERÁ 3.
                    ptosGenerala=VerificacionGENERALA(v);
                    if( ptosGenerala==50 && ContTiros==1){
                        cout << "PUNTOS: " << ptosGenerala << endl << endl;
                        AcumPtos+=ptosGenerala;
                        system("pause");
                        system("cls");
                        GeneralaServida=true;
                        ContTiros=3;
                    }

                    ///SI NO SE CUMPLE...
                    else{


                    ///OPCION DE TIRAR POR 2°VEZ


                    cout << "CONTINUAR TIRANDO? S/N: "; cin >> Respuesta;
                    cout << endl;

                    switch(Respuesta){

                        case 'S':
                        case 's':
                            {

                            ///SI LA RESPUESTA ES "S", INCREMENTA ++ "ContTiros"
                            ContTiros++;

                            cout << "CUANTOS VOLVES A TIRAR?: "; cin >> t;
                            cout << endl;
                            ///SI "t" ES MENOR A 5, PREGUNTA CUÁLES DADOS QUIERE VOLVER A TIRAR
                            if(t<5){

                            ///Genera un NUEVO VectorDados aleatorio de tamaño "t"
                            int v2[t];
                            TirarDados2(v2, t);


                            int v3[t];
                            cout << "CUAL/ES?: " << endl;
                            cout << endl;

                            ///Genera un vector con los INDICES que van a ser reemplazados del VectorDados ORIGINAL
                            CargarVectorCambio(v3, t);
                            ///En el VectorDados ORIGINAL se reemplazan las posiciones indicadas por el usuario -1 , CON EL NUEVO VECTOR ALEATORIO TAMAÑO "t".
                            CambiarDados(v, v2, v3, t);

                            system("pause");
                            system("cls");

                            cout << "\t\t\t\t Partida de " << nombre << "\t\t" << endl;
                            cout << endl << endl;

                            MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);

                            MostrarDados(v);

                            cout << endl << endl;

                            }

                            ///SI "t" ES 5, NO PREGUNTA CUÁLES DADOS QUIERE VOLVER A TIRAR, SINO QUE TIRA LOS 5 AUTOMATICAMENTE
                            else{
                                TirarDados(v, MODO);
                                system("cls");

                                cout << "\t\t\t\t Partida de " << nombre << "\t\t" << endl;
                                cout << endl << endl;

                                MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);

                                MostrarDados(v);

                                cout << endl << endl;

                                }

                            ///OPCION DE TIRAR POR 3°VEZ

                            cout << "CONTINUAR TIRANDO? S/N: "; cin >> Respuesta2;
                            cout << endl;

                            switch(Respuesta2){
                                case 'S':
                                case 's':
                                    {///ABRE LLAVE "AUXILIAR?"

                                    ///SI "Respuesta2" ES "S", ENTRA AL SWITCH E INCREMENTA "ContTiros"
                                    ContTiros++;

                                    cout << "CUANTOS VOLVES A TIRAR?: "; cin >> t;
                                    cout << endl;

                                    ///SI "t" ES MENOR A 5, PREGUNTA CUÁLES DADOS QUIERE VOLVER A TIRAR
                                    if(t<5){

                                    int v2[t];
                                    TirarDados2(v2, t);
                                    int v3[t];

                                    cout << "CUAL/ES?:" << endl;
                                    cout << endl;

                                    ///SE REPITE LO ANTERIOR
                                    CargarVectorCambio(v3, t);
                                    CambiarDados(v, v2, v3, t);

                                    system("pause");
                                    system("cls");

                                    cout << "\t\t\t\t Partida de " << nombre << "\t\t" << endl;
                                    cout << endl << endl;

                                    MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);

                                    MostrarDados(v);

                                    cout << endl << endl;
                                    }

                                    ///SI "t" ES 5, NO PREGUNTA CUÁLES DADOS QUIERE VOLVER A TIRAR, SINO QUE TIRA LOS 5 AUTOMATICAMENTE
                                    else{
                                        TirarDados(v, MODO);
                                        system("cls");

                                        cout << "\t\t\t\t Partida de " << nombre << "\t\t" << endl;
                                        cout << endl << endl;

                                        MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);

                                        MostrarDados(v);

                                        cout << endl << endl;
                                     }

                                    }///CIERRA LLAVE "AUXILIAR?"

                                    break;

                                case 'N':
                                case 'n':
                                    ContTiros=3;
                                    break;

                                default:{

                                    for(int i=0; i<5; i++){v[i]=0;}
                                    cout<< "Ingreso de opcion incorrecta. Se volveran a tirar los dados." << endl << endl;
                                    }
                                    break;
                                    }///Switch RESP2

                                    }
                            break;

                        case 'N':
                        case 'n':
                            {
                            ContTiros=3;
                                }
                            break;

                        default:
                            {
                                cout << "Ingreso de opcion incorrecta. Se volveran a tirar los dados." << endl << endl;

                                }
                             break;


                    }///Switch RESP1

///UTILIZO FUNCIONES PARA ANALIZAR EL VECTOR DADOS FINAL
                    ///CADA FUNCION RETORNA UN PUNTAJE DEPENDIENDO SI SE CUMPLEN LAS CONDICIONES DE CADA UNA

                    ptosGenerala=VerificacionGENERALA(v);

                    ptosPoker=VerificacionPOKER(v);

                    ptosFull=VerificacionFULL(v);

                    ptosEscalera=VerificacionESCALERA(v);

                    ptos6=VerificacionDeSEIS(v);

                    ptos5=VerificacionDeCINCO(v);

                    ptos4=VerificacionDeCUATRO(v);

                    ptos3=VerificacionDeTRES(v);

                    ptos2=VerificacionDeDOS(v);

                    ptos1=VerificacionDeUNOS(v);


                    ///SE CARGA UN VECTOR CON TODOS LOS VALORES QUE RETORNAN LAS FUNCIONES ANTERIORES
                    CargarVectorPuntos(VecPuntos, ptosGenerala, ptosPoker, ptosFull, ptosEscalera, ptos6, ptos5, ptos4, ptos3, ptos2, ptos1);
                    ///DENTRO DE ESE VECTOR SE BUSCA EL MAXIMO


                    MayorPtos=BuscarPuntosMax(VecPuntos);

                    cout << "PUNTOS: " << MayorPtos << endl << endl;
                    ///SE ACUMULA EL MAXIMO

                    AcumPtos+=MayorPtos;
                    cout << endl<<endl<<endl;

                    system("pause");
                    system("cls");

                } ///CIERRA "else" SI NO SE CUMPLE GENERALA SERVIDA

                }///WHILE TIROS



            }///WHILE RONDAS

            return GeneralaServida;
        }


void Jugada2jgs(const int T, bool MODO, bool& GeneralaServida, char nombre1[20], char nombre2[20], int& AcumPtos, int& AcumPtos2, int& ContRonda, bool& GeneralaServidaJug1, bool& GeneralaServidaJug2){
    /// VARIABLE QUE GUARDA LOS PUNTOS CUANDO SE HACE UN JUEGO DE NUMEROS
    int ptos1, ptos2, ptos3, ptos4, ptos5, ptos6, ptosGenerala, ptosPoker, ptosFull, ptosEscalera, VecPuntos[9], MayorPtos;
    /// VECTOR QUE SERÁ EVALUADO
    int v[5];
    /// VARIABLE QUE DETERMINA EL TAMAÑO DEL NUEVO VECTOR ALEATORIO QUE SE GENERARÁ
    int t;
    /// VARIABLES CHAR SI(S) O NO(N) QUE INGRESA EL USUARIO PARA CONTINUAR TIRANDO O DEJAR DE TIRAR
    char Respuesta, Respuesta2;
    /// CONTADOR DE TURNOS PARA 2 JUGADORES
    int turno=0;
    /// CONTADOR PARA MANTENER LAS RONDA DOS JUGADAS
    int sumaronda=0;




            ///ABRO CICLO WHILE PARA RONDAS

            while(sumaronda<(T*2) && GeneralaServida==false){
                int ContTiros=1;    ///CONTADOR DE TIROS


                ///"Sumaronda" inicia en cero, primero pregunta si sumaronda es menor a T*2, es decir si es menor a 20 (por defecto), si es menor entra al while,
                /// ya dentro del while, pregunta si "sumaronda" es PAR, al ser cero en primera instancia, da VERDADERO, entonces incrementa CONTRONDA a 1.
                ///Asi, ContRonda queda en 1 para AMBOS JUGADORES. Luego incrementa TURNO++, por lo tanto queda en 1. Entonces al preguntar si TURNO es impar,
                ///da VERDADERO (ahi el jugador 1 realiza todo su juego), luego incrementa SUMARONDA++ y vuelve al principio.
                ///Pregunta si SUMARONDA es menor a T*2, da VERDADERO (sumaronda es 1), entra al while y pregunta si suma ronda es PAR, da FALSO
                ///Por lo que NO incrementa CONTRONDA, (sigue siendo 1 para el jugador 2). Luego incrementa TURNO++ y queda en 2.
                ///Entonces ahi pregunta si TURNO es IMPAR, da falso ya que es 2, saltea todo el juego del JUGADOR 1 y pregunta si TURNO ES PAR, da VERDADERO
                ///Entonces el jugador 2 realiza todo su juego. Incrementa SUMARONDA++. y vuelve al principio, y asi sucesivamente hasta que CONTRONDA sea 20.



                if(sumaronda%2==0){ /// CONTADOR DE RONDAS, LE SUMA 1 CUANDO PASAN DOS VUELTAS.
                    ContRonda++;
                    }
                turno++;

                ///SI TURNOS ES IMPAR, JUEGA EL JUGADOR 1 Y SI PAR JUEGA JUGADOR 2
                if(turno%2!=0){
                    entreturnos(nombre1,AcumPtos,ContRonda);

                    while(ContTiros<3){///ABRO CICLO PARA EJECUTAR 3 TIROS JUGADOR 1

                        cout << "\t\t\t\t Turno de " << nombre1 << "\t\t" << endl;
                        cout << endl << endl;

                        MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);
                        TirarDados(v, MODO);
                        MostrarDados(v);
                        cout << endl << endl<< endl<< endl;


                        ///Si se cumple grala servida..
                        ptosGenerala=VerificacionGENERALA(v);
                        if( ptosGenerala==50 && ContTiros==1){
                            GeneralaServidaJug1=true;
                            ContTiros=3;

                        }

                        ///Si no se cumple..
                        else{


                        ///OPCION DE TIRAR POR 2°VEZ

                        cout << "CONTINUAR TIRANDO? S/N: "; cin >> Respuesta;
                        cout << endl;



                        switch(Respuesta){

                            case 'S':
                            case 's':
                                {

                                ContTiros++;

                                cout << "CUANTOS VOLVES A TIRAR?: "; cin >> t;
                                cout << endl;
                                if(t<5){ ///<--- TIRA LOS 5 DADOS SIN PREGUNTAR CUALES.
                                int v2[t];
                                TirarDados2(v2, t);

                                int v3[t];
                                cout << "CUAL/ES?: " << endl;
                                cout << endl;

                                CargarVectorCambio(v3, t);
                                CambiarDados(v, v2, v3, t);

                                system("pause");
                                system("cls");

                                cout << "\t\t\t\t Turno de " << nombre1 << "\t\t" << endl;
                                cout << endl << endl;

                                MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);

                                MostrarDados(v);
                                cout << endl << endl;

                                }
                                else{
                                    TirarDados(v, MODO);
                                    system("cls");

                                    cout << "\t\t\t\t Turno de " << nombre1 << "\t\t" << endl;
                                    cout << endl << endl;

                                    MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);

                                    MostrarDados(v);
                                    cout << endl << endl;

                                    }
                                ///OPCION DE TIRAR POR 3°VEZ

                                cout << "CONTINUAR TIRANDO? S/N: "; cin >> Respuesta2;
                                cout << endl;

                                switch(Respuesta2){
                                    case 'S':
                                    case 's':
                                        {
                                        ContTiros++;

                                        cout << "CUANTOS VOLVES A TIRAR?: "; cin >> t;
                                        cout << endl;
                                        if(t<5){  ///<--- TIRA LOS 5 DADOS SIN PREGUNTAR CUALES.
                                        int v2[t];
                                        TirarDados2(v2, t);
                                        int v3[t];

                                        cout << "CUAL/ES?:" << endl;
                                        cout << endl;

                                        CargarVectorCambio(v3, t);
                                        CambiarDados(v, v2, v3, t);

                                        system("pause");
                                        system("cls");

                                        cout << "\t\t\t\t Turno de " << nombre1 << "\t\t" << endl;
                                        cout << endl << endl;

                                        MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);
                                        MostrarDados(v);
                                        cout << endl << endl;

                                        }
                                        else{
                                            TirarDados(v, MODO);
                                            system("cls");

                                            cout << "\t\t\t\t Turno de " << nombre1 << "\t\t" << endl;
                                            cout << endl << endl;

                                            MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos);

                                            MostrarDados(v);
                                            cout << endl << endl;
                                        }
                                        }

                                        break;

                                    case 'N':
                                    case 'n':
                                        ContTiros=3;
                                        break;

                                    default:{
                                        cout<< "Ingreso de opcion incorrecta. Se volveran a tirar los dados." << endl << endl;

                                        }
                                        break;
                                        }///Switch RESP2

                                        }
                                break;

                            case 'N':
                            case 'n':
                                {
                                ContTiros=3;
                                    }
                                break;

                            default:
                                {
                                    cout << "Ingreso de opcion incorrecta. Se volveran a tirar los dados." << endl << endl;

                                     }
                                 break;


                        }///Switch RESP1


                    }


                    ///UTILIZO FUNCIONES PARA ANALIZAR EL VECTOR DADOS FINAL
                    ///CADA FUNCION RETORNA UN PUNTAJE DEPENDIENDO SI SE CUMPLEN LAS CONDICIONES DE CADA UNA

                    ptosGenerala=VerificacionGENERALA(v);

                    ptosPoker=VerificacionPOKER(v);

                    ptosFull=VerificacionFULL(v);

                    ptosEscalera=VerificacionESCALERA(v);

                    ptos6=VerificacionDeSEIS(v);

                    ptos5=VerificacionDeCINCO(v);

                    ptos4=VerificacionDeCUATRO(v);

                    ptos3=VerificacionDeTRES(v);

                    ptos2=VerificacionDeDOS(v);

                    ptos1=VerificacionDeUNOS(v);


                    ///SE CARGA UN VECTOR CON TODOS LOS VALORES QUE RETORNAN LAS FUNCIONES ANTERIORES
                    CargarVectorPuntos(VecPuntos, ptosGenerala, ptosPoker, ptosFull, ptosEscalera, ptos6, ptos5, ptos4, ptos3, ptos2, ptos1);
                    ///DENTRO DE ESE VECTOR SE BUSCA EL MAXIMO
                    MayorPtos=BuscarPuntosMax(VecPuntos);
                    cout << "PUNTOS: " << MayorPtos << endl << endl;
                    ///SE ACUMULA EL MAXIMO
                    AcumPtos+=MayorPtos;
                    cout << endl<<endl<<endl;

                        system("pause");
                        system("cls");




                    }///WHILE TIROS


                }///Cierra llave para cuando "turnos" es impar.

                else{ ///Abro llave para cuando "turnos" es par. (juega el jugador 2)
                    entreturnos(nombre2,AcumPtos2,ContRonda);
                    while(ContTiros<3){ ///ABRO CICLO PARA EJECUTAR 3 TIROS PARA JUGADOR 2

                        cout << "\t\t\t\t Turno de " << nombre2 << "\t\t" << endl;
                        cout << endl << endl;

                        MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos2);
                        TirarDados(v, MODO);
                        MostrarDados(v);
                        cout << endl << endl<< endl<< endl;

                        ptosGenerala=VerificacionGENERALA(v);   ///<---GENERALA SERVIDA.
                        if( ptosGenerala==50 && ContTiros==1){
                            GeneralaServidaJug2=true;
                            ContTiros=3;

                        }
                        else{


                        ///OPCION DE TIRAR POR 2°VEZ

                        cout << "CONTINUAR TIRANDO? S/N: "; cin >> Respuesta;
                        cout << endl;



                        switch(Respuesta){

                            case 'S':
                            case 's':
                                {

                                ContTiros++;

                                cout << "CUANTOS VOLVES A TIRAR?: "; cin >> t;
                                cout << endl;
                                if(t<5){ ///<--- TIRA LOS 5 DADOS SIN PREGUNTAR CUALES.
                                int v2[t];
                                TirarDados2(v2, t);

                                int v3[t];
                                cout << "CUAL/ES?: " << endl;
                                cout << endl;

                                CargarVectorCambio(v3, t);
                                CambiarDados(v, v2, v3, t);

                                system("pause");
                                system("cls");

                                cout << "\t\t\t\t Turno de " << nombre2 << "\t\t" << endl;
                                cout << endl << endl;

                                MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos2);
                                MostrarDados(v);
                                cout << endl << endl;

                                }
                                else{
                                    TirarDados(v, MODO);
                                    system("cls");

                                    cout << "\t\t\t\t Turno de " << nombre2 << "\t\t" << endl;
                                    cout << endl << endl;

                                    MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos2);

                                    MostrarDados(v);
                                    cout << endl << endl;

                                    }
                                ///OPCION DE TIRAR POR 3°VEZ

                                cout << "CONTINUAR TIRANDO? S/N: "; cin >> Respuesta2;
                                cout << endl;

                                switch(Respuesta2){
                                    case 'S':
                                    case 's':
                                        {
                                        ContTiros++;

                                        cout << "CUANTOS VOLVES A TIRAR?: "; cin >> t;
                                        cout << endl;
                                        if(t<5){  ///<--- TIRA LOS 5 DADOS SIN PREGUNTAR CUALES.
                                        int v2[t];
                                        TirarDados2(v2, t);
                                        int v3[t];

                                        cout << "CUAL/ES?:" << endl;
                                        cout << endl;

                                        CargarVectorCambio(v3, t);
                                        CambiarDados(v, v2, v3, t);

                                        system("pause");
                                        system("cls");

                                        cout << "\t\t\t\t Turno de " << nombre2 << "\t\t" << endl;
                                        cout << endl << endl;

                                        MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos2);

                                        MostrarDados(v);
                                        cout << endl << endl;
                                        }
                                        else{
                                            TirarDados(v, MODO);
                                            system("cls");

                                            cout << "\t\t\t\t Turno de " << nombre2 << "\t\t" << endl;
                                            cout << endl << endl;

                                            MuestraRondaTiroPuntos(ContRonda, ContTiros, AcumPtos2);

                                            MostrarDados(v);
                                            cout << endl << endl;
                                        }
                                        }

                                        break;

                                    case 'N':
                                    case 'n':
                                        ContTiros=3;
                                        break;

                                    default:{
                                        cout<< "Ingreso de opcion incorrecta. Se volveran a tirar los dados." << endl << endl;
                                        }
                                        break;
                                        }///Switch RESP2

                                        }
                                break;

                            case 'N':
                            case 'n':
                                {
                                ContTiros=3;
                                    }
                                break;

                            default:
                                {
                                    cout << "Ingreso de opcion incorrecta. Se volveran a tirar los dados." << endl << endl;
                                    }
                                 break;


                        }///Switch RESP1
                        }

                         ///UTILIZO FUNCIONES PARA ANALIZAR EL VECTOR DADOS FINAL
                    ///CADA FUNCION RETORNA UN PUNTAJE DEPENDIENDO SI SE CUMPLEN LAS CONDICIONES DE CADA UNA

                    ptosGenerala=VerificacionGENERALA(v);

                    ptosPoker=VerificacionPOKER(v);

                    ptosFull=VerificacionFULL(v);

                    ptosEscalera=VerificacionESCALERA(v);

                    ptos6=VerificacionDeSEIS(v);

                    ptos5=VerificacionDeCINCO(v);

                    ptos4=VerificacionDeCUATRO(v);

                    ptos3=VerificacionDeTRES(v);

                    ptos2=VerificacionDeDOS(v);

                    ptos1=VerificacionDeUNOS(v);


                    ///SE CARGA UN VECTOR CON TODOS LOS VALORES QUE RETORNAN LAS FUNCIONES ANTERIORES
                    CargarVectorPuntos(VecPuntos, ptosGenerala, ptosPoker, ptosFull, ptosEscalera, ptos6, ptos5, ptos4, ptos3, ptos2, ptos1);
                    ///DENTRO DE ESE VECTOR SE BUSCA EL MAXIMO
                    MayorPtos=BuscarPuntosMax(VecPuntos);
                    cout << "PUNTOS: " << MayorPtos << endl << endl;
                    ///SE ACUMULA EL MAXIMO
                    AcumPtos2+=MayorPtos;
                    cout << endl<<endl<<endl;

                    system("pause");
                    system("cls");


                    }///WHILE TIROS
                if((GeneralaServidaJug1==true && GeneralaServidaJug2==true)||(GeneralaServidaJug1==true && GeneralaServidaJug2==false)||(GeneralaServidaJug1==false && GeneralaServidaJug2==true))
                    GeneralaServida=true;
                    ///empate en grala servida

                }
                sumaronda++;


                }///Fin del while de las rondas.


}


void comprobacionfinal(bool GeneralaServida, int ContRonda, int AcumPtos, char nombre[20]){
    if(GeneralaServida==true){
        cartelgenerala(nombre,AcumPtos,ContRonda);

    }
    ///SI NO SE CUMPLE, MUESTRA EL PUNTAJE FINAL, NOMBRE Y RONDAS JUGADAS
    else{
        Puntajefinal(nombre,AcumPtos,ContRonda);
    }
}


char comprobacion_maximo_JG1(int ContRonda, int AcumPtos, int& min_rondas, int& max_puntos, char nombre[20], char max_name[20], bool& empate){

    if(ContRonda<min_rondas||min_rondas==0){
        min_rondas=ContRonda;
        max_puntos=AcumPtos;
        strcpy(max_name, nombre);
        NuevoRecord();
        empate=false;
    }
    else{
        if(ContRonda==min_rondas||min_rondas==0){
          if(AcumPtos>max_puntos){
            min_rondas=ContRonda;
            max_puntos=AcumPtos;
            strcpy(max_name, nombre);
            NuevoRecord();
            empate=false;
            }
        }

    }
return max_name[20];
}

#endif // FUNCIONESGENERALA_H_INCLUDED

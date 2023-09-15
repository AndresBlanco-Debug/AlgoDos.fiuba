#include <iostream>
#include "tablero.h"
#include "jugador.h"
#include "reglas.h"
using namespace std;
class Juego
{
private:
    Tablero tableroJuego;
    Player jugadorNumeroUno;
    Player jugadorNumeroDos;
    Reglas reglamento;
public:
    Juego(Tablero tableroInicial, Player jugador1, Player jugador2, Reglas interaciones):
    tableroJuego(tableroInicial),jugadorNumeroUno(jugador1),jugadorNumeroDos(jugador2),reglamento(interaciones){}
    //se inicia el juego
    void asigarTurnos(){
        int ordenTurno = (rand() % 2) + 1;
        jugadorNumeroUno.ordenJuego = ordenTurno;
        jugadorNumeroDos.ordenJuego = (ordenTurno == 1) ? 2: 1;
    }//----------------------------------------------------------------------------------------------------
    void ingresarTesorosPrimerJugadorINICIO(){
        char tesoro = '$';
        //se define el caracter de tesoro
        for(int i = 0; i < 4; i++){
            int fila, columna;
            jugadorNumeroUno.pedirCoordenadas(fila,columna);
            while(tableroJuego.tesoroRepetido(fila, columna) && !(tableroJuego.compararTesoros())){
                //se hace la validacion
                reglamento.imprimirCoordenadas(fila,columna);
                jugadorNumeroUno.pedirCoordenadas(fila,columna);
            }
            tableroJuego.guardarIgresoTesoro(fila,columna,1);  
        }
    }
    //---------------------------------------------------------------------------------------------------
    void ingresarTesorosSegundoJugadorINICIO(){
        char tesoro = '$';
        //se define el caracter de tesoro
        for(int i = 0; i < 4; i++){
            int fila, columna;
            jugadorNumeroUno.pedirCoordenadas(fila,columna);
            while(tableroJuego.tesoroRepetido(fila, columna) && !(tableroJuego.compararTesoros())){
                //se hace la validacion
                reglamento.imprimirCoordenadas(fila,columna);
                jugadorNumeroUno.pedirCoordenadas(fila,columna);
            }
            tableroJuego.guardarIgresoTesoro(fila,columna,2);  
        }
    }//----------------------------------------------------------------------------------------------------
    //hacer interacciones separadas segun el turno.

    void IngresoTesoroPrimerJugador(){
        if((jugadorNumeroUno.validarIngresoTesoro() || (jugadorNumeroUno.val() == '1'))){
            //se evalua si hay mas tesoros en posecion del jugador que en el tablero
            //se evalua si mover el tesoro es true
            //se evalua si el ingreso es el tesoro y luego pasa
            int fila, columna;
            jugadorNumeroUno.pedirCoordenadas(fila,columna);
            //se valida que no se intente ingresar en una casilla invalida
            while(tableroJuego.casillaInvalida(fila,columna)){
                cout << "La casilla no esta disponible, intente con otra" << endl;
                jugadorNumeroUno.pedirCoordenadas(fila,columna);
            }
            //Se valida que no se ingrese en una casilla que ya ocupa un tesoro del jugador
            while(tableroJuego.tesoroRepetido(fila, columna) && !(tableroJuego.compararTesoros())){
                //evalua si hay un tesoro del jugador ingresado en el tablero y si no esta en ambos jugadores es solo del jgador 1
                reglamento.imprimirCoordenadas(fila, columna);
                cout << "Cada jugador solo puede tener un tesoro por casilla" << '\n';
                cout << "Por favor ingrese otras coordenadas" << endl;
                jugadorNumeroUno.pedirCoordenadas(fila,columna);
            }
            tableroJuego.guardarIgresoTesoro(fila, columna, 1);
            //puede pasar que lo ingrese en un:
            //1. un espia enemigo
            //2. un teroso del enemigo
            //3. una casilla vacia
            //CASO 1: UN ESPIA ENEMIGO
            if(tableroJuego.espiaEnPrimerJugador()){
                //se evalua si hay algun espia donde se ingreso el tesoro y de ser asi lo elimina
                //se reducen los tesoros en juego
                cout << "ERROR! UN ESPIA INFLILTRADO HA ROBADO SU TESORO" << '\n';
                cout << "El tesoro ha sido capturado" << endl;
            }
                //CASO 2: El tesoro se ingresa en un tesoro enemigo
            if(tableroJuego.compararTesoros()){
                reglamento.imprimirCoordenadas(fila,columna);
                //el tesoro se queda ahi porque es una casilla valida   
                //porque es un tesoro del enemigo.
            }
            //CASO 3: Una casilla esta vacia
            if(!tableroJuego.espiaEnPrimerJugador()){
                    //significa que la casilla esta vacia y es un ingreso normal
                    cout << "El tesoro se ha escondido con exito" << endl;
            }
        }
        else{
            cout << "Error, intente mas tarde" << endl;
        }
    }
    void ingresoEspiaPrimerJugador(){
        //SIEMPRE HAY QUE VALIDAR QUE LOS TESOROS SEAN DEL JUGADOR CORRESPONDIENTE PERO SOLO PARA MOVER O RECUPERAR.
        //HAY QUE PENSAR EN LA FUCNION PARA RECUPERAR EL TESORO.
        int fila, columna;
        jugadorNumeroUno.pedirCoordenadas(fila,columna);
        while(tableroJuego.casillaInvalida(fila,columna)){
            cout << "Error! ha seleccionado una casilla invalida, intente con otras coordenadas" << endl;
            jugadorNumeroUno.pedirCoordenadas(fila,columna);
        }
        //hay que evaluar que no lo ingrese con otro espia sdel mismo jugador
        while(tableroJuego.espiaRepetido(fila,columna)){
            cout << "Los jugadores solo pueden tener un espia por posicion, ingrese otras coordenadas" << endl;
            jugadorNumeroUno.pedirCoordenadas(fila,columna);
        }
        //se ingresa el epsia;
        tableroJuego.guardarIngresoEspia(fila, columna, 1);
        //a partir de aca evaluamos los casos posibles
        //1.El espia encuentre un tesoro
        //2.El espia encuentre otro espia
        //3.El jugador ponga al espia sobre un tesoro y lo recupere
        //4.El jugador ponga al espia en una casilla limpia y aca salen 2 sub-casos
            //4.1)El jugador decide mover cualquier tesoro disponible
            //4.2)El jugador no hace nada y acaba el turno
            
        //CASO 1.
        if(tableroJuego.espiaEnSegundoJugador()){
            //se ejecuta si hay un tesoro colocado donde el jugador ingreso al espia y lo elimina
            //hay que quitar los tesoros al jugador
            jugadorNumeroDos.reducirTesoros();
        }
        //CASO 2: El espia encuentra a otro espia
        else if(tableroJuego.eliminarEspias()){
            //Esta funcion recorre las coordenadas donde estan guardados todos los ingresos de espias
            //se valida si hay un tesoro en la posicion que se ingreso en espia
            cout << "El espia se ha encontrado con un espia enemigo" << '\n';
            cout << "Ambos espias han caido en fuego enemigo" << endl;
            //la casilla regresa a su estado normal
            tableroJuego.resetearCasilla(fila,columna);
            jugadorNumeroUno.espiaCaido();
            jugadorNumeroDos.espiaCaido();
            //se reducen la cantidad de espias en juego de ambos jugadores
        }
        //CASO 3: El jugador pone al espia sobre un tesoro suyo y lo recupera
        else if(tableroJuego.recuperarTesoroPrimerJugador()){
            //se evalua si hay un tesoro en la posicion donde se ingreso el espia.
            //se aplica la penalidad de los 5 turnos inactivos.
        }
        //CASO 4:
        else{
            int moverTesoro = jugadorNumeroUno.val();
            //SUB-CASO 4.1) Se desea mover cualquier tesoro
            if(moverTesoro == '1'){
                IngresoTesoroPrimerJugador();
                //se llama a la funcion del ingreso de tesoro
            }
            else{
                //caso que no se desee mover ningun tesoro;
                cout << "El espia se ha infiltrado correctamente" << endl;
            }
        }
    }
    void IngresoTesoroSegundoJugador(){
        if((jugadorNumeroDos.validarIngresoTesoro() || (jugadorNumeroDos.val() == '1'))){
            //se evalua si hay mas tesoros en posecion del jugador que en el tablero
            //se evalua si mover el tesoro es true
            //se evalua si el ingreso es el tesoro y luego pasa
            int fila, columna;
            jugadorNumeroDos.pedirCoordenadas(fila,columna);
            //se valida que no se intente ingresar en una casilla invalida
            while(tableroJuego.casillaInvalida(fila,columna)){
                cout << "La casilla no esta disponible, intente con otra" << endl;
                jugadorNumeroDos.pedirCoordenadas(fila,columna);
            }
            //Se valida que no se ingrese en una casilla que ya ocupa un tesoro del jugador
            while(tableroJuego.tesoroRepetido(fila, columna) && !(tableroJuego.compararTesoros())){
                //evalua si hay un tesoro del jugador ingresado en el tablero y si no esta en ambos jugadores es solo del jgador 1
                reglamento.imprimirCoordenadas(fila, columna);
                cout << "Cada jugador solo puede tener un tesoro por casilla" << '\n';
                cout << "Por favor ingrese otras coordenadas" << endl;
                jugadorNumeroDos.pedirCoordenadas(fila,columna);
            }
            tableroJuego.guardarIgresoTesoro(fila, columna, 1);
            //puede pasar que lo ingrese en un:
            //1. un espia enemigo
            //2. un teroso del enemigo
            //3. una casilla vacia
            //CASO 1: UN ESPIA ENEMIGO
            if(tableroJuego.espiaEnPrimerJugador()){
                //se evalua si hay algun espia donde se ingreso el tesoro y de ser asi lo elimina
                //se reducen los tesoros en juego
                cout << "ERROR! UN ESPIA INFLILTRADO HA ROBADO SU TESORO" << '\n';
                cout << "El tesoro ha sido capturado" << endl;
            }
                //CASO 2: El tesoro se ingresa en un tesoro enemigo
            if(tableroJuego.compararTesoros()){
                reglamento.imprimirCoordenadas(fila,columna);
                //el tesoro se queda ahi porque es una casilla valida   
                //porque es un tesoro del enemigo.
            }
            //CASO 3: Una casilla esta vacia
            if(!tableroJuego.espiaEnPrimerJugador()){
                    //significa que la casilla esta vacia y es un ingreso normal
                    cout << "El tesoro se ha escondido con exito" << endl;
            }
        }
        else{
            cout << "Error, intente mas tarde" << endl;
            //reingreso de las coordenadas
        }
    }
    void ingresoEspiaSegundoJugador(){
        int fila, columna;
        jugadorNumeroDos.pedirCoordenadas(fila,columna);
        while(tableroJuego.casillaInvalida(fila,columna)){
            cout << "Error! ha seleccionado una casilla invalida, intente con otras coordenadas" << endl;
            jugadorNumeroDos.pedirCoordenadas(fila,columna);
        }
        while(tableroJuego.espiaRepetido(fila,columna)){
            cout << "Los jugadores solo pueden tener un espia por posicion, ingrese otras coordenadas" << endl;
            jugadorNumeroDos.pedirCoordenadas(fila,columna);
        }
        tableroJuego.guardarIngresoEspia(fila, columna, 1);
        if(tableroJuego.espiaEnSegundoJugador()){
            jugadorNumeroUno.reducirTesoros();
        }
        else if(tableroJuego.eliminarEspias()){
            cout << "El espia se ha encontrado con un espia enemigo" << '\n';
            cout << "Ambos espias han caido en fuego enemigo" << endl;
            //la casilla regresa a su estado normal
            tableroJuego.resetearCasilla(fila,columna);
            jugadorNumeroDos.espiaCaido();
            jugadorNumeroUno.espiaCaido();//jugador numero 1
            //se reducen la cantidad de espias en juego de ambos jugadores
        }
        //CASO 3: El jugador pone al espia sobre un tesoro suyo y lo recupera
        else if(tableroJuego.recuperarTesoroPrimerJugador()){
            //se evalua si hay un tesoro en la posicion donde se ingreso el espia.
            //se aplica la penalidad de los 5 turnos inactivos.
        }
        //CASO 4:
        else{
            int moverTesoro = jugadorNumeroDos.val();
            //SUB-CASO 4.1) Se desea mover cualquier tesoro
            if(moverTesoro == '1'){
                IngresoTesoroSegundoJugador();
                //se llama a la funcion del ingreso de tesoro
            }
            else{
                //caso que no se desee mover ningun tesoro;
                cout << "El espia se ha infiltrado correctamente" << endl;
            }
        }
    }
    int turno(){
        int turnoActual = 0;
        char primeraRespuesta = jugadorNumeroUno.pedirIngreso();
        if(primeraRespuesta == '$'){
            IngresoTesoroPrimerJugador();
        }
        else if(primeraRespuesta == 'E'){
            IngresoTesoroPrimerJugador();
        }
        char segundaRespuesta = jugadorNumeroDos.pedirIngreso();
        if(segundaRespuesta == '$'){
            IngresoTesoroSegundoJugador();
        }
        else if(segundaRespuesta == 'E'){
            ingresoEspiaSegundoJugador();
        }
        turnoActual++;
        return turnoActual;
    }
    void juego(){}

};

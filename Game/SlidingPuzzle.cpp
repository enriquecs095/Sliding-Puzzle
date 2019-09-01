#include "SlidingPuzzle.h"
#include <string>
#include <iostream>
#include <thread>
#include <fstream>
using namespace std;

const string Sprite1="\x1";//Tablero y lineas verticales
const string Sprite2="\x2";
const string Sprite3="\x3";
const string Sprite4="\x4";
const string Sprite5="\x5";
const string Sprite6="\x6";
const string Sprite7="\x1\x1\x1\x1\x1\x1\x1\x1";
int PiezaVacia[9][2];
int Pieza1[7][2];
int Pieza2[21][2];
int Pieza3[21][2];
int Pieza4[13][2];
int Pieza5[22][2];
int Pieza6[23][2];
int Pieza7[11][2];
int Pieza8[26][2];
int Pieza9[23][2];
int Boton[1][2];
int Segundos;
int Contador=0;
int MoverHaciaAbajo=9;
int XInmovil=0;
int MoverHaciaDerecha=9;
int YInmovil=0;
int MoverHaciaIzquierda=-9;
int MoverHaciaArriba=-9;
int ContadorTablero=0;
int TableroAleatorio;
CColor ColorVacio=CColor::Aqua;
CColor ColorPiezaVacia=CColor::Maroon;
CColor ColorPieza=CColor::White;
bool SalirPrograma=false;
bool SalirVideojuego=false;
bool SalirEstadisticas=false;
bool DetenerCronometro=false;

void SlidingPuzzle::run()
 {  
     CargarMenuPrincipal();
     MenuPrincipal();
     return;
}

void SlidingPuzzle::CargarMenuPrincipal(){
     con.setBackcolor(CColor::Grey);
     con.clearScreen();
     DibujarMarcoGrande();
     con.setForecolor(CColor::Black);
     //Dibujo el rotulo 
     //Letra S
     for (int i = 6; i < 9; i++)
     {
     con.setCursor(3,i);
     con<<Sprite1;
     con.setCursor(5,i);
     con<<Sprite1;
     con.setCursor(7,i);
     con<<Sprite1;
     }
     con.setCursor(4,5);
     con<<Sprite1;
     con.setCursor(6,9);
     con<<Sprite1;
     //Letra L
     for (int i = 3; i < 7; i++)
     {
     con.setCursor(i,11);
     con<<Sprite1;
     }
     for (int i = 12; i < 15; i++)
     {
     con.setCursor(7,i);
     con<<Sprite1;
     }
     //Letra I
     for (int i = 5; i < 8; i++)
     {
     con.setCursor(i,16);
     con<<Sprite1;
     }
     con.setCursor(3,16);
     con<<Sprite1;
     //Letra D
     for (int i = 3; i < 8; i++)
     {
     con.setCursor(i,18);
     con<<Sprite1;
     }
     for (int i = 19; i <22 ; i++)
     {
     con.setCursor(3, i);
     con<<Sprite1;
     con.setCursor(7, i);
     con<<Sprite1;
     
     }
     for (int i = 4; i <7 ; i++)
     {
     con.setCursor(i, 22);
     con<<Sprite1;
     }
     //I
     for (int i = 5; i < 8; i++)
     {
     con.setCursor(i,24);
     con<<Sprite1;
     }
     con.setCursor(3,24);
     con<<Sprite1;
     //N
     for (int i = 3; i < 8; i++)   
     {
     con.setCursor(i,26);
     con<<Sprite1;
     con.setCursor(i,30);
     con<<Sprite1;
     }
     con.setCursor(4,27);
     con<<Sprite1;
     con.setCursor(5,28);
     con<<Sprite1;
     con.setCursor(6,29);
     con<<Sprite1;
     //G
     for (int i = 33; i < 37; i++)
     {
     con.setCursor(3,i);
     con<<Sprite1;
     con.setCursor(7,i);
     con<<Sprite1;
     }
     for (int i = 4; i < 7; i++)
     {
     con.setCursor(i,32);
     con<<Sprite1;
     }
     for (int i = 5; i < 8; i++)
     {
   con.setCursor(i,36);
     con<<Sprite1;
     }
     con.setCursor(5,35);
     con<<Sprite1;

     //Dibujamos la P
     for (int i = 9; i < 14; i++)
     {
   con.setCursor(i,6);
     con<<Sprite1;
     }
     for (int i = 7; i < 10; i++)
     {
     con.setCursor(9,i);
     con<<Sprite1;
     con.setCursor(11,i);
     con<<Sprite1;
     }
   con.setCursor(10,10);
     con<<Sprite1;
     //Dibujamos la U
     for (int i = 9; i < 13; i++)
     {
   con.setCursor(i,12);
     con<<Sprite1;
     con.setCursor(i,15);
     con<<Sprite1;
     }
     for (int i = 13; i < 15; i++)
     {
   con.setCursor(13,i);
     con<<Sprite1;
     }
     //Dibujamos las z
     for (int i = 17; i <21 ; i++)
     {
     con.setCursor(9,i);
     con<<Sprite1;
     con.setCursor(13,i);
     con<<Sprite1;
     }
     int j=12;
     for (int i =18; i <21 ; i++)
     {
     con.setCursor(j,i);
     con<<Sprite1;   
     j--;
     }
     //La otra z
     for (int i = 22; i <26 ; i++)
     {
     con.setCursor(9,i);
     con<<Sprite1;
     con.setCursor(13,i);
     con<<Sprite1;
     }
     int j1=12;
     for (int i =23; i <26 ; i++)
     {
     con.setCursor(j1,i);
     con<<Sprite1;   
     j1--;
     }
     //La letra l
     for (int i = 9; i < 13; i++)
     {
     con.setCursor(i,27);
     con<<Sprite1;
     }
     for (int i = 28; i < 31; i++)
     {
     con.setCursor(13,i);
     con<<Sprite1;
     }
     //La letra E
     for (int i = 33; i < 36; i++)
     {
     con.setCursor(9,i);
     con<<Sprite1;
     con.setCursor(11,i);
     con<<Sprite1;
     con.setCursor(13,i);
     con<<Sprite1;
     }
  con.setCursor(10,32);
  con<<Sprite1;
  con.setCursor(12,32);
  con<<Sprite1;
  //Dibujo la linea debajo de PUZZLE
  for (int i = 8; i < 34; i++)
     {
     con.setCursor(15,i);
     con<<Sprite2; 
     }
  //Dibujamos las opciones
     con.setCursor(18,19);
     con<<"Jugar";
     con.setCursor(21,15);
     con<<"Estadisticas";
     con.setCursor(24,19);
     con<<"Salir";
     //Aqui cargo el boton de opciones
     Boton[0][0]=18;
     Boton[0][1]=17;
     con.setCursor(Boton[0][0], Boton[0][1]);
     con<<Sprite1;
     con.refresh();
     //Dibujo el creador del Videojuego, osea yo 
     con.setForecolor(CColor::Red);
     con.setCursor(25,29);
     con<<"Co-creado por:";
     con.setCursor(26,31);
     con<<" enriquecs";
}

void SlidingPuzzle::MenuPrincipal(){
  con.flushKeybuffer();
     while(!SalirPrograma){
     TableroAleatorio=1+rand()%(4-1);
        SalirEstadisticas=false;
        uint32_t key = con.getKey();
        if (key != SDLK_UNKNOWN) {
            switch (key) {
                case SDLK_UP:
                 if(Boton[0][0]==18 && Boton[0][1]==17){
                       con.setForecolor(CColor::Grey);
                      con.setCursor(Boton[0][0],Boton[0][1]);
                      con<<Sprite1;
                     Boton[0][0]=Boton[0][0]+6;
                    con.setForecolor(CColor::Black);
                     con.setCursor(Boton[0][0], Boton[0][1]);
                     con<<Sprite1;
                 }else if(Boton[0][0]==21 && Boton[0][1]==13){
                      con.setForecolor(CColor::Grey);
                      con.setCursor(Boton[0][0],Boton[0][1]);
                      con<<Sprite1;
                     Boton[0][0]=Boton[0][0]-3;
                     Boton[0][1]=Boton[0][1]+4;
                     con.setForecolor(CColor::Black);
                     con.setCursor(Boton[0][0], Boton[0][1]);
                     con<<Sprite1;
                 }else if(Boton[0][0]==24 &&Boton[0][1]==17){
                       con.setForecolor(CColor::Grey);
                      con.setCursor(Boton[0][0],Boton[0][1]);
                      con<<Sprite1;
                     Boton[0][0]=Boton[0][0]-3;
                     Boton[0][1]=Boton[0][1]-4;
                    con.setForecolor(CColor::Black);
                     con.setCursor(Boton[0][0], Boton[0][1]);
                     con<<Sprite1;
                 }
                     break;
                case SDLK_DOWN:
                 if(Boton[0][0]==18 && Boton[0][1]==17){
                       con.setForecolor(CColor::Grey);
                      con.setCursor(Boton[0][0],Boton[0][1]);
                      con<<Sprite1;
                     Boton[0][0]=Boton[0][0]+3;
                     Boton[0][1]=Boton[0][1]-4;
                   con.setForecolor(CColor::Black);
                     con.setCursor(Boton[0][0], Boton[0][1]);
                     con<<Sprite1;
                 }else if(Boton[0][0]==21 && Boton[0][1]==13){
                      con.setForecolor(CColor::Grey);
                      con.setCursor(Boton[0][0],Boton[0][1]);
                      con<<Sprite1;
                     Boton[0][0]=Boton[0][0]+3;
                     Boton[0][1]=Boton[0][1]+4;
                    con.setForecolor(CColor::Black);
                      con.setCursor(Boton[0][0], Boton[0][1]);
                     con<<Sprite1;
                 }else if(Boton[0][0]==24 &&Boton[0][1]==17){
                       con.setForecolor(CColor::Grey);
                      con.setCursor(Boton[0][0],Boton[0][1]);
                      con<<Sprite1;
                    Boton[0][0]=Boton[0][0]-6;
                    con.setForecolor(CColor::Black);
                     con.setCursor(Boton[0][0], Boton[0][1]);
                     con<<Sprite1;
                 }
                    break;
                       case SDLK_e:
                     if(Boton[0][0]==18 && Boton[0][1]==17){
                      VideoJuego();
                    }else if(Boton[0][0]==21 && Boton[0][1]==13){
                      Estadisticas();
                    } else if(Boton[0][0]==23 && Boton[0][1]==17){
                         SalirPrograma=true;
                }
                  break;
                    default:
                   break;
            }
            con.refresh();
        }
        EfectoParpadeo();
     }
}

void SlidingPuzzle::EfectoParpadeo(){
        con.setForecolor(CColor::Black);
        con.setCursor(16,16);
        con<<"Presione \"e\"";
        con.delayMs(500);
        con.setCursor(16,16);
        con<<"            ";
        con.delayMs(500);
}

void SlidingPuzzle::VideoJuego(){
  SalirVideojuego=false;
  DetenerCronometro=false;
  Segundos =0;
  Contador=0;
  con.clearScreen();
  DibujarTablero();
  PosicionPiezasPorDefecto();
 if(TableroAleatorio==1){
     DibujarPiezas();
 }
 else if(TableroAleatorio==2){
     PosicionPiezas2();
     DibujarPiezas();
 }else if(TableroAleatorio==3)
 {
     PosicionPiezas3();
     DibujarPiezas();
 }
 con.setForecolor(CColor::White);
 con.setCursor(13,30);
 con<<"Iniciando en ";
  con.setCursor(14,36);
 con<<"5";
 con.delayMs(1000);
  con.setCursor(14,36);
 con<<"4";
 con.delayMs(1000);
 con.setCursor(14,36);
 con<<"3";
 con.delayMs(1000);
 con.setCursor(14,36);
 con<<"2";
 con.delayMs(1000);
 con.setCursor(14,36);
 con<<"1";
 con.delayMs(1000);
 con.setCursor(13,30);
 con<<"             ";
 con.setCursor(14,34);
 con<<"AREE!";
 con.delayMs(1000);
 con.setForecolor(CColor::Grey);
 con.setCursor(13,30);
 con.setCursor(14,34);
 con<<"      ";
   while(!SalirVideojuego){
        uint32_t key = con.getKey();    
        if (key != SDLK_UNKNOWN) {
            switch (key) {
                case SDLK_LEFT:
                 MoverIzquierda();
                  ImprimirContador();
                     con.flushKeybuffer();
                     break;
                case SDLK_RIGHT:
                 MoverDerecha();
                 ImprimirContador();
                    con.flushKeybuffer();
                    break;
                case SDLK_UP:
                    MoverArriba();
                    ImprimirContador();
                       con.flushKeybuffer();
                         break;
                       case SDLK_DOWN:
                            MoverAbajo();
                            ImprimirContador();
                               con.flushKeybuffer();
                            break;
                        case SDLK_s:
                                GuardarEstadistica();
                                SalirVideojuego=true;
                                DetenerCronometro=true;
                            break;
                     default:
                    break;
            }
            con.refresh();
        }
         Cronometro();
       }
     con.clearScreen();
    CargarMenuPrincipal();
}

void SlidingPuzzle::DibujarTablero(){
     con.setBackcolor(CColor::Grey);
     con.setCursor(1,1);
     con.setForecolor(CColor::Maroon);
    for (int i = 0; i < 28; i++)//1 columna
    {
          con.setCursor(i,0);//i es la fila y 0 es la columna
          con<<Sprite1;
     }   
 for (int i = 1; i < 27; i++)//2 columna
    {
          con.setCursor(i,9);//i es la fila y 6 es la columna
          con<<Sprite1;
          con.setCursor(i,18);//i es la fila y 18 es la columna
          con<<Sprite1;
          con.setCursor(i,27);//i es la fila y 27 es la columna
          con<<Sprite1;
     }  
      for (int i = 1; i < 28; i++)//1 fila
    {
          con.setCursor(0,i);// 0 es la fila e i es la columna
          con<<Sprite1;
           con.setCursor(9,i);// 9 es la fila e i es la columna
          con<<Sprite1;
          con.setCursor(18,i);// 18 es la fila e i es la columna
          con<<Sprite1;
           con.setCursor(27,i);// 27 es la fila e i es la columna
          con<<Sprite1;
     }   
     con.setForecolor(CColor::Aqua);
     for (int i = 1; i < 9; i++){//Dibujo de color aqua el fondo alrededor de los numeros posicion 1
     con.setCursor(i,1);
     con<<Sprite7;
      }
      for (int i = 10; i < 18; i++){//Dibujo de color aqua el fondo alrededor de los numeros posicion 4
     con.setCursor(i,1);
     con<<Sprite7;
      }
      for (int i = 19; i < 27; i++){//Dibujo de color aqua el fondo alrededor de los numeros posicion 7
     con.setCursor(i,1);
     con<<Sprite7;
      }
     for (int i = 1; i < 9; i++){//Dibujo de color aqua el fondo alrededor de los numeros posicion 2
     con.setCursor(i,10);
     con<<Sprite7;
      }
      for (int i = 10; i < 18; i++){//Dibujo de color aqua el fondo alrededor de los numeros posicion 5
     con.setCursor(i,10);
     con<<Sprite7;
      }
      for (int i = 19; i < 27; i++){//Dibujo de color aqua el fondo alrededor de los numeros posicion 8
     con.setCursor(i,10);
     con<<Sprite7;
      }
     for (int i = 1; i < 9; i++){//Dibujo de color aqua el fondo alrededor de los numeros posicion 3
     con.setCursor(i,19);
     con<<Sprite7;
      }
      for (int i = 10; i < 18; i++){//Dibujo de color aqua el fondo alrededor de los numeros posicion 6
     con.setCursor(i,19);
     con<<Sprite7;
      }
      for (int i = 19; i < 27; i++){//Dibujo de color aqua el fondo alrededor de los numeros posicion 9
     con.setCursor(i,19);
     con<<Sprite7;
      }
      DibujarMarcoPequeno();
     con.setForecolor(CColor::White);
     con.setCursor(2,29);
     con<<"Tiempo (s)";
     con.setCursor(3,29);
     con<<"Movimientos:";
     con.setCursor(3,41);
     con<<"0";
     con.setCursor(26,34);
     con<<" \"s\"=salir";
}

void SlidingPuzzle::DibujarMarcoPequeno(){
      con.setForecolor(CColor::Black);
      for (int i = 29; i < 44; i++)//por defecto los marcos los genera en color negro, linea horizontal arriba
     {
     con.setCursor(0,i);
     con<<Sprite5;
     }
     for (int i = 1; i < 27; i++)//por defecto los marcos los genera en color negro, linea vertical izquierda
     {
     con.setCursor(i,28);
     con<<Sprite3;
     }
     for (int i = 29; i < 44; i++)//por defecto los marcos los genera en color negro, linea horizontal abajo
     {
     con.setCursor(27,i);
     con<<Sprite2;
     }
     for (int i = 1; i < 27; i++)//por defecto los marcos los genera en color negro, linea vertical derecha
     {
     con.setCursor(i,44);
     con<<Sprite4;
     }
}
void SlidingPuzzle::DibujarMarcoGrande(){
     con.setForecolor(CColor::Black);
     for (int i = 1; i < 44; i++)//por defecto los marcos los genera en color negro, linea horizontal arriba
     {
     con.setCursor(0,i);
     con<<Sprite5;
     }
     for (int i = 1; i < 27; i++)//por defecto los marcos los genera en color negro, linea vertical izquierda
     {
     con.setCursor(i,0);
     con<<Sprite3;
     }

     for (int i = 1; i < 44; i++)//por defecto los marcos los genera en color negro, linea horizontal abajo
     {
     con.setCursor(27,i);
     con<<Sprite2;
     }
     for (int i = 1; i < 27; i++)//por defecto los marcos los genera en color negro, linea vertical derecha
     {
     con.setCursor(i,44);
     con<<Sprite4;
     }
}

void SlidingPuzzle::PosicionPiezas2(){
   for (int i = 0; i < 9; i++)
  {
       PiezaVacia[i][0]=PiezaVacia[i][0]-18;
       PiezaVacia[i][1]=PiezaVacia[i][1]-18;
  }

  for (int i = 0; i < 7; i++)
  {
       Pieza1[i][0]=Pieza1[i][0]+9;
  }
  for (int i = 0; i < 21; i++)
  {
             Pieza2[i][0]=Pieza2[i][0]-18;
  }
  for (int i = 0; i < 21; i++)
  {
             Pieza3[i][0]=Pieza3[i][0]+9;
             Pieza3[i][1]=Pieza3[i][1]-18;
  }
  for (int i = 0; i < 13; i++)
  {
             Pieza4[i][1]=Pieza4[i][1]+9;
  }
  for (int i = 0; i < 22; i++)
    {
               Pieza5[i][0]=Pieza5[i][0]+9;
    }
  
  for (int i = 0; i < 23; i++)
    {
               Pieza6[i][0]=Pieza6[i][0]+9;
                 Pieza6[i][1]=Pieza6[i][1]-9;
    }
  
  for (int i = 0; i < 11; i++)
    {
               Pieza7[i][0]=Pieza7[i][0]+9;
               Pieza7[i][1]=Pieza7[i][1]+18;
    }
  
  for (int i = 0; i < 26; i++)
    {
               Pieza8[i][0]=Pieza8[i][0]-9;
               Pieza8[i][1]=Pieza8[i][1]+18;
    }
}

void SlidingPuzzle::PosicionPiezas3(){

  for (int i = 0; i < 9; i++)
  {
       PiezaVacia[i][0]=PiezaVacia[i][0]-18;
       PiezaVacia[i][1]=PiezaVacia[i][1]-18;
  }

  for (int i = 0; i < 7; i++)
  {
       Pieza1[i][0]=Pieza1[i][0]-9;
  }
  for (int i = 0; i < 21; i++)
  {
             Pieza2[i][1]=Pieza2[i][1]+9;
  }

  for (int i = 0; i < 21; i++)
  {
             Pieza3[i][0]=Pieza3[i][0]+9;
  }
  //La pieza 4 la dejamos en la misma posicion
  for (int i = 0; i < 22; i++)
    {
               Pieza5[i][0]=Pieza5[i][0]+9;
               Pieza5[i][1]=Pieza5[i][1]-9;
    }
  
  for (int i = 0; i < 23; i++)
    {
               Pieza6[i][0]=Pieza6[i][0]-9;
    }
  
  for (int i = 0; i < 11; i++)
    {
               Pieza7[i][0]=Pieza7[i][0]+9;
               Pieza7[i][1]=Pieza7[i][1]+9;
    }
  
  for (int i = 0; i < 26; i++)
    {
               Pieza8[i][0]=Pieza8[i][0]+9;
               Pieza8[i][1]=Pieza8[i][1]+9;
    }
}

void SlidingPuzzle::PosicionPiezasPorDefecto(){
     //Dibujamos la pieza 0 por defecto en la posicion 6;
     PiezaVacia[0][0]=20;
     PiezaVacia[0][1]=25;
     PiezaVacia[1][0]=19;
     PiezaVacia[1][1]=19;
     PiezaVacia[2][0]=20;
     PiezaVacia[2][1]=19;
     PiezaVacia[3][0]=21;
     PiezaVacia[3][1]=19;
     PiezaVacia[4][0]=22;
     PiezaVacia[4][1]=19;
     PiezaVacia[5][0]=23;
     PiezaVacia[5][1]=19;
     PiezaVacia[6][0]=24;
     PiezaVacia[6][1]=19;
     PiezaVacia[7][0]=25;
     PiezaVacia[7][1]=19;
     PiezaVacia[8][0]=26;
     PiezaVacia[8][1]=19;
     //Dibujamos pieza 1 por defecto en la posicion 6
      Pieza1[0][0]=11;
      Pieza1[0][1]=25;
      Pieza1[1][0]=12;
      Pieza1[1][1]=25;
      Pieza1[2][0]=13;
      Pieza1[2][1]=25;
      Pieza1[3][0]=14;
      Pieza1[3][1]=25;
      Pieza1[4][0]=15;
      Pieza1[4][1]=25;
      Pieza1[5][0]=16;
      Pieza1[5][1]=25;
      Pieza1[6][0]=11;
      Pieza1[6][1]=24;
     //Dibujamos pieza 2 por defecto en la posicion 8
      Pieza2[0][0]=20;//x
      Pieza2[0][1]=11;//y
      Pieza2[1][0]=20;
      Pieza2[1][1]=12;
      Pieza2[2][0]=20;//x
      Pieza2[2][1]=13;//y
      Pieza2[3][0]=20;
      Pieza2[3][1]=14;
      Pieza2[4][0]=20;
      Pieza2[4][1]=15;
      Pieza2[5][0]=20;//aqui referencia para mover
      Pieza2[5][1]=16;//aqui referencia para mover
      Pieza2[6][0]=21;
      Pieza2[6][1]=16;
      Pieza2[7][0]=22;
      Pieza2[7][1]=16;
      Pieza2[8][0]=22;
      Pieza2[8][1]=15;
      Pieza2[9][0]=22;
      Pieza2[9][1]=14;
      Pieza2[10][0]=22;
      Pieza2[10][1]=13;
      Pieza2[11][0]=22;
      Pieza2[11][1]=12;
      Pieza2[12][0]=22;
      Pieza2[12][1]=11;
      Pieza2[13][0]=23;
      Pieza2[13][1]=11;
      Pieza2[14][0]=24;
      Pieza2[14][1]=11;
      Pieza2[15][0]=25;
      Pieza2[15][1]=11;
      Pieza2[16][0]=25;
      Pieza2[16][1]=12;
      Pieza2[17][0]=25;
      Pieza2[17][1]=13;
      Pieza2[18][0]=25;
      Pieza2[18][1]=14;
      Pieza2[19][0]=25;
      Pieza2[19][1]=15;
      Pieza2[20][0]=25;
      Pieza2[20][1]=16;
      //Dibujamos la pieza 3 por defecto en la posicion 3
      Pieza3[0][0]=2;
      Pieza3[0][1]=20;
      Pieza3[1][0]=2;
      Pieza3[1][1]=21;
      Pieza3[2][0]=2;
      Pieza3[2][1]=22;
      Pieza3[3][0]=2;
      Pieza3[3][1]=23;
      Pieza3[4][0]=2;
      Pieza3[4][1]=24;
      Pieza3[5][0]=2;//aqui referncia para mover
      Pieza3[5][1]=25;//aqui referencia para mover
      Pieza3[6][0]=3;
      Pieza3[6][1]=25;
      Pieza3[7][0]=4;
      Pieza3[7][1]=25;
      Pieza3[8][0]=5;
      Pieza3[8][1]=25;
      Pieza3[9][0]=6;
      Pieza3[9][1]=25;
      Pieza3[10][0]=7;
      Pieza3[10][1]=25;
      Pieza3[11][0]=4;
      Pieza3[11][1]=20;
      Pieza3[12][0]=4;
      Pieza3[12][1]=21;
      Pieza3[13][0]=4;
      Pieza3[13][1]=22;
      Pieza3[14][0]=4;
      Pieza3[14][1]=23;
      Pieza3[15][0]=4;
      Pieza3[15][1]=24;
      Pieza3[16][0]=7;
      Pieza3[16][1]=20;
      Pieza3[17][0]=7;
      Pieza3[17][1]=21;
       Pieza3[18][0]=7;
      Pieza3[18][1]=22;
       Pieza3[19][0]=7;
      Pieza3[19][1]=23;
       Pieza3[20][0]=7;
      Pieza3[20][1]=24;
      //Dibujamos la pieza 4 por defecto en la posicion 7
      Pieza4[0][0]=20;
      Pieza4[0][1]=2;
      Pieza4[1][0]=21;
      Pieza4[1][1]=2;
      Pieza4[2][0]=22;
      Pieza4[2][1]=2;
      Pieza4[3][0]=22;
      Pieza4[3][1]=3;
      Pieza4[4][0]=22;
      Pieza4[4][1]=4;
      Pieza4[5][0]=22;
      Pieza4[5][1]=5;
      Pieza4[6][0]=22;
      Pieza4[6][1]=6;
      Pieza4[7][0]=20;//aqui referencia para mover
      Pieza4[7][1]=7;//aqui refernencia para mover
       Pieza4[8][0]=21;
      Pieza4[8][1]=7;
       Pieza4[9][0]=22;
      Pieza4[9][1]=7;
       Pieza4[10][0]=23;
      Pieza4[10][1]=7;
       Pieza4[11][0]=24;
      Pieza4[11][1]=7;
       Pieza4[12][0]=25;
      Pieza4[12][1]=7;    
      //Dibujamos la pieza 5 por defecto en la posicion 2
      Pieza5[0][0]=2;//aqui referencia para mover
      Pieza5[0][1]=16;//aqui referencia para mover
      Pieza5[1][0]=2;
      Pieza5[1][1]=15;
      Pieza5[2][0]=2;
      Pieza5[2][1]=14;
      Pieza5[3][0]=2;
      Pieza5[3][1]=13;
      Pieza5[4][0]=2;
      Pieza5[4][1]=12;
      Pieza5[5][0]=2;
      Pieza5[5][1]=11;
      Pieza5[6][0]=3;
      Pieza5[6][1]=11;
       Pieza5[7][0]=4;
      Pieza5[7][1]=11;
       Pieza5[8][0]=4;
      Pieza5[8][1]=12;
       Pieza5[9][0]=4;
      Pieza5[9][1]=13;
       Pieza5[10][0]=4;
      Pieza5[10][1]=14;
       Pieza5[11][0]=4;
      Pieza5[11][1]=15;
       Pieza5[12][0]=4;
      Pieza5[12][1]=16;
       Pieza5[13][0]=5;
      Pieza5[13][1]=16;
       Pieza5[14][0]=6;
      Pieza5[14][1]=16;
       Pieza5[15][0]=7;
      Pieza5[15][1]=16;
       Pieza5[16][0]=7;
      Pieza5[16][1]=16;
       Pieza5[17][0]=7;
      Pieza5[17][1]=15;
       Pieza5[18][0]=7;
      Pieza5[18][1]=14;
       Pieza5[19][0]=7;
      Pieza5[19][1]=13;
       Pieza5[20][0]=7;
      Pieza5[20][1]=12;
       Pieza5[21][0]=7;
      Pieza5[21][1]=11;
      //Dibujamos la pieza 6 por defecto en la posicion 5
      Pieza6[0][0]=11;//aqui referencia para mover
      Pieza6[0][1]=16;//aqui referencia para mover
      Pieza6[1][0]=11;
      Pieza6[1][1]=15;
      Pieza6[2][0]=11;
      Pieza6[2][1]=14;
      Pieza6[3][0]=11;
      Pieza6[3][1]=13;
      Pieza6[4][0]=11;
      Pieza6[4][1]=12;
      Pieza6[5][0]=11;
      Pieza6[5][1]=11;
      Pieza6[6][0]=12;
      Pieza6[6][1]=11;
      Pieza6[7][0]=13;
      Pieza6[7][1]=11;
      Pieza6[8][0]=14;
      Pieza6[8][1]=11;
      Pieza6[9][0]=15;
      Pieza6[9][1]=11;
      Pieza6[10][0]=16;
      Pieza6[10][1]=11;
      Pieza6[11][0]=16;
      Pieza6[11][1]=12;
      Pieza6[12][0]=16;
      Pieza6[12][1]=13;
      Pieza6[13][0]=16;
      Pieza6[13][1]=14;
      Pieza6[14][0]=16;
      Pieza6[14][1]=15;
      Pieza6[15][0]=16;
      Pieza6[15][1]=16;
      Pieza6[16][0]=15;
      Pieza6[16][1]=16;
      Pieza6[17][0]=14;
      Pieza6[17][1]=16;
      Pieza6[18][0]=13;
      Pieza6[18][1]=16;
      Pieza6[19][0]=13;
      Pieza6[19][1]=15;
      Pieza6[20][0]=13;
      Pieza6[20][1]=14;
      Pieza6[21][0]=13;
      Pieza6[21][1]=13;
      Pieza6[22][0]=13;
      Pieza6[22][1]=12;
     //Dibujamos la pieza 7 por defecto en la posicion 1
     Pieza7[0][0]=2;
     Pieza7[0][1]=2;
    Pieza7[1][0]=2;
     Pieza7[1][1]=3;
      Pieza7[2][0]=2;
     Pieza7[2][1]=4;
      Pieza7[3][0]=2;
     Pieza7[3][1]=5;
      Pieza7[4][0]=2;
     Pieza7[4][1]=6;
      Pieza7[5][0]=2; //aqui referencia para mover
     Pieza7[5][1]=7;//aqui referencia para mover
     Pieza7[6][0]=3;
     Pieza7[6][1]=7;
      Pieza7[7][0]=4;
     Pieza7[7][1]=7;
      Pieza7[8][0]=5;
     Pieza7[8][1]=7;
      Pieza7[9][0]=6;
     Pieza7[9][1]=7;
      Pieza7[10][0]=7;
      Pieza7[10][1]=7;
      //Dibujamos la pieza 8 por defecto en la posicion 4
      Pieza8[0][0]=11;
      Pieza8[0][1]=2;
      Pieza8[1][0]=11;
      Pieza8[1][1]=3;
      Pieza8[2][0]=11;
      Pieza8[2][1]=4;
      Pieza8[3][0]=11;
      Pieza8[3][1]=5;
      Pieza8[4][0]=11;
      Pieza8[4][1]=6;
      Pieza8[5][0]=11;//aqui referencia para mover
      Pieza8[5][1]=7;//aqui referencia para mover
      Pieza8[6][0]=11;
      Pieza8[6][1]=7;
      Pieza8[7][0]=12;
      Pieza8[7][1]=7;
      Pieza8[8][0]=13;
      Pieza8[8][1]=7;
      Pieza8[9][0]=14;
      Pieza8[9][1]=7;
      Pieza8[10][0]=15;
      Pieza8[10][1]=7;
      Pieza8[11][0]=16;
      Pieza8[11][1]=7;
      Pieza8[12][0]=16;
      Pieza8[12][1]=6;
      Pieza8[13][0]=16;
      Pieza8[13][1]=5;
      Pieza8[14][0]=16;
      Pieza8[14][1]=4;
      Pieza8[15][0]=16;
      Pieza8[15][1]=3;
      Pieza8[16][0]=16;
      Pieza8[16][1]=2;
      Pieza8[17][0]=15;
      Pieza8[17][1]=2;
      Pieza8[18][0]=14;
      Pieza8[18][1]=2;
      Pieza8[19][0]=13;
      Pieza8[19][1]=2;
      Pieza8[20][0]=12;
      Pieza8[20][1]=2;
      Pieza8[21][0]=12;
      Pieza8[21][1]=2;
      Pieza8[22][0]=13;
      Pieza8[22][1]=3;
      Pieza8[23][0]=13;
      Pieza8[23][1]=4;
      Pieza8[24][0]=13;
      Pieza8[24][1]=5;
      Pieza8[25][0]=13;
      Pieza8[25][1]=6;
     //Cargamos la pieza 9 sin dibujarla hasta que el jugador gane
      Pieza9[0][0]=20;
      Pieza9[0][1]=20;
      Pieza9[1][0]=20;
      Pieza9[1][1]=21;
      Pieza9[2][0]=20;
      Pieza9[2][1]=22;
      Pieza9[3][0]=20;
      Pieza9[3][1]=23;
      Pieza9[4][0]=20;
      Pieza9[4][1]=24;
      Pieza9[5][0]=20;//aqui referencia para mover
      Pieza9[5][1]=25;//aqui referencia para mover
      Pieza9[6][0]=21;
      Pieza9[6][1]=25;
      Pieza9[7][0]=22;
      Pieza9[7][1]=25;
      Pieza9[8][0]=23;
      Pieza9[8][1]=25;
      Pieza9[9][0]=24;
      Pieza9[9][1]=25;
      Pieza9[10][0]=25;
      Pieza9[10][1]=25;
      Pieza9[11][0]=25;
      Pieza9[11][1]=24;
      Pieza9[12][0]=25;
      Pieza9[12][1]=23;
      Pieza9[13][0]=25;
      Pieza9[13][1]=22;
      Pieza9[14][0]=25;
      Pieza9[14][1]=21;
      Pieza9[15][0]=25;
      Pieza9[15][1]=20;
      Pieza9[16][0]=21;
      Pieza9[16][1]=20;
      Pieza9[17][0]=22;
      Pieza9[17][1]=20;
      Pieza9[18][0]=22;
      Pieza9[18][1]=20;
      Pieza9[19][0]=22;
      Pieza9[19][1]=21;
      Pieza9[20][0]=22;
      Pieza9[20][1]=22;
      Pieza9[21][0]=22;
      Pieza9[21][1]=23;
      Pieza9[22][0]=22;
      Pieza9[22][1]=24; 
}

void SlidingPuzzle::DibujarPiezas(){
     //Pieza1
     con.setForecolor(ColorPieza);
     for (int i = 0; i <7; i++)
     {
    con.setCursor(Pieza1[i][0], Pieza1[i][1]);  
    con<<Sprite1;   
     }
     //Pieza2
     con.setForecolor(ColorPieza);
     for (int i = 0; i <21; i++)
     {
    con.setCursor(Pieza2[i][0], Pieza2[i][1]);  
    con<<Sprite1;   
     }
     //Pieza3
     con.setForecolor(ColorPieza);
     for (int i = 0; i <21; i++)
     {
    con.setCursor(Pieza3[i][0], Pieza3[i][1]);  
    con<<Sprite1;   
     }
     //Pieza4
     con.setForecolor(ColorPieza);
     for (int i = 0; i <13; i++)
     {
    con.setCursor(Pieza4[i][0], Pieza4[i][1]);  
    con<<Sprite1;   
     }
     //Pieza5
     con.setForecolor(ColorPieza);
     for (int i = 0; i <22; i++)
     {
    con.setCursor(Pieza5[i][0], Pieza5[i][1]);  
    con<<Sprite1;   
     }

     //Pieza6
     con.setForecolor(ColorPieza);
     for (int i = 0; i <23; i++)
     {
    con.setCursor(Pieza6[i][0], Pieza6[i][1]);  
    con<<Sprite1;   
     }
     //Pieza7
     con.setForecolor(ColorPieza);
     for (int i = 0; i <11; i++)
     {
    con.setCursor(Pieza7[i][0], Pieza7[i][1]);  
    con<<Sprite1;   
     }
     //Pieza8
     con.setForecolor(ColorPieza);
     for (int i = 0; i <26; i++)
     {
    con.setCursor(Pieza8[i][0], Pieza8[i][1]);  
    con<<Sprite1;   
     }
     //PiezaVacia
     con.setForecolor(ColorPiezaVacia);
     for (int i = 1; i <9; i++)
     {
    con.setCursor(PiezaVacia[i][0], PiezaVacia[i][1]);  
    con<<Sprite7;   
     }
     con.refresh();
}

void SlidingPuzzle::MoverIzquierda(){
               if(Pieza1[0][0]==2&& Pieza1[0][1]==25 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza1(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza1[0][0]==11&& Pieza1[0][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza1(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza1[0][0]==20&& Pieza1[0][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza1(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza1[0][0]==2&& Pieza1[0][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==7){
                     MoverPieza1(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza1[0][0]==11&& Pieza1[0][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                     MoverPieza1(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza1[0][0]==20&& Pieza1[0][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza1(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else //////////////
                if(Pieza2[5][0]==2&& Pieza2[5][1]==25 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza2(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza2[5][0]==11&& Pieza2[5][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza2(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza2[5][0]==20&& Pieza2[5][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza2(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza2[5][0]==2&& Pieza2[5][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==7){
                     MoverPieza2(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza2[5][0]==11&& Pieza2[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                     MoverPieza2(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza2[5][0]==20&& Pieza2[5][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza2(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else ///////////
                 if(Pieza3[5][0]==2&& Pieza3[5][1]==25 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza3(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza3[5][0]==11&& Pieza3[5][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza3(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza3[5][0]==20&& Pieza3[5][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza3(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza3[5][0]==2&& Pieza3[5][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==7){
                     MoverPieza3(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza3[5][0]==11&& Pieza3[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                     MoverPieza3(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza3[5][0]==20&& Pieza3[5][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza3(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else //////////////
                 if(Pieza4[7][0]==2 && Pieza4[7][1]==25 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza4(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza4[7][0]==11&& Pieza4[7][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza4(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza4[7][0]==20&& Pieza4[7][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza4(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza4[7][0]==2 && Pieza4[7][1]==16 && PiezaVacia[0][0]== 2 &&PiezaVacia[0][1]==7){
                     MoverPieza4(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza4[7][0]==11&& Pieza4[7][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                     MoverPieza4(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza4[7][0]==20&& Pieza4[7][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza4(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else ////////////////

                 if(Pieza5[0][0]==2&& Pieza5[0][1]==25 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza5(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza5[0][0]==11&& Pieza5[0][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza5(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza5[0][0]==20&& Pieza5[0][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza5(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza5[0][0]==2&& Pieza5[0][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==7){
                     MoverPieza5(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza5[0][0]==11&& Pieza5[0][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                     MoverPieza5(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza5[0][0]==20&& Pieza5[0][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza5(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else ////////////////
                if(Pieza6[0][0]==2&& Pieza6[0][1]==25 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza6(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza6[0][0]==11&& Pieza6[0][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza6(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza6[0][0]==20&& Pieza6[0][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza6(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza6[0][0]==2&& Pieza6[0][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==7){
                     MoverPieza6(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza6[0][0]==11&& Pieza6[0][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                     MoverPieza6(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza6[0][0]==20&& Pieza6[0][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza6(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else //////////////
                  if(Pieza7[5][0]==2&& Pieza7[5][1]==25 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza7(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza7[5][0]==11&& Pieza7[5][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza7(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza7[5][0]==20&& Pieza7[5][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza7(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza7[5][0]==2&& Pieza7[5][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==7){
                     MoverPieza7(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza7[5][0]==11&& Pieza7[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                     MoverPieza7(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza7[5][0]==20&& Pieza7[5][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza7(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else //////////////////
                 if(Pieza8[5][0]==2&& Pieza8[5][1]==25 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza8(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza8[5][0]==11&& Pieza8[5][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza8(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza8[5][0]==20&& Pieza8[5][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza8(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza8[5][0]==2&& Pieza8[5][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==7){
                     MoverPieza8(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza8[5][0]==11&& Pieza8[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                     MoverPieza8(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }else if(Pieza8[5][0]==20&& Pieza8[5][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza8(XInmovil, MoverHaciaIzquierda, XInmovil, MoverHaciaDerecha);
                }
}

void SlidingPuzzle::MoverDerecha(){
                    if(Pieza1[0][0]==2&& Pieza1[0][1]==7 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza1(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza1[0][0]==11&& Pieza1[0][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza1(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza1[0][0]==20&& Pieza1[0][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza1(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza1[0][0]==2&& Pieza1[0][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==25){
                     MoverPieza1(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza1[0][0]==11&& Pieza1[0][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza1(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza1[0][0]==20&& Pieza1[0][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza1(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else///////////
                if(Pieza2[5][0]==2&& Pieza2[5][1]==7 && PiezaVacia[0][0]==2 && PiezaVacia[0][1]==16){
                  MoverPieza2(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza2[5][0]==11&& Pieza2[5][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza2(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza2[5][0]==20&& Pieza2[5][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza2(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza2[5][0]==2&& Pieza2[5][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==25){
                     MoverPieza2(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza2[5][0]==11&& Pieza2[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza2(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza2[5][0]==20&& Pieza2[5][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza2(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else////////////
                 if(Pieza3[5][0]==2&& Pieza3[5][1]==7 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza3(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza3[5][0]==11&& Pieza3[5][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza3(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza3[5][0]==20&& Pieza3[5][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza3(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza3[5][0]==2&& Pieza3[5][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==25){
                     MoverPieza3(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza3[5][0]==11&& Pieza3[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza3(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza3[5][0]==20&& Pieza3[5][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza3(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else /////////777
                 if(Pieza4[7][0]==2&& Pieza4[7][1]==7 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza4(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza4[7][0]==11&& Pieza4[7][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza4(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza4[7][0]==20&& Pieza4[7][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza4(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza4[7][0]==2&& Pieza4[7][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==25){
                     MoverPieza4(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza4[7][0]==11&& Pieza4[7][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza4(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza4[7][0]==20&& Pieza4[7][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza4(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else////////////

                 if(Pieza5[0][0]==2&& Pieza5[0][1]==7 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza5(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza5[0][0]==11&& Pieza5[0][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza5(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza5[0][0]==20&& Pieza5[0][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza5(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza5[0][0]==2&& Pieza5[0][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==25){
                     MoverPieza5(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza5[0][0]==11&& Pieza5[0][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza5(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza5[0][0]==20&& Pieza5[0][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza5(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else /////////////
                if(Pieza6[0][0]==2&& Pieza6[0][1]==7 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza6(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza6[0][0]==11&& Pieza6[0][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza6(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza6[0][0]==20&& Pieza6[0][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza6(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza6[0][0]==2&& Pieza6[0][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==25){
                     MoverPieza6(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza6[0][0]==11&& Pieza6[0][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza6(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza6[0][0]==20&& Pieza6[0][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza6(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else ////////////////
                  if(Pieza7[5][0]==2&& Pieza7[5][1]==7 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza7(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza7[5][0]==11&& Pieza7[5][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza7(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza7[5][0]==20&& Pieza7[5][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza7(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza7[5][0]==2&& Pieza7[5][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==25){
                     MoverPieza7(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza7[5][0]==11&& Pieza7[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza7(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza7[5][0]==20&& Pieza7[5][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza7(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else //////////////////
                 if(Pieza8[5][0]==2&& Pieza8[5][1]==7 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                  MoverPieza8(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza8[5][0]==11&& Pieza8[5][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza8(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza8[5][0]==20&& Pieza8[5][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza8(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza8[5][0]==2&& Pieza8[5][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==25){
                     MoverPieza8(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza8[5][0]==11&& Pieza8[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza8(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }else if(Pieza8[5][0]==20&& Pieza8[5][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza8(XInmovil, MoverHaciaDerecha, XInmovil, MoverHaciaIzquierda);
                }
}

void SlidingPuzzle::MoverArriba(){
            if(Pieza1[0][0]==20&& Pieza1[0][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                  MoverPieza1(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza1[0][0]==20&& Pieza1[0][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza1(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza1[0][0]==20&& Pieza1[0][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza1(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza1[0][0]==11&& Pieza1[0][1]==7 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==7){
                     MoverPieza1(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza1[0][0]==11&& Pieza1[0][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                     MoverPieza1(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza1[0][0]==11&& Pieza1[0][1]==25 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==25){
                     MoverPieza1(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else///////////
                if(Pieza2[5][0]==20&& Pieza2[5][1]==7 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==7){
                  MoverPieza2(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza2[5][0]==20&& Pieza2[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza2(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza2[5][0]==20&& Pieza2[5][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza2(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza2[5][0]==11&& Pieza2[5][1]==7 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==7){
                     MoverPieza2(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza2[5][0]==11&& Pieza2[5][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                     MoverPieza2(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza2[5][0]==11&& Pieza2[5][1]==25 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==25){
                     MoverPieza2(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else////////////
                 if(Pieza3[5][0]==20&& Pieza3[5][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                  MoverPieza3(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza3[5][0]==20&& Pieza3[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza3(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza3[5][0]==20&& Pieza3[5][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza3(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza3[5][0]==11&& Pieza3[5][1]==7 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==7){
                     MoverPieza3(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza3[5][0]==11&& Pieza3[5][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                     MoverPieza3(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza3[5][0]==11&& Pieza3[5][1]==25 && PiezaVacia[0][0]==2 && PiezaVacia[0][1]==25){
                     MoverPieza3(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else /////////777
                 if(Pieza4[7][0]==20 && Pieza4[7][1]==7 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==7){
                  MoverPieza4(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza4[7][0]==20 && Pieza4[7][1]==16 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==16){
                     MoverPieza4(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza4[7][0]==20 && Pieza4[7][1]==25 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==25){
                     MoverPieza4(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza4[7][0]==11 && Pieza4[7][1]==7 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==7){
                     MoverPieza4(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza4[7][0]==11 && Pieza4[7][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                     MoverPieza4(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza4[7][0]==11 && Pieza4[7][1]==25 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==25){
                     MoverPieza4(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else////////////
                 if(Pieza5[0][0]==20 && Pieza5[0][1]==7 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==7){
                  MoverPieza5(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza5[0][0]==20 && Pieza5[0][1]==16 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==16){
                     MoverPieza5(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza5[0][0]==20 && Pieza5[0][1]==25 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==25){
                     MoverPieza5(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza5[0][0]==11 && Pieza5[0][1]==7 && PiezaVacia[0][0]==2 && PiezaVacia[0][1]==7){
                     MoverPieza5(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza5[0][0]==11 && Pieza5[0][1]==16 && PiezaVacia[0][0]==2 && PiezaVacia[0][1]==16){
                     MoverPieza5(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza5[0][0]==11 && Pieza5[0][1]==25 && PiezaVacia[0][0]==2 && PiezaVacia[0][1]==25){
                     MoverPieza5(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else /////////////
                if(Pieza6[0][0]==20 && Pieza6[0][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                  MoverPieza6(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza6[0][0]==20 && Pieza6[0][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza6(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza6[0][0]==20 && Pieza6[0][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza6(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza6[0][0]==11 && Pieza6[0][1]==7 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==7){
                     MoverPieza6(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza6[0][0]==11 && Pieza6[0][1]==16 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==16){
                     MoverPieza6(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza6[0][0]==11 && Pieza6[0][1]==25 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==25){
                     MoverPieza6(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else ////////////////
                  if(Pieza7[5][0]==20 && Pieza7[5][1]==7 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==7){
                  MoverPieza7(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza7[5][0]==20 && Pieza7[5][1]==16 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==16){
                     MoverPieza7(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza7[5][0]==20 && Pieza7[5][1]==25 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==25){
                     MoverPieza7(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza7[5][0]==11 && Pieza7[5][1]==7 && PiezaVacia[0][0]==2 && PiezaVacia[0][1]==7){
                     MoverPieza7(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza7[5][0]==11 && Pieza7[5][1]==16 && PiezaVacia[0][0]==2 && PiezaVacia[0][1]==16){
                     MoverPieza7(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza7[5][0]==11 && Pieza7[5][1]==25 && PiezaVacia[0][0]==2 && PiezaVacia[0][1]==25){
                     MoverPieza7(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else //////////////////
                 if(Pieza8[5][0]==20 && Pieza8[5][1]==7 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==7){
                  MoverPieza8(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza8[5][0]==20 && Pieza8[5][1]==16 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==16){
                     MoverPieza8(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza8[5][0]==20 && Pieza8[5][1]==25 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==25){
                     MoverPieza8(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza8[5][0]==11 && Pieza8[5][1]==7 && PiezaVacia[0][0]==2 &&PiezaVacia[0][1]==7){
                     MoverPieza8(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza8[5][0]==11 && Pieza8[5][1]==16 && PiezaVacia[0][0]==2 && PiezaVacia[0][1]==16){
                     MoverPieza8(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }else if(Pieza8[5][0]==11 && Pieza8[5][1]==25 && PiezaVacia[0][0]==2 && PiezaVacia[0][1]==25){
                     MoverPieza8(MoverHaciaArriba, YInmovil, MoverHaciaAbajo, YInmovil);
                }             
}

void SlidingPuzzle::MoverAbajo(){
               if(Pieza1[0][0]==2 && Pieza1[0][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                  MoverPieza1(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza1[0][0]==2 && Pieza1[0][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza1(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza1[0][0]==2 && Pieza1[0][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza1(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza1[0][0]==11&& Pieza1[0][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza1(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza1[0][0]==11&& Pieza1[0][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza1(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza1[0][0]==11&& Pieza1[0][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza1(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else///////////
                if(Pieza2[5][0]==2&& Pieza2[5][1]==7 && PiezaVacia[0][0]==11 && PiezaVacia[0][1]==7){
                  MoverPieza2(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza2[5][0]==2&& Pieza2[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza2(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza2[5][0]==2&& Pieza2[5][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza2(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza2[5][0]==11&& Pieza2[5][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza2(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza2[5][0]==11&& Pieza2[5][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza2(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza2[5][0]==11&& Pieza2[5][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza2(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else////////////
                 if(Pieza3[5][0]==2 && Pieza3[5][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                  MoverPieza3(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza3[5][0]==2 && Pieza3[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza3(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza3[5][0]==2 && Pieza3[5][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza3(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza3[5][0]==11&& Pieza3[5][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza3(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza3[5][0]==11&& Pieza3[5][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza3(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza3[5][0]==11&& Pieza3[5][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza3(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else /////////777
                 if(Pieza4[7][0]==2&& Pieza4[7][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                  MoverPieza4(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza4[7][0]==2&& Pieza4[7][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza4(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza4[7][0]==2&& Pieza4[7][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza4(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza4[7][0]==11&& Pieza4[7][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza4(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza4[7][0]==11&& Pieza4[7][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza4(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza4[7][0]==11&& Pieza4[7][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza4(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else////////////

                 if(Pieza5[0][0]==2&& Pieza5[0][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                  MoverPieza5(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza5[0][0]==2&& Pieza5[0][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza5(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza5[0][0]==2&& Pieza5[0][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza5(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza5[0][0]==11&& Pieza5[0][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza5(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza5[0][0]==11&& Pieza5[0][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza5(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza5[0][0]==11&& Pieza5[0][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza5(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else /////////////
                if(Pieza6[0][0]==2&& Pieza6[0][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                  MoverPieza6(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza6[0][0]==2&& Pieza6[0][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza6(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza6[0][0]==2&& Pieza6[0][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza6(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza6[0][0]==11&& Pieza6[0][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza6(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza6[0][0]==11&& Pieza6[0][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza6(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza6[0][0]==11&& Pieza6[0][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza6(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else ////////////////
                  if(Pieza7[5][0]==2&& Pieza7[5][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                  MoverPieza7(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza7[5][0]==2&& Pieza7[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza7(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza7[5][0]==2&& Pieza7[5][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza7(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza7[5][0]==11&& Pieza7[5][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza7(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza7[5][0]==11&& Pieza7[5][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza7(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza7[5][0]==11&& Pieza7[5][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza7(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else //////////////////
                 if(Pieza8[5][0]==2&& Pieza8[5][1]==7 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==7){
                  MoverPieza8(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza8[5][0]==2&& Pieza8[5][1]==16 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==16){
                     MoverPieza8(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza8[5][0]==2&& Pieza8[5][1]==25 && PiezaVacia[0][0]==11 &&PiezaVacia[0][1]==25){
                     MoverPieza8(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza8[5][0]==11&& Pieza8[5][1]==7 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==7){
                     MoverPieza8(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza8[5][0]==11&& Pieza8[5][1]==16 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==16){
                     MoverPieza8(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }else if(Pieza8[5][0]==11&& Pieza8[5][1]==25 && PiezaVacia[0][0]==20 &&PiezaVacia[0][1]==25){
                     MoverPieza8(MoverHaciaAbajo, YInmovil, MoverHaciaArriba, YInmovil);
                }
}

//Aqui muevo las piezas

void SlidingPuzzle::MoverPieza1(int x, int y, int XPiezaVacia, int YPiezaVacia){
     int VerificarFilas=Pieza1[0][0]+x;                             //recibe Pa=8 y pn=9
     int VerificarColumnas=Pieza1[0][1]+y;
     if(VerificarFilas<26 && VerificarColumnas<26 )//La pieza debe moverse dentro del tablero la longitud es 26
     {
     if(VerificarFilas>1&&VerificarColumnas>1){
     //Sumo un parametro al arreglo para mover la pieza  hacia abajo o arriba, izquierda o derecha
      for (int i = 0; i < 7; i++)
      {
         Pieza1[i][0]=Pieza1[i][0]+x;
         Pieza1[i][1]=Pieza1[i][1]+y;
      }
       //Por default antes de pintar la pieza a la nueva posicion la dejo con el color del tablero
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorVacio);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
      //Dibujo nuevamente la pieza en la otra posicion
      for (int i = 0; i < 7; i++)
      {
       con.setForecolor(ColorPieza);
       con.setCursor(Pieza1[i][0],Pieza1[i][1]);
       con<<Sprite1;
      }
        //Sumo o resto los parametros en X, Y  de la pieza vacia 
      for (int i = 0; i < 9; i++)
      {
         PiezaVacia[i][0]=PiezaVacia[i][0]+XPiezaVacia;
         PiezaVacia[i][1]=PiezaVacia[i][1]+YPiezaVacia;
      }
      //Dibujo la pieza vacia en la posicion anterior de la pieza 
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorPiezaVacia);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
     con.refresh();
     Contador++;
     ImprimirContador();
     VerificarVictoria();
     }
     }
}

void SlidingPuzzle::MoverPieza2(int x, int y, int XPiezaVacia, int YPiezaVacia){
     int VerificarFilas=Pieza2[5][0]+x;                           
     int VerificarColumnas=Pieza2[5][1]+y;
     if(VerificarFilas<26 && VerificarColumnas<26 )//La pieza debe moverse dentro del tablero la longitud es 26
     {
     if(VerificarFilas>1&&VerificarColumnas>1){
     //Sumo un parametro al arreglo para mover la pieza  hacia abajo o arriba. izquierda o derecha
      for (int i = 0; i < 21; i++)
      {
         Pieza2[i][0]=Pieza2[i][0]+x;
         Pieza2[i][1]=Pieza2[i][1]+y;
      }
    //Por default antes de pintar la pieza a la nueva posicion la dejo con el color del tablero
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorVacio);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
      for (int i = 0; i < 21; i++)
      {
       con.setForecolor(ColorPieza);//Dibujo nuevamente la pieza en la otra posicion
       con.setCursor(Pieza2[i][0],Pieza2[i][1]);
       con<<Sprite1;
      }
      //Sumo o resto los parametros en X, Y de la pieza vacia
      for (int i = 0; i < 9; i++)
      {
         PiezaVacia[i][0]=PiezaVacia[i][0]+XPiezaVacia;
         PiezaVacia[i][1]=PiezaVacia[i][1]+YPiezaVacia;
      }
      //Dibujo la pieza vacia en la posicion anterior de la pieza que se movio
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorPiezaVacia);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
      con.refresh();
     Contador++;
     ImprimirContador();
     VerificarVictoria();
     }
     }
}

void SlidingPuzzle::MoverPieza3(int x, int y, int XPiezaVacia, int YPiezaVacia){
     int VerificarFilas=Pieza3[5][0]+x;
     int VerificarColumnas=Pieza3[5][1]+y;
     if(VerificarFilas<26 && VerificarColumnas<26 )//La pieza debe moverse dentro del tablero la longitud es 26
     {
     if(VerificarFilas>1&&VerificarColumnas>1){
     //Sumo un parametro al arreglo para mover la pieza  hacia abajo o arriba, izquierda o derecha
      for (int i = 0; i < 21; i++)
      {
         Pieza3[i][0]=Pieza3[i][0]+x;
         Pieza3[i][1]=Pieza3[i][1]+y;
      }
    //Por default antes de pintar la pieza a la nueva posicion la dejo con el color del tablero
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorVacio);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
      for (int i = 0; i < 21; i++)//Dibujo nuevamente la pieza en la otra posicion
      {
       con.setForecolor(ColorPieza);
       con.setCursor(Pieza3[i][0],Pieza3[i][1]);
       con<<Sprite1;
      }
       //Sumo o resto los parametros en X, Y de la pieza vacia
      for (int i = 0; i < 9; i++)
      {
         PiezaVacia[i][0]=PiezaVacia[i][0]+XPiezaVacia;
         PiezaVacia[i][1]=PiezaVacia[i][1]+YPiezaVacia;
      }
      //Dibujo la pieza vacia en la posicion anterior de la pieza 
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorPiezaVacia);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
     con.refresh();
     Contador++;
     ImprimirContador();
     VerificarVictoria();
     }
     }
}

void SlidingPuzzle::MoverPieza4(int x, int y, int XPiezaVacia, int YPiezaVacia){
     int VerificarFilas=Pieza4[7][0]+x;
     int VerificarColumnas=Pieza4[7][1]+y;
     if(VerificarFilas<26 && VerificarColumnas<26 )//La pieza debe moverse dentro del tablero la longitud es 26
     {
     if(VerificarFilas>1&&VerificarColumnas>1){
     //Sumo un parametro al arreglo para mover la pieza  hacia abajo o arriba, izquierda o derecha
      for (int i = 0; i < 13; i++)
      {
         Pieza4[i][0]=Pieza4[i][0]+x;
         Pieza4[i][1]=Pieza4[i][1]+y;
      }
      //Por default antes de pintar la pieza a la nueva posicion la dejo con el color del tablero
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorVacio);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
      for (int i = 0; i < 13; i++)//Dibujo nuevamente la pieza en la otra posicion
      {
       con.setForecolor(ColorPieza);
       con.setCursor(Pieza4[i][0],Pieza4[i][1]);
       con<<Sprite1;
      }
        //Sumo o resto los parametros en X, Y de la pieza vacia
      for (int i = 0; i < 9; i++)
      {
         PiezaVacia[i][0]=PiezaVacia[i][0]+XPiezaVacia;
         PiezaVacia[i][1]=PiezaVacia[i][1]+YPiezaVacia;
      }
     //Dibujo la pieza vacia en la posicion anterior de la pieza
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorPiezaVacia);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
     con.refresh();
     Contador++;
     ImprimirContador();
     VerificarVictoria();
     }
     }
}

void SlidingPuzzle::MoverPieza5(int x, int y, int XPiezaVacia, int YPiezaVacia){
     int VerificarFilas=Pieza5[0][0]+x;
     int VerificarColumnas=Pieza5[0][1]+y;
     if(VerificarFilas<26 && VerificarColumnas<26 )//La pieza debe moverse dentro del tablero la longitud es 26
     {
     if(VerificarFilas>1&&VerificarColumnas>1){
     //Sumo un parametro al arreglo para mover la pieza  hacia abajo o arriba, izquierda o derecha
      for (int i = 0; i < 22; i++)
      {
         Pieza5[i][0]=Pieza5[i][0]+x;
         Pieza5[i][1]=Pieza5[i][1]+y;
      }
      //Por default antes de pintar la pieza a la nueva posicion la dejo con el color del tablero
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorVacio);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
      for (int i = 0; i < 22; i++)//Dibujo nuevamente la pieza en la otra posicion
      {
       con.setForecolor(ColorPieza);
       con.setCursor(Pieza5[i][0],Pieza5[i][1]);
       con<<Sprite1;
      }
       //Sumo o resto los parametros en X, Y de la pieza vacia
      for (int i = 0; i < 9; i++)
      {
         PiezaVacia[i][0]=PiezaVacia[i][0]+XPiezaVacia;
          PiezaVacia[i][1]=PiezaVacia[i][1]+YPiezaVacia;
      }
 //Dibujo la pieza vacia en la posicion anterior de la pieza 

      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorPiezaVacia);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
     con.refresh();
     Contador++;
     ImprimirContador();
     VerificarVictoria();
     }
     }
}

void SlidingPuzzle::MoverPieza6(int x, int y, int XPiezaVacia, int YPiezaVacia){
     int VerificarFilas=Pieza6[0][0]+x;
     int VerificarColumnas=Pieza6[0][1]+y;
     if(VerificarFilas<26 && VerificarColumnas<26 )//La pieza debe moverse dentro del tablero la longitud es 26
     {
     if(VerificarFilas>1&&VerificarColumnas>1){
     //Sumo un parametro al arreglo para mover la pieza  hacia abajo o arriba, izquierda o derecha
      for (int i = 0; i < 23; i++)
      {
         Pieza6[i][0]=Pieza6[i][0]+x;
         Pieza6[i][1]=Pieza6[i][1]+y;
      }
      //Por default antes de pintar la pieza a la nueva posicion la dejo con el color del tablero
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorVacio);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
      for (int i = 0; i < 23; i++)//Dibujo nuevamente la pieza en la otra posicion
      {
       con.setForecolor(ColorPieza);
       con.setCursor(Pieza6[i][0],Pieza6[i][1]);
       con<<Sprite1;
      }
        //Sumo o resto los parametros en X, Y de la pieza vacia
       for (int i = 0; i < 9; i++)
      {
         PiezaVacia[i][0]=PiezaVacia[i][0]+XPiezaVacia;
         PiezaVacia[i][1]=PiezaVacia[i][1]+YPiezaVacia;
      }
       //Dibujo la pieza vacia en la posicion anterior de la pieza 
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorPiezaVacia);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
     con.refresh();
     Contador++;
     ImprimirContador();
     VerificarVictoria();
     }
     }
}

void SlidingPuzzle::MoverPieza7(int x, int y, int XPiezaVacia, int YPiezaVacia){
     int VerificarFilas=Pieza7[5][0]+x;
     int VerificarColumnas=Pieza7[5][1]+y;
     if(VerificarFilas<26 && VerificarColumnas<26 )//La pieza debe moverse dentro del tablero la longitud es 26
     {
     if(VerificarFilas>1&&VerificarColumnas>1){
     //Sumo un parametro al arreglo para mover la pieza  hacia abajo o arriba, izquierda o derecha
      for (int i = 0; i < 11; i++)
      {
         Pieza7[i][0]=Pieza7[i][0]+x;
         Pieza7[i][1]=Pieza7[i][1]+y;
      }
       //Por default antes de pintar la pieza a la nueva posicion la dejo con el color del tablero
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorVacio);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
      for (int i = 0; i < 11; i++)//Dibujo nuevamente la pieza en la otra posicion
      {
       con.setForecolor(ColorPieza);
       con.setCursor(Pieza7[i][0],Pieza7[i][1]);
       con<<Sprite1;
      }
      //Sumo o resto los parametros en X, Y del espacio vacio
      for (int i = 0; i < 9; i++)
      {
         PiezaVacia[i][0]=PiezaVacia[i][0]+XPiezaVacia;
         PiezaVacia[i][1]=PiezaVacia[i][1]+YPiezaVacia;
      }
       //Dibujo la pieza vacia en la posicion anterior de la pieza 
      for (int i = 1; i <9; i++)
      {
       con.setForecolor(ColorPiezaVacia);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
     con.refresh();
     Contador++;
     ImprimirContador();
     VerificarVictoria();
     }
     }
}

void SlidingPuzzle::MoverPieza8(int x, int y, int XPiezaVacia, int YPiezaVacia){
     int VerificarFilas=Pieza8[5][0]+x;
     int VerificarColumnas=Pieza8[5][1]+y;
     if(VerificarFilas<26 && VerificarColumnas<26 )//La pieza debe moverse dentro del tablero la longitud es 26
     {
     if(VerificarFilas>1&&VerificarColumnas>1){
     //Sumo un parametro al arreglo para mover la pieza  hacia abajo o arriba, izquierda o derecha
     for (int i = 0; i < 26; i++)
     {
    Pieza8[i][0]=Pieza8[i][0]+x;
    Pieza8[i][1]=Pieza8[i][1]+y;
     }
     //Por default antes de pintar la pieza a la nueva posicion la dejo con el color del tablero
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorVacio);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
     for (int i = 0; i < 26; i++)//Dibujo nuevamente la pieza en la otra posicion
     {
       con.setForecolor(ColorPieza);
       con.setCursor(Pieza8[i][0],Pieza8[i][1]);
       con<<Sprite1;
     }
     //Sumo o resto los parametros en X,Y de la pieza vacia
      for (int i = 0; i < 9; i++)
      {
         PiezaVacia[i][0]=PiezaVacia[i][0]+XPiezaVacia;
         PiezaVacia[i][1]=PiezaVacia[i][1]+YPiezaVacia;
      }
      //Dibujo la pieza vacia en la posicion anterior de la pieza 
      for (int i = 1; i < 9; i++)
      {
       con.setForecolor(ColorPiezaVacia);
       con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
       con<<Sprite7;
      }
     con.refresh();
     Contador++;
     ImprimirContador();
     VerificarVictoria();
     }
 }
}

void SlidingPuzzle::VerificarVictoria(){
     if(Pieza1[0][0]==2 && Pieza1[0][1]==7&& Pieza2[5][0]==2 &&Pieza2[5][1]==16 &&
     Pieza3[5][0]==2 && Pieza3[5][1]==25 && Pieza4[7][0]==11 &&Pieza4[7][1]==7 &&
     Pieza5[0][0]==11 && Pieza5[0][1]==16 && Pieza6[0][0]==11 &&Pieza6[0][1]==25 &&
     Pieza7[5][0]==20 && Pieza7[5][1]==7 && Pieza8[5][0]==20 &&Pieza8[5][1]==16)
     {
     PiezaVacia[0][0]=27;
     PiezaVacia[0][1]=27;
     con.setForecolor(CColor::Aqua);
     for (int i = 1; i < 9; i++)
     {
         con.setCursor(PiezaVacia[i][0],PiezaVacia[i][1]);
         con<<Sprite7;
     }
     con.setForecolor(CColor::Maroon);
     con.setCursor(27,27);
     con<<Sprite1;
      con.setForecolor(CColor::White);
     for (int i = 0; i < 23; i++)
     {
       con.delayMs(100);
       con.setCursor(Pieza9[i][0], Pieza9[i][1]);
       con<<Sprite1;
     }
          con.setForecolor(CColor::White);
          con.setCursor(10,29);
          con<<"Felicitaciones!";
          con.setCursor(11,31);
          con<<"Has ganado!";
          GuardarEstadistica();
          while(!SalirVideojuego){
        uint32_t key = con.getKey();    
        if (key != SDLK_UNKNOWN) {
            switch (key) {
                case SDLK_s:
                    SalirVideojuego=true;
                    DetenerCronometro=true;
                     break;
            }
            }
          }
     }
}

void SlidingPuzzle::Estadisticas(){
     con.clearScreen();
     DibujarMarcoGrande();
     con.setForecolor(CColor::White);
     con.setCursor(26,34);
     con<<" \"s\"=salir";
     con.setForecolor(CColor::Blue);
     con.setCursor(2,2);
     con<<"Tiempo (s)";
     con.setCursor(2,15);
     con<<"Movimientos";
     con.setForecolor(CColor::Black);
     LeerArchivo();
     do{
        uint32_t key = con.getKey();    
        if (key != SDLK_UNKNOWN) {
            switch (key) {
                case SDLK_s:
                    SalirEstadisticas=true;
                     break;
               }
               con.refresh();
            }
     }while(!SalirEstadisticas);
    con.clearScreen();
    CargarMenuPrincipal();
}

void SlidingPuzzle::GuardarEstadistica(){
           Segundos=Segundos-1;
           ofstream  Escritura("/home/enriquecs/Documents/Proyecto1Programacion3/Estadisticas.gsl",ios::app);
           if(!Escritura){
           con.setCursor(26,29);
            con<<"Error";
           }else{
          Escritura<< Segundos<<"            "<<Contador<<endl;
          }
          Escritura.close();
}

void SlidingPuzzle::LeerArchivo(){
     ifstream Lectura("/home/enriquecs/Documents/Proyecto1Programacion3/Estadisticas.gsl",ios::app);
     int leerSegundos, leerContador;
      con.setForecolor(CColor::Grey);
          if(!Lectura){
           con.setCursor(26,29);
           con<<"Error";
          }else{
               int contador=4;
                con.setForecolor(CColor::Black);
                while(Lectura>>leerSegundos>>leerContador){
                     if(contador<28){
                       con.setCursor(contador,4);
                       con<<leerSegundos<<"            "<<leerContador;
                       contador++;
                        }
                      }    
                 Lectura.close();
               }
}

void SlidingPuzzle::Cronometro(){
  con.setForecolor(CColor::White);
  if(!DetenerCronometro){
     con.setCursor(2,40);
	con<<Segundos;
     Segundos++;
	con.delayMs(1000); 
}  
}

void SlidingPuzzle::ImprimirContador(){
     con.setForecolor(CColor::White);         
     con.setCursor(3,41);
     con<<Contador;
}

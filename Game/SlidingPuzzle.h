#ifndef __GAME_H__
#define __GAME_H__
#include "TextConsole.h"

class SlidingPuzzle: public CClient {
public:
    SlidingPuzzle(TextConsole& con): CClient(con) {}
    void run() override;
    void DibujarTablero();
    void EfectoParpadeo();
    void MenuPrincipal();
    void PosicionPiezasPorDefecto();
    void PosicionPiezas2();
    void PosicionPiezas3();
    void DibujarPiezas();
    void CargarMenuPrincipal();
    void MoverIzquierda();
    void MoverDerecha();
    void MoverArriba();
    void MoverAbajo();
    void VideoJuego();
    void MoverPieza1(int, int, int, int);
    void MoverPieza2(int, int, int, int);
    void MoverPieza3(int, int, int, int);
    void MoverPieza4(int, int, int, int);
    void MoverPieza5(int, int, int, int);
    void MoverPieza6(int, int, int, int);
    void MoverPieza7(int, int, int, int);
    void MoverPieza8(int, int, int, int);
    void DibujarMarcoPequeno();
    void DibujarMarcoGrande();
    void VerificarVictoria();
    void Estadisticas();
    void GuardarEstadistica();
    void LeerArchivo();
    void ImprimirContador();
    void Cronometro();
};
#endif

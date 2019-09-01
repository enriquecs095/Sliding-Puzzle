#include <iostream>
#include "TextConsole.h"
#include "SlidingPuzzle.h"

int main(int argc, char *argv[])
{
    TextConsole con(45, 28);//45 columnas y 28 filas

    if (!con.activate()) {
        return 1;
    }
    SlidingPuzzle game(con);

    con.run(game);
      return 0;
}


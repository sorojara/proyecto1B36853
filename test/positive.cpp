#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "AVL.hpp"

int main(){

  int errores = 0;
  int salida = 0;
  int *out = &salida;

  AVLtree prueba;
  errores += prueba.createTree("datosPrueba.txt");
  errores += prueba.insert("JoguiCaracoli", 100000049);
  errores += prueba.getHeight(out);
  errores += prueba.getSize(out);
  errores += prueba.salidasArbol();

  if (errores == 0) {
    std::cout << "PRUEBA FINALIZA SIN ERRORES" << '\n';
  } else {
    std::cout << "SE DETECTARON ERRORES EN EJECUCION" << '\n';
  }

  prueba.limpiarMemoria();
}

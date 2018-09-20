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
  errores += prueba.getHeight(out);
  errores += prueba.getSize(out);
  errores += prueba.salidasArbol();
  errores += prueba.createTree("ArchivoInexistente.txt");
  errores += prueba.insert("Cedula con digito extra", 1111111111);

  if (errores == 0) {
    std::cout << "PRUEBA FINALIZA SIN ERRORES" << '\n';
  } else {
    std::cout << "SE DETECTARON " << errores << " ERRORES EN EJECUCION" << '\n';
  }
}

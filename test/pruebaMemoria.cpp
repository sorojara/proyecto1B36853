#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "AVL.hpp"

int main(){
  int errores = 0;
  string base = "Ludicolo ";
  string nombre = "";
  int i = 100000000;
  int count = 0;
  int salida = 0;
  int *out = &salida;

  AVLtree prueba;
  for (i = 100000000 ; i <= 999999999; i++) {
    count ++;
    nombre = base;
    nombre.append(to_string(count));
    std::cout << nombre << '\n';
    errores += prueba.insert(nombre, i);
  }

    errores += prueba.salidasArbol();

    prueba.limpiarMemoria();

    if (errores == 0) {
      std::cout << "PRUEBA FINALIZA SIN ERRORES" << '\n';
    } else {
      std::cout << "SE DETECTARON ERRORES EN EJECUCION" << '\n';
    }

}

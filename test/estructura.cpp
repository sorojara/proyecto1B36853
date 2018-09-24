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
  errores += prueba.insert("Soro", 100000420);
  std::cout << "Soro, 100000420" << '\n';
  errores += prueba.insert("Espeon", 100000069);
  std::cout << "Espeon, 100000069" << '\n';
  errores += prueba.insert("Umbreon", 100000042);
  std::cout << "Umbreon, 100000042" << '\n';
  errores += prueba.insert("Byron", 100000030);
  std::cout << "Byron, 100000030" << '\n';
  errores += prueba.insert("Leopoldo", 100000015);
  std::cout << "Leopoldo, 100000015" << '\n';
  errores += prueba.insert("JoguiCaracoli", 100000049);
  std::cout << "JoguiCaracoli, 100000049" << '\n';

  std::cout << "________________________" << '\n';
  std::cout << "Estructura:" << '\n';
  std::cout << "________________________" << '\n';
  prueba.root -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> RC -> printInfo();


  if (errores == 0) {
    std::cout << "PRUEBA FINALIZA SIN ERRORES" << '\n';
  } else {
    std::cout << "SE DETECTARON ERRORES EN EJECUCION" << '\n';
  }

  prueba.limpiarMemoria();
}

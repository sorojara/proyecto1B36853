#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "AVL.hpp"


int main(){
  AVLtree prueba;
  prueba.createTree("lista_1000.txt");

  prueba.salidasArbol();

  prueba.limpiarMemoria();

  std::cout << "FIN" << '\n';
  return 0;
}

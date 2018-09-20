#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "AVL.hpp"


int main(){
  AVLtree prueba;
  prueba.createTree("lista_100.txt");
  //prueba.getSize();
  //prueba.getHeight();
  /*
  std::cout << "________________________" << '\n';
  std::cout << "PRUEBA 1:" << '\n';
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
  */

  prueba.salidasArbol();

  //std::cout << "\n\n\n";

  prueba.limpiarMemoria();

  /*
  prueba.insert("Limpio", 111111111);
  std::cout << "________________________" << '\n';
  std::cout << "PRUEBA 2:" << '\n';
  prueba.root -> printInfo();
  */


  std::cout << "FIN" << '\n';
  return 0;
}

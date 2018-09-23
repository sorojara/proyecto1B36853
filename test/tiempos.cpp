#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "AVL.hpp"

using namespace std;


int main(){

  int salida = 0;
  int *out = &salida;
  string tiempos = "";

  AVLtree prueba;
  clock_t begin = clock();
  prueba.createTree("lista_10.txt");
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << "Duracion: " << elapsed_secs << '\n';
  tiempos.append("10 ");
  tiempos.append(to_string(elapsed_secs));
  tiempos.append("\n");
  prueba.limpiarMemoria();

  begin = clock();
  prueba.createTree("lista_100.txt");
  end = clock();
  elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << "Duracion: " << elapsed_secs << '\n';
  tiempos.append("100 ");
  tiempos.append(to_string(elapsed_secs));
  tiempos.append("\n");
  prueba.limpiarMemoria();

  begin = clock();
  prueba.createTree("lista_1000.txt");
  end = clock();
  elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << "Duracion: " << elapsed_secs << '\n';
  tiempos.append("1000 ");
  tiempos.append(to_string(elapsed_secs));
  tiempos.append("\n");
  prueba.limpiarMemoria();

  begin = clock();
  prueba.createTree("lista_5000.txt");
  end = clock();
  elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << "Duracion: " << elapsed_secs << '\n';
  tiempos.append("5000 ");
  tiempos.append(to_string(elapsed_secs));
  tiempos.append("\n");
  prueba.limpiarMemoria();

  begin = clock();
  prueba.createTree("lista_10000.txt");
  end = clock();
  elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << "Duracion: " << elapsed_secs << '\n';
  tiempos.append("10000 ");
  tiempos.append(to_string(elapsed_secs));
  tiempos.append("\n");
  prueba.limpiarMemoria();

  std::cout << "____________________" << '\n';
  std::cout << tiempos << '\n';

  ofstream myfile;
  myfile.open ("running_times.txt");
  myfile << tiempos;
  myfile.close();



}

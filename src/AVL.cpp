#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "AVL.hpp"


using namespace std;

AVLtree::AVLtree(){
  root = NULL;
}

void AVLtree::rotLL(nodo *punto){
  nodo *padre = punto -> Parent;
  nodo *bufferY = punto -> LC;
  nodo *bufferX = bufferY -> LC;
  nodo *bufferZ = punto;
  nodo *bufferGeneral = bufferY -> RC;
  bufferY -> RC = bufferZ;
  bufferZ -> LC = bufferGeneral;
  bufferY -> LC = bufferX;
  //falta asignar como hijo de padre
  //falta asignar padres
}

void AVLtree::rotRR(nodo *punto){
  nodo *padre = punto -> Parent;
  nodo *bufferY = punto -> RC;
  nodo *bufferX = bufferY -> RC;
  nodo *bufferZ = punto;
  nodo *bufferGeneral = bufferY -> LC;
  bufferY -> RC = bufferX;
  bufferZ -> RC = bufferGeneral;
  bufferY -> LC = bufferZ;
  //falta asignar como hijo de padre
  //falta asignar padres
}

void AVLtree::rotRL(nodo *punto){
  //nodo *padre = punto -> Parent;
  nodo *bufferY = punto -> RC;
  nodo *bufferX = bufferY -> RC;
  nodo *bufferZ = punto;
  nodo *bufferGeneral = bufferX -> RC;
  bufferZ -> RC = bufferX;
  bufferX -> RC = bufferY;
  bufferY -> LC = bufferGeneral;
  rotRR(bufferZ);
  //falta asignar como hijo de padre
  //falta asignar padres
}

void AVLtree::rotLR(nodo *punto){
  //nodo *padre = punto -> Parent;
  nodo *bufferY = punto -> RC;
  nodo *bufferX = bufferY -> RC;
  nodo *bufferZ = punto;
  nodo *bufferGeneral = bufferX -> LC;
  bufferZ -> LC = bufferX;
  bufferX -> LC = bufferY;
  bufferY -> RC = bufferGeneral;
  rotLL(bufferZ);
  //falta asignar como hijo de padre
  //falta asignar padres
}




//Para pruebas de compilacion
int main()
{
    return 0;
}

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
  bufferZ -> Parent = bufferY;
  bufferZ -> LC = bufferGeneral;
  bufferGeneral -> Parent = bufferZ;
  bufferY -> LC = bufferX;
  bufferX -> Parent = bufferY;
  //falta asignar como hijo de padre
}

void AVLtree::rotRR(nodo *punto){
  nodo *padre = punto -> Parent;
  nodo *bufferY = punto -> RC;
  nodo *bufferX = bufferY -> RC;
  nodo *bufferZ = punto;
  nodo *bufferGeneral = bufferY -> LC;
  bufferY -> RC = bufferX;
  bufferX -> Parent = bufferY;
  bufferZ -> RC = bufferGeneral;
  bufferGeneral -> Parent = bufferZ;
  bufferY -> LC = bufferZ;
  bufferZ -> Parent = bufferY;
  //falta asignar como hijo de padre
}

void AVLtree::rotRL(nodo *punto){
  //nodo *padre = punto -> Parent;
  nodo *bufferY = punto -> RC;
  nodo *bufferX = bufferY -> LC;
  nodo *bufferZ = punto;
  nodo *bufferGeneral = bufferX -> RC;
  bufferZ -> RC = bufferX;
  bufferX -> Parent = bufferZ;
  bufferX -> RC = bufferY;
  bufferY -> Parent = bufferX;
  bufferY -> LC = bufferGeneral;
  bufferGeneral -> Parent = bufferY;
  rotRR(bufferZ);
  //falta asignar como hijo de padre
}

void AVLtree::rotLR(nodo *punto){
  //nodo *padre = punto -> Parent;
  nodo *bufferY = punto -> LC;
  nodo *bufferX = bufferY -> RC;
  nodo *bufferZ = punto;
  nodo *bufferGeneral = bufferX -> LC;
  bufferZ -> LC = bufferX;
  bufferX -> Parent = bufferZ;
  bufferX -> LC = bufferY;
  bufferY -> Parent = bufferX;
  bufferY -> RC = bufferGeneral;
  bufferGeneral -> Parent = bufferY;
  rotLL(bufferZ);
  //falta asignar como hijo de padre
}




//Para pruebas de compilacion
int main()
{
    return 0;
}

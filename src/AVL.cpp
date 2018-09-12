#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "AVL.hpp"


using namespace std;

nodo::nodo(string nom, int ced){
  data = ced;
  nombre = nom;
  LC = NULL;
  RC = NULL;
  Parent = NULL;
  h=1;
}

nodo::nodo(string nom, int ced, nodo *pad){
  data = ced;
  nombre = nom;
  LC = NULL;
  RC = NULL;
  Parent = pad;
  h=(pad -> h) + 1;
  if (data > pad -> data) {
    pad -> RC = this;
  } else {
    padre -> LC = this;
  }
}

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
  if (bufferY -> data > padre -> data) {
    padre -> RC = bufferY;
  } else {
    padre -> LC = bufferY;
  }
  bufferY -> Parent = padre;
  //agregar un actualizador de H recursivo

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
  if (bufferY -> data > padre -> data) {
    padre -> RC = bufferY;
  } else {
    padre -> LC = bufferY;
  }
  bufferY -> Parent = padre;
  //agregar un actualizador de H recursivo
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
  if (bufferY -> data > padre -> data) {
    padre -> RC = bufferY;
  } else {
    padre -> LC = bufferY;
  }
  bufferY -> Parent = padre;
  //agregar un actualizador de H recursivo
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
  if (bufferY -> data > padre -> data) {
    padre -> RC = bufferY;
  } else {
    padre -> LC = bufferY;
  }
  bufferY -> Parent = padre;
  //agregar un actualizador de H recursivo
}




//Para pruebas de compilacion
int main()
{
    return 0;
}

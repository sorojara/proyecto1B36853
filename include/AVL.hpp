#ifndef AVL
#define AVL

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <queue>
using namespace std;

class nodo
  {
  public:
    void printInfo();
    int isLeaf();
    int data;
    int hI;
    int hD;
    string nombre;
    nodo *LC;
    nodo *RC;
    nodo *Parent;
    nodo(string nom, int ced);
    nodo(string nom, int ced, nodo *pad);
    ~nodo();

  };

class AVLtree
{
//private:
public:
  nodo *root;
  int size;
  AVLtree();
  AVLtree(string nom, int ced);
  //~AVLtree();
  int insert(string nom, int ced);//UNITTEST
  int limpiarMemoria();
  int getSize();//UNITTEST E IMPLEMENTAR PARAMETRO DE SALIDA
  int getHeight();//UNITTEST E IMPLEMENTAR PARAMETRO DE SALIDA
  int createTree(string archivo);//UNITTEST Y MANEJO DE ERRORES
  int salidasArbol();//UNITEST Y PROCEDIMIENTO

private:
  void rotLL(nodo *punto);
  void rotRR(nodo *punto);
  void rotRL(nodo *punto);
  void rotLR(nodo *punto);
  nodo *checkK(nodo *punto, queue <int> dirs);
  void actualizarH(nodo *punto);
  void ubicar(string nom, int ced);
  nodo *encontrarPosicion(string nom, int ced, nodo *punto);
  nodo *getMayor(nodo *punto);
  nodo *getMenor(nodo *punto);

};

#endif

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
  int getSize(int *salida);//UNITTEST 
  int getHeight(int *salida);//UNITTEST
  int createTree(string archivo);//UNITTEST
  int salidasArbol();//UNITEST

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
  int writeFile (string archivo, string mensaje);
  bool is_file_exist(const char *fileName);

};

#endif

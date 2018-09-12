#ifndef AVL
#define AVL

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
using namespace std;

class nodo
  {
  public:
    int data;
    //int k;
    int h;
    string nombre;
    nodo *LC;
    nodo *RC;
    nodo *Parent;
    nodo(string nom, int ced);
    nodo(string nom, int ced, nodo *pad);

  };

class AVLtree
{
private:

  nodo *root;

public:
  AVLtree();
  AVLtree(string nom, int ced);
  void rotLL(nodo *punto);
  void rotRR(nodo *punto);
  void rotRL(nodo *punto);
  void rotLR(nodo *punto);
};

#endif

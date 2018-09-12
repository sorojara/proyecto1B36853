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
  };

class AVLtree
{
private:

  nodo *root;

public:
  AVLtree();
  void rotLL(nodo *punto);
  void rotRR(nodo *punto);
  void rotRL(nodo *punto);
  void rotLR(nodo *punto);
};

#endif

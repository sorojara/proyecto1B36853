#ifndef AVL
#define AVL

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
using namespace std;

struct nodo
  {
    int data;
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

};

#endif

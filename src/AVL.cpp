#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <queue>
#include <algorithm>//std::max
#include "AVL.hpp"


using namespace std;

nodo::nodo(string nom, int ced){
  data = ced;
  nombre = nom;
  LC = NULL;
  RC = NULL;
  Parent = NULL;
  hI=0;
  hD=0;
}

nodo::nodo(string nom, int ced, nodo *pad){
  data = ced;
  nombre = nom;
  LC = NULL;
  RC = NULL;
  Parent = pad;
  hI=0;
  hD=0;
  //h=(pad -> h) + 1;
  if (data > pad -> data) {
    pad -> RC = this;
  } else {
    pad -> LC = this;
  }
}

void nodo::printInfo(){ //arreglar print de nulls
  std::cout << "Cedula: " << data << '\n';
  std::cout << "Nombre: " << nombre << '\n';
  //std::cout << "Altura: " << h << '\n';
  if (Parent == NULL) {
    std::cout << "Padre: ES NODO RAIZ" << endl;
  } else {
    std::cout << "Padre: " << Parent -> nombre << '\n';
  }


  if (LC == NULL) {
    std::cout << "LC: no hay hijo izquierdo " << endl;
  } else {
    std::cout << "LC: " << LC -> nombre << endl;
  }

  if (RC == NULL) {
    std::cout << "RC: no hay hijo derecho " << endl;
  } else {
    std::cout << "RC: " << RC -> nombre << endl;
  }


}

AVLtree::AVLtree(){
  root = NULL;
}

AVLtree::AVLtree(string const nom, int const ced){
  root = new nodo (nom, ced);
  //cout << (void*)this << endl;
  //root = &nodo(nom, ced);
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
  if (bufferGeneral!=NULL) {
    bufferGeneral -> Parent = bufferZ;
  }
  bufferY -> LC = bufferX;
  bufferX -> Parent = bufferY;
  if (padre  == NULL) {
    bufferY -> Parent = NULL;
    root = bufferY;
  } else {
    if (bufferY -> data > padre -> data) {
      padre -> RC = bufferY;
    } else {
      padre -> LC = bufferY;
    }
    bufferY -> Parent = padre;
  }
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
  if (bufferGeneral!=NULL) {
    bufferGeneral -> Parent = bufferZ;
  }
  bufferY -> LC = bufferZ;
  bufferZ -> Parent = bufferY;
  if (padre  == NULL) {
    bufferY -> Parent = NULL;
    root = bufferY;
  } else {
    if (bufferY -> data > padre -> data) {
      padre -> RC = bufferY;
    } else {
      padre -> LC = bufferY;
    }
    bufferY -> Parent = padre;
  }
  //agregar un actualizador de H recursivo
}

void AVLtree::rotRL(nodo *punto){
  nodo *padre = punto -> Parent;
  nodo *bufferY = punto -> RC;
  nodo *bufferX = bufferY -> LC;
  nodo *bufferZ = punto;
  nodo *bufferGeneral = bufferX -> RC;
  bufferZ -> RC = bufferX;
  bufferX -> Parent = bufferZ;
  bufferX -> RC = bufferY;
  bufferY -> Parent = bufferX;
  bufferY -> LC = bufferGeneral;
  if (bufferGeneral!=NULL) {
    bufferGeneral -> Parent = bufferY;
  }
  rotRR(bufferZ);
  if (padre  == NULL) {
    bufferX -> Parent = NULL;
    root = bufferX;
  } else {
    if (bufferX -> data > padre -> data) {
      padre -> RC = bufferX;
    } else {
      padre -> LC = bufferX;
    }
    bufferY -> Parent = padre;
  }
  //agregar un actualizador de H recursivo
}

void AVLtree::rotLR(nodo *punto){
  nodo *padre = punto -> Parent;
  nodo *bufferY = punto -> LC;
  nodo *bufferX = bufferY -> RC;
  nodo *bufferZ = punto;
  nodo *bufferGeneral = bufferX -> LC;
  bufferZ -> LC = bufferX;
  bufferX -> Parent = bufferZ;
  bufferX -> LC = bufferY;
  bufferY -> Parent = bufferX;
  bufferY -> RC = bufferGeneral;
  if (bufferGeneral!=NULL) {
    bufferGeneral -> Parent = bufferY;
  }
  rotLL(bufferZ);
  if (padre  == NULL) {
    bufferX -> Parent = NULL;
    root = bufferX;
  } else {
    if (bufferX -> data > padre -> data) {
      padre -> RC = bufferX;
    } else {
      padre -> LC = bufferX;
    }
    bufferY -> Parent = padre;
  }
  //agregar un actualizador de H recursivo
}


nodo *AVLtree::checkK(nodo *punto, queue <int> dirs){//dirs[i]=0-->NO ASIGNADO; dirs[i]=1-->Izq; dirs[i]=2-->Der

  if (punto == NULL) {
    return NULL;
  }else {
    int k = (punto -> hD) - (punto -> hI);
    if (k>1 || k<-1) {
      int a = dirs.front();
      dirs.pop();
      int b = dirs.front();
      dirs.pop();
      if (a==1 && b==1) {
        rotLL(punto);
      } else if (a==1 && b==2) {
        rotRL(punto);
      }
      else if (a==2 && b==1) {
        rotLR(punto);
      }
      else if (a==2 && b==2) {
        rotRR(punto);
      }
      return punto -> Parent;
    }else{
      if (dirs.size() >= 2) {
        dirs.pop();
      }
      if (punto -> data > punto -> Parent -> data) {
        dirs.push(2);
      } else {
        dirs.push(1);
      }
      return checkK(punto -> Parent, dirs);
    }

  }

}

void AVLtree::actualizarH(nodo *punto){
  if (punto != NULL) {
    if (punto -> LC == NULL) {
      punto -> hI = 0;
    } else {
      punto -> hI = std::max(punto -> LC ->hI, punto -> LC ->hD)+1;
    }
    if (punto -> RC == NULL) {
      punto -> hD = 0;
    } else {
      punto -> hD = std::max(punto -> RC ->hI, punto -> RC ->hD)+1;
    }
    actualizarH(punto -> Parent);

  } else {
    //haga algo
  }
}

nodo *AVLtree::encontrarPosicion(string nom, int ced, nodo *punto){
  nodo *buffer = NULL;
  int lado = 0;
  if (ced > punto -> data) {
    buffer = punto -> RC;
    lado = 2;
  } else {
    buffer = punto -> LC;
    lado = 1;
  }
  if (buffer == NULL) {
    buffer = new nodo(nom, ced, punto);
    if (lado == 2) {
      punto -> RC = buffer;
      return punto -> RC;
    } else {
      punto -> LC = buffer;
      return punto -> LC;
    }
  } else {
    return encontrarPosicion(nom, ced, buffer);
  }
}


void AVLtree::ubicar(string nom, int ced){
  if (root == NULL){
    root = new nodo (nom, ced);
  }else{
    nodo *buffer = encontrarPosicion(nom, ced, root);
    actualizarH(buffer);
    queue <int> cola;
    nodo *buffer2 = checkK(buffer, cola);
    if (buffer2 != NULL) {
      //actualizar hs de hijo izquierdo
      if (buffer2 -> LC -> LC == NULL) {
        buffer2 -> LC -> hI = 0;
      } else {
        buffer2 -> LC -> hI = std::max(buffer2 -> LC -> LC ->hI, buffer2 -> LC -> LC ->hD)+1;
      }
      if (buffer2 -> LC -> RC == NULL) {
        buffer2 -> LC -> hD = 0;
      } else {
        buffer2 -> LC -> hD = std::max(buffer2 -> LC -> RC ->hI, buffer2 -> LC -> RC ->hD)+1;
      }

      //actualizar hs de hijo derecho
      if (buffer2 -> RC -> LC == NULL) {
        buffer2 -> RC -> hI = 0;
      } else {
        buffer2 -> RC -> hI = std::max(buffer2 -> RC -> LC ->hI, buffer2 -> RC -> LC ->hD)+1;
      }
      if (buffer2 -> RC -> RC == NULL) {
        buffer2 -> RC -> hD = 0;
      } else {
        buffer2 -> RC -> hD = std::max(buffer2 -> RC -> RC ->hI, buffer2 -> RC -> RC ->hD)+1;
      }
      actualizarH(buffer2);
    } else {
      //actualizarH(buffer);
    }

  }
}







//Para pruebas de compilacion
int main()
{
  AVLtree prueba("soro", 420);
  //cout << (void*)prueba.root << endl;
  //prueba.root -> printInfo();
  prueba.root -> LC = new nodo ("espeon", 69, prueba.root);
  prueba.root -> LC -> LC = new nodo ("Umbreon", 42, prueba.root -> LC);

  std::cout << "________________________" << '\n';
  std::cout << "PRUEBA 1:" << '\n';
  std::cout << "________________________" << '\n';
  prueba.root -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> LC -> printInfo();
  std::cout << "________________________" << '\n';

  prueba.rotLL(prueba.root);

  std::cout << "________________________" << '\n';
  std::cout << "PRUEBA 2 (LL):" << '\n';
  std::cout << "________________________" << '\n';
  prueba.root -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> printInfo();
  std::cout << "________________________" << '\n';

  prueba.root -> RC -> RC = new nodo ("Victor", 666, prueba.root -> RC);


  prueba.rotRR(prueba.root);
  std::cout << "________________________" << '\n';
  std::cout << "PRUEBA 3 (RR):" << '\n';
  std::cout << "________________________" << '\n';
  prueba.root -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> LC -> printInfo();
  std::cout << "________________________" << '\n';

  prueba.root -> LC -> RC = new nodo ("Kurt Bernard", 77, prueba.root -> LC);
  prueba.rotLR(prueba.root);

  std::cout << "________________________" << '\n';
  std::cout << "PRUEBA 4 (LR):" << '\n';
  std::cout << "________________________" << '\n';
  prueba.root -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> RC -> printInfo();
  std::cout << "________________________" << '\n';

  prueba.root -> RC -> LC = new nodo ("Helber", 100, prueba.root -> RC);
  prueba.rotRL(prueba.root);

  std::cout << "________________________" << '\n';
  std::cout << "PRUEBA 5 (RL):" << '\n';
  std::cout << "________________________" << '\n';
  prueba.root -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> RC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> LC -> LC -> printInfo();
  std::cout << "________________________" << '\n';


  return 0;
}

#include <fstream>
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


nodo::~nodo(){

  if(LC != NULL){
    if (LC -> isLeaf()==1) {
      delete LC;
    } else {
      LC -> ~nodo();
    }
  }
  if(RC != NULL){
    if (RC -> isLeaf()==1) {
      delete RC;
    } else {
      RC -> ~nodo();
    }
  }
  //delete this;
}


//metodo para imprimir informacion en las pruebas
void nodo::printInfo(){ //arreglar print de nulls
  std::cout << "Cedula: " << data << '\n';
  std::cout << "Nombre: " << nombre << '\n';
  //std::cout << "Altura: " << h << '\n';
  if (Parent == NULL) {
    std::cout << "Padre: ES NODO RAIZ" << endl;
  } else {
    std::cout << "Padre: " << Parent -> nombre << '\n';
  }

  //std::cout << "Imprimir hijo izquierdo"<< '\n';

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

//chequeo de condicion hoja de nodo
int nodo::isLeaf(){
  if (LC == NULL && RC == NULL) {
    return 1;
  } else {
    return 2;
  }
}

AVLtree::AVLtree(){
  root = NULL;
  size = 0;
}

AVLtree::AVLtree(string const nom, int const ced){
  root = new nodo (nom, ced);
  size = 0;
  //cout << (void*)this << endl;
  //root = &nodo(nom, ced);
}

/*

AVLtree::~AVLtree(){
  limpiarMemoria(root);

}
*/

//Metodo para liberar la memoria en un arbol
int AVLtree::limpiarMemoria(){
  delete root;
  root = NULL;
  size = 0;
  return 0;
}

//rotacion LL de un nodo
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

//rotacion RR de un nodo
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

//Rotacion RL de un nodo
void AVLtree::rotRL(nodo *punto){
  //std::cout << "Nodo: " << (size+1) <<'\n';
  if (size == 160) {
    punto -> printInfo();
  }

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
    //bufferY -> Parent = padre;
    bufferX -> Parent = padre;
  }
  //agregar un actualizador de H recursivo
}

//rotacion LR en un Nodo
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
    //bufferY -> Parent = padre;
    bufferX -> Parent = padre;
  }
  //agregar un actualizador de H recursivo
}

//funcion que retorna en el puntero dado el tamaño total del arbol
int AVLtree::getSize(int *salida){
  if (root != NULL) {
    std::cout << "Size: " << size << '\n';
    *salida = size;
    return 0;
  } else {
    std::cout << "ARBOL VACIO" << '\n';
    return 1;
  }

}

//funcion que retorna en el puntero dado la altura maxima del arbol
int AVLtree::getHeight(int *salida){
  int a = 0;
  if (root != NULL) {
    a = std::max(root -> hI,root -> hD)+1;
    *salida = a;
    std::cout << "Height: " << a << '\n';
    return 0;
  }else {
    a=0;
    std::cout << "Height: " << a << '\n';
    return 1;
  }
}


//funcion de uso interno que permite chequear el balance del arbol desde un nodo dado hasta root; y en caso de encontrar un nodo infractor -1<k>1 retornar su puntero; caso contrario retornar NULL
nodo *AVLtree::checkK(nodo *punto, queue <int> dirs){//dirs[i]=0-->NO ASIGNADO; dirs[i]=1-->Izq; dirs[i]=2-->Der


  //DEBUGGING
  /*
  if (size == 160) {
    std::cout << "HI = " << (punto -> hI) <<'\n';
    std::cout << "HD = " << (punto -> hD) <<'\n';

    if (dirs.size()>=1) {
      std::cout << "dirs[0] =" << dirs.front() <<'\n';
      std::cout << "dirs[1] =" << dirs.back() <<'\n';
    }
    //
    std::cout << "k = " << (punto -> hD) - (punto -> hI) <<'\n';
    punto -> printInfo();
    std::cout << "___________\n" << '\n';
  }
  */

  /*
  if (punto != NULL && punto -> data == 100000578) {
    punto -> printInfo();
    std::cout << "___________\n" << '\n';
  }
  */

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
      if (punto -> Parent != NULL) {
        if (punto -> data > punto -> Parent -> data) {
          dirs.push(2);
        } else {
          dirs.push(1);
        }
      }
      return checkK(punto -> Parent, dirs);
    }

  }

}

//funcion de uso interno para actualizar las alturas de cada nodo despues de realizar un cambio
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

//funcion de uso interno para colocar un nuevo nodo en la posicion libre correspondiente para realizar asi su respectiva rotacion en caso de ser necesario
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

//funcion de uso interno para insertar nuevos nodos
void AVLtree::ubicar(string nom, int ced){
  size ++;
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
      actualizarH(buffer);
    }

  }
}

//funcion para insertar un nuevo nodo con manejo de errores
int AVLtree::insert(string nom, int ced){
  if (ced >= 100000000 && ced <=999999999) {
    ubicar(nom, ced);
    return 0;
  }else{
    std::cout << "VALORES DE INSERCION INVALIDOS EN: "<< nom << ", " << ced << '\n';
    return 1;
  }
}

//funcion de uso interno para chequear la existencia de un archivo para su lectura
bool AVLtree::is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

//funcion para crear un arbol nuevo a partir de un archivo dado en formato: "NOMBRE, CEDULA \n"; y respectivo manejo de errores en cada linea
int AVLtree::createTree(string archivo){
  string dir = "misc/input/";
  dir.append(archivo);
  if (is_file_exist(dir.c_str())) {
    ifstream file(dir);
    if (file.is_open()) {
      std::string line;
      while (getline(file, line)) {
        //cout << line << '\n';
        int ind = 0;
        int cont= 0;
        for (int j = 0; j < line.length(); j++) {
            if (line[j]==',') {
              if (cont == 0) {
                ind = j;
                cont ++;
              }else{
                std::cout << "ATENCION! Exceso de argumentos" << '\n';
              }
            }
        }
        string input1 = line.substr(0,ind);
        string input2 = line.substr(ind+2); //si hay espacio; sino es un +1

        int iValid = 1;

        for (int i = 0; i < input2.length(); i++) {
          if (!isdigit(input2[i])){
            iValid = 0;
          }
        }

        if (iValid == 0) {
          std::cout << "ATENCION! Número de cédula ingresado es NO numérico en: " << line << '\n';
        } else {
          //std::cout << input2 << '\n';
          if (input2.length() < 10) {
            int a = stoi(input2);
            insert(input1, a);
          }else{
            std::cout << "ATENCION! Cedula demasiado grande" << '\n';
          }

        }
      }
    }
    file.close();
    return 0;
  } else {
    std::cout << "ARCHIVO NO EXISTE" << '\n';
    return 1;
  }


}

//funcion de uso interno que recorre el arbol por hijo derecho hasta encontrar la mayor entrada
nodo *AVLtree::getMayor(nodo *punto){
  if (root == NULL) {
    //std::cout << "EL ARBOL ESTA VACIO" << '\n';
    return NULL;
  } else {
    if (punto -> RC == NULL) {
      return punto;
    } else {
      return getMayor(punto -> RC);
    }
  }

}

//funcion de uso interno que recorre el arbol por hijo izquierdo hasta encontrar la menor entrada
nodo *AVLtree::getMenor(nodo *punto){
  if (root == NULL) {
    //std::cout << "EL ARBOL ESTA VACIO" << '\n';
    return NULL;
  } else {
    if (punto -> LC == NULL) {
      return punto;
    } else {
      return getMenor(punto -> LC);
    }
  }
}

//Funcion de uso interno para la escritura de archivos
int AVLtree::writeFile (string archivo, string mensaje)
{
  ofstream myfile;
  myfile.open (archivo);
  myfile << mensaje;
  myfile.close();
  return 0;
}

//Funcion para encontrar mayor y menor del arbol e imprimirlo en archivo
int AVLtree::salidasArbol(){
  nodo *buffer = getMayor(root);
  if (buffer == NULL) {
    std::cout << "EL ARBOL ESTA VACIO; No se crea el archivo de Salidas" << '\n';
    return 1;
  } else {
    string mensaje = "MAYOR: ";
    mensaje.append(buffer -> nombre);
    mensaje.append("; ");
    mensaje.append(to_string(buffer -> data));
    mensaje.append("\n\n");
    buffer = getMenor(root);
    mensaje.append("MENOR: ");
    mensaje.append(buffer -> nombre);
    mensaje.append("; ");
    mensaje.append(to_string(buffer -> data));

    writeFile("misc/output/max_and_min_id.txt", mensaje);
    std::cout << '\n' << mensaje << '\n';

    return 0;
  }
}

/*
int main() {
  AVLtree prueba;
  prueba.createTree("lista_100.txt");
  //prueba.getSize();
  //prueba.getHeight();

  std::cout << "________________________" << '\n';
  std::cout << "PRUEBA 1:" << '\n';
  std::cout << "________________________" << '\n';
  prueba.root -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> RC -> printInfo();

  prueba.salidasArbol();

  std::cout << "\n\n\n";

  prueba.limpiarMemoria();

  prueba.insert("Limpio", 111111111);
  std::cout << "________________________" << '\n';
  std::cout << "PRUEBA 2:" << '\n';
  prueba.root -> printInfo();


  std::cout << "FIN" << '\n';
  return 0;
}
*/


//prueba 2

/*

int main()
{
  AVLtree prueba;
  prueba.insert("Soro", 100000420);
  prueba.insert("Espeon", 100000069);
  prueba.insert("Umbreon", 100000042);
  prueba.insert("Byron", 100000030);
  prueba.insert("Leopoldo", 100000015);
  prueba.insert("JoguiCaracoli", 100000049);

  prueba.getSize();
  prueba.getHeight();


  std::cout << "________________________" << '\n';
  std::cout << "PRUEBA 1:" << '\n';
  std::cout << "________________________" << '\n';
  prueba.root -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> LC -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> LC -> printInfo();
  std::cout << "________________________" << '\n';
  prueba.root -> RC -> RC -> printInfo();

}

*/


//prueba 1

/*

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

*/

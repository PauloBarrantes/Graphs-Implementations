#include <iostream>
#include "DiccionarioLSE.h"
#include "CPArbol.h"
#include "Relaciones1_1.h"
#include "CDCD.h"
#include "GNDMatriz.h"
//#include "GNDLista.h"
//#include "Test.h"
#include "Menu.h"
using namespace std;

int main(int argc, char const *argv[]) {

  Menu* menu = new Menu();
  menu->controlador();
  return 0;

}

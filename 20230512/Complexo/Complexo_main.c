#include <stdio.h>
#include <stdlib.h>

#include "Complexo.h"

int main(){
  Complexo *num;
  num = criar(2.0, 4.0);
  linha();

  Complexo *num2;
  num2 = criar(3.0, 5.0);
  linha();

  somar(num, num2);
  linha();

  subtrair(num, num2);
  linha();

  multiplicar(num, num2);
  linha();

  dividir(num, num2);
  linha();

  destruir(num, num2);
}

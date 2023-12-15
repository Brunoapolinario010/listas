#include <stdio.h>
#include "./modulos/luhn.h"

int main(int argc, char *argv[])
{
  // int quant;
  // scanf("%d", &quant);

  // for (int i = 0; i < quant; i++)
  // {
  //   ulli cardNumber;
  //   scanf("%llu", &cardNumber);
  //   classifyCard(cardNumber);
  // }

  ulli cardNumber;
  scanf("%llu", &cardNumber);
  classifyCard(cardNumber);
  return 0;
}
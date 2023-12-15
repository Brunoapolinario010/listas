#include <stdio.h>
#include "luhn.h"

int checksum(ulli cardNumber)
{
  int oddSum = 0;
  int evenSum = 0;
  int totalSum = 0;

  for (int i = 0; cardNumber > 0; i++)
  {
    int digit = cardNumber % 10;

    if (i % 2 == 1)
    {
      int doubledNumber = digit * 2;
      if (doubledNumber > 9)
      {
        int firstDigit = doubledNumber % 10;
        int secondDigit = doubledNumber / 10;
        doubledNumber = firstDigit + secondDigit;
      }
      oddSum += doubledNumber;
    }
    else
    {
      evenSum += digit;
    }
    cardNumber /= 10;
    totalSum = oddSum + evenSum;
  }
  return totalSum % 10;
}

void isAmex(ulli cardNumber)
{
  int tam = 2;
  int amex[] = {34, 37};

  for (int i = 0; i < tam; i++)
  {
    int count = 2;
    ulli cardStart = cardNumber;
    for (int j = 0; cardStart > 100; j++)
    {
      count++;
      cardStart /= 10;
    }
    if (cardStart == amex[i] && count == 15)
    {
      printf("AMEX\n");
      break;
    }
  }
}

void isMastercard(ulli cardNumber)
{
  int tam = 5;
  int mastercard[] = {51, 52, 53, 54, 55};

  for (int i = 0; i < tam; i++)
  {
    int count = 2;
    ulli cardStart = cardNumber;
    for (int j = 0; cardStart > 100; j++)
    {
      count++;
      cardStart /= 10;
    }
    if (cardStart == mastercard[i] && count == 16)
    {
      printf("MASTERCARD\n");
      break;
    }
  }
}

void isVisa(ulli cardNumber)
{
  int tam = 1;
  int visa[] = {4};

  for (int i = 0; i < tam; i++)
  {
    int count = 1;
    ulli cardStart = cardNumber;
    for (int j = 0; cardStart > 10; j++)
    {
      count++;
      cardStart /= 10;
    }
    if (cardStart == visa[i] && count >= 13 && count <= 16)
    {
      printf("VISA\n");
      break;
    }
  }
}

void classifyCard(ulli cardNumber)
{
  if (checksum(cardNumber) == 0)
  {
    isAmex(cardNumber);
    isMastercard(cardNumber);
    isVisa(cardNumber);
  }
  else
  {
    printf("%llu INVALID\t\n", cardNumber);
  }
}
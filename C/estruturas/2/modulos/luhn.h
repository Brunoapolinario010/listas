#ifndef _LUHN_H
#define _LUHN_H
#define ulli unsigned long long int

int checksum(ulli cardNumber);

void isAmex(ulli cardNumber);

void isMastercard(ulli cardNumber);

void isVisa(ulli cardNumber);

void classifyCard(ulli cardNumber);

#endif
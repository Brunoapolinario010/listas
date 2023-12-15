#ifndef _PESSOA_H
#define _PESSOA_H

typedef struct _pessoa
{
  char nome[50];
  int anoNascimento;
  int idade;
} Pessoa;

void lerDados(Pessoa *p);

void calcularIdade(Pessoa *p);

void mostrarDados(Pessoa *p);

#endif
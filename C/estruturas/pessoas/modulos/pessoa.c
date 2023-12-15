#include <stdio.h>
#include "./pessoa.h"

void lerDados(Pessoa *p)
{
  printf("Digite o nome: ");
  scanf("%s", p->nome);
  printf("Digite o ano de nascimento: ");
  scanf("%d", &p->anoNascimento);
}

void calcularIdade(Pessoa *p)
{
  p->idade = 2023 - p->anoNascimento;
}

void mostrarDados(Pessoa *p)
{
  printf("Nome: %s\n", p->nome);
  printf("Ano de nascimento: %d\n", p->anoNascimento);
  printf("Idade: %d\n", p->idade);
}
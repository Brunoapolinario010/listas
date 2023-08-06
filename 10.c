#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int codigo;
    char nome[100];
    int quantidade;
    float preco;
    char fornecedor[100];
} Produto;

void cadastrarProduto(Produto produtos[], int *quantidadeProdutos) {
    printf("\n");
    printf("--------Cadastro de produto--------\n");
    printf("\n");

    int indice = *quantidadeProdutos;

    produtos[indice].codigo = indice + 1;

    printf("Digite o nome do produto: ");
    scanf("%99s", produtos[indice].nome);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &produtos[indice].quantidade);

    printf("Digite o preço do produto: ");
    scanf("%f", &produtos[indice].preco);

    printf("Digite o fornecedor do produto: ");
    scanf("%99s", produtos[indice].fornecedor);

    *quantidadeProdutos = *quantidadeProdutos + 1;

    printf("\n");
    printf("Produto cadastrado com sucesso!\n");
    printf("\n");
    printf("Código do produto: %d\n", produtos[indice].codigo);
    printf("Nome do produto: %s\n", produtos[indice].nome);
    printf("Quantidade do produto: %d\n", produtos[indice].quantidade);
    printf("Preço do produto: %.2f\n", produtos[indice].preco);
    printf("Fornecedor do produto: %s\n", produtos[indice].fornecedor);
    printf("\n");
}

void comprarProduto(Produto produtos[], int quantidateProdutos) {
    int codigo;

    printf("\n");
    printf("--------Compra de produto--------\n");
    printf("\n");

    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    bool encontrado = false;
    for (int i = 0; i < quantidateProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            int quantidadeComprada;
            printf("Digite a quantidade comprada: ");
            scanf("%d", &quantidadeComprada);

            produtos[i].quantidade += quantidadeComprada;

            printf("Produto comprado com sucesso!\n");
            printf("Existe %d de %s em estoque\n", produtos[i].quantidade, produtos[i].nome);

            encontrado = true;
        }
    }

    if(!encontrado) {
        printf("Produto não encontrado!\n");
    }
}

void venderProduto(Produto produtos[], int quantidateProdutos) {
    int codigo;

    printf("\n");
    printf("--------Venda de produto--------\n");
    printf("\n");

    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    bool encontrado = false;
    for (int i = 0; i < quantidateProdutos; i++) {
        if (produtos[i].codigo == codigo && produtos[i].quantidade > 0) {
            int quantidadeVendida;
            printf("Digite a quantidade vendida: ");
            scanf("%d", &quantidadeVendida);


            if(quantidadeVendida > produtos[i].quantidade) {
                printf("Não é possível vender mais do que existe em estoque!\nExistem %d de %s em estoque\n", produtos[i].quantidade, produtos[i].nome);
                return;
            }

            produtos[i].quantidade -= quantidadeVendida;

            printf("Produto vendido com sucesso!\n");
            printf("Existe %d de %s em estoque\n", produtos[i].quantidade, produtos[i].nome);

            encontrado = true;
        }
    }

    if(!encontrado) {
        printf("Produto não encontrado!\n");
    }
}

void listarProdutos(Produto produtos[], int quantidadeProdutos) {
    if (quantidadeProdutos == 0) {
        printf("Não existem produtos cadastrados!\n");
        return;
    }

    for(int i = 0; i < quantidadeProdutos; i++) {
        printf("\n");
        printf("--------Produto %d--------\n", i + 1);
        printf("\n");
        printf("Código do produto: %d\n", produtos[i].codigo);
        printf("Nome do produto: %s\n", produtos[i].nome);
        printf("Quantidade do produto: %d\n", produtos[i].quantidade);
        printf("Preço do produto: %.2f\n", produtos[i].preco);
        printf("Fornecedor do produto: %s\n", produtos[i].fornecedor);
        printf("Existe %.2f em estoque\n", produtos[i].preco * produtos[i].quantidade);
        printf("\n");
    }
}

void pesquisarProdutoPorCodigo(Produto produtos[], int quantidadeProdutos) {
    int codigo;

    printf("\n");
    printf("--------Pesquisa de produto por código--------\n");
    printf("\n");

    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    bool encontrado = false;
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("\n");
            printf("--------Produto %d--------\n", i + 1);
            printf("\n");
            printf("Código do produto: %d\n", produtos[i].codigo);
            printf("Nome do produto: %s\n", produtos[i].nome);
            printf("Quantidade do produto: %d\n", produtos[i].quantidade);
            printf("Preço do produto: %.2f\n", produtos[i].preco);
            printf("Fornecedor do produto: %s\n", produtos[i].fornecedor);
            printf("\n");

            encontrado = true;
        }
    }

    if(!encontrado) {
        printf("Produto não encontrado!\n");
    }
}

void pesquisarProdutoPorNome(Produto produtos[], int quantidadeProdutos) {
    char nome[100];

    printf("\n");
    printf("--------Pesquisa de produto por nome--------\n");
    printf("\n");

    printf("Digite o nome do produto: ");
    scanf("%99s", nome);

    bool encontrado = false;
    for (int i = 0; i < quantidadeProdutos; i++) {
        if(strcmp(produtos[i].nome, nome) == 0) {
            printf("\n");
            printf("--------Produto %d--------\n", i + 1);
            printf("\n");
            printf("Código do produto: %d\n", produtos[i].codigo);
            printf("Nome do produto: %s\n", produtos[i].nome);
            printf("Quantidade do produto: %d\n", produtos[i].quantidade);
            printf("Preço do produto: %.2f\n", produtos[i].preco);
            printf("Fornecedor do produto: %s\n", produtos[i].fornecedor);
            printf("\n");

            encontrado = true;
        }
    }

    if(!encontrado) {
        printf("Produto não encontrado!\n");
    }
}

void editarProduto(Produto produtos[], int quantidadeProdutos) {
    int codigo;

    printf("\n");
    printf("--------Edição de produto--------\n");
    printf("\n");

    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    bool encontrado = false;
    for(int i = 0; i < quantidadeProdutos; i++) {
        if(produtos[i].codigo == codigo) {
            printf("Digite o novo nome do produto: ");
            scanf("%99s", produtos[i].nome);

            printf("Digite a nova quantidade do produto: ");
            scanf("%d", &produtos[i].quantidade);

            printf("Digite o novo preço do produto: ");
            scanf("%f", &produtos[i].preco);

            printf("Digite o novo fornecedor do produto: ");
            scanf("%99s", produtos[i].fornecedor);

            printf("Produto editado com sucesso!\n");

            encontrado = true;
        }
    }

    if(!encontrado) {
        printf("Produto não encontrado!\n");
    }
}

void main() {
    int opcao;
    Produto produtos[100];
    int quantidadeProdutos = 0;


    do {
        printf("--------Menu--------\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Comprar produto\n");
        printf("3 - Vender produto\n");
        printf("4 - Listar produtos\n");
        printf("5 - Pesquisar produto por código\n");
        printf("6 - Pesquisar produto por nome\n");
        printf("7 - Editar Produto\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            cadastrarProduto(produtos, &quantidadeProdutos);
            break;

        case 2:
            comprarProduto(produtos, quantidadeProdutos);
            break;
        
        case 3:
            venderProduto(produtos, quantidadeProdutos);
            break;
        
        case 4:
            listarProdutos(produtos, quantidadeProdutos);
            break;

        case 5:
            pesquisarProdutoPorCodigo(produtos, quantidadeProdutos);
            break;
        
        case 6:
            pesquisarProdutoPorNome(produtos, quantidadeProdutos);
            break;
        
        case 7:
            editarProduto(produtos, quantidadeProdutos);
            break;
        
        case 0:
            printf("Saindo...\n");
            break;
        
        default:
            printf("Opção inválida!\n");
            break;
        }

    } while (opcao != 0);

}
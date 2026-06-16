#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#define MAX 100

struct Animal {
    int codigo;
    char nome[50];
    char especie[50];
    char raca[50];
    char sexo[50];
    char tutor[50];
    char telefone[50];
    char endereco[200];
    int idade;
};

struct Animal animais[MAX];
int totalAnimais = 0;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarAnimal() {
    if (totalAnimais >= MAX) {
        printf("Limite de cadastros atingido\n");
        return;
    }
    printf("\n--- Cadastro de Animal ---\n");
    printf("Código: ");
    scanf("%d", &animais[totalAnimais].codigo);
    limparBuffer(); 
    
    printf("Nome do animal: ");
    fgets(animais[totalAnimais].nome, 50, stdin);
    strtok(animais[totalAnimais].nome, "\n");
    
    printf("Espécie: ");
    fgets(animais[totalAnimais].especie, 50, stdin);
    strtok(animais[totalAnimais].especie, "\n");
    
    printf("Raça: ");
    fgets(animais[totalAnimais].raca, 50, stdin);
    strtok(animais[totalAnimais].raca, "\n");
    
    printf("Sexo: ");
    fgets(animais[totalAnimais].sexo, 50, stdin);
    strtok(animais[totalAnimais].sexo, "\n");
    
    printf("Idade: ");
    scanf("%d", &animais[totalAnimais].idade);
    limparBuffer(); 
    
    printf("Nome do tutor: ");
    fgets(animais[totalAnimais].tutor, 50, stdin);
    strtok(animais[totalAnimais].tutor, "\n");
    
    printf("Telefone: ");
    fgets(animais[totalAnimais].telefone, 50, stdin);
    strtok(animais[totalAnimais].telefone, "\n");
    
    printf("Endereço: ");
    fgets(animais[totalAnimais].endereco, 200, stdin);
    strtok(animais[totalAnimais].endereco, "\n");
    
    totalAnimais++;
    printf("\nAnimal cadastrado com sucesso!\n");
}

void consultarAnimal() { 
    int codigo;
    int encontrado = 0;
    
    printf("\nDigite o código do animal para consulta: ");
    scanf("%d", &codigo);
    limparBuffer();
    
    for(int i = 0; i < totalAnimais; i++) {
        if(animais[i].codigo == codigo) {
            printf("\n--- Dados do Animal ---\n");
            printf("Código: %d\n", animais[i].codigo);
            printf("Nome: %s\n", animais[i].nome);
            printf("Espécie: %s\n", animais[i].especie);
            printf("Raça: %s\n", animais[i].raca);
            printf("Sexo: %s\n", animais[i].sexo);
            printf("Idade: %d anos\n", animais[i].idade);
            printf("Tutor: %s\n", animais[i].tutor);
            printf("Telefone: %s\n", animais[i].telefone);
            printf("Endereço: %s\n", animais[i].endereco); 
            
            encontrado = 1;
            break;
        }
    }
    
    if(!encontrado) {
        printf("\nAnimal não encontrado!\n");
    }
}

void alterarAnimal() {
    int codigo;
    int encontrado = 0;
    
    printf("\nDigite o código do animal que deseja alterar: ");
    scanf("%d", &codigo);
    limparBuffer();
    
    for(int i = 0; i < totalAnimais; i++) {
        if(animais[i].codigo == codigo) {
            printf("\n--- Editando Dados ---\n");
            printf("Novo nome do animal: ");
            fgets(animais[i].nome, 50, stdin);
            strtok(animais[i].nome, "\n");
    
            printf("Nova espécie: ");
            fgets(animais[i].especie, 50, stdin);
            strtok(animais[i].especie, "\n");
            
            printf("Nova raça: ");
            fgets(animais[i].raca, 50, stdin);
            strtok(animais[i].raca, "\n");
    
            printf("Novo sexo: ");
            fgets(animais[i].sexo, 50, stdin);
            strtok(animais[i].sexo, "\n"); 
    
            printf("Nova idade: ");
            scanf("%d", &animais[i].idade);
            limparBuffer();
    
            printf("Novo nome do tutor: ");
            fgets(animais[i].tutor, 50, stdin);
            strtok(animais[i].tutor, "\n");
    
            printf("Novo telefone: ");
            fgets(animais[i].telefone, 50, stdin);
            strtok(animais[i].telefone, "\n");
    
            printf("Novo endereço: ");
            fgets(animais[i].endereco, 200, stdin);
            strtok(animais[i].endereco, "\n");
            
            printf("\nDados alterados com sucesso!\n");
            encontrado = 1;
            break;
        }
    }
    
    if(!encontrado) {
        printf("\nAnimal não encontrado!\n");
    }
}

void excluirAnimal() {
    int codigo;
    int encontrado = 0;
    
    printf("\nDigite o código do animal que deseja excluir: ");
    scanf("%d", &codigo);
    limparBuffer();
    
    for(int i = 0; i < totalAnimais; i++) {
        if(animais[i].codigo == codigo) {
            for(int j = i; j < totalAnimais - 1; j++) {
                animais[j] = animais[j + 1];
            }
            totalAnimais--;
            printf("\nAnimal excluído com sucesso!\n");
            encontrado = 1;
            break;
        }
    }
    
    if(!encontrado) {
        printf("\nAnimal não encontrado!\n");
    }
}

void listarAnimais() {
    if(totalAnimais == 0) {
        printf("\nNenhum animal cadastrado!\n");
        return;
    }
    printf("\n--- Lista de Animais --- \n");
    for(int i = 0; i < totalAnimais; i++) {
        printf("\nCódigo: %d | Nome: %s | Tutor: %s\n", animais[i].codigo, animais[i].nome, animais[i].tutor);
    }
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
    int opcao;
    
    do {
        printf("\n==================================\n");
        printf("  Clínica Veterinária Vida Animal \n");
        printf("==================================\n");
        printf("1 - Cadastrar Animal\n");
        printf("2 - Consultar Animal\n");
        printf("3 - Alterar Animal\n");
        printf("4 - Excluir Animal\n");
        printf("5 - Listar Animais\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);
        limparBuffer();
        
        switch(opcao) {
            case 1:
                cadastrarAnimal();
                break;
            case 2:
                consultarAnimal(); 
                break;
            case 3:
                alterarAnimal();
                break;
            case 4:
                excluirAnimal();
                break;
            case 5:
                listarAnimais(); 
                break;
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\nOpção inválida!\n"); 
        }
    } while(opcao != 0); 
    
    printf("\nPressione qualquer tecla para fechar.");
    getch(); 
    return 0;
}
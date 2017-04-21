#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONS 10

void delay(int milliseconds);

typedef int bool;
#define true 1
#define false 0

struct {
	char name[32];
	char gender[12];
	int age;
} person[MAX_PERSONS];

int main() {
	
	int i;
	char tmp[8];
	bool exit = false;
	
	for(i = 0; i < MAX_PERSONS; ++i)
	{
		system("color f");
		printf("-> Criar um novo registro para a pessoa %d\n\n", i);
		
		printf("[Pessoa %d] - Digite um nome:", i);
		gets(person[i].name);
		
		printf("[Pessoa %d] - Digite um genero:", i);
		gets(person[i].gender);		
		
		printf("[Pessoa %d] - Digite uma idade:", i);
		gets(tmp);
		
		//converter string  do input pra inteiro, quem dera tivesse a função get como em C++...
		person[i].age = atoi(tmp);
		
		printf("\n\n--- Inserido registro ---\n Nome -> %s\n Genero -> %s\n Idade -> %d\n--- Fim do Registro ---\n\n", person[i].name, person[i].gender, person[i].age);
		
	}
	do
	{
		char tmp[32];
		int x;
		printf("Digite uma alternativa de busca:\n1-Genero\n2-Idade\n3-Sair\nAlternativa:");
		gets(tmp);
		
		if(!strcmp(tmp, "genero"))
		{
			printf("Digite um genero a ser buscado:");
			gets(tmp);
					
			system("cls");
			printf("\n\n---- Resultados da busca -------\n\n", tmp);
			for(x = 0; x < MAX_PERSONS; ++x)
			{
				if(!strcmp(person[x].gender, tmp))
					printf("Pessoa: %d | Nome: %s | Genero: %s\n", x, person[x].name, tmp);
			}
			printf("------- Fim da busca -------\n\n", tmp);
		}
		
		if(!strcmp(tmp, "idade"))
		{
			printf("Digite uma idade a ser buscada (somente numeros):");
			gets(tmp);
			
			int age = atoi(tmp);			
			
			system("cls");
			printf("\n\n---- Resultados da busca -------\n\n", tmp);
			for(x = 0; x < MAX_PERSONS; ++x)
			{
				if(person[x].age == age)
					printf("Pessoa: %d | Nome: %s | Idade: %d\n", x, person[x].name, age);
			}
			printf("------- Fim da busca -------\n\n", tmp);
		}
		if(!strcmp(tmp, "sair"))
		{
			printf("\n\nPoxa... Voce escolheu sair do programa :(\nEspero que volte em breve...\n\n\n");
			exit = true;
			return 0;
		}
		
	}while(!exit);
	return 0;
}

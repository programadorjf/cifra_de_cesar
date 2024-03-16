/*
Autor: João Fabricio
Disiplina de Criptografia e segurança de Dados
		
		TRABALHO 2
EXERCICIO 1. Crie um programa capaz de criptografar e decriptografar usando a cifra de césar. 
Tal programa deverá receber a chave e a mensagem como parâmetro. Para simplificar 
o programa, suponha que o texto claro é composto apenas de letras minúsculas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define pangrama "thequickbrownfoxjumpsoverthelazydog" // Definição do pangrama.

void cesar(int chave, char cript, char texto_claro[100]){ // Função cifra de César. Recebe os parâmetros para criptografar/descriptografar.
	char texto_cifrado[36]; int i=0; // Vetor para receber o texto cifrado, e inicialização do contador.
	
	if (cript=='c' || cript=='C'){ // Condição para criptografar o texto.
		while(texto_claro[i]!='\0'){ // Percorre todos os caracteres do vetor texto_claro.
			texto_cifrado[i] = texto_claro[i]+chave; // Avança no alfabeto cada caracter do texto_claro com o valor da chave e armazena no vetor texto_cifrado.
			if((texto_claro[i] + chave) > 122){ // Verifica se algum caracter está acima dos valores do alfabeto minúsculo.
                texto_cifrado[i] -=26; // Torna o caracter minúsculo, caso necessário.
            }
            if((texto_claro[i] + chave) < 97){ // Verifica se algum caracter está abaixo dos valores do alfabeto minúsculo.
                texto_cifrado[i] +=26; // Torna o caracter minúsculo, caso necessário.
            }
		i++; // Alimenta o contador.
		}
		printf("\n\nTEXTO CRIPTOGRAFADO:\n\n %s",texto_cifrado); // Imprime o texto criptografado.
	}
	if(cript=='d' || cript=='D'){ // Condição para descriptografar o texto.
		while(texto_claro[i]!='\0'){ // Percorre todos os caracteres do vetor texto_claro.
			texto_cifrado[i] = texto_claro[i]-chave; // Retorna no alfabeto cada caracter do texto_claro com o valor da chave e armazena no vetor texto_cifrado.
			if((texto_claro[i]-chave) > 122){ // Verifica se algum caracter está acima dos valores do alfabeto minúsculo.
                texto_cifrado[i] -=26; // Torna o caracter minúsculo, caso necessário.
            }
            if((texto_claro[i]-chave) < 97){ // Verifica se algum caracter está abaixo dos valores do alfabeto minúsculo.
                texto_cifrado[i] +=26; // Torna o caracter minúsculo, caso necessário.
            }
		i++; // Alimenta o contador.
		}
	    printf("\n\nTEXTO DESCRIPTOGRAFADO:\n\n %s",texto_cifrado); // Imprime o texto descriptografado.
	}
}
int main(int argc, char *argv[]){ // Função que gerencia o código.
	int chave=0, teste=1; char cript, texto_claro[100]; // Inicialização das variáveis e vetores.
	printf("CIRPTOGRAFIA E SEGURANCA DE DADOS\nCIFRA DE CESAR - JOAO FABRICIO\n\n"); // Imprime mensagem com informações.
	printf("DIGITE 'C' SE QUISER CIRPTOGRAFAR OU 'D' SE QUISER DESCRIPTOGRAFAR O TEXTO: "); // Imprime a mensagem para que o usuário escolha sua opção.
	scanf("%c",&cript); // Escaneia o que foi digitado pelo usuário e armazena em cript.
	printf("\nDIGITE '1' PARA ESCREVER O TEXTO PARA ENCRIPTACAO / DECRIPTACAO OU \nDIGITE '2' PARA UTILIZAR O PANGRAMA 'thequickbrownfoxjumpsoverthelazydog': "); // Imprime a mensagem para que o usuário escolha sua opção.
	scanf("%i",&teste); // Escaneia o que foi digitado pelo usuário e armazena em teste.
	if(teste==2){ // Verifica se o usuário deseja utilizar o pangrama.
		char texto_claro[100]= pangrama; // Coloca o pangrama "thequickbrownfoxjumpsoverthelazydog" no vetor texto_claro.
	}
	else{ // caso não queira usar o pangrama, poderá digitar o texto.
		printf("\nESCREVA O TEXTO PARA ENCRIPTACAO / DECRIPTACAO (SEM ESPACO ENTRE AS PALAVRAS):\n\n "); // Imprime a mensagem para que o usuário escreva o texto.
		scanf("%s",&texto_claro); // Escaneia o que foi digitado pelo usuário e armazena em texto_claro.
	}
	printf("\nESCOLHA A CHAVE DE ENCRIPTACAO / DECRIPTACAO (VALOR ENTRE 1 E 25): "); // Imprime a mensagem para que o usuário escolha a chave de encriptação.
	scanf("%i",&chave); // Escaneia o que foi digitado pelo usuário e armazena em chave.
	while(chave<1 || chave>25){ // Solicita nova chave, enquanto a chave digitada estiver fora do intervalo aceito.
		printf("A CHAVE DIGITADA ESTA FORA DO INTERVALO ACEITO! \nESCOLHA A CHAVE DE ENCRIPTACAO (VALOR ENTRE 1 E 25): "); // Imprime a mesagem de erro.
		scanf("%i",&chave); // Escaneia o que foi digitado pelo usuário e armazena em chave.
	}		
	cesar(chave, cript, texto_claro); // Chama a função cesar, passando os parâmetros informados pelo usuário.
	printf("\n\n\nPROGRAMA EXECUTADO COM SUCESSO!\n\n\n"); // Imprime mensagem de exito.
	system("pause"); // Aguarda até que uma tecla seja pressionada para fechar a tela após a finalização do programa.
	return 0;
}

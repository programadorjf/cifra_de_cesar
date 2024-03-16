/*
Autor: Jo�o Fabricio
Disiplina de Criptografia e seguran�a de Dados
		
		TRABALHO 2
EXERCICIO 1. Crie um programa capaz de criptografar e decriptografar usando a cifra de c�sar. 
Tal programa dever� receber a chave e a mensagem como par�metro. Para simplificar 
o programa, suponha que o texto claro � composto apenas de letras min�sculas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define pangrama "thequickbrownfoxjumpsoverthelazydog" // Defini��o do pangrama.

void cesar(int chave, char cript, char texto_claro[100]){ // Fun��o cifra de C�sar. Recebe os par�metros para criptografar/descriptografar.
	char texto_cifrado[36]; int i=0; // Vetor para receber o texto cifrado, e inicializa��o do contador.
	
	if (cript=='c' || cript=='C'){ // Condi��o para criptografar o texto.
		while(texto_claro[i]!='\0'){ // Percorre todos os caracteres do vetor texto_claro.
			texto_cifrado[i] = texto_claro[i]+chave; // Avan�a no alfabeto cada caracter do texto_claro com o valor da chave e armazena no vetor texto_cifrado.
			if((texto_claro[i] + chave) > 122){ // Verifica se algum caracter est� acima dos valores do alfabeto min�sculo.
                texto_cifrado[i] -=26; // Torna o caracter min�sculo, caso necess�rio.
            }
            if((texto_claro[i] + chave) < 97){ // Verifica se algum caracter est� abaixo dos valores do alfabeto min�sculo.
                texto_cifrado[i] +=26; // Torna o caracter min�sculo, caso necess�rio.
            }
		i++; // Alimenta o contador.
		}
		printf("\n\nTEXTO CRIPTOGRAFADO:\n\n %s",texto_cifrado); // Imprime o texto criptografado.
	}
	if(cript=='d' || cript=='D'){ // Condi��o para descriptografar o texto.
		while(texto_claro[i]!='\0'){ // Percorre todos os caracteres do vetor texto_claro.
			texto_cifrado[i] = texto_claro[i]-chave; // Retorna no alfabeto cada caracter do texto_claro com o valor da chave e armazena no vetor texto_cifrado.
			if((texto_claro[i]-chave) > 122){ // Verifica se algum caracter est� acima dos valores do alfabeto min�sculo.
                texto_cifrado[i] -=26; // Torna o caracter min�sculo, caso necess�rio.
            }
            if((texto_claro[i]-chave) < 97){ // Verifica se algum caracter est� abaixo dos valores do alfabeto min�sculo.
                texto_cifrado[i] +=26; // Torna o caracter min�sculo, caso necess�rio.
            }
		i++; // Alimenta o contador.
		}
	    printf("\n\nTEXTO DESCRIPTOGRAFADO:\n\n %s",texto_cifrado); // Imprime o texto descriptografado.
	}
}
int main(int argc, char *argv[]){ // Fun��o que gerencia o c�digo.
	int chave=0, teste=1; char cript, texto_claro[100]; // Inicializa��o das vari�veis e vetores.
	printf("CIRPTOGRAFIA E SEGURANCA DE DADOS\nCIFRA DE CESAR - JOAO FABRICIO\n\n"); // Imprime mensagem com informa��es.
	printf("DIGITE 'C' SE QUISER CIRPTOGRAFAR OU 'D' SE QUISER DESCRIPTOGRAFAR O TEXTO: "); // Imprime a mensagem para que o usu�rio escolha sua op��o.
	scanf("%c",&cript); // Escaneia o que foi digitado pelo usu�rio e armazena em cript.
	printf("\nDIGITE '1' PARA ESCREVER O TEXTO PARA ENCRIPTACAO / DECRIPTACAO OU \nDIGITE '2' PARA UTILIZAR O PANGRAMA 'thequickbrownfoxjumpsoverthelazydog': "); // Imprime a mensagem para que o usu�rio escolha sua op��o.
	scanf("%i",&teste); // Escaneia o que foi digitado pelo usu�rio e armazena em teste.
	if(teste==2){ // Verifica se o usu�rio deseja utilizar o pangrama.
		char texto_claro[100]= pangrama; // Coloca o pangrama "thequickbrownfoxjumpsoverthelazydog" no vetor texto_claro.
	}
	else{ // caso n�o queira usar o pangrama, poder� digitar o texto.
		printf("\nESCREVA O TEXTO PARA ENCRIPTACAO / DECRIPTACAO (SEM ESPACO ENTRE AS PALAVRAS):\n\n "); // Imprime a mensagem para que o usu�rio escreva o texto.
		scanf("%s",&texto_claro); // Escaneia o que foi digitado pelo usu�rio e armazena em texto_claro.
	}
	printf("\nESCOLHA A CHAVE DE ENCRIPTACAO / DECRIPTACAO (VALOR ENTRE 1 E 25): "); // Imprime a mensagem para que o usu�rio escolha a chave de encripta��o.
	scanf("%i",&chave); // Escaneia o que foi digitado pelo usu�rio e armazena em chave.
	while(chave<1 || chave>25){ // Solicita nova chave, enquanto a chave digitada estiver fora do intervalo aceito.
		printf("A CHAVE DIGITADA ESTA FORA DO INTERVALO ACEITO! \nESCOLHA A CHAVE DE ENCRIPTACAO (VALOR ENTRE 1 E 25): "); // Imprime a mesagem de erro.
		scanf("%i",&chave); // Escaneia o que foi digitado pelo usu�rio e armazena em chave.
	}		
	cesar(chave, cript, texto_claro); // Chama a fun��o cesar, passando os par�metros informados pelo usu�rio.
	printf("\n\n\nPROGRAMA EXECUTADO COM SUCESSO!\n\n\n"); // Imprime mensagem de exito.
	system("pause"); // Aguarda at� que uma tecla seja pressionada para fechar a tela ap�s a finaliza��o do programa.
	return 0;
}

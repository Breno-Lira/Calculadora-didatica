#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decimalParaBinario(int numero);
void decimalParaOcta(int numero);
void decimalParaHexa(int numero);

//Aluno: Breno Monterio Rodrigues Lira
// 25/08/24: Commit primeria questão, implementando as letras a,b,c e d

int main(void){

    int operacao, num, temp;

    while(1){

        printf("Converter numero de base 10 para:\n1-Binario\n2-Octadecimal\n3-Hexadecimal\n4-Codigo BCD\n");
        scanf("%d", &operacao);

        if (operacao!=4){
           printf("\nDigite um numero: ");
            scanf("%d", &num);
            temp = num;
        }
        else{
            getchar();
            char numStr[100];
            int cont = 0;

            printf("\nDigite um numero: ");
            scanf("%s", numStr);

            while (numStr[cont] != '\0'){
                temp = numStr[cont] - '0';
                printf("%d(10) = ", temp);
                if(temp<2){
                    printf("000");
                    decimalParaBinario(temp);
                }
                else if (temp<4){
                    printf("00");
                    decimalParaBinario(temp);
                }
                else if (temp<=7){
                    printf("0");
                    decimalParaBinario(temp);
                }
                else{
                    decimalParaBinario(temp);
                }
                printf("(2)");
                printf("\n");
                cont++;
            }
            cont=0;
            printf("BCD = ");
            while (numStr[cont] != '\0'){
                temp = numStr[cont] - '0';
                if(temp<2){
                    printf("000");
                    decimalParaBinario(temp);
                    printf(" ");
                }
                else if (temp<4){
                    printf("00");
                    decimalParaBinario(temp);
                    printf(" ");
                }
                else if (temp<=7){
                    printf("0");
                    decimalParaBinario(temp);
                    printf(" ");
                }
                else{
                    decimalParaBinario(temp);
                    printf(" ");
                }
                cont++;
            }
            printf("\n\n");

        }

        if (operacao==1){
            while (temp > 1) {
                printf("%d %% 2 = %d\n", temp, temp % 2);
                if (temp/2 == 1){
                    printf("%d / 2 = 1\n", temp);
                }
                temp = temp/2;
            }
            printf("Binario = ");
            decimalParaBinario(num);
            printf("\n\n");
        }

        else if (operacao==2){
            while (temp >= 8) {
                printf("%d %% 8 = %d\n", temp, temp % 8);
                if (temp/8 < 8){
                    printf("%d / 8 = %d\n", temp, temp/8);
                }
                temp = temp/8;
            }
            printf("Octadecimal = ");
            decimalParaOcta(num);
            printf("\n\n");
        }

        else if (operacao==3){
            while (temp >= 16) {
                printf("%d %% 16 = %d\n", temp, temp % 16);
                if (temp/16 < 16){
                    printf("%d / 16 = %d\n", temp, temp/16);
                }
                temp = temp/16;
            }
            printf("Hexadecimal = ");
            decimalParaHexa(num);
            printf("\n\n");
        }

    }

    return 0;
}


void decimalParaBinario(int numero) {
    if (numero > 1) {
        decimalParaBinario(numero / 2);
    }
    printf("%d", numero % 2);
}

void decimalParaOcta(int numero) {
    if (numero >= 8) {
        decimalParaOcta(numero / 8);
    }
    printf("%d", numero % 8);
}

void decimalParaHexa(int numero) {
    if (numero >= 16) {
        decimalParaHexa(numero / 16);
    }
    if(numero%16 == 10){
        printf("A");
    }
    if(numero%16 == 11){
        printf("B");
    }
    if(numero%16 == 12){
        printf("C");
    }
    if(numero%16 == 13){
        printf("D");
    }
    if(numero%16 == 14){
        printf("E");
    }
    if(numero%16 == 15){
        printf("F");
    }
    if (numero%16 < 10){
        printf("%d", numero % 16);
    }
}



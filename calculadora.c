#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void decimalParaBinario(int numero);
void decimalParaOcta(int numero);
void decimalParaHexa(int numero);
void decimal16bits(int numero);
void realparafloat(double numero);
void Mantissafloat(double fracao, int cont2);
void realparadouble(double numero);
void Mantissadouble(double fracao, int cont2);

//Aluno: Breno Monterio Rodrigues Lira
// 25/08/24: Commit primeria questão, implementando as letras a,b,c e d
// 25/08/24: Implementado a fucao de 16 bits e complemento a 2
// 27/08/24: Adicionando as ultimas funcionalidades de conversão para flaot e double 

int main(void){

    int operacao, num, temp;

    while(1){

        printf("Converter numero de base 10 para:\n1-Binario\n2-Octadecimal\n3-Hexadecimal\n4-Codigo BCD\n5-16 bits(binario)\n6-Float\n7-Double\n");
        scanf("%d", &operacao);

        if (operacao!=4 && operacao!=6 && operacao!=7){
            if (operacao>7 || operacao<1){
                printf("\n\nSAINDO.....");
                break;
            }
            printf("\nDigite um numero: ");
            scanf("%d", &num);
            temp = num;
        }
        else if (operacao==4){
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
        
        else if (operacao==5){
            if(num>pow(2,15)-1 || num<-(pow(2,15))){
                printf("Overflow\n\n");
            }
            else{
                decimal16bits(num);
                printf("\n");
            }
        }


        else if (operacao==6){
            double num2;
            printf("\nDigite um numero: ");
            scanf("%lf", &num2);
            realparafloat(num2);
        }

        else if (operacao==7){
            double num2;
            printf("\nDigite um numero: ");
            scanf("%lf", &num2);
            realparadouble(num2);
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

void decimal16bits(int numero) {
    int binario[16];
    int i;

    for (i = 0; i < 16; i++) {
        binario[i] = 0;
    }

    if (numero < 0) {
        numero = pow(2,16) + numero;
    }

    for (i = 15; numero > 0 && i >= 0; i--) {
        binario[i] = numero % 2;
        numero = numero/2;
    }

    printf("O numero em 16 bits: ");
    for (i = 0; i < 16; i++) {
        printf("%d", binario[i]);
    }
    printf("\n");
}

void realparafloat(double numero) {
    int binario[8];
    int binario2[8] = {0};
    int i, sinal = 0;
    int temp = numero, temp2 = numero;
    double fracao = fabs(numero) - abs(temp);
    
    for (i = 0; i < 8; i++) {
        binario[i] = 0;
    }

    if(temp == 0){
        int mantissa[23];
        int contMant=0;
        int cont3=0;
        
        if (numero < 0) {
            sinal=1;
        }
        
        printf("Bit de sinal: %d\n", sinal);
        printf("Expoente sem vies em float: ");
        for (i = 0; i < 8; i++) {
            printf("%d", binario[i]);
        }
        printf("\n");

        for (i = 0; i < 23; i++) {
           mantissa[i] = 0;
        }
        for (i = 0; i < 23 && fracao > 0; i++) {
            fracao *= 2;
            if (fracao >= 1) {
                cont3++;
                if(cont3==1){
                    contMant=(i+1)*(-1);
                }
                mantissa[i] = 1;
                fracao -= 1;
            } else {
                mantissa[i] = 0;
            }
        }

        temp2 = contMant + 127;
        for (i = 7; temp2 > 0 && i >= 0; i--) {
            binario2[i] = temp2 % 2;
            temp2 = temp2/2;
        }
        
        printf("Expoente com vies em float: ");
        for (i = 0; i < 8; i++) {
            printf("%d", binario2[i]);
        }
        printf("\n");


        cont3=0;
        printf("Mantissa: ");
        for (i = 0; i < 23; i++) {
            if (cont3>0){
                printf("%d", mantissa[i]);
            }
            if (mantissa[i] == 1){
                cont3++;
            }
        }
        printf("\n");

        printf("Valor completo do numero em float: ");
        printf("%d ", sinal);
        for (i = 0; i < 8; i++) {
            printf("%d", binario2[i]);
        }
        printf(" ");
        cont3=0;
        for (i = 0; i < 23; i++) {
            if (cont3>0){
                printf("%d", mantissa[i]);
            }
            if (mantissa[i] == 1){
                cont3++;
            }
        }

        printf("\n\n");
    }

    else{

        if (temp < 0) {
            temp = temp*(-1);
            sinal=1;
        }
        if (temp2 < 0) {
            temp2 = temp2*(-1);
        }

        for (i = 7; temp > 0 && i >= 0; i--) {
            binario[i] = temp % 2;
            temp = temp/2;
        }

        printf("Bit de sinal: %d\n", sinal);
        printf("Expoente sem vies em float: ");
        for (i = 0; i < 8; i++) {
            printf("%d", binario[i]);
        }
        printf("\n");
        
        int cont=0, cont2=0;
        for (i = 0; i < 8; i++) {
            if(cont>0){
                cont2++;
            }
            if (i!=0 && binario[i]==1 && cont==0){
                cont++;
            }
        }
        

        temp2 = cont2 + 127;
        for (i = 7; temp2 > 0 && i >= 0; i--) {
            binario2[i] = temp2 % 2;
            temp2 = temp2/2;
        }
        printf("Expoente com vies em float: ");
        for (i = 0; i < 8; i++) {
            printf("%d", binario2[i]);
        }
        printf("\n");

        printf("Mantissa: ");
        cont = 0;
        for (i = 0; i < 8; i++) {
            if(cont>0){
                printf("%d", binario[i]);
            }
            if (i!=0 && binario[i]==1 && cont==0){
                printf(",");
                cont++;
            }
        }
        Mantissafloat(fracao, cont2);
        
        printf("Valor completo do numero em float: ");
        printf("%d ", sinal);
        for (i = 0; i < 8; i++) {
            printf("%d", binario2[i]);
        }
        cont = 0;
        for (i = 0; i < 8; i++) {
            if(cont>0){
                printf("%d", binario[i]);
            }
            if (i!=0 && binario[i]==1 && cont==0){
                printf(" ");
                cont++;
            }
        }
        Mantissafloat(fracao, cont2);

        printf("\n\n");
    }
}


void Mantissafloat(double fracao, int cont2) {
    int mantissa[23];
    int i;

    for (i = 0; i < 23; i++) {
           mantissa[i] = 0;;
    }
    
    for (i = 0; i < 23 -cont2 && fracao > 0; i++) {
        fracao *= 2;
        if (fracao >= 1) {
            mantissa[i] = 1;
            fracao -= 1;
        } else {
            mantissa[i] = 0;
        }
    }

    for (i = 0; i < 23 - cont2; i++) {
           printf("%d", mantissa[i]);
    }

    printf("\n");
}


void realparadouble(double numero){
    int binario[11];
    int binario2[11] = {0};
    int i, sinal = 0;
    int temp = numero, temp2 = numero;
    double fracao = fabs(numero) - abs(temp);
    
    for (i = 0; i < 11; i++) {
        binario[i] = 0;
    }

    if(temp == 0){
        int mantissa[52];
        int binario3[11] = {0};
        int contMant=0;
        int cont3=0;
        
        if (numero < 0) {
            sinal=1;
        }
        
        printf("Bit de sinal: %d\n", sinal);
        printf("Expoente sem vies em double: ");
        for (i = 0; i < 11; i++) {
            printf("%d", binario[i]);
        }
        printf("\n");

    
        for (i = 0; i < 52; i++) {
           mantissa[i] = 0;
        }
        for (i = 0; i < 52 && fracao > 0; i++) {
            fracao *= 2;
            if (fracao >= 1) {
                cont3++;
                if(cont3==1){
                    contMant=(i+1)*(-1);
                }
                mantissa[i] = 1;
                fracao -= 1;
            } else {
                mantissa[i] = 0;
            }
        }


        temp2 = contMant + 1023;
        for (i = 10; i >= 0; i--) {
            binario3[i] = temp2 % 2;
            temp2 = temp2 / 2;
        }
        
        printf("Expoente com vies em double: ");
        for (i = 0; i < 11; i++) {
            printf("%d", binario3[i]);
        }
        printf("\n");
        

        cont3=0;
        printf("Mantissa: ");
        for (i = 0; i < 52; i++) {
            if (cont3>0){
                printf("%d", mantissa[i]);
            }
            if (mantissa[i] == 1){
                cont3++;
            }
        }
        printf("\n");

        printf("Valor completo do numero em double: ");
        printf("%d ", sinal);
        for (i = 0; i < 11; i++) {
            printf("%d", binario3[i]);
        }
        printf(" ");
        cont3=0;
        for (i = 0; i < 52; i++) {
            if (cont3>0){
                printf("%d", mantissa[i]);
            }
            if (mantissa[i] == 1){
                cont3++;
            }
        }

        printf("\n\n");
    }

    else{
        if (temp < 0) {
            temp = temp*(-1);
            sinal=1;
        }
        if (temp2 < 0) {
            temp2 = temp2*(-1);
        }

        for (i = 10; temp > 0 && i >= 0; i--) {
            binario[i] = temp % 2;
            temp = temp/2;
        }

        printf("Bit de sinal: %d\n", sinal);
        printf("Expoente sem vies em double: ");
        for (i = 0; i < 11; i++) {
            printf("%d", binario[i]);
        }
        printf("\n");
        
        int cont=0, cont2=0;
        for (i = 0; i < 11; i++) {
            if(cont>0){
                cont2++;
            }
            if (i!=0 && binario[i]==1 && cont==0){
                cont++;
            }
        }

        temp2 = cont2 + 1023;
        for (i = 10; temp2 > 0 && i >= 0; i--) {
            binario2[i] = temp2 % 2;
            temp2 = temp2/2;
        }
        printf("Expoente com vies em double: ");
        for (i = 0; i < 11; i++) {
            printf("%d", binario2[i]);
        }
        printf("\n");

        printf("Mantissa: ");
        cont = 0;
        for (i = 0; i < 11; i++) {
            if(cont>0){
                printf("%d", binario[i]);
            }
            if (i!=0 && binario[i]==1 && cont==0){
                printf(",");
                cont++;
            }
        }
        Mantissadouble(fracao, cont2);
        
        printf("Valor completo do numero em double: ");
        printf("%d ", sinal);
        for (i = 0; i < 11; i++) {
            printf("%d", binario2[i]);
        }
        cont = 0;
        for (i = 0; i < 11; i++) {
            if(cont>0){
                printf("%d", binario[i]);
            }
            if (i!=0 && binario[i]==1 && cont==0){
                printf(" ");
                cont++;
            }
        }
        Mantissadouble(fracao, cont2);

        printf("\n\n");
    }
}

void Mantissadouble(double fracao, int cont2) {
    int i;
    int mantissa[52];

    for (i = 0; i < 52; i++) {
           mantissa[i] = 0;;
    }
    
    for (i = 0; i < 52 -cont2 && fracao > 0; i++) {
        fracao *= 2;
        if (fracao >= 1) {
            mantissa[i] = 1;
            fracao -= 1;
        } else {
            mantissa[i] = 0;
        }
    }

    for (i = 0; i < 52 - cont2; i++) {
           printf("%d", mantissa[i]);
    }

    printf("\n");
}
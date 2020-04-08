/*
 * File:   main.c
 * Author: Esteban
 *
 * Created on 4 de abril de 2020, 01:19 AM
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 *
 */


int fibonacci(int n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));
}

int MCD(int mayor, int menor) {
    int operation = mayor % menor;
    if (operation == 0) {
        return menor;
    } else {
        return operation;
    }
}

int isPrime(int numero) {
    if (numero < 2 || (numero % 2 == 0 && numero != 2)) {
        return 0;
    } else {
        for (int x = 3; x * x <= numero; x += 2) {
            if (numero % x == 0) {
                return 0;
            }
        }

    }
    return 1;
}

int number_Friens(int num1, int num2) {

    printf("\n num1 %i \n num2 %i", num1, num2);
    int f, count1 = 0, count2;
    for (f = 1; f <= num1; f++) {
        if (num1 <= f) {
            if (num1 % f == 0) {
                count1 = count1 + f;

            }
        }

        if (num2 <= f) {
            if (num2 % f == 0) {
                count2 += f;
            }
        }

    }

    printf("\n cont1 %i \n cont2 %i", count1, count2);

    if (num1 == count2 && num2 == count1) {
        printf("sin amigos");

    }

}

void capicua(int num) {
    int unidad, decena, centena;
    centena = num / 100;
    decena = (num % 100) / 10;
    unidad = (num % 100) % 10;
    if (centena == unidad) {
        printf("capicua");
    } else {
        printf("no capicua");
    }
}



void palindroma(){
     char palabra[20];
    int i, j;
    int palindromo = 1;
    printf("Escribe una cadena: ");
    fflush(stdout);
    gets(palabra);
    j=strlen(palabra)-1;
    for(i=0; i<strlen(palabra)/2; i++, j--) {
        printf("Comprobando %c==%c\n", *(palabra+i), *(palabra+j));
        if (*(palabra+i)!=*(palabra+j)) {
            palindromo = 0;
            break;
        }
    }
    if (palindromo)
        printf("\nEs un palíndrimo.\n");
    else
        printf("\nNo es un palíndrimo.\n");

}

int bisisesto(int year){
    if(year%4==0){
        return 1;
    }else{
        if(year%100==0){
            return 0;
        }else{
            if(year%400==0){
                return 1;
            }
        }

    }
}
int main() {
    int option, num1, num2=0, f;
    char op[35];
    printf(" 1) Fibonacci \n 2) MCD\n 3) primo \n 4) numeros amigo \n 5) numero capicua \n 6) palabra palijndroma \n 7) año bisiesto");
    scanf("%i", &option);
    fflush(stdin);
    switch (option) {
        case 1:
            printf("Digite el termino de la suma Fibonacci que desea saber");
            scanf("%i", &num1);
            printf("el resultado es %i", fibonacci(num1));
            break;
        case 2:
            printf("Digite el primer numero ");
            scanf("%i", &num1);
            printf("Digite el segundo numero ");
            scanf("%i", &num2);
            printf("MCD: %i", (num1 > num2 ? MCD(num1, num2) : MCD(num2, num1)));
            break;
        case 3:

            printf("Digite el numero ");
            scanf("%i", &num1);
            printf("numero %i",num1);
            for (f = num1; f >= 1; f--) {
                if (isPrime(f) == 1) {
                    printf("- %i \n", f);
                }
            }

            break;
        case 4:
            printf("Digite el primer numero ");
            scanf("%i", &num1);
            printf("Digite el segundo numero ");
            scanf("%i", &num2);
            num1 > num2 ? number_Friens(num1, num2) : number_Friens(num2, num1);

            break;
        case 5:
            printf("Digite el primer numero ");
            scanf("%i", &num1);
            capicua(num1);

            break;
        case 6:
            palindroma();
            break;
            case 7:
              printf("Digite el primer numero ");
            scanf("%i", &num1);
            bisisesto(num1)==1? printf("Es bisiesto "):printf("No es bisiesto ");
            break;
    }


    getchar();


    return (EXIT_SUCCESS);
}




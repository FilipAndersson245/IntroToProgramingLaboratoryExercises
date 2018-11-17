#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "exercises.h"
#include <stdlib.h>
#include "simpio.h"

#pragma warning(disable:4996)

typedef struct Cordinate {
    float X, Y;
};

int exercise1(void) {
    float x, y, r, phi;

    printf("Write x and y to display them as polar: ");
    scanf_s("%f %f", &x, &y);

    cartesianToPolarByParameters(x, y, &r, &phi);
    printf("Cartesian: %g   %g\n Polar: %g   %g\n", x, y, r, phi);
}

cartesianToPolarByParameters(float x, float y, float * r, float * phi) {
    *r = sqrtf(powf(x, 2) + powf(y, 2));
    *phi = atan2f(y, x);
}

int exercise2(void) {
    float r, phi;
    printf("Write r and phi to display them as Cartesian: ");
    scanf_s("%f %f", &r, &phi);

    Cordinate cartesian = polarToCartesianByStruct(r, phi);
    printf("Polar: %g   %g\nCartesian:  %g   %g\n", r, phi, cartesian.X, cartesian.Y);
}

Cordinate polarToCartesianByStruct(float r, float phi) {
    Cordinate cartesian = { .X = r * cos(phi),.Y = r * sin(phi) };
    return cartesian;
}

int exercise3(void) {
    printf("Write a char that we can give you info about: ");
    getchar();
    char ch;
    /*unsigned char ch = getchar();*/
    scanf_s("%c", &ch);
    testChar(ch);
    testUnsignedChar(ch);
}

void testChar(char ch) {
    printf("%C is: ", ch);
    if (isalnum(ch)) {
        printf("Alfanumerisk ");
        if (isalpha(ch)) {
            printf("Bokstav ");
            if (isupper(ch)) {
                printf("Versal ");
            }
            else if (islower(ch)) {
                printf("Gemen ");
            }
        }
        else if (isalnum(ch)) {
            printf("Siffra ");
        }
    }
    else if (ispunct(ch)) {
        printf("PunktSymbol");
    }
    else if (isspace(ch)) {
        printf("Vitt tecken");
    }
    else {
        printf("okant tecken");
    }
    printf("\n");
}

void testUnsignedChar(unsigned char ch) {
    printf("%c is: ", ch);
    if (isalnum(ch)) {
        printf("Alfanumerisk ");
        if (isalpha(ch)) {
            printf("Bokstav ");
            if (isupper(ch)) {
                printf("Versal ");
            }
            else if (islower(ch)) {
                printf("Gemen ");
            }
        }
        else if (isalnum(ch)) {
            printf("Siffra ");
        }
    }
    else if (ispunct(ch)) {
        printf("PunktSymbol");
    }
    else if (isspace(ch)) {
        printf("Vitt tecken");
    }
    else {
        printf("okant tecken");
    }
    printf("\n");
}

int exercise4(void) {
    char myStr[10];
    printf("%s\n", myStr);
    printf("len: %d\n", strlen(myStr));
    myStr[9] = '\0';
    printf("len: %d\n", strlen(myStr));
    printf("%s\n\n", myStr);

    char* myCharPtr;
    // printf("%s\n", myCharPtr); // Uninitalized local variable 'myCharPtr' used

    getchar();
    int size = 0;
    scanf_s("%d", &size);

    myCharPtr = malloc(sizeof(char) * (size));
    for (int i = 0; i < size; i++) {
        myCharPtr[i] = (65 + i);
    }
    printf("%s\n", myCharPtr);

    myCharPtr[size / 2] = '\0';
    printf("%s\n", myCharPtr);

    /*
    Stack vs Heap
    Must allocate memmory yourself when using pointers (Heap).
    */

    free(myCharPtr);
}

bool isPalindrom(string text) {
    size_t len = strlen(text);
    string placeholder = malloc(sizeof(char)* len);
    size_t currentPos = 0;
    for (size_t i = 0; text[i] != '\0'; i++)
    {
        if (text[i] != ' ') {
            placeholder[currentPos] = tolower(text[i]);
            currentPos++;
        }
    }
    int start = 0;
    int end = currentPos - 1;
    while (end > start)
    {
        if (placeholder[start++] != placeholder[end--]) {
            free(placeholder);
            return FALSE;
        }
    }
    free(placeholder);
    return TRUE;
}

int exercise5(void) {
    FILE *infile = fopen("../LaboratoryFive/palindrom_test.txt", "r");
    FILE *outfile = fopen("../LaboratoryFive/palindroms.txt", "w");
    if (infile == NULL) {
        printf("Error occured when reading file!");
        return;
    }
    if (outfile == NULL) {
        printf("Error occured when writing to file!");
        return;
    }
    string line = "";
    while (TRUE) {
        line = ReadLine(infile);
        if (line == NULL)
            break;
        if (isPalindrom(line)) {
            fprintf(outfile, "%s\n", line);
        }
    }
    fclose(infile);
    fclose(outfile);
    return;
}
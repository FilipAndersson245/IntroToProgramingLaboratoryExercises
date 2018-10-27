#define PI  3.14159265358979

#include <stdio.h>

#include <time.h>
#include <stdlib.h>

#include <math.h>

#include "Common.h";

int exercise1() {
    int sumToBeBellow = 0;
    scanf_s("%d", &sumToBeBellow);

    int amountOfLoops = 0;
    int sumOfGeneratedNumbers = 0;
    float avgValueOfGeneratedNumbers = 0;

    while (sumOfGeneratedNumbers < sumToBeBellow)
    {
        amountOfLoops++;
        sumOfGeneratedNumbers += rand() % 100;
    }
    avgValueOfGeneratedNumbers = (float)sumOfGeneratedNumbers / amountOfLoops;
    printf("number of loops: %d \nSum of generated numbers: %d \navg of the generated values: %.1f \n",
        amountOfLoops, sumOfGeneratedNumbers, avgValueOfGeneratedNumbers);

    return 0;
}

int exercise2() {
    int loopsUntilStop = 0;
    scanf_s("%d", &loopsUntilStop);

    int numberOfSumerisedValues = 0;
    int sumOfGeneratedNumbers = 0;
    float avgValueOfGeneratedNumbers = 0;

    for (int i = 0; i < loopsUntilStop; i++)
    {
        numberOfSumerisedValues++;
        sumOfGeneratedNumbers += rand() % 100;
    }
    avgValueOfGeneratedNumbers = (float)sumOfGeneratedNumbers / numberOfSumerisedValues;
    printf("number of loops: %d \nSum of generated numbers: %d \navg of the generated values: %.1f \n",
        numberOfSumerisedValues, sumOfGeneratedNumbers, avgValueOfGeneratedNumbers);

    return 0;
}

int exercise3() {
    int exit = 0;
    printf("Calculate\n\n1 Sqrt\n2 Abs\n3 Exp of e^x\n4 ln\n5 Sin\n6 Cos\n0 to exit\n\nWhat do you pick: ");
    do
    {
        float val = 0;

        int command = 0;
        scanf_s("%d", &command);

        switch (command)
        {
        case 0:
            exit = 1;
            break;
        case 1:
            scanf_s("%f", &val);
            printf("Sqrt of %g is %g", val, sqrt(val));
            break;
        case 2:
            scanf_s("%f", &val);
            printf("Abs of %g is %g", val, abs(val));
            break;
        case 3:
            scanf_s("%f", &val);
            printf("Exp of %g is %g", val, exp(val));
            break;
        case 4:
            scanf_s("%f", &val);
            printf("Ln of %g is %g", val, log(val));
            break;
        case 5:
            scanf_s("%f", &val);
            printf("Sin of %g is %g", val, sin(val));
            break;
        case 6:
            scanf_s("%f", &val);
            printf("Cos of %g is %g", val, cos(val));
            break;
        default:
            printf("Invalid command\n");
            break;
        }
        printf("\n");
    } while (!exit);
    return 0;
}

int main(int argc, char *argv[]) {
    srand((int)time(NULL)); // Set seed to least significant byte
    Exercise a[] = { {exercise1,1},{exercise2,2}, {exercise3,3} };
    runExercises(a, 3);
}
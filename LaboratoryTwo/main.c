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

int exercise4() {
    int dice1 = 1, dice2 = 1, dice3 = 1;
    int money = 50;
    while (1)
    {
        printf("Do you wannt to play? (y/n)? ");
        char playOrNotToPlay = ' ';
        while ((playOrNotToPlay = getchar()) != '\n' && playOrNotToPlay != EOF) {}
        playOrNotToPlay = getchar();
        if (playOrNotToPlay == 'n')
            break;
        else if (playOrNotToPlay != 'y')
            continue;

        money -= 10;
        dice1 = (rand() % 6) + 1;
        dice2 = (rand() % 6) + 1;
        dice2 = (rand() % 6) + 1;

        if (dice1 == dice2 && dice2 == dice3) {
            if (dice1 == 6) {
                printf("You won BIG! +100kr\n");
                money += 100;
            }
            else {
                printf("You won! +50kr\n");
                money += 50;
            }
        }
        else if (dice1 == dice2 || dice2 == dice3 || dice1 == dice3) {
            printf("You got your moneys worth +10kr\n");
            money += 10;
        }
        else {
            printf("You lost! +0kr\n");
        }
        printf("Money:%d\ndices: %d, %d, %d\n", money, dice1, dice2, dice3);

        if (money < 10) {
            printf("You got thrown out becuse you had no money!\n");
            break;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    srand((int)time(NULL)); // Set seed to least significant byte
    Exercise a[] = { {exercise1, 1},{exercise2, 2}, {exercise3, 3}, {exercise4, 4} };
    runExercises(a, 3);
}
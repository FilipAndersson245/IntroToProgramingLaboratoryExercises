#include <stdio.h>
#include "Exercises.h"

int exercise1() {
    char myFavoriteCharacter;
    char myFirstName[20];

    printf("Hello world!\n");
    printf("-------------------------\n");

    printf("Please enter your favorite character: ");
    myFavoriteCharacter = getchar();
    getchar();
    printf("Thanks! I now know that your favorite character is %c.\n", myFavoriteCharacter);
    printf("-------------------------\n");

    printf("Please enter your first name: ");
    scanf_s("%s", myFirstName, sizeof(myFirstName));
    getchar();
    printf("Thanks! I now know that your first name is %s", myFirstName);
    getchar(); // Makes the program wait for a [ENTER]-press
    return 0;
}

int exercise2() {
    const int baseInt = 5, heightInt = 5;
    const float baseFloat = baseInt, heightFloat = heightInt;

    const int   a0 = baseInt * heightInt / 2;
    const float a1 = baseInt * heightInt / 2;
    const int   a2 = baseInt * (heightInt / 2);
    const float a3 = baseFloat * (heightInt / 2);
    const float a4 = baseInt * (heightFloat / 2);
    const float a5 = baseFloat * heightInt / 2;
    const int   a6 = baseFloat * heightInt / 2;

    printf("+-------+-------+--------+----------------------------+--------+ \n");
    printf("| area  | base  | height | expression                 | result | \n");
    printf("+-------+-------+--------+----------------------------+--------+ \n");
    printf("| int   | int   | int    | area = base *  height / 2  | %4d   |  \n", a0);
    printf("+-------+-------+--------+----------------------------+--------+ \n");
    printf("| float | int   | int    | area = base *  height / 2  | %4g   |  \n", a1);
    printf("+-------+-------+--------+----------------------------+--------+ \n");
    printf("| int   | int   | int    | area = base * (height / 2) | %4d   |  \n", a2);
    printf("+-------+-------+--------+----------------------------+--------+ \n");
    printf("| float | float | int    | area = base * (height / 2) | %4g   |  \n", a3);
    printf("+-------+-------+--------+----------------------------+--------+ \n");
    printf("| float | int   | float  | area = base * (height / 2) | %4g   |  \n", a4);
    printf("+-------+-------+--------+----------------------------+--------+ \n");
    printf("| float | float | int    | area = base *  height / 2  | %4g   |  \n", a5);
    printf("+-------+-------+--------+----------------------------+--------+ \n");
    printf("| int   | float | int    | area = base *  height / 2  | %4d   |  \n", a6);
    printf("+-------+-------+--------+----------------------------+--------+ \n");

    getchar();
    return 0;
}

int exercise3() {
    int number;       // A number to test if it's uneven
    int totalAmount;  // The amount of integers that stall be summed. Given by the user.
    int summedAmount; // Keeps track of the summed so far
    int sum = 0;

    /*
     * Tell the user what the program should do!
     */
    printf("The program sums the first uneven positive integers 1 + 3 + 5 + ...\n");
    printf("As many as you wish \n\n");

    /*
     * Read the amount of integers that should be added.
     */
    printf("How many numbers shall be added? ");
    scanf_s("%d", &totalAmount);
    getchar();

    /*
     * Calculate the sum
     */
    summedAmount = 0;
    number = 1; // 0 is negative and should not be taken in.

    while (summedAmount < totalAmount) { // CHANGED [<=] TO [<]
        if (number % 2 == 1) { // ADDED brackets
            sum += number;
            summedAmount += 1;
        }
        number += 1; // ADDED number counter
    }

    /*
     * Print the resulting sum
     */
    printf("\nThe sum of the %d first uneven integers is %d\n", totalAmount, sum);

    getchar();
    return 0;
}
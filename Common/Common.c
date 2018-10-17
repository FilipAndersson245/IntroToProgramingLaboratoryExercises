#include "stdafx.h"
#include <assert.h>
#include <ctype.h>
#include "Common.h"

ExerciseFunction selectExercise(const Exercise exercises[], const int size, const int selectedValue) {
    if (selectedValue == exercises[selectedValue - 1].number)
        return exercises[selectedValue - 1].function;
    return NULL;
}

int inputExercise() {
    printf("Select exercise:");
    int exercise = 0;
    scanf_s("%d", &exercise);
    clrscr();
    return exercise;
}

int wanntToQuit() {
    printf("Wannt to quit? (y/n)");
    char command;
    for (;;) {
        do
            command = getchar();
        while (isspace(command));

        if (command == 'y' || command == 'Y') {
            clrscr();
            return 0;
        }
        else if (command == 'n' || command == 'N') {
            clrscr();
            return 1;
        }
        else
            printf("(%c) Is not a valid command. please try again:", command);
    }
}

void clrscr()
{
    system("@cls||clear");
}
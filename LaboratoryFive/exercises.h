#pragma once

typedef int bool;
#define TRUE 1
#define FALSE 0

int exercise1(void);

int exercise2(void);

int exercise3(void);

void testChar(char ch);

void testUnsignedChar(unsigned char ch);

int exercise4(void);

int exercise5(void);

cartesianToPolarByParameters(float x, float y, float * r, float * phi);

typedef struct
{
    float X, Y;
}Cordinate;

Cordinate polarToCartesianByStruct(float r, float phi);
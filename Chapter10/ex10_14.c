/*
 * Filename:    ex10_14.c
 * Author:      Andrew Laing
 * Email:       parisianconnections@gmail.com
 * Date:        21/07/2017.
 */

#include <stdio.h>

unsigned packCharacters( char, char );
void unpackCharacters( unsigned );
void displayBits( unsigned );


int main()
{    
    char a, b;
    unsigned result;
    
    printf("Enter character 1: ");
    scanf("%c", &a);
    fflush(stdin);
    
    printf("Enter character 2: ");
    scanf("%c", &b);
    fflush(stdin);
    
    printf("%c before = ", a);
    displayBits( a );
    printf("%c before = ", b);
    displayBits( b );
    result = packCharacters(a, b); 
    printf("Result   = ");
    displayBits( result );
    
    printf("\nUnpacking ...\n");
    unpackCharacters( result );
    return 0;
}


void unpackCharacters( unsigned packed )
{
    unsigned temp = packed;
    unsigned maskA=65280, maskB=255;
    char a,b;
    temp &= maskA;
    temp>>=8;
    a = temp;
    
    packed &=maskB;
    b = packed;
    
    printf("a = %c\nb = %c\n", a, b);
    printf("%c = ", a);
    displayBits( a );
    printf("%c = ", b);
    displayBits( b );
}


unsigned packCharacters( char a, char b )
{
    unsigned result = a;
    result <<=8;
    return result|=b;  /* Inclusive OR */
}


void displayBits( unsigned value )
{
    unsigned c, displayMask = 1<<31;
    
    for( c=1; c<=32; c++ )
    {
        putchar( value & displayMask ? '1' : '0' );
        value <<= 1;
        
        if(c % 8 == 0)
            putchar( ' ' );
    }
    
    putchar( '\n' );
}



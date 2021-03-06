/*
 * Filename:    ex10_11.c
 * Author:      Andrew Laing
 * Email:       parisianconnections@gmail.com
 * Date:        21/07/2017.
 */

#include <stdio.h>

void displayBits( unsigned );

int main()
{    
    unsigned number1;
    
    number1 = 1023;
    printf("The result of right shifting the following\n");
    display2BytesInBits( number1 );
    printf("is\n");
    display2BytesInBits( number1 >> 4 ); 
    
    
    printf("\n\nsize of int (same as long int) = %d\n",sizeof(int));
    printf("size of short                  = %d\n",sizeof(short));
    printf("size of long                   = %d\n",sizeof(long));
    printf("size of long long int          = %d\n",sizeof(long long int));
    return 0;
}


void display2BytesInBits( unsigned value )
{
    unsigned c, displayMask = 1<<15;
    
    printf( "%7u = ", value );
    
    for( c=1; c<=16; c++ )
    {
        putchar( value & displayMask ? '1' : '0' );
        value <<= 1;
        
        if(c % 8 == 0)
            putchar( ' ' );
    }
    
    putchar( '\n' );
}



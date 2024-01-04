// 2 Display de 7 Segmentos y 99 Pulsaciones | 2 7 Segment Display and 99 Pulsations

// Librerias | Libraries
#include <16f877a.h>
#fuses NOWDT, XT, NOPROTECT, NOLVP
#use delay(clock = 4000000)
#use fast_io(B)
#use fast_io(D)

// Numero en Exadecimal | Hexadecimal Number
// 0X3F es 0, 0X06 es 1, 0X5B es 2, 0X4F es 3, 0X66 es 4, 0X6D es 5, 0X7D es 6, 0X07 es 7, 0X7F es 8, 0X6F es 9
int const num[10] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F};

// Variables Globales | Global Variables
int display1 = 0;
int display2 = 0;
int pulsations = 0;

// Funcion Principal | Main Function
void main()
{
    // Declarando los puertos de entrada y salida | Declaring input and output ports
    set_tris_B(0b0000000);
    set_tris_D(0b1111111);

    // Bucle Infinito | Infinite Loop
    While(true)
    {
        // Display de 7 Segmentos 1 | 7 Segment Display 1
        output_B(num[display1]);
        output_high(PIN_C7);
        output_low(PIN_C5);
        delay_ms(110);

        // Display de 7 Segmentos 2 | 7 Segment Display 2
        output_B(num[display2]);
        output_high(PIN_C5);
        output_low(PIN_C7);
        delay_ms(110);

        // Detecta si el boton esta presionado | Detects if the button is pressed
        if (input(PIN_D7) == 1)
        {
            pulsations++;

            // Si las pulsaciones son menores o iguales a 9 | If the pulsations are less than or equal to 9
            if (pulsations <= 9)
            {
                display1++;
            }
            else if (pulsations > 9)
            {
                display2++;
                display1 = 0;
                pulsations = 0;
            }

            // Si el display 2 es mayor a 9 | If display 2 is greater than 9
            if (display2 > 9)
            {
                display1 = 0;
                display2 = 0;
                pulsations = 0;
            }
        }
    }
}
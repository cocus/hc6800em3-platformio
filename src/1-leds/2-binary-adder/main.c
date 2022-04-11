
/* Include the header files required */
#include <STC89xx.h> /* STC89xx series (including the 90C516RD+) */

/* Declaration of functions prototypes */
void Delay10ms(unsigned int c); /* Delay 10ms * c */

/**
 * @brief Main function, called upon MCU reset.
 * @note Should not return!
 */
void main(void)
{
    unsigned char Num = 0x00;

    /**
     * The main idea of this code is to set the Port0 pins with
     * the binary representation of a variable which gets incremented
     * each time the code loops.
     */

    while (1)
    {
        P0 = Num; /* set Port0 with the value of variable "Num" */
        Delay10ms(50); /* delay for 500ms */
        Num++; /* increment variable "Num" */
    }
}

/**
 * @brief Delays a given amount of time, in 10ms steps.
 * @note This routing is XTAL and 6T/12T dependant.
 * @param c Amount of 10ms to delay.
 */
void Delay10ms(unsigned int c)
{
    unsigned char a, b;

    /* c has already been assigned when it is passed, so there is no need to assign it in the first sentence of the for statement */
    for (; c>0; c--)
    {
        for (b=38; b>0; b--)
        {
            for (a=130; a>0; a--);
        }
    }
}
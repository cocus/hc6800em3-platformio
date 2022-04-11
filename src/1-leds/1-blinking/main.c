
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
    /**
     * The main idea of this code is to toggle all the pins of the Port0 (P0)
     * using a fixed delay in between setting it to all-zeros and all-ones.
     * Hexadecimal numbers are noted with a "0x" at the beginning. For instance,
     * 0x00 is 0000 0000 in binary; where 0xff is 1111 1111.
     */
    while(1)
    {
        /* Set P0 to low level */
        P0 = 0x00;

        /* Delay 500ms, modify the value "50" to adjust the delay time */
        Delay10ms(50);

        /* Set P0 to high level */
        P0 = 0xff;

        /* Delay 500ms, modify the value "50" to adjust the delay time */
        Delay10ms(50);
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
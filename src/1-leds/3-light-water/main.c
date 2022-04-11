
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
	unsigned char LED = 0xfe; /* 0xfe = 1111 1110 */

    /**
     * The main idea of this code is to turn off pins of Port0,
     * one at a time, delaying 500ms and repeating this process
     * until all pins are off, where it would re-assign the original
     * default value and start again. This code uses the rotate
     * left binary operator on the LED variable.
     */
    while (1)
    {
        P0 = LED;
        Delay10ms(50);
        LED = LED << 1; /* Rotate left by 1 bit, turn off the next LED */
        if (P0 == 0x00) /* When it is all extinguished, restart */
        {
            LED = 0xfe; /* 0xfe = 1111 1110 */
        }
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
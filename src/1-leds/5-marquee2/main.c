
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
	unsigned int LED = 0xfe; /* 0xfe = 1111 1110 */

    /**
     * The main idea of this code is to have a fixed pattern
     * to move in a marquee style on the pins of Port0.
     */
    unsigned char i;

    while (1)
    {
        /* LED blinks to the left */
        for (i = 0; i < 7; i++)
        {
            /* Assign the value of variable LED to Port0 */
            P0 = LED;

            /* Delay for a while, in order to keep the lights on */
            Delay10ms(50);

            /* Shift the value of the LED to the left by one, and then reassign it to itself */
            LED = LED << 1;

            /* After shifting, the lowest bit is set */
            LED = LED | 0x01;
        }

        /* LED blinks to the right */
        for (i = 0; i < 7; i++)
        {
            P0 = LED;

            /* Delay for a while, in order to keep the lights on */
            Delay10ms(50);

            /* Shift the value of the LED to the right by one, and then reassign it to itself */
            LED = LED >> 1;

            /* After shifting, the highest bit is set */
            LED = LED | 0x80;
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

/* Include the header files required */
#include <STC89xx.h> /* STC89xx series (including the 90C516RD+) */

/* Declaration of functions prototypes */
void Delay10ms(unsigned int c); /* Delay 10ms * c */
unsigned char Key_Scan(); /* Scan the keyboard */

/* Define GPIO ports */
#define GPIO_KEY P1 /* Port1 used for Keys */
#define GPIO_LED P0 /* Port0 used for LEDs */

/**
 * @brief Main function, called upon MCU reset.
 * @note Should not return!
 */
void main(void)
{
    unsigned char ledValue, keyNum;

    /**
     * The main idea of this code is to scan for pressed buttons on the 8 buttons
     * keyboard. Then, if a button is detected, turn on the LEDs that correspond
     * to the read binary value from the buttons port.
     */

    ledValue = 0x00;

    while (1)
    {
        keyNum = Key_Scan(); /* scan pressed buttons */

        if (keyNum != 0) /* if there's a button pressd, update the ledValue variable */
        {
            ledValue = keyNum;
        }

        GPIO_LED = ledValue; /* turn the appropriate LEDs */
    }
}

/**
 * @brief Reads the value of all 8 buttons into a single byte.
 *
 * @return unsigned char 0 if no button is pressed. A value where each bit
 *                       corresponds to the pressed button.
 */
unsigned char Key_Scan()
{
    unsigned char keyValue = 0; /* Stores the button pressed */
    unsigned char i;

    /* detect if some button is pressed */
    if (GPIO_KEY != 0xFF)
    {
        Delay10ms(1); /* delay to de-bounce */

        if (GPIO_KEY != 0xFF) /* check again if some button is pressed */
        {
            keyValue = GPIO_KEY;
            i = 0;
            /* wait some time while the button is pressed */
            while ((i < 50) && (GPIO_KEY != 0xFF))
            {
                Delay10ms(1);
                i++;
            }
        }
    }

    return keyValue; /* return the read button in a single byte's bits */
}

void LED1()
{
    unsigned char i;
    unsigned char carry;

    GPIO_LED = 0x01;
    for (i = 0; i < 16; i++)
    {
        carry = GPIO_LED & 0x80 ? 1 : 0;
        GPIO_LED = (GPIO_LED << 1) | carry;
        Delay10ms(5);
    }
}

void LED2()
{
    unsigned char i;
    unsigned char carry;

    GPIO_LED = 0x80;
    for (i = 0; i < 16; i++)
    {
        carry = GPIO_LED & 1 ? 0x80 : 0;
        GPIO_LED = (GPIO_LED >> 1) | carry;
        Delay10ms(5);
    }
}

void LED3()
{

    GPIO_LED = 0xaa;
    Delay10ms(5);

    GPIO_LED = 0x55;
    Delay10ms(5);

    GPIO_LED = 0xaa;
    Delay10ms(5);

    GPIO_LED = 0x55;
    Delay10ms(5);
}

void LED4()
{
    GPIO_LED = 0x55;
    Delay10ms(5);

    GPIO_LED = 0xaa;
    Delay10ms(5);

    GPIO_LED = 0x55;
    Delay10ms(5);

    GPIO_LED = 0xaa;
    Delay10ms(5);
}

void LED5()
{
    GPIO_LED = 0xCC;
    Delay10ms(5);

    GPIO_LED = 0x33;
    Delay10ms(5);

    GPIO_LED = 0xCC;
    Delay10ms(5);

    GPIO_LED = 0x33;
    Delay10ms(5);
}

void LED6()
{
    GPIO_LED = 0x33;
    Delay10ms(5);

    GPIO_LED = 0xCC;
    Delay10ms(5);

    GPIO_LED = 0x33;
    Delay10ms(5);

    GPIO_LED = 0xCC;
    Delay10ms(5);
}

void LED7()
{
    LED1();
    LED2();
    LED3();
    LED4();
    LED5();
    LED6();
}

void LED8()
{
    GPIO_LED = 0x00;
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
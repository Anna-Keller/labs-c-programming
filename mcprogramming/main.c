#include <msp430.h> 
#include <msp430fr6989.h>
#include "lcd.h"
#include "led.h"

//this boolean stores the information about which sensor data is displayed on the LCD
_Bool isLeftActive = 1;

void tick(void);
void ADC_Init(void);
void OnSampleReceivedRight(float digSignal);
void OnSampleReceivedLeft(float digSignal);

void main(void)
{
	WDTCTL = WDT_MDLY_0_5; // 0.5ms wdt
	
	PM5CTL0 &= ~LOCKLPM5; // enable changes to port registers

	// S1 button config
	P1SEL0 &= ~BIT1;
	P1SEL1 &= ~BIT1;
	P1DIR &= ~BIT1;

	// configure P1.1 (button S1) as input with pull-up resistor
	P1OUT |= BIT1;
	P1REN |= BIT1;

	//Initialize everything
	LED_Init();
	LCD_Init();
	ADC_Init();

	SFRIE1 |= WDTIE;  // Enable watchdog interrupts
	_EINT();          // Enable interrupts globally

	while(1)
	{
	    if (P1IN & BIT1)
	    {
	        // button released
	        isLeftActive = !isLeftActive; //toggle left and right hand sensors

	        if(isLeftActive)
	        {
	            LCD_Symbol(LCD_TX_ID, LCD_SYMBOL_ON);
                LCD_Symbol(LCD_RX_ID, LCD_SYMBOL_OFF);
	        }
	        else
	        {
                LCD_Symbol(LCD_RX_ID, LCD_SYMBOL_ON);
                LCD_Symbol(LCD_TX_ID, LCD_SYMBOL_OFF);
	        }
	    }
	}
}

int intervalCounter = 0;
#pragma vector=WDT_VECTOR
__interrupt void tick(void)
{
    intervalCounter++;
    if(intervalCounter >= 200)
    {
        ADC12CTL0 |= ADC12SC; // Start sampling & conversion

        while (ADC12CTL0 & ADC12BUSY);

        OnSampleReceivedLeft((float)ADC12MEM0);
        OnSampleReceivedRight((float)ADC12MEM1);

        intervalCounter = 0;
    }
}

void ADC_Init(void)
{
    // set P9.1 as A9
    P9SEL0 |= BIT1;
    P9SEL1 |= BIT1;

    // set P9.2 as A10
    P9SEL0 |= BIT2;
    P9SEL1 |= BIT2;

    // select internal ref = 2.5V
    REFCTL0 |= REFVSEL_2 | REFON;


    ADC12CTL0 = ADC12SHT1_4        // sampling frequency once in 64 cycles
              | ADC12MSC           // multi channel sampling
              | ADC12SSEL_0        // clock source: ADC12OSC (5 MHz)
              | ADC12ON            // ADC on
              | ADC12ENC;          // enable conversion

    ADC12CTL1 = ADC12CONSEQ_1;     // mode of operation: Sequence of Channels

    ADC12CTL3 |= ADC12CSTARTADD_0; // start saving to MEM0 (CTL0 -> MEM0, CTL1 -> MEM1 (EOS))


    ADC12MCTL0 = ADC12VRSEL_1      // VR+ = VREF buffered, VR- = AVSS (analog ground)
               | ADC12INCH_9;      // Input channel A9

    ADC12MCTL1 = ADC12VRSEL_1      // VR+ = VREF buffered, VR- = AVSS (analog ground)
               | ADC12INCH_10      // Input channel A10
               | ADC12EOS;         // end of sequence
  }

void OnSampleReceivedRight(float digSignal)
{
    unsigned short distance = digSignal / 20;

    if(distance < 20)
    {
        LED2_on();
    }
    else
    {
        LED2_off();
    }

    if(!isLeftActive)
    {
        LCD_displayShort(distance);
    }
}

void OnSampleReceivedLeft(float digSignal)
{
    unsigned short distance = digSignal / 20;

    if(distance < 20)
    {
        LED1_on();
    }
    else
    {
        LED1_off();
    }

    if(isLeftActive)
    {
        LCD_displayShort(distance);
    }
}

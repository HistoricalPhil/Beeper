/*
 * Beeper.c
 *
 * Created: 5/28/2016 11:35:21 PM
 * Author : Phillip
 */

 /*
 GUIDE:
 PB5 / PIN1 / Nothing
 PB3 / PIN2 / Piezo
 PB4 / PIN3 / Reed
 PB2 / PIN7 / Green
 PB1 / PIN6 / Yellow
 PB0 / PIN5 / RED


 */


#include <avr/io.h>
#define F_CPU 1000000UL // 1MHZ pg 30 of data sheet

#include <util/delay.h>

int main(void)
{  
    //Variables Setup
    DDRB = (1<<DDB0) | (1<<DDB1) | (1<<DDB2) | (1<<DDB3); // Set two DDRB registers as output. We will use PB0 and PB4 so we will use DDB0 and DDB1.
    DDRB &= ~(1<<DDB4); // Setup one DDRB as an Input register. DDB2 will start out as zero. &= ~ means inverted.
    PORTB |= (1<<PB4); // Enable PB1 pull up resistor. when enable, it creates a connection. The circuit must be connected to the ground. (I don't know if this is right).
    //Startup preferences
    PORTB &= ~(1<<PB0);
    PINB &= ~(1<<PB1);
    PORTB &= ~(1<<PB2);
    PORTB &= ~(1<<PB3);  //LED and PIEZO STARTS AS OFF
    //Boolean Logic Startup
    int stage1 = 1;
    int stage2 = 0;
    int stage3 = 0;
    int stage4 = 0;
    int stage5 = 0;
    int reedswitchlock = 0;
    int sec = 10;
    int sec2 = 10000;
    int sec3 = 10;


    /* Replace with your application code */
    while (1)
    {
    //Variables
    stage1;
    stage2;
    stage3;
    stage4;
    reedswitchlock;
    sec;
    sec2;
    sec3;
  
    //stage 1, Play Annoying Noise
    if (stage1 == 1){
        PINB = (1<<PB3);
        _delay_ms(.1);
        }

    if ((stage1) == 0){
        //PINB = (1<<PB4);
        //_delay_ms(10);
        //delete contents to turn off PIN4.   
        }
  
    //Stage 2: Turn on Green Light, start countdown
    if ((PINB & (1<<PINB4)) == 0){
        stage1 = 0;
        stage2 = 1;
        }

    if (stage2 == 1){
        PINB = (1<<PB2);
        _delay_ms(1000);
        --sec;

        }

    //Stage 3: turn on yellow light
    if (sec < 0){
        // Turn on Yellow Light
        stage3 = 1;
        stage2 = 0;
        stage1 = 0;
        _delay_ms(10);
        sec = 10;
        PORTB &= ~(1<<PB2);
        //turn off green light
      
        }

        // Make noise for 10 seconds
    if (stage3 == 1){
        PINB = (1<<PB1) | (1<<PB3);
        _delay_ms(1);
        --sec2;
        }

    if (sec2 < 0){
        stage1 = 0;
        stage2 = 0;
        stage3 = 0;
        stage4 = 1;
        _delay_ms(10);
        //turn off sound
        PORTB &= ~(1<<PB3);
        sec2 = 10;
        }
    // stage 4: Turn on Yellow light, turn off sound.

    if (stage4 == 1){
        PINB = (1<<PB1);
        _delay_ms(1000);
        --sec3;
        }

    if (sec3 < 0)
    {
        stage1 = 0;
        stage2 = 0;
        stage3 = 0;
        stage4 = 0;
        stage5 = 1;
        PORTB &= ~(1<<PB1);
      
        sec3 = 10;
    }

    // stage 5: Turn on Red Light, Turn On Sound.
    if (stage5 == 1){
        PINB = (1<<PB3) | (1<<PB0);
        _delay_ms(.1);
        }  
  
    }
  
}

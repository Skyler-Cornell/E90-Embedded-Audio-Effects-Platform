/*
 * audio_process.c
 *
 *  Created on: Apr 16, 2021
 *      Author: skylercornell
 */


#include "audio_process.h"
#include "user_controls.h"
#include <math.h>
#include "CONSTANTS.h"


extern RGB_LED_t LED1;
extern RGB_LED_t LED2;
extern RGB_LED_t LED3;

extern uint32_t POT_1, POT_2, POT_3;

/*
 * Declare global variables and structures units here
 */



void process_init()
{
  // initialize data structures
  init_LEDs();

}

void loop() {

   // manage user controls here (LEDs, Pots)
  update_LED(&LED1, 20,POT_1,POT_2);
  update_LED(&LED2, 0,POT_2,0);
  update_LED(&LED3, POT_2,0,POT_3);


}

void process(int *in_sample, int *out_sample)
{


  // passthru
  *out_sample = *in_sample;

  //PEAK DETECTION
  if (*in_sample > 5000000 || *in_sample < -5000000 ) {
       update_LED(&LED1, 255,0,0);
       update_LED(&LED2, 255,0,0);
       update_LED(&LED3, 255,0,0);
  }

}



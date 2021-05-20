/*
 * audio_process.c
 *
 *  Created on: Apr 16, 2021
 *      Author: skylercornell
 */


#include "audio_process.h"
#include <math.h>
#include "CONSTANTS.h"

/*
 * Declare global variables and structures units here
 */




void process_init()
{
  // initialize data structures
}

void loop() {

   // manage user controls here (LEDs, Pots)
}

void process(int *in_sample, int *out_sample)
{

  // passthru
  *out_sample = *in_sample;

}



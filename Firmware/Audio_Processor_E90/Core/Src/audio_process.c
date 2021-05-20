/*
 * audio_process.c
 *
 *  Created on: Apr 16, 2021
 *      Author: skylercornell
 */


/*
 * audio_process.c
 *
 *  Created on: Jan 22, 2020
 *      Author: skylercornell
 */

#include "audio_process.h"
#include "biquads.h"
#include <math.h>
#include "CONSTANTS.h"

/*
 * Declare global variables and structures units here
 */

// Bandpass
biquad_t BPF_biquad;

float F0;
float w0;
float Q;

/*
 * Executes once before entering program loop
 */

void process_init()
{
  //reset biquad history
  BPF_biquad.yn2 = 0;
  BPF_biquad.yn1 = 0;
  BPF_biquad.xn2 = 0;
  BPF_biquad.xn1 = 0;


  F0 = 1000; // start off at 1000 Hz center freq;
  w0 = 2*3.141592*(F0/SAMPLE_RATE_ACTUAL);
  Q = 6;

  //compute an initial set of coefficients to avoid Nan
  compute_BPF_coeff(&BPF_biquad, w0, Q);

}

void loop() {

   //handle LEDs and Pots on slower time scale
}

void process(int *in_sample, int *out_sample)
{

  float in = (float)*in_sample;
  float out = 0;

  //produce filtered output sample
  compute_biquad(&BPF_biquad, &in, &out);

  //cast float to int
  *out_sample = (int)out;
}



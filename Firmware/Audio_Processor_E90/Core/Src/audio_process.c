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
#include <math.h>

/*
 * Declare global variables and structures units here
 */


/*
 * Executes once before entering program loop
 */


void compute_BPF_coeff(biquad_t *bq, float w0, float Q){
  float sinw0_over2 = sin(w0)/2;
  float alpha = sinw0_over2/Q;;

  bq->ready_coef = 0; //lock
  bq->shadow_coef.b0 = sinw0_over2;
  bq->shadow_coef.b1 = 0;
  bq->shadow_coef.b2 = -sinw0_over2;

  bq->shadow_coef.a0 = 1+alpha;
  bq->shadow_coef.a1 = -2*cos(w0);
  bq->shadow_coef.a2 = 1-alpha;
  bq->ready_coef = 1; //unlock

}
void compute_LPF_coeff(biquad_t *bq, float w0, float Q){

  float one_minus_cosw0 = 1-cos(w0);
  float alpha = sin(w0)/(2*Q);


  //bq->ready_coef = 0; // flag ISR not to copy these shadows

  bq->coef.b0 = one_minus_cosw0/2;
  bq->coef.b1 = one_minus_cosw0;
  bq->coef.b2 = one_minus_cosw0/2;

  bq->coef.a0 = 1+alpha;
  bq->coef.a1 = -2*cos(w0);
  bq->coef.a2 = 1-alpha;

  //bq->ready_coef = 1; // flag ISR that it's safe to copy the shadows

}

void compute_biquad(biquad_t *bq, float *in, float *out){

  //if shadow coefficients are done
  if(bq->ready_coef == 1) {
      bq->coef = bq->shadow_coef;
      bq->ready_coef = 0;
  }

  float b0 = bq->coef.b0;
  float b1 = bq->coef.b1;
  float b2 = bq->coef.b2;

  float a0 = bq->coef.a0;
  float a1 = bq->coef.a1;
  float a2 = bq->coef.a2;

  *out = (*in)*(b0/a0);
  *out += bq->xn1*(b1/a0);
  *out += bq->xn2*(b2/a0);
  *out -= bq->yn1*(a1/a0);
  *out -= bq->yn2*(a2/a0);

  //update struct
  bq->yn2 = bq->yn1;
  bq->yn1 = *out;
  bq->xn2 = bq->xn1;
  bq->xn1 = *in;
}



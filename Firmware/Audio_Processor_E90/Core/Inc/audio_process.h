/*
 * audio_process.h
 *
 *  Created on: Jan 22, 2021
 *      Author: skylercornell
 */

#ifndef INC_AUDIO_PROCESS_H_
#define INC_AUDIO_PROCESS_H_



#endif /* INC_AUDIO_PROCESS_H_ */


// generic struct containing 5 floating point IIR coefficients
typedef struct  {
  float b0, b1, b2, a0, a1, a2; //coefficients

}biquad_coef_t;


typedef struct {

  biquad_coef_t coef;		// biquad coefficients
  biquad_coef_t shadow_coef; 	// shadow coefficients which are atomically updated

  float xn1, xn2;  //previous inputs
  float yn1,yn2;  //prev outputs

  char ready_coef; // flag indicating if the shadow coefficients are ready to be copied into real coef

}biquad_t;


void process_init();
void process(int *left_in, int *right_in, int *left_out, int *right_out);

void compute_BPF_coeff(biquad_t *bq, float w0, float Q);
void compute_LPF_coeff(biquad_t *bq, float w0, float Q);
void compute_biquad(biquad_t *bq, float *in, float *out);

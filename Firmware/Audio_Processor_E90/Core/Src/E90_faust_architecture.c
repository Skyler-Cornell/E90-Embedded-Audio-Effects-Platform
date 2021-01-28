/*
 * STM32AudioDSP Faust Architecture File
 * Faust command line tool generates a c file valid for this project's audio
 * framework.
 * Use the following command to generate the code:
 * faust -a E90_faust_architecture.c -lang c -o generated_audio_process.c my_faust_fx.dsp

 * The generated c file should replace audio_process.c for faust effect to run
 * At the moment need to remove the unused functions involving UI or metaglue. no idea wtf those are for
 */


#include "audio_process.h"
#include "CONSTANTS.h"

<<includeIntrinsic>>
<<includeclass>>
/*
 * global faust object pointers
 */
mydsp* dsp;
FAUSTFLOAT** inputs;
FAUSTFLOAT** outputs;

void process_init() {

  // allocate memory for dsp struct and input and output channel pointers
  dsp = (mydsp*)malloc(sizeof(mydsp));
  inputs = (FAUSTFLOAT**)malloc(sizeof(FAUSTFLOAT*)*CHANNELS);
  outputs = (FAUSTFLOAT**)malloc(sizeof(FAUSTFLOAT*)*CHANNELS);

  //point output blocks at valid memory so can modify later no problem
  outputs[0] = (FAUSTFLOAT*)malloc(sizeof(FAUSTFLOAT)*BLOCKSIZE);
  outputs[1] = (FAUSTFLOAT*)malloc(sizeof(FAUSTFLOAT)*BLOCKSIZE);

  initmydsp(dsp, SAMPLE_RATE_ACTUAL);


}

// assumes a right justified 24 bit signed sample
void process(int *left_in, int *right_in, int *left_out, int *right_out) {

  //convert 24 bit int samples (−8,388,608 to 8,388,607) to float (0 to 1) without losing precision
  FAUSTFLOAT left_in_float = ((FAUSTFLOAT) *left_in)/8388607.0f;
  FAUSTFLOAT right_in_float = ((FAUSTFLOAT) *right_in)/8388607.0f;

  inputs[0] = (FAUSTFLOAT*)&left_in_float; //inputs[0] gets pointer to left sample
  inputs[1] = (FAUSTFLOAT*)&right_in_float; //inputs[1] gets pointer to right sample

  computemydsp(dsp, BLOCKSIZE, inputs, outputs);

  // scale up processed float to half of the 24 bit sample range and store as an int (which truncates fractional part)
  //+/-4000000 is roughly half of the fullscale range and is a bit softer on the ears than the full range
  *left_out = (int)(*outputs[0]*4000000.0f);
  *right_out = (int)(*outputs[1]*4000000.0f);

}

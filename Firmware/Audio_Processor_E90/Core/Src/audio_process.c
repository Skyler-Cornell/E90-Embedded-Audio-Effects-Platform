/* ------------------------------------------------------------
name: "hslider_test"
Code generated with Faust 2.5.23 (https://faust.grame.fr)
Compilation options: c, -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

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

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif


#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdlib.h>


#ifndef FAUSTCLASS
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__
#define exp10f __exp10f
#define exp10 __exp10
#endif

typedef struct {

	FAUSTFLOAT fHslider0;
	int IOTA;
	float fRec0[8192];
	int fSamplingFreq;

} mydsp;

mydsp* newmydsp() {
	mydsp* dsp = (mydsp*)malloc(sizeof(mydsp));
	return dsp;
}

void deletemydsp(mydsp* dsp) {
	free(dsp);
}

//void metadatamydsp(MetaGlue* m) {
//	m->declare(m->metaInterface, "filename", "hslider_test");
//	m->declare(m->metaInterface, "name", "hslider_test");
//}

int getSampleRatemydsp(mydsp* dsp) { return dsp->fSamplingFreq; }

int getNumInputsmydsp(mydsp* dsp) {
	return 2;

}
int getNumOutputsmydsp(mydsp* dsp) {
	return 2;

}
int getInputRatemydsp(mydsp* dsp, int channel) {
	int rate;
	switch (channel) {
		case 0: {
			rate = 1;
			break;
		}
		case 1: {
			rate = 1;
			break;
		}
		default: {
			rate = -1;
			break;
		}

	}
	return rate;

}
int getOutputRatemydsp(mydsp* dsp, int channel) {
	int rate;
	switch (channel) {
		case 0: {
			rate = 1;
			break;
		}
		case 1: {
			rate = 1;
			break;
		}
		default: {
			rate = -1;
			break;
		}

	}
	return rate;

}

void classInitmydsp(int samplingFreq) {

}

void instanceResetUserInterfacemydsp(mydsp* dsp) {
	dsp->fHslider0 = (FAUSTFLOAT)5000.0f;

}

void instanceClearmydsp(mydsp* dsp) {
	dsp->IOTA = 0;
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; (l0 < 8192); l0 = (l0 + 1)) {
			dsp->fRec0[l0] = 0.0f;

		}

	}

}

void instanceConstantsmydsp(mydsp* dsp, int samplingFreq) {
	dsp->fSamplingFreq = samplingFreq;

}

void instanceInitmydsp(mydsp* dsp, int samplingFreq) {
	instanceConstantsmydsp(dsp, samplingFreq);
	instanceResetUserInterfacemydsp(dsp);
	instanceClearmydsp(dsp);
}

void initmydsp(mydsp* dsp, int samplingFreq) {
	classInitmydsp(samplingFreq);
	instanceInitmydsp(dsp, samplingFreq);
}

//void buildUserInterfacemydsp(mydsp* dsp, UIGlue* ui_interface) {
//	ui_interface->openVerticalBox(ui_interface->uiInterface, "hslider_test");
//	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "delay", &dsp->fHslider0, 5000.0f, 1.0f, 7000.0f, 10.0f);
//	ui_interface->closeBox(ui_interface->uiInterface);
//
//}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
	FAUSTFLOAT* input0 = inputs[0];
	FAUSTFLOAT* input1 = inputs[1];
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];

	int iSlow0 = ((int)(float)dsp->fHslider0 + 1);
	/* C99 loop */
	{
		int i;
		for (i = 0; (i < count); i = (i + 1)) {
 			dsp->fRec0[(dsp->IOTA & 8191)] = (((0.5f * dsp->fRec0[((dsp->IOTA - iSlow0) & 8191)]) + (float)input0[i]) + (float)input1[i]);
			output0[i] = (FAUSTFLOAT)dsp->fRec0[((dsp->IOTA - 0) & 8191)];
			output1[i] = (FAUSTFLOAT)dsp->fRec0[((dsp->IOTA - 0) & 8191)];
			dsp->IOTA = (dsp->IOTA + 1);

		}

	}

}

#ifdef __cplusplus
}
#endif

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
  FAUSTFLOAT left_in_float = ((FAUSTFLOAT) *left_in)/8388607.0;
  FAUSTFLOAT right_in_float = ((FAUSTFLOAT) *right_in)/8388607.0;

  inputs[0] = (FAUSTFLOAT*)&left_in_float; //inputs[0] gets pointer to left sample
  inputs[1] = (FAUSTFLOAT*)&right_in_float; //inputs[1] gets pointer to right sample

  computemydsp(dsp, BLOCKSIZE, inputs, outputs);

  // scale up processed float to 24 bit sample range and store as an int (which truncates fractional part)
  *left_out = (int)(*outputs[0]*8388607);
  *right_out = (int)(*outputs[1]*8388607);

}

#endif

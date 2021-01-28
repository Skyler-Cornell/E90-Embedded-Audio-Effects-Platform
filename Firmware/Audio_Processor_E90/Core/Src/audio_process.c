/* ------------------------------------------------------------
author: "Grame"
copyright: "(c)GRAME 2009"
license: "BSD"
name: "osc"
version: "1.0"
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

	int iVec0[2];
	int fSamplingFreq;
	float fConst0;
	float fRec2[2];
	float fRec1[2];
	float fRec0[2];

} mydsp;

mydsp* newmydsp() {
	mydsp* dsp = (mydsp*)malloc(sizeof(mydsp));
	return dsp;
}

void deletemydsp(mydsp* dsp) {
	free(dsp);
}

//void metadatamydsp(MetaGlue* m) {
//	m->declare(m->metaInterface, "author", "Grame");
//	m->declare(m->metaInterface, "copyright", "(c)GRAME 2009");
//	m->declare(m->metaInterface, "filename", "osc");
//	m->declare(m->metaInterface, "license", "BSD");
//	m->declare(m->metaInterface, "maths.lib/author", "GRAME");
//	m->declare(m->metaInterface, "maths.lib/copyright", "GRAME");
//	m->declare(m->metaInterface, "maths.lib/license", "LGPL with exception");
//	m->declare(m->metaInterface, "maths.lib/name", "Faust Math Library");
//	m->declare(m->metaInterface, "maths.lib/version", "2.1");
//	m->declare(m->metaInterface, "name", "osc");
//	m->declare(m->metaInterface, "oscillators.lib/name", "Faust Oscillator Library");
//	m->declare(m->metaInterface, "oscillators.lib/version", "0.0");
//	m->declare(m->metaInterface, "version", "1.0");
//}

int getSampleRatemydsp(mydsp* dsp) { return dsp->fSamplingFreq; }

int getNumInputsmydsp(mydsp* dsp) {
	return 0;

}
int getNumOutputsmydsp(mydsp* dsp) {
	return 2;

}
int getInputRatemydsp(mydsp* dsp, int channel) {
	int rate;
	switch (channel) {
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

}

void instanceClearmydsp(mydsp* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			dsp->iVec0[l0] = 0;

		}

	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			dsp->fRec2[l1] = 0.0f;

		}

	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			dsp->fRec1[l2] = 0.0f;

		}

	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			dsp->fRec0[l3] = 0.0f;

		}

	}

}

void instanceConstantsmydsp(mydsp* dsp, int samplingFreq) {
	dsp->fSamplingFreq = samplingFreq;
	dsp->fConst0 = (1256.63708f / fmin(192000.0f, fmax(1.0f, (float)dsp->fSamplingFreq)));

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
//	ui_interface->openVerticalBox(ui_interface->uiInterface, "osc");
//	ui_interface->closeBox(ui_interface->uiInterface);
//
//}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	/* C99 loop */
	{
		int i;
		for (i = 0; (i < count); i = (i + 1)) {
			dsp->iVec0[0] = 1;
			dsp->fRec2[0] = (dsp->fRec2[1] + (dsp->fConst0 * (0.0f - dsp->fRec0[1])));
			dsp->fRec1[0] = ((dsp->fRec1[1] + (dsp->fConst0 * dsp->fRec2[0])) + (float)(1 - dsp->iVec0[1]));
			dsp->fRec0[0] = dsp->fRec1[0];
			output0[i] = (FAUSTFLOAT)dsp->fRec0[0];
			output1[i] = (FAUSTFLOAT)dsp->fRec0[0];
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fRec0[1] = dsp->fRec0[0];

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
  *left_out = (int)(*outputs[0]*2000000);
  *right_out = (int)(*outputs[1]*2000000);

}

#endif

/* ------------------------------------------------------------
name: "vibe"
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


typedef struct {

	int iRec0[2];

} mydspSIG0;

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)malloc(sizeof(mydspSIG0)); }
static void deletemydspSIG0(mydspSIG0* dsp) { free(dsp); }

int getNumInputsmydspSIG0(mydspSIG0* dsp) {
	return 0;

}
int getNumOutputsmydspSIG0(mydspSIG0* dsp) {
	return 1;

}
int getInputRatemydspSIG0(mydspSIG0* dsp, int channel) {
	int rate;
	switch (channel) {
		default: {
			rate = -1;
			break;
		}

	}
	return rate;

}
int getOutputRatemydspSIG0(mydspSIG0* dsp, int channel) {
	int rate;
	switch (channel) {
		case 0: {
			rate = 0;
			break;
		}
		default: {
			rate = -1;
			break;
		}

	}
	return rate;

}

static void instanceInitmydspSIG0(mydspSIG0* dsp, int samplingFreq) {
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			dsp->iRec0[l1] = 0;

		}

	}

}

static void fillmydspSIG0(mydspSIG0* dsp, int count, float* output) {
	/* C99 loop */
	{
		int i;
		for (i = 0; (i < count); i = (i + 1)) {
			dsp->iRec0[0] = (dsp->iRec0[1] + 1);
			output[i] = sinf((9.58738019e-05f * (float)(dsp->iRec0[0] + -1)));
			dsp->iRec0[1] = dsp->iRec0[0];

		}

	}

};

static float ftbl0mydspSIG0[32250];

#ifndef FAUSTCLASS
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__
#define exp10f __exp10f
#define exp10 __exp10
#endif

typedef struct {

	int IOTA;
	float fVec0[16384];
	FAUSTFLOAT fHslider0;
	int fSamplingFreq;
	float fConst0;
	FAUSTFLOAT fHslider1;
	float fRec1[2];

} mydsp;

mydsp* newmydsp() {
	mydsp* dsp = (mydsp*)malloc(sizeof(mydsp));
	return dsp;
}

void deletemydsp(mydsp* dsp) {
	free(dsp);
}

//void metadatamydsp(MetaGlue* m) {
//	m->declare(m->metaInterface, "basics.lib/name", "Faust Basic Element Library");
//	m->declare(m->metaInterface, "basics.lib/version", "0.0");
//	m->declare(m->metaInterface, "delays.lib/name", "Faust Delay Library");
//	m->declare(m->metaInterface, "delays.lib/version", "0.0");
//	m->declare(m->metaInterface, "filename", "vibe");
//	m->declare(m->metaInterface, "maths.lib/author", "GRAME");
//	m->declare(m->metaInterface, "maths.lib/copyright", "GRAME");
//	m->declare(m->metaInterface, "maths.lib/license", "LGPL with exception");
//	m->declare(m->metaInterface, "maths.lib/name", "Faust Math Library");
//	m->declare(m->metaInterface, "maths.lib/version", "2.1");
//	m->declare(m->metaInterface, "name", "vibe");
//	m->declare(m->metaInterface, "oscillators.lib/name", "Faust Oscillator Library");
//	m->declare(m->metaInterface, "oscillators.lib/version", "0.0");
//}

int getSampleRatemydsp(mydsp* dsp) { return dsp->fSamplingFreq; }

int getNumInputsmydsp(mydsp* dsp) {
	return 1;

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
	mydspSIG0* sig0 = newmydspSIG0();
	instanceInitmydspSIG0(sig0, samplingFreq);
	fillmydspSIG0(sig0, 65536, ftbl0mydspSIG0);
	deletemydspSIG0(sig0);

}

void instanceResetUserInterfacemydsp(mydsp* dsp) {
	dsp->fHslider0 = (FAUSTFLOAT)800.0f;
	dsp->fHslider1 = (FAUSTFLOAT)2.0f;

}

void instanceClearmydsp(mydsp* dsp) {
	dsp->IOTA = 0;
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; (l0 < 16384); l0 = (l0 + 1)) {
			dsp->fVec0[l0] = 0.0f;

		}

	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			dsp->fRec1[l2] = 0.0f;

		}

	}

}

void instanceConstantsmydsp(mydsp* dsp, int samplingFreq) {
	dsp->fSamplingFreq = samplingFreq;
	dsp->fConst0 = (1.0f / fmin(192000.0f, fmax(1.0f, (float)dsp->fSamplingFreq)));

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
//	ui_interface->openVerticalBox(ui_interface->uiInterface, "vibe");
//	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "delay", &dsp->fHslider0, 800.0f, 1.0f, 10000.0f, 1.0f);
//	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "freq", &dsp->fHslider1, 2.0f, 0.0f, 3.0f, 0.00999999978f);
//	ui_interface->closeBox(ui_interface->uiInterface);
//
//}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
	FAUSTFLOAT* input0 = inputs[0];
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	float fSlow0 = (float)dsp->fHslider0;
	float fSlow1 = (dsp->fConst0 * (float)dsp->fHslider1);
	/* C99 loop */
	{
		int i;
		for (i = 0; (i < count); i = (i + 1)) {
			float fTemp0 = (float)input0[i];
			dsp->fVec0[(dsp->IOTA & 16383)] = fTemp0;
			dsp->fRec1[0] = (fSlow1 + (dsp->fRec1[1] - floorf((fSlow1 + dsp->fRec1[1]))));
			float fTemp1 = (fSlow0 * (ftbl0mydspSIG0[(int)(65536.0f * dsp->fRec1[0])] + 1.0f));
			int iTemp2 = (int)fTemp1;
			float fTemp3 = floorf(fTemp1);
			float fTemp4 = ((int)(dsp->fVec0[((int)(dsp->IOTA - fmin(10001, fmax(0, iTemp2))) & 16383)] * (fTemp3 + (1.0f - fTemp1))) + ((fTemp1 - fTemp3) * dsp->fVec0[((int)(dsp->IOTA - fmin(10001, fmax(0, (iTemp2 + 1)))) & 16383)]));
			output0[i] = (FAUSTFLOAT)fTemp4;
			output1[i] = (FAUSTFLOAT)fTemp4;
			dsp->IOTA = (dsp->IOTA + 1);
			dsp->fRec1[1] = dsp->fRec1[0];

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

#endif

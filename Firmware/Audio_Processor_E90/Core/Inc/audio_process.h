/*
 * audio_process.h
 *
 *  Created on: Jan 22, 2021
 *      Author: skylercornell
 */

#ifndef INC_AUDIO_PROCESS_H_
#define INC_AUDIO_PROCESS_H_



#endif /* INC_AUDIO_PROCESS_H_ */


/*
 * Executes once before audio stream starts
 */
void process_init();

/*
 * Called once per while(1) loop
 */
void loop();

/*
 * Main DSP routine, called each sample period
 */
void process(int *in_sample, int *out_sample);



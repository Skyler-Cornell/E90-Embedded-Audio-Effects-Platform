/*
 * user_controls.h
 *
 *  Created on: May 20, 2021
 *      Author: skylercornell
 */

#ifndef INC_USER_CONTROLS_H_
#define INC_USER_CONTROLS_H_


#endif /* INC_USER_CONTROLS_H_ */
#include "main.h"

typedef struct {
  //Pointers to LED's R,G, and B Timer PWM CCR registers
  uint32_t *R_CCR;
  uint32_t *G_CCR;
  uint32_t *B_CCR;

}RGB_LED_t;

void init_LEDs();
void update_LED(RGB_LED_t *led, uint8_t R, uint8_t G, uint8_t B);

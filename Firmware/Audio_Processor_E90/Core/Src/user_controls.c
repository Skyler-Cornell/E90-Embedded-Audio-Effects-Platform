/*
 * user_controls.c
 *
 *  Created on: May 20, 2021
 *      Author: skylercornell
 */


#include "user_controls.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

RGB_LED_t LED1;
RGB_LED_t LED2;
RGB_LED_t LED3;



void update_LED(RGB_LED_t *led, uint8_t R, uint8_t G, uint8_t B) {

  *(led->R_CCR) = 255-R;
  *(led->G_CCR) = 255-G;
  *(led->B_CCR) = 255-B;

}

/*
 * Assign Timers and channels to each LED Struct and start the pWM
 *
 */
void init_LEDs() {

  /*
   * Assign RGB_LED_t struct fields to the timer handles and PWM capture
   * compare register addresses corresponding to the connection
   * of the 3 onboard LEDs
   * It's possible ythe R_TIM,G_TIM,B_TIM fields serve no purpose. Because once
   * the TIM PWM is running after Starting them, just need to update the capture
   * compare registers, which can be done by dereferencing the R_CCR field and
   * changing its contents, to change the color.
   */

  //LED 1
  LED1.R_CCR = &(htim4.Instance->CCR1);
  LED1.G_CCR = &(htim4.Instance->CCR3);
  LED1.B_CCR = &(htim4.Instance->CCR2);

  //LED 2
  LED2.R_CCR = &(htim2.Instance->CCR4);
  LED2.G_CCR = &(htim3.Instance->CCR3);
  LED2.B_CCR = &(htim3.Instance->CCR4);

  //LED 3
  LED3.R_CCR = &(htim2.Instance->CCR1);
  LED3.G_CCR = &(htim3.Instance->CCR1);
  LED3.B_CCR = &(htim3.Instance->CCR2);

  update_LED(&LED1, 0,0,0);
  update_LED(&LED2, 0,0,0);
  update_LED(&LED3, 0,0,0);

  //LED 1
  HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);

  //LED 2
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);

  //LED 3
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);


}


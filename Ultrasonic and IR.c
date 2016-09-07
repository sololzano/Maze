/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      
#include "ping.h"
#include "adcDCpropab.h"
#include "abdrive.h"

const int ULTRASONIC = 8;

int distance;
int irLeft, irRight;


int main()                                    // Main function
{
  // Add startup code here.
  dac_ctr(26, 0, 0);
  dac_ctr(27, 1, 0);
  //low(26);
  //low(27);
  
 
  while(1)
  {
    
    freqout(10, 1, 38000);
    irLeft = input(11);
    pause(10);
    low(10);
    
    freqout(1, 1, 38000);
    irRight = input(2);
    pause(10);
    low(1);
    
    distance = ping_cm(ULTRASONIC);

    
    if ((distance > 10) && (irLeft == 0)) {
      print("%c irLeft = %d, irRight = %d .. Seguir adelante", 
      HOME, irLeft, irRight);   
      drive_speed(60, 60); 
    } else if (irLeft == 1){       
      print("%c irLeft = %d, irRight = %d .. Rotar izquierda", 
      HOME, irLeft, irRight);
      drive_speed(0, 26);
      pause(1000);
      drive_speed(0, 0);
    } else if (distance < 10) {
      print("%c irLeft = %d, irRight = %d .. Cul de sac", 
      HOME, irLeft, irRight);
      drive_speed(0, 52);
      pause(2000);   
      drive_speed(0, 0);
    } else {
      print("%c irLeft = %d, irRight = %d .. Ni idea", 
      HOME, irLeft, irRight);   
      drive_speed(52, 0);
      pause(2000);
      drive_speed(0, 0);
    }                   
    /*
    print("%c distance = %d%c cm",
    HOME, distance, CLREOL);
    */

    //print("%c irLeft = %d, irRight = %d", HOME, irLeft, irRight);
    
    pause(500);
  }  
}

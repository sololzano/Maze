/*
 * Universidad del Valle de Guatemala
 * Algoritmos y Estructuras de Datos
 * Sección 10
 * Luis Diego Sierra
 * Carlos Solórzano
 * salvador recinos 
 *Giovani Velasquez
 * Resuelve un laberinto utilizando la regla de la mano izquierda
 */
#include "simpletools.h"                      // Include simple tools
#include "abdrive.h"
#include "ping.h"

// Constantes
const int LEFT_IN = 10;
const int RIGHT_IN = 2;
const int LEFT_OUT = 11;
const int RIGHT_OUT = 1;
const int ULTRASONIC = 8;

// Variables globales
int left;
int right;
int distance;

int main()                                    // Main function
{
  // Configuración inicial
  low(26);
  low(27);
  drive_trimSet(0,0,0);

  while(1)
  {
      // Revisar lado izquierdo
      freqout(LEFT_OUT, 1, 38000);
      pause(10);
      left = input(LEFT_IN);
      freqout(LEFT_OUT, 1, 0);
      
      // Revisar lado derecho
      freqout(RIGHT_OUT, 1, 38000);
      pause(10);
      right = input(RIGHT_IN);
      freqout(RIGHT_OUT, 1, 0);
      
      // Medir distancia frontal
      distance = ping_cm(ULTRASONIC);
      pause(10);
      
      // Tomar decisiones de movimiento
      choices(left, right, distance);
      
      pause(50);
  }  
}

/**
 * Toma de decisiones en base a mediciones
 * @param left - 1 si no existe pared al lado izquierdo
 * @param right - 1 si no existe pared al lado derecho
 * @param distance - Distancia en cm medida con sensor ultrasónico
 * @return void
 */
void choices(int left, int right, int distance)
{
   // Regla de la mano izquierda
   if (left == 0 && distance > 10) {
    drive_speed(128, 128); 
   }else if (left == 1) {
    drive_speed(0, 0);
    pause(15);
    drive_goto(-25, 26);  
   }else if (right == 1) {
     drive_speed(0, 0);
     pause(15);
     drive_goto(26, -25);
   }else {
     drive_speed(0, 0);
     pause(15);
     drive_goto(104, -100);
   }                    
}  

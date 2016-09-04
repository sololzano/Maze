/*
 * Universidad del Valle de Guatemala
 * Algoritmos y Estructuras de Datos
 * Sección 10
 * Luis Diego Sierra
 * Carlos Solórzano
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
      distance = ping(ULTRASONIC);
      pause(10);
      
      // Tomar decisiones de movimiento
      choices(left, right, distance);
      
      pause(100);
    
  }  
}

/**
 * Toma de decisiones en base a mediciones
 
 */
void choices(int left, int right, int distance)
{
   
}  

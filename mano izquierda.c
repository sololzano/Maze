// algoritmo de regla de la mano 
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
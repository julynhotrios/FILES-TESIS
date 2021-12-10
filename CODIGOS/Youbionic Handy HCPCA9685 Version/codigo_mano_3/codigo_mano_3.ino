  
/* Incluimos la libreria HCPCA9685 */
#include "HCPCA9685.h"

#define  I2CAdd 0x40


/* Creamos la instancia de la libreria */
HCPCA9685 HCPCA9685(I2CAdd);

  int Pos1=350;

void setup() 
{
  /* Inisializamos la libreria en modo servo */ 
  HCPCA9685.Init(SERVO_MODE);

  /* Wake the device up */
  HCPCA9685.Sleep(false);

HCPCA9685.Servo(0, Pos1);
HCPCA9685.Servo(1, Pos1);
HCPCA9685.Servo(2, Pos1);  
HCPCA9685.Servo(3, Pos1);
HCPCA9685.Servo(4, Pos1);
HCPCA9685.Servo(5, Pos1);
HCPCA9685.Servo(6, Pos1);
HCPCA9685.Servo(7, Pos1);
HCPCA9685.Servo(8, Pos1);
HCPCA9685.Servo(9, Pos1);
HCPCA9685.Servo(10, Pos1);

   delay(500);
  
}


void loop() 
{
  unsigned int Pos;

  for(Pos = 350; Pos >= 200; Pos--)

  {

HCPCA9685.Servo(0, Pos);
HCPCA9685.Servo(1, Pos);
HCPCA9685.Servo(2, Pos);  
HCPCA9685.Servo(3, Pos);
HCPCA9685.Servo(4, Pos);
HCPCA9685.Servo(5, Pos);
HCPCA9685.Servo(6, Pos);
HCPCA9685.Servo(7, Pos);
HCPCA9685.Servo(8, Pos);
HCPCA9685.Servo(9, Pos);
HCPCA9685.Servo(10, Pos);

           
    delay(10);
  }
  
  for(Pos = 200; Pos < 350; Pos++)
  {
HCPCA9685.Servo(0, Pos);
HCPCA9685.Servo(1, Pos); 
HCPCA9685.Servo(2, Pos);  
HCPCA9685.Servo(3, Pos);  
HCPCA9685.Servo(4, Pos);
HCPCA9685.Servo(5, Pos);
HCPCA9685.Servo(6, Pos);
HCPCA9685.Servo(7, Pos);  
HCPCA9685.Servo(8, Pos);
HCPCA9685.Servo(9, Pos);
HCPCA9685.Servo(10, Pos);

      
    delay(10);
  }
}


/* Inclimos la libreria HCPCA9685 para hacer uso del controlador */
#include "HCPCA9685.h"

#define  I2CAdd 0x40

/* Creamos una instancia de la libreria */
HCPCA9685 HCPCA9685(I2CAdd);

  int Pos1=450;

void setup() 
{
  /* Inicializamos la libreria y configúramos en 'modo servo' */ 
  HCPCA9685.Init(SERVO_MODE);

  /* Activamos el dispositivo*/
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

HCPCA9685.Servo(0, 350);
    delay(200);
HCPCA9685.Servo(0, 450);
    delay(200);

HCPCA9685.Servo(1, 350);
    delay(200);
HCPCA9685.Servo(1, 450);
    delay(200);

HCPCA9685.Servo(2, 350);
    delay(200);
HCPCA9685.Servo(2, 450);
    delay(200);

HCPCA9685.Servo(3, 350);
    delay(200);
HCPCA9685.Servo(3, 450);
    delay(200);

HCPCA9685.Servo(4, 350);
    delay(200);
HCPCA9685.Servo(4, 450);
    delay(200);

HCPCA9685.Servo(5, 350);
    delay(200);
HCPCA9685.Servo(5, 450);
    delay(200);

HCPCA9685.Servo(6, 350);
    delay(200);
HCPCA9685.Servo(6, 450);
    delay(200);

HCPCA9685.Servo(7, 350);
    delay(200);
HCPCA9685.Servo(7, 450);
    delay(200);

HCPCA9685.Servo(8, 350);
    delay(200);
HCPCA9685.Servo(8, 450);
    delay(200);

HCPCA9685.Servo(9, 350);
    delay(200);
HCPCA9685.Servo(9, 450);
    delay(200);

HCPCA9685.Servo(10, 350);
    delay(200);
HCPCA9685.Servo(10, 450);
    delay(200);

HCPCA9685.Servo(11, 350);
    delay(200);
HCPCA9685.Servo(11, 450);
    delay(200);

     unsigned int Pos;

  for(Pos = 450; Pos >= 200; Pos--)

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
  
  for(Pos = 200; Pos < 450; Pos++)
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

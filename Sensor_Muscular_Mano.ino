#include <Servo.h>

#define pinMusSen A1

int position = 1;
int contractionlimitvalue= 150;
int instantreading = 0;
int savedreading = 0;
int maxcontractionset = 0;
int mincontractionset= 1023;
int minmaxdifferenceset = 0 ;

int maxcontraction = 0;
int mincontraction= 1023;
int deltavalue = 0;
int maxmindifference = 0 ;
int contractiontype = 1;

Servo myservo2; //indice
Servo myservo3; //indice
Servo myservo4; //medio
Servo myservo5; //medio
Servo myservo6; //anular
Servo myservo7; //anular
Servo myservo8; //meñique
Servo myservo9; //meñique
Servo myservo10; //pulgar
Servo myservo11; //pulgar
Servo myservo12; //rotacion

int posmyservo2 = 0 ;
int posmyservo3 = 0 ;
int posmyservo4 = 0 ;
int posmyservo5 = 0 ;
int posmyservo6 = 0 ;
int posmyservo7 = 0 ;
int posmyservo8 = 0 ;
int posmyservo9 = 0 ;
int posmyservo10 = 0 ;
int posmyservo11 = 0 ;
int posmyservo12 = 0 ;

void setup() {
  
  myservo2.attach(2);  
  myservo3.attach(3); 
  myservo4.attach(4); 
  myservo5.attach(5); 
  myservo6.attach(6); 
  myservo7.attach(7); 
  myservo8.attach(8); 
  myservo9.attach(9); 
  myservo10.attach(10); 
  myservo11.attach(11); 
  myservo12.attach(12);


//Open
myservo10.write(120); 
delay(200);
myservo11.write(120); 
delay(200);
myservo12.write(90); 
delay(200);
myservo2.write(180); 
delay(200);
myservo3.write(180); 
delay(200);
myservo4.write(180); 
delay(200);
myservo5.write(180); 
delay(200);
myservo6.write(180); 
delay(200);
myservo7.write(180); 
delay(200);
myservo8.write(180); 
delay(200);
myservo9.write(180); 
delay(200);

delay(1000);

//Fase de calibración de la contracción muscular
delay(1000);     
instantreading = analogRead( pinMusSen );   //lee el valor de la contracción
savedreading = instantreading ;   //Escribir en la lectura guardada un número ya leído, diferente de cero
delay(25);
for (int i=0; i <= 120; i++)  //3 segundos para realizar una calibración precisa
      //contrae y suelta el músculo a veces durante 10 segundos para realizar la configuración de la señal
{
instantreading = analogRead( pinMusSen );
  if (instantreading > savedreading  &&  instantreading > maxcontractionset )
{
maxcontractionset = instantreading ;
}
  if (instantreading < savedreading  &&  instantreading < mincontractionset)
{
mincontractionset= instantreading ;
}
savedreading = instantreading;
Serial.print  ("Lettura Istantanea: ");
Serial.println( instantreading );
delay(25);
}
contractionlimitvalue= (( ( maxcontractionset - mincontractionset) / 2 ) + mincontractionset) * 0.8 ;

Serial.print  ("Maximum Contraction Set: ");
Serial.println(maxcontractionset);

Serial.print  ("Minimum Contrast Set: ");
Serial.println(mincontractionset);

//Detener calibración
  
myservo12.write(180); 
delay(200);
myservo12.write(90); 
delay(1000);

}

void loop() 
{
out:
instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
         savedreading = instantreading ;    //guardar la lectura guardada diferente de cero
        maxcontraction = instantreading ;     //guardar maxcontraction diferente de cero
         mincontraction= instantreading ;        //guardar mincontracción diferente de cero
delay(25);
  for (int i=0; i <= 20; i++)   //   
{
instantreading = analogRead( pinMusSen );
    if (instantreading > savedreading  &&  instantreading > maxcontraction )
  {
  maxcontraction = instantreading ;
  }
    if (instantreading < savedreading  &&  instantreading < mincontraction)
  {
  mincontraction= instantreading ;
  }
savedreading = instantreading;
Serial.print  ("Instant reading : ");
Serial.println( instantreading );
delay(25);
}
deltavalue = analogRead( pinMusSen );
maxmindifference = maxcontraction - mincontraction;
minmaxdifferenceset = maxcontractionset - mincontractionset;



if ( deltavalue < (contractionlimitvalue* 0.9) &&  mincontraction< (contractionlimitvalue* 0.8)  )
{
  contractiontype = 1 ;  //Contraction Pulse
  }
if ( deltavalue > (contractionlimitvalue* 0.9) &&  mincontraction> (contractionlimitvalue* 0.8)  )
{
  contractiontype = 2 ;  //Contraction Durable
  }
if ( deltavalue > (contractionlimitvalue* 0.9) &&  mincontraction< (contractionlimitvalue* 0.8)  )
{
  contractiontype = 3 ;
  }

if ( contractiontype == 2 && position == 1 ) 
  {
//Corre al puño
fist:
myservo8.write(60); 
myservo9.write(60); 
myservo6.write(60); 
myservo7.write(60); 
myservo4.write(60); 
myservo5.write(60); 
myservo2.write(60); 
myservo3.write(60); 
myservo12.write(180); 
delay(200);
myservo10.write(70); 
myservo11.write(70); 

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//que continúe corriendo al puño
goto fist ;
}

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//que continúe corriendo al puño
goto fist ;
}

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//que continúe corriendo al puño
goto fist ;
}
//de lo contrario, detenga los servomotores

posmyservo2 = myservo2.read();
myservo2.write(posmyservo2); 
posmyservo3 = myservo3.read();
myservo3.write(posmyservo3); 
posmyservo4 = myservo4.read();
myservo4.write(posmyservo4); 
posmyservo5 = myservo5.read();
myservo5.write(posmyservo5); 
posmyservo6 = myservo6.read();
myservo6.write(posmyservo6); 
posmyservo7 = myservo7.read();
myservo7.write(posmyservo7); 
posmyservo8 = myservo8.read();
myservo8.write(posmyservo8); 
posmyservo9 = myservo9.read();
myservo9.write(posmyservo9); 
posmyservo10 = myservo10.read();
myservo10.write(posmyservo10); 
posmyservo11 = myservo11.read();
myservo11.write(posmyservo11); 
posmyservo12 = myservo12.read();
myservo12.write(posmyservo12); 


delay(150);

Serial.print  ("Tipo de contracción : ");
Serial.println( contractiontype );

Serial.println  ("Mano cerrada ");

position = 2 ;
contractiontype = 0;
goto out ;

}

if ( contractiontype == 2 && position == 2 ) 
  {
//Corre al puño
fist2:
myservo8.write(50); 
myservo9.write(50); 
myservo6.write(50); 
myservo7.write(50); 
myservo4.write(50); 
myservo5.write(50); 
myservo2.write(50); 
myservo3.write(50); 
myservo12.write(180); 
delay(300);
myservo10.write(60); 
myservo11.write(60); 

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//que continúe corriendo al puño
goto fist2 ;
}

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
// que continúe corriendo al puño
goto fist2 ;
}

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//que continúe corriendo al puño
goto fist2 ;
}

//de lo contrario, detenga los motores
posmyservo2 = myservo2.read();
myservo2.write(posmyservo2); 
posmyservo3 = myservo3.read();
myservo3.write(posmyservo3); 
posmyservo4 = myservo4.read();
myservo4.write(posmyservo4); 
posmyservo5 = myservo5.read();
myservo5.write(posmyservo5); 
posmyservo6 = myservo6.read();
myservo6.write(posmyservo6); 
posmyservo7 = myservo7.read();
myservo7.write(posmyservo7); 
posmyservo8 = myservo8.read();
myservo8.write(posmyservo8); 
posmyservo9 = myservo9.read();
myservo9.write(posmyservo9); 
posmyservo10 = myservo10.read();
myservo10.write(posmyservo10); 
posmyservo11 = myservo11.read();
myservo11.write(posmyservo11); 
posmyservo12 = myservo12.read();
myservo12.write(posmyservo12); 

delay(150);

Serial.print  ("Tipo de contracción: ");
Serial.println( contractiontype );

Serial.println  ("Mano cerrada ");

position = 2 ;
contractiontype = 0;
goto out ;

}

if ( contractiontype == 1 && position == 2 )
  {
//Abrir la mano
myservo10.write(120); 
myservo11.write(120); 
myservo12.write(90); 
delay(200);
myservo2.write(180); 
myservo3.write(180); 
myservo4.write(180); 
myservo5.write(180); 
myservo6.write(180); 
myservo7.write(180); 
myservo8.write(180); 
myservo9.write(180); 

Serial.print  ("Tipo de contracción: ");
Serial.println( contractiontype );

Serial.println  ("Mano abierta ");


delay(1200);

position = 1 ;
contractiontype = 0;
goto out ;


}

if ( contractiontype == 1 && position == 1 )
  {
// obtener la posición de los 3 dedos (posición 3)
myservo8.write(20); 
myservo9.write(20); 
myservo6.write(20); 
myservo7.write(20); 
myservo12.write(180); 


position = 3 ;
contractiontype = 0;
goto out ;

}

if ( contractiontype == 2 && position == 3 ) 
  {
//Correr a 3 dedos cerrados
TFC:  // 3 dedos cerrados

myservo4.write(70); 
myservo5.write(110); 
myservo2.write(70); 
myservo3.write(110); 
delay(200);
myservo10.write(70); 
myservo11.write(70); 

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//luego continuar con 3 dedos cerrados
goto TFC ;
}

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//luego continuar con 3 dedos cerrados
goto TFC ;
}

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//luego continuar con 3 dedos cerrados
goto TFC ;
}

//de lo contrario, detenga los motores
posmyservo2 = myservo2.read();
myservo2.write(posmyservo2); 
posmyservo3 = myservo3.read();
myservo3.write(posmyservo3); 
posmyservo4 = myservo4.read();
myservo4.write(posmyservo4); 
posmyservo5 = myservo5.read();
myservo5.write(posmyservo5); 
posmyservo6 = myservo6.read();
myservo6.write(posmyservo6); 
posmyservo7 = myservo7.read();
myservo7.write(posmyservo7); 
posmyservo8 = myservo8.read();
myservo8.write(posmyservo8); 
posmyservo9 = myservo9.read();
myservo9.write(posmyservo9); 
posmyservo10 = myservo10.read();
myservo10.write(posmyservo10); 
posmyservo11 = myservo11.read();
myservo11.write(posmyservo11); 
posmyservo12 = myservo12.read();
myservo12.write(posmyservo12); 


delay(150);

position = 4 ;
contractiontype = 0;
goto out ;

}

if ( contractiontype == 2 && position == 4 ) 
  {
//Correr a 3 dedos cerrados
TFCC: // 3 dedos cerrados

myservo4.write(60); 
myservo5.write(100); 
myservo2.write(60); 
myservo3.write(100); 
delay(200);
myservo10.write(70); 
myservo11.write(70); 


delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//luego continuar con 3 dedos cerrados
goto TFCC ;
}

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//luego continuar con 3 dedos cerrados 
goto TFCC ;
}

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//luego continuar con 3 dedos cerrados
goto TFCC ;
}

//de lo contrario, detenga los motores
posmyservo2 = myservo2.read();
myservo2.write(posmyservo2); 
posmyservo3 = myservo3.read();
myservo3.write(posmyservo3); 
posmyservo4 = myservo4.read();
myservo4.write(posmyservo4); 
posmyservo5 = myservo5.read();
myservo5.write(posmyservo5); 
posmyservo6 = myservo6.read();
myservo6.write(posmyservo6); 
posmyservo7 = myservo7.read();
myservo7.write(posmyservo7); 
posmyservo8 = myservo8.read();
myservo8.write(posmyservo8); 
posmyservo9 = myservo9.read();
myservo9.write(posmyservo9); 
posmyservo10 = myservo10.read();
myservo10.write(posmyservo10); 
posmyservo11 = myservo11.read();
myservo11.write(posmyservo11); 
posmyservo12 = myservo12.read();
myservo12.write(posmyservo12); 

delay(150);

position = 4 ;
contractiontype = 0;
goto out ;

}

if ( contractiontype == 1 && position == 4 )
  {
//Abre la mano
myservo10.write(90); 
myservo11.write(90); 
myservo12.write(90); 
delay(200);
myservo2.write(180); 
myservo3.write(180); 
myservo4.write(180); 
myservo5.write(180); 
myservo6.write(180); 
myservo7.write(180); 
myservo8.write(180); 
myservo9.write(180); 

Serial.print  ("Contraction type : ");
Serial.println( contractiontype );

Serial.println  ("Open Hand ");


delay(1200);

position = 1 ;
contractiontype = 0;
goto out ;


}

if ( contractiontype == 1 && position == 3 )
  {
//obtener la posición de 1 dedo (posición 5)

myservo4.write(20); 
myservo5.write(20); 

position = 5 ;
contractiontype = 0;
goto out ;

}

if ( contractiontype == 2 && position == 5 ) 
  {
//Correr a 1 dedo cerrado
OFC: // Un dedo cerrado - Pellizcar

myservo2.write(60); 
myservo3.write(135); 
myservo12.write(180); 
delay(200);
myservo10.write(70); 
myservo11.write(90); 


delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//than continue to 1 Finger closed
goto OFC ;
}

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
// luego continuar con 1 dedo cerrado
goto OFC ;
}

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//luego continuar con 1 dedo cerrado
goto OFC ;
}

//de lo contrario, detenga los motores
posmyservo2 = myservo2.read();
myservo2.write(posmyservo2); 
posmyservo3 = myservo3.read();
myservo3.write(posmyservo3); 
posmyservo4 = myservo4.read();
myservo4.write(posmyservo4); 
posmyservo5 = myservo5.read();
myservo5.write(posmyservo5); 
posmyservo6 = myservo6.read();
myservo6.write(posmyservo6); 
posmyservo7 = myservo7.read();
myservo7.write(posmyservo7); 
posmyservo8 = myservo8.read();
myservo8.write(posmyservo8); 
posmyservo9 = myservo9.read();
myservo9.write(posmyservo9); 
posmyservo10 = myservo10.read();
myservo10.write(posmyservo10); 
posmyservo11 = myservo11.read();
myservo11.write(posmyservo11); 
posmyservo12 = myservo12.read();
myservo12.write(posmyservo12); 

delay(150);

position = 6 ;
contractiontype = 0;
goto out ;

}

if ( contractiontype == 2 && position == 6 ) 
  {
// Correr a 1 dedo cerrado
OFCC: // Un dedo cerrado

myservo2.write(55); 
myservo3.write(135); 
myservo12.write(180); 
delay(200);
myservo10.write(65); 
myservo11.write(90); 

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
// luego continuar con 1 dedo cerrado
goto OFCC ;
}

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//luego continuar con 1 dedo cerrado
goto OFCC ;
}

delay(100);

instantreading = analogRead( pinMusSen );
if ( instantreading > contractionlimitvalue)
{
//luego continuar con 1 dedo cerrado
goto OFCC ;
}

//de lo contrario, detenga los motores
posmyservo2 = myservo2.read();
myservo2.write(posmyservo2); 
posmyservo3 = myservo3.read();
myservo3.write(posmyservo3); 
posmyservo4 = myservo4.read();
myservo4.write(posmyservo4); 
posmyservo5 = myservo5.read();
myservo5.write(posmyservo5); 
posmyservo6 = myservo6.read();
myservo6.write(posmyservo6); 
posmyservo7 = myservo7.read();
myservo7.write(posmyservo7); 
posmyservo8 = myservo8.read();
myservo8.write(posmyservo8); 
posmyservo9 = myservo9.read();
myservo9.write(posmyservo9); 
posmyservo10 = myservo10.read();
myservo10.write(posmyservo10); 
posmyservo11 = myservo11.read();
myservo11.write(posmyservo11); 
posmyservo12 = myservo12.read();
myservo12.write(posmyservo12); 

delay(150);

position = 6 ;
contractiontype = 0;
goto out ;

}

if ( contractiontype == 1 && position == 6 )
  {
// Open the Hand
myservo10.write(120); 
myservo11.write(120); 
myservo12.write(90); 
delay(200);
myservo2.write(180); 
myservo3.write(180); 
myservo4.write(180); 
myservo5.write(180); 
myservo6.write(180); 
myservo7.write(180); 
myservo8.write(180); 
myservo9.write(180); 

Serial.print  ("Tipo de contracción : ");
Serial.println( contractiontype );

Serial.println  ("Mano abierta ");

delay(1200);

position = 1 ;
contractiontype = 0;
goto out ;


}

if ( contractiontype == 1 && position == 5 )
  {
// Open the Hand
myservo10.write(120); 
myservo11.write(120); 
myservo12.write(90); 
delay(200);
myservo2.write(180); 
myservo3.write(180); 
myservo4.write(180); 
myservo5.write(180); 
myservo6.write(180); 
myservo7.write(180); 
myservo8.write(180); 
myservo9.write(180); 


Serial.print  ("Tipo de contracción : ");
Serial.println( contractiontype );


Serial.println  ("Mano abierta ");


delay(1200);

position = 1 ;
contractiontype = 0;
goto out ;

}

}

}

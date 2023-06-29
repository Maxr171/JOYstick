#include <PS2X_lib.h>  

PS2X ps2x;

int error = 0;
byte vibrate = 0;

void setup()
{
  Serial.begin(9600);
  error = ps2x.config_gamepad(8,12,A0,13,true,true);  //(clock, command, attention, data)

  if(error == 0)
  {
    Serial.println("Controlador encontrado y configurado");
  }
  else
  {
    Serial.println("Error, mando no encontrado");
  }
}

void loop() 
{
  int temp;
  ps2x.read_gamepad(false,vibrate);

  vibrate = ps2x.Analog(PSAB_BLUE);
  
  if(ps2x.Button(PSB_PAD_UP))
  {
    temp = ps2x.Analog (PSAB_PAD_UP);
    Serial.print("Presionaste arriba: ");
    Serial.println(temp);
  }
  
  else if(ps2x.Button (PSB_PAD_DOWN))
  {
    temp = ps2x.Analog(PSAB_PAD_DOWN);
    Serial.print("Presionaste abajo: ");
    Serial.println(temp);
  }

  else if(ps2x.Button (PSB_PAD_LEFT))
  {
    temp = ps2x.Analog (PSAB_PAD_LEFT);
    Serial.println("Presionaste izquierda: ");
    Serial.print(temp);
  }

  else if(ps2x.Button(PSB_PAD_RIGHT))
  {
    temp = ps2x.Analog(PSAB_PAD_RIGHT);
    Serial.println("Presionaste derecha: ");
    Serial.print(temp);
  }


  if(ps2x.Button (PSB_BLUE))
  {
    Serial.println("Presionaste X: ");
  }
  if(ps2x.Button (PSB_PINK))
  {
    Serial.println ("Presionaste cuadrado: ");
  }
  if(ps2x.Button(PSB_RED))
  {
    Serial.println("Presionaste redondo: ");
  }
  if(ps2x.Button(PSB_GREEN))
  {
    Serial.println("Presionaste triangulo: ");
  }
  if(ps2x.Button(PSB_L1))
  {
    Serial.println("Presionaste L1: ");
  }
  if(ps2x.Button(PSB_L2))
  {
    Serial.println("Presionaste L2: ");
  }
  if(ps2x.Button(PSB_R1))
  {
    Serial.println("Presionaste R1: ");
  }
  if(ps2x.Button(PSB_R2))
  {
    Serial.println("Presionaste R2: ");
  }

  
  if(ps2x.Button(PSB_SELECT))
  {
    Serial.println("Presionaste seleccionar: ");
  }
  else if(ps2x.Button(PSB_START))
  {
    Serial.println("Presionaste entrar: ");
  }

  
  delay(50);
}




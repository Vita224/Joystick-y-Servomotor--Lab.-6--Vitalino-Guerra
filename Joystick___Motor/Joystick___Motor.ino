#include <Servo.h> //Libreria del Servomotor
Servo servomotor;

int direccionX = A0;  //Pin para leer los movimientos en el eje X
int direccionY = A1;  //Pin para leer los movimientos en el eje Y
int pulsador_joystick = 7;  //Pin para leer el pulsador

int lecturaX;  //Almacena el valor leido en el eje X
int lecturaY;  //Almacena el valor leido en el eje Y, valor que en este caso no se usara pero si se indicara donde se escribe
int lectura_pulsador;  //Almacena el valor leido del pulsador

int posicion_servo = 0; //Variable para el control de la posicion incial del servo, esta en 0 grados

void setup() {
  servomotor.attach(3); //Pin PWM 3 del Arduino
  pinMode(direccionX, INPUT);
  pinMode(direccionY, INPUT);
  pinMode(pulsador_joystick, INPUT_PULLUP);   //Si el pulsador está presionado, muestra un 0
}

void loop() {
  int lecturaX = analogRead(A0);  //Lee y almacena el valor del joystick en X
  int lecturaY = analogRead(A1);  //Lee y almacena el valor del joystick en Y
  int lectura_pulsador = digitalRead(7);  //Lee y almacena el valor del pulsador del joystick

  if (lecturaX >= 550) //Si se mueve el joystick a la derecha, el angulo aumenta
  {
    posicion_servo++;

    if (posicion_servo > 180)  //El angulo no puede ser mayor a 180
    {
      posicion_servo = 180;
    }
  }

  if (lecturaX <= 450) //Si se mueve el joystick a la izquierda, el angulo disminuye
  {
    posicion_servo--;

    if (posicion_servo < 0)  //El angulo no puede ser menor a cero
    {
      posicion_servo = 0;
    }
  }

  if (lectura_pulsador == LOW) //Si se presiona el pulsador del joystick, el servo vuelve a los 90 grados
  {
    posicion_servo = 0;
  }

  servomotor.write(posicion_servo);   //Escribimos el angulo en el servo
  delay(1);
}

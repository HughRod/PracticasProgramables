/**
 * TAREA 1
 * Programa que simula semáforos que, al presionar un botón, cambia a verde para
 * peatones y a rojo para coches.
 * Se toma en consideración que debe de pasar cierto tiempo antes de que se pueda
 * presionar el botón nuevamente. Este tiempo es controlado por el valor del potenciómetro
 * de 10K.
 * Autor: Hugo Rodrigo Murillo Martínez
 * Maestro: Carlos Rafael Levy Rojas
 * Materia: Sistemas Programables
 * Horario: Martes y jueves 8.45 - 10.25
 */

int LED_VERDE_COCHE = 13; // VERDE COCHES
int LED_ROJO_COCHE = 12; // ROJO COCHES

int LED_VERDE_PEATON = 11; // VERDE PEATÓN
int LED_AMARILLO_PEATON = 10; // AMARILLO PEATÓN
int LED_ROJO_PEATON = 9; // ROJO PEATÓN

int PULSADOR = 2; // BOTÓN
boolean PAUSAR = false; // VARIABLE BANDERA QUE CAMBIA DE ESTADO CUANDO SE HA PRESIONADO EL BOTÓN

void setup() {
  pinMode(LED_VERDE_COCHE, OUTPUT); // CONFIGURAR LED COMO SALIDA
  pinMode(LED_ROJO_COCHE, OUTPUT); // CONFIGURAR LED COMO SALIDA

  pinMode(LED_VERDE_PEATON, OUTPUT); // CONFIGURAR LED COMO SALIDA
  pinMode(LED_AMARILLO_PEATON, OUTPUT); // CONFIGURAR LED COMO SALIDA
  pinMode(LED_ROJO_PEATON, OUTPUT); // CONFIGURAR LED COMO SALIDA

  pinMode(PULSADOR, INPUT); // CONFIGURAR BOTÓN COMO ENTRADA

  Serial.begin(9600); // INICIAR COMUNICACIÓN SERIAL
}

void loop() {
  if (PAUSAR) { // SI ACABA DE PRESIONARSE EL BOTÓN
    delay(analogRead(A0)*3); // TIEMPO DE ESPERA EN FUNCIÓN DEL VALOR DEL POTENCIÓMETRO
    Serial.println(analogRead(A0)*3); // IMPRIMIR EL TIEMPO DE ESPERA EN LA CONSOLA
    PAUSAR = false; // CAMBIAR ESTADO DE LA VARIABLE BANDERA A FALSO
  } else { // SI NO SE HA PRESIONADO EL BOTÓN
    digitalWrite(LED_VERDE_COCHE, HIGH); // ENCENDER EL VERDE PARA COCHES
    digitalWrite(LED_ROJO_PEATON, HIGH); // ENCENDER EL ROJO PARA PEATONES

    if (digitalRead(PULSADOR) == LOW) { // SI SE PULSÓ EL BOTÓN
      digitalWrite(LED_VERDE_COCHE, LOW); // APAGAR EL VERDE DE COCHES
      digitalWrite(LED_ROJO_COCHE, HIGH); // ENCENDER EL ROJO DE COCHES

      digitalWrite(LED_VERDE_PEATON, HIGH); // ENCENDER EL VERDE DE PEATÓN
      digitalWrite(LED_ROJO_PEATON, LOW); // APAGAR EL ROJO DE PEATÓN
      delay(2000); // ESPERAR DOS SEGUNDOS
      PAUSAR = true; // CAMBIAR EL ESTADO DE LA VARIABLE A 'TRUE' PORQUE SE ACABA DE PRESIONAR EL BOTÓN

      digitalWrite(LED_VERDE_COCHE, LOW); // APAGAR EL VERDE DE COCHES
      digitalWrite(LED_VERDE_PEATON, LOW); // APAGAR EL VERDE DE PEATÓN
      digitalWrite(LED_AMARILLO_PEATON, HIGH); // ENCENDER EL AMARILLO DE PEATONES
      delay(1000); // ESPERAR UN SEGUNDO ANTES DE REESTABLECER VALORES DE LEDS
      resetBotones(); // LLAMAR AL MÉTODO QUE REESTABLECE VALORES DE LEDS
    }
  }
}

// MÉTODO QUE REESTABLECE VALORES DE LOS LEDS. DEJA PASAR A LOS COCHES, PERO NO AL PEATÓN
void resetBotones() {
  digitalWrite(LED_VERDE_COCHE, HIGH); // ENCENDER BOTÓN VERDE DE COCHES
  digitalWrite(LED_ROJO_COCHE, LOW); // APAGAR EL ROJO DE COCHES

  digitalWrite(LED_VERDE_PEATON, LOW); // APAGAR VERDE DE PEATONES
  digitalWrite(LED_ROJO_PEATON, HIGH); // ENCENDER BOTÓN ROJO DE PEATONES
  digitalWrite(LED_AMARILLO_PEATON, LOW); // APAGAR LED AMARILLO DE PEATONES
}


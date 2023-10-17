#define PLACA 1

#if PLACA == 1
  #define VERDE PB7
  #define AMARILLO PB8
  #define ROJO PB9
  #define BUZZER PA0
  #define BTN PA1
  #define BTNALARMA PA2
  
  #define BTNTYPE INPUT_PULLUP
  #define PRENDIDOBTN LOW
  #define APAGADOBTN HIGH
  
  #define PRENDIDOLED HIGH
  #define APAGADOLED LOW  
   
#endif

#if PLACA == 2
  #define VERDE PA7
  #define AMARILLO PB5
  #define ROJO PB6
  #define BUZZER PA3
  #define BTN PA4
  #define BTNALARMA PA5
  
  #define BTNTYPE INPUT_PULLUP
  #define PRENDIDOBTN LOW
  #define APAGADOBTN HIGH
  
  #define PRENDIDOLED LOW
  #define APAGADOLED HIGH
   
#endif

#if PLACA == 3
  #define VERDE PB11
  #define AMARILLO PB1
  #define ROJO PB0
  #define BUZZER PB9
  #define BTN PB7
  #define BTNALARMA PB8
  
  #define BTNTYPE INPUT_PULLDOWN
  #define PRENDIDOBTN HIGH
  #define APAGADOBTN LOW
  
  #define PRENDIDOLED HIGH
  #define APAGADOLED LOW
#endif

#if PLACA == 4
  #define VERDE PB12
  #define AMARILLO PB13
  #define ROJO PB14
  #define BUZZER PA9
  #define BTN PA0
  #define BTNALARMA PA1
  
  #define BTNTYPE INPUT_PULLDOWN
  #define PRENDIDOBTN HIGH
  #define APAGADOBTN LOW
  
  #define PRENDIDOLED LOW
  #define APAGADOLED HIGH
#endif

int btnState;
int btnAlarmaState;
int estado = 1;

void setup() {
  pinMode(VERDE, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(ROJO, OUTPUT);
  afio_cfg_debug_ports(AFIO_DEBUG_SW_ONLY);

  pinMode(BTN, BTNTYPE);
  pinMode(BTNALARMA, BTNTYPE);

  Serial.begin(9600);
}

void loop() {
  btnState = digitalRead(BTN);
  btnAlarmaState = digitalRead(BTNALARMA);

switch (estado) {
    case 1:
      digitalWrite(VERDE, PRENDIDO);

      if (btnState == PRENDIDOBTN){
        estado = 2;
      }
      break;
  }

}

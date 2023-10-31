#define PLACA 4


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
int estado;

void setup() {
  pinMode(VERDE, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(ROJO, OUTPUT);
  afio_cfg_debug_ports(AFIO_DEBUG_SW_ONLY);

  pinMode(BTN, BTNTYPE);
  pinMode(BTNALARMA, BTNTYPE);

  //attachInterrupt(BTNALARMA, Alarma, CHANGE);

   
  Timer1.pause();
  Timer1.setPeriod(2000000); // in microseconds. Ej: 500000 = 500 milisec
  Timer1.setMode(TIMER_CH1,TIMER_OUTPUT_COMPARE);
  Timer1.setCompare(TIMER_CH1, -1); // Interrupts on overflow
  Timer1.attachInterrupt(TIMER_CH1, BtnPressed);
  Timer1.refresh();
  Timer1.resume();

  estado = 1;
  Serial.begin(9600);
 
}

void loop() {
  btnState = digitalRead(BTN);
  btnAlarmaState = digitalRead(BTNALARMA);
  switch (estado) {
    case 1:
      digitalWrite(ROJO, APAGADOLED);
      digitalWrite(AMARILLO, APAGADOLED);
      digitalWrite(VERDE, PRENDIDOLED);

      if (btnState == APAGADOBTN){
       Timer1.pause();
       Timer1.setPeriod(500000); // in microseconds. Ej: 500000 = 500 milisec
       Timer1.refresh();
       Timer1.resume();
      }
      
     /* if (btnState == PRENDIDOBTN){
        estado = 2;
        Serial.print("dos");
        digitalWrite(BUZZER, HIGH);
      }        

     if (BTNALARMA == PRENDIDOBTN){
       digitalWrite(VERDE, APAGADOLED);
       estado = 3;
       Serial.print(estado);
     } */

     break;

     case 2:
     digitalWrite(ROJO, PRENDIDOLED);
     digitalWrite(AMARILLO, APAGADOLED);
     digitalWrite(VERDE, APAGADOLED);
     break;
   }
 }

 void BtnPressed(){
  digitalWrite(AMARILLO, PRENDIDOLED);
  digitalWrite(VERDE, APAGADOLED);
  estado = 2;
 }

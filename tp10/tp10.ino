#define PLACA 2


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
  #define VERDE PA10
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
  Timer1.attachInterrupt(TIMER_CH1, Hola);
 

  Timer2.pause();
  Timer2.setPeriod(5000000);
  Timer2.setMode(TIMER_CH1,TIMER_OUTPUT_COMPARE);
  Timer2.setCompare(TIMER_CH1, -1); // Interrupts on overflow
  Timer2.attachInterrupt(TIMER_CH1, Hola2);

  estado = 1;
  Serial.begin(9600);
}

void loop() {
  btnState = digitalRead(BTN);
  btnAlarmaState = digitalRead(BTNALARMA);

      digitalWrite(ROJO, PRENDIDOLED);
      digitalWrite(AMARILLO, APAGADOLED);
      digitalWrite(VERDE, APAGADOLED);  
        
 /* switch (estado) {
    case 1:

      Timer1.pause();
      Timer1.refresh();
      Timer1.resume();         
      
      break;
 } */
 
 }

 void Hola(){
  digitalWrite(VERDE, APAGADOLED);
  digitalWrite(AMARILLO, PRENDIDOLED);
  digitalWrite(ROJO, APAGADOLED);
  }
 
 void Hola2(){
  digitalWrite(VERDE, APAGADOLED);
  digitalWrite(AMARILLO, APAGADOLED);
  digitalWrite(ROJO, PRENDIDOLED);
 }

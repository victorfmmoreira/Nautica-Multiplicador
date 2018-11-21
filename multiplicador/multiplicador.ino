//Pinos dos botoes.
#define PIN_BOTAO_1 1
#define PIN_BOTAO_2 2

//Pinos do display esquerdo
//Mais significativo
#define PIN_LED_1A 3
#define PIN_LED_1B ( PIN_LED_1A + 1 )
#define PIN_LED_1C ( PIN_LED_1B + 1 )
#define PIN_LED_1D ( PIN_LED_1C + 1 )
#define PIN_LED_1E ( PIN_LED_1D + 1 )
#define PIN_LED_1F ( PIN_LED_1E + 1 )
#define PIN_LED_1G ( PIN_LED_1F + 1 )

//Pinos do display direito
//Menos significativo
#define PIN_LED_2A ( PIN_LED_1G + 1 )
#define PIN_LED_2B ( PIN_LED_2A + 1 )
#define PIN_LED_2C ( PIN_LED_2B + 1 )
#define PIN_LED_2D ( PIN_LED_2C + 1 )
#define PIN_LED_2E ( PIN_LED_2D + 1 )
#define PIN_LED_2F ( PIN_LED_2E + 1 )
#define PIN_LED_2G ( PIN_LED_2F + 1 )

// Tempo do debounce
#define DEBOUNCE_TIME 500

unsigned fator1, fator2, produto, estado;


void escreverNumeroNoDisplay( int pinA, int pinB, int pinC,
                              int pinD, int pinE, int pinF, 
                              int pinG, int numero );

void setup()
{
  // Botoes
  pinMode( PIN_BOTAO_1, INPUT);
  pinMode( PIN_BOTAO_2, INPUT);
  
  // Display esquerdo 
  //( mais significativo )
  pinMode( PIN_LED_1A, OUTPUT);
  pinMode( PIN_LED_1B, OUTPUT);
  pinMode( PIN_LED_1C, OUTPUT);
  pinMode( PIN_LED_1D, OUTPUT);
  pinMode( PIN_LED_1E, OUTPUT);
  pinMode( PIN_LED_1F, OUTPUT);
  pinMode( PIN_LED_1G, OUTPUT);

  // Display direiro
  // Menos Significativo

  pinMode( PIN_LED_2A, OUTPUT);
  pinMode( PIN_LED_2B, OUTPUT);
  pinMode( PIN_LED_2C, OUTPUT);
  pinMode( PIN_LED_2D, OUTPUT);
  pinMode( PIN_LED_2E, OUTPUT);
  pinMode( PIN_LED_2F, OUTPUT);
  pinMode( PIN_LED_2G, OUTPUT);
  
  fator1 = 0;
  fator2 = 0;
  produto = 0;
  estado = 0;
}

void loop()
{
  
  if( digitalRead( PIN_BOTAO_1) == HIGH )  {
    //Soma ao fator do estado atual
    switch( estado) {
      case 0:
        if( fator1 == 9 )
          fator1 = 0;
        else
          fator1++;
      case 1:
        if( fator2 == 9 )
          fator2 = 0;
        else
          fator2++;
    } 
    //Debounce
    delay( DEBOUNCE_TIME );
  }  
  else if( digitalRead( PIN_BOTAO_2) == HIGH ) {
    //Muda de estado
    switch( estado) {
      case 0:
        estado = 1;
        break;
      case 1:
        produto = fator1 * fator2;
        estado = 2;
        break;
      case 2:
        fator1 = 0;
        fator2 = 0;
        produto = 0;
        estado = 0;
        break;
    }    
    //Debounce
    delay( DEBOUNCE_TIME );  
  }
  
  //Retorno no display
  //O display so mudara apos o debouncer
  switch( estado ) {
    case 0:
      //Display 1 mostra o estado atual
      //Led superior
      digitalWrite( PIN_LED_1A, HIGH );
      digitalWrite( PIN_LED_1B, LOW );
      digitalWrite( PIN_LED_1C, LOW );
      digitalWrite( PIN_LED_1D, LOW );
      digitalWrite( PIN_LED_1E, LOW );
      digitalWrite( PIN_LED_1F, LOW );
      digitalWrite( PIN_LED_1G, LOW );
      //Display 2 mostra a entrada
      escreverNumeroNoDisplay( PIN_LED_2A, PIN_LED_2B, PIN_LED_2C, 
                               PIN_LED_2D, PIN_LED_2E, PIN_LED_2F, 
                               PIN_LED_2G, fator1 );
    case 1:
      //Display 1 mostra o estado atual
      //Led do meio
      digitalWrite( PIN_LED_1A, LOW );
      digitalWrite( PIN_LED_1B, LOW );
      digitalWrite( PIN_LED_1C, LOW );
      digitalWrite( PIN_LED_1D, LOW );
      digitalWrite( PIN_LED_1E, LOW );
      digitalWrite( PIN_LED_1F, LOW );
      digitalWrite( PIN_LED_1G, HIGH );
      //Display 2 mostra a entrada
      escreverNumeroNoDisplay( PIN_LED_2A, PIN_LED_2B, PIN_LED_2C, 
                               PIN_LED_2D, PIN_LED_2E, PIN_LED_2F, 
                               PIN_LED_2G, fator2 ); 
    case 2:
      //Display 1 mostra algarismo mais significativo
      escreverNumeroNoDisplay( PIN_LED_1A, PIN_LED_1B, PIN_LED_1C, 
                               PIN_LED_1D, PIN_LED_1E, PIN_LED_1F, 
                               PIN_LED_1G, (int) produto / 10 ); 
    
      //Display 2 mostra algarismo menos significativo
      escreverNumeroNoDisplay( PIN_LED_2A, PIN_LED_2B, PIN_LED_2C, 
                               PIN_LED_2D, PIN_LED_2E, PIN_LED_2F, 
                               PIN_LED_2G, produto % 10 ); 
      
  } 

}

//Funcao do display
//Catodo comum
//Display so muda apos o debounce
void escreverNumeroNoDisplay( int pinA, int pinB, int pinC,
                              int pinD, int pinE, int pinF, 
                              int pinG, int numero ) {
                                
  switch( numero) {
    case 0:
      digitalWrite( pinA, HIGH);
      digitalWrite( pinB, HIGH);
      digitalWrite( pinC, HIGH);
      digitalWrite( pinD, HIGH);
      digitalWrite( pinE, HIGH);
      digitalWrite( pinF, HIGH);
      digitalWrite( pinG, LOW);
    case 1:
      digitalWrite( pinA, LOW);
      digitalWrite( pinB, HIGH);
      digitalWrite( pinC, HIGH);
      digitalWrite( pinD, LOW);
      digitalWrite( pinE, LOW);
      digitalWrite( pinF, LOW);
      digitalWrite( pinG, LOW);
    case 2:
      digitalWrite( pinA, HIGH);
      digitalWrite( pinB, HIGH);
      digitalWrite( pinC, LOW);
      digitalWrite( pinD, HIGH);
      digitalWrite( pinE, HIGH);
      digitalWrite( pinF, LOW);
      digitalWrite( pinG, HIGH);
    case 3:
      digitalWrite( pinA, HIGH);
      digitalWrite( pinB, HIGH);
      digitalWrite( pinC, HIGH);
      digitalWrite( pinD, HIGH);
      digitalWrite( pinE, LOW);
      digitalWrite( pinF, LOW);
      digitalWrite( pinG, HIGH);
    case 4:
      digitalWrite( pinA, LOW);
      digitalWrite( pinB, HIGH);
      digitalWrite( pinC, HIGH);
      digitalWrite( pinD, LOW);
      digitalWrite( pinE, LOW);
      digitalWrite( pinF, HIGH);
      digitalWrite( pinG, HIGH);
    case 5:
      digitalWrite( pinA, HIGH);
      digitalWrite( pinB, LOW);
      digitalWrite( pinC, HIGH);
      digitalWrite( pinD, HIGH);
      digitalWrite( pinE, LOW);
      digitalWrite( pinF, HIGH);
      digitalWrite( pinG, HIGH);
    case 6:
      digitalWrite( pinA, HIGH);
      digitalWrite( pinB, HIGH);
      digitalWrite( pinC, HIGH);
      digitalWrite( pinD, HIGH);
      digitalWrite( pinE, LOW);
      digitalWrite( pinF, HIGH);
      digitalWrite( pinG, HIGH);
    case 7:
      digitalWrite( pinA, HIGH);
      digitalWrite( pinB, HIGH);
      digitalWrite( pinC, HIGH);
      digitalWrite( pinD, LOW);
      digitalWrite( pinE, LOW);
      digitalWrite( pinF, LOW);
      digitalWrite( pinG, LOW);
    case 8:
      digitalWrite( pinA, HIGH);
      digitalWrite( pinB, HIGH);
      digitalWrite( pinC, HIGH);
      digitalWrite( pinD, HIGH);
      digitalWrite( pinE, HIGH);
      digitalWrite( pinF, HIGH);
      digitalWrite( pinG, HIGH);
    case 9:
      digitalWrite( pinA, HIGH);
      digitalWrite( pinB, HIGH);
      digitalWrite( pinC, HIGH);
      digitalWrite( pinD, LOW);
      digitalWrite( pinE, LOW);
      digitalWrite( pinF, HIGH);
      digitalWrite( pinG, HIGH);
  }

}

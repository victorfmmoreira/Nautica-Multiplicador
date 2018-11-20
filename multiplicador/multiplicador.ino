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
}

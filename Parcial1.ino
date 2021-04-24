#define DATA_PIN 11
#define CLOCK_PIN 13
#define SS_PIN_1 10
#define SS_PIN_2 9
int ch[8][8] =
{        
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}    
};
int matriz_modificable[8][8]{0};
int *puntero_matriz = new int[8]{0};
char col[8]{48,48,48,48,48,48,48,48};
int fila = 1;
char data;
void spi_write_1(unsigned  char cData) {
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, cData);
  digitalWrite (SS_PIN_1, HIGH);
  digitalWrite (SS_PIN_1, LOW);}
void spi_write_2( unsigned char cData) {
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, cData);
  digitalWrite (SS_PIN_2, HIGH);
  digitalWrite (SS_PIN_2, LOW);}
void writePosition(int x, int y) {
  spi_write_1(  B00000001 << x );  // COL  
    spi_write_2(~(B00000001 << y )); // ROW
}
  void setup (){  
    pinMode(SS_PIN_1, OUTPUT);
    pinMode(SS_PIN_2, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    Serial.begin(9600);
    Serial.println("1. Verificacion de leds");
    Serial.println("2. Crear tu propia imagen");
    spi_write_1(  B00000000);  // COL 
    spi_write_2(~(B00000000)); // ROW   
    }
  void loop(){
    if(Serial.available()==1){
      char t = Serial.read();
      Serial.println(t);
      if(t=='1'){
    	for (int row=0; row <8;row++) 
    	{
  			for (int colu=0; colu <8;colu++) 
  				{if (ch[colu][row] == 1) {
   					writePosition(colu,row);
  					}
                }
        }
      }
    Serial.print("Ingresa opcion");
      if (t =='2'){
        
        while (fila < 8){
          Serial.print("Ingrese la fila que quiere manipular");
          fila = Serial.read();
          Serial.print("Ingrese con 0 y 1 en orden para decidir cualquiere que encienda y cualquiere que se mantenga apagada, 1 para encender, 0 para mantener apagado");
          col[1] = Serial.read();
          for (int i = 0; i<8;i++){
            *(puntero_matriz+i) = int(col[i]);
          }
          for (int i = 0; i<8; i++){
            matriz_modificable[fila][i] = *(puntero_matriz+i);
          }          
          for (int row = 0; row < 8;row++){
                        for (int colu=0; colu < 8;colu++){
              if (matriz_modificable[row][colu]== 1){
                writePosition(colu,row);
              }
            }
          }
          Serial.print("Quieres modificar otra fila? Escribe 'Y' en caso que si o 'N' si no");
          data = Serial.read();
          if (data == 'Y');
          else if (data == 'N'){
      		fila = 8;
          }
          while(data != 'Y' && data != 'N'){
            Serial.print("Ingresa un caracter valido, Y para ingresar otra fila, N si quiere salir");
            data = Serial.read();
            if (data == 'Y');
            else if (data == 'N'){
              fila = 8;
            }
          }
        }
      }
    }
  }
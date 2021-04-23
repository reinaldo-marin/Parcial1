#define DATA_PIN 11
#define CLOCK_PIN 13
#define SS_PIN_1 10
#define SS_PIN_2 9
int ch[5][8][8] =
{  
  {    
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}  
  },
  {    
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}  
  },
  {    
    {1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}  
  },
  {    
    {1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}  
  },
  {    
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1}  
  }
  
};
unsigned long timestamp = 0;
int ch_no = 0;
void spi_write_1(unsigned  char cData) {
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, cData);
  digitalWrite (SS_PIN_1, HIGH);
  digitalWrite (SS_PIN_1, LOW);}
void spi_write_2( unsigned char cData) {
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, cData);
  digitalWrite (SS_PIN_2, HIGH);
  digitalWrite (SS_PIN_2, LOW);}
void writePosition(int x, int y) {
  spi_write_1(  0b00000001 << x );  // COL  
    spi_write_2(~(0b00000001 << y )); // ROW
}
  void setup (){  
    pinMode(SS_PIN_1, OUTPUT);
    pinMode(SS_PIN_2, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    Serial.begin(9600);
    Serial.println("Enter character : ");
    timestamp = millis();
    spi_write_1(  0b00000000);  // COL 
    spi_write_2(~(0b00000000)); // ROW   
    }
  void loop(){
    if(Serial.available()==1){
      char t = Serial.read();
      Serial.println(t);
      if(t=='t'){ch_no=0;}
      if(t=='o'){ch_no=1;}
      if(t=='f'){ch_no=3;}
      if(t=='y'){ch_no=4;}
      Serial.print("Enter character : ");
    }
    for (int row=0; row <8;row++) 
    {
      for (int col=0; col <8;col++) 
      {if (ch[ch_no][row][col] == 1) {
        writePosition(col,7-row);
       }      
      }    
    }
  }
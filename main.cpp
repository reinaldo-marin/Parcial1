#include <iostream>

using namespace std;

int main()
{
    const int SER2 = 2;
    const int RCLK2 = 4;
    const int SRCLK2 = 5;
    const int SER = 7;
    const int RCLK = 8;
    const int SRCLK = 9;
    void setup()
    {
      //configuracion de puertos digitales como salida[1]
      pinMode (SER2, OUTPUT);
      pinMode (RCLK2, OUTPUT);
      pinMode (SRCLK2, OUTPUT);
      pinMode (SER, OUTPUT);
      pinMode (RCLK, OUTPUT);
      pinMode (SRCLK, OUTPUT);

      digitalWrite(SER, LOW);
      digitalWrite(RCLK, LOW);
      digitalWrite(SRCLK, LOW);
      digitalWrite(SER2, LOW);
      digitalWrite(RCLK2, LOW);
      digitalWrite(SRCLK, LOW);

      //llevar el dato al puerto serial de los 74HC595 0/1 [2]
      digitalWrite (SER, 1);
      digitalWrite (SER2,1);

      digitalWrite (SRCLK, 0);
      digitalWrite (SRCLK, 1);
      digitalWrite (SRCLK, 0);

      digitalWrite (SRCLK2, 0);
      digitalWrite (SRCLK2, 1);
      digitalWrite (SRCLK2, 0);

      digitalWrite (RCLK, 0);
      digitalWrite (RCLK, 1);
      digitalWrite (RCLK, 0);

      digitalWrite (RCLK2, 0);
      digitalWrite (RCLK2, 1);
      digitalWrite (RCLK2, 0);

      digitalWrite (SER, 1);
      digitalWrite (SER2,0);

      digitalWrite (SRCLK, 0);
      digitalWrite (SRCLK, 1);
      digitalWrite (SRCLK, 0);
      digitalWrite (SRCLK2, 0);
      digitalWrite (SRCLK2, 1);
      digitalWrite (SRCLK2, 0);

      digitalWrite (RCLK, 0);
      digitalWrite (RCLK, 1);
      digitalWrite (RCLK, 0);
      digitalWrite (RCLK2, 0);
      digitalWrite (RCLK2, 1);
      digitalWrite (RCLK2, 0);
    }

    void loop()
    {
      digitalWrite(13, HIGH);
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(13, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
    }
}

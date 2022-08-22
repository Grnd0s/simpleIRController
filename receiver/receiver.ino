#include <IRremote.h>
#include <IRremoteInt.h>

#define IR_RECEIVE_PIN 11
#define LEFT 0xE41B6B68
#define RIGHT 0xE31C6B68
#define LED_PIN 4

void setup() {
  Serial.begin(9600);       
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("Init Receiver"); 
}


void loop() {
  if (IrReceiver.decode()) {
    uint32_t code = IrReceiver.decodedIRData.decodedRawData;
    //Serial.print("RECV: ");
    //Serial.println(code, HEX);
    if (code == LEFT)
    {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("left");
    }
    else if (code == RIGHT)
    {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("right");
    }
    else
    {
      digitalWrite(LED_PIN, LOW);
    }
  IrReceiver.resume();
  }
  delay(10);
}

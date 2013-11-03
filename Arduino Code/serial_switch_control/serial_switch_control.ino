#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int incomingByte = 0;   // for incoming serial data

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        
        // Transmitter is connected to Arduino Pin #10  
        mySwitch.enableTransmit(11);

        // Optional set pulse length.
        mySwitch.setPulseLength(161);
}

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                
                // read the incoming byte:
                incomingByte = Serial.read();

                /*
                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte, DEC);
                */
                
                if(incomingByte == 0x05){
                  Serial.println("Sending signal to switch 5");
                  //The following is switch 5
                  mySwitch.send("110100010101011100000000");
                }
                else if(incomingByte == 0x04){
                  Serial.println("Sending signal to switch 4");
                  //The following is switch 4
                  mySwitch.send("110100010101010011000000");
                  
                }
                else if(incomingByte == 0x03){
                  Serial.println("Sending signal to switch 3");
                  //The following is switch 3
                  mySwitch.send("110100010101010000110000");
                }
                else if(incomingByte == 0x02){
                  Serial.println("Sending signal to switch 2");
                  //The following is switch 2
                  mySwitch.send("110100010101010000001100");
                }
                else if(incomingByte == 0x01){
                  Serial.println("Sending signal to switch 1");
                  //The following is switch 1
                  mySwitch.send("110100010101010000000011");
                }
                
        
        }
}


#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  
  Serial.println();
  Serial.println("DFRobot DFPlayer Mini Demo");
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  
  myDFPlayer.volume(20);  // Set volume level
}

void loop() {
  if (Serial.available() > 0) {
    int songNumber = Serial.parseInt(); // Read the input from Serial Monitor
    
    // Check if a valid number was received
    if (songNumber > 0) {
      myDFPlayer.play(songNumber); // Play the song corresponding to the received number
      Serial.print("Playing song ");
      Serial.println(songNumber);
    } else {
      Serial.println("Invalid input. Please enter a number greater than 0.");
    }
    
    // Clear the input buffer
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}
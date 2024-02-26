#include "Arduino.h"
#include"HardwareSerial.h"
#include "DFRobotDFPlayerMini.h"

DFRobotDFPlayerMini DFPlayer;
HardwareSerial &DFmini = Serial3;
void setup() {
  DFmini.begin(9600);
  Serial.begin(115200);
  
  Serial.println();
  Serial.println("DFRobot DFPlayer Mini Demo");
  
  if (!DFPlayer.begin(DFmini)) {  
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  
  DFPlayer.volume(60);  // Set volume level
}

void loop() {
  if (Serial.available() > 0) {
    int songNumber = Serial.parseInt(); // Read the input from Serial Monitor
    
    // Check if a valid number was received
    if (songNumber > 0) {
      DFPlayer.play(songNumber); // Play the song corresponding to the received number
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
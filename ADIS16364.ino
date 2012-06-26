////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Analog Devices, Inc.
//  June 2012
//  By: Adam Gleason, and Brian Holford
////////////////////////////////////////////////////////////////////////////////////////////////////////
//  ADIS16364.ino
////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  This file is part of Interfacing ADIS16364 with Arduino example.
//
//  Interfacing ADIS16364 with Arduino example is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Interfacing ADIS16364 with Arduino example is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser Public License for more details.
//
//  You should have received a copy of the GNU Lesser Public License
//  along with Interfacing ADIS16364 with Arduino example.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////////////////////////////////////
//  NOTES:
//  This software package is an example of how to interface an ADIS16364 with Arduino Mega 2560.
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ADIS16364.h"
#include <SPI.h>

// Instantiate ADIS16364 class as iSensor with CS pin 53
ADIS16364 iSensor(53);

void setup (){
  // Start serial
  Serial.begin(115200);

  delay(100);  
}

void loop(){

  // Print out debug information
  // ****NOTE****
  // this will possibly mess up the plotting program if you do this at the same time
  // so only do it if you don't want to plot data just yet
  //iSensor.debug();
  
  // If serial has received 
  if(Serial.available() > 0){   
    // if the recieved character is 'D'
      if(Serial.read() == 'D'){
        // Perform burst read on iSensor
        iSensor.burst_read();
  
        // Formating is specific to the python script provided
        Serial.print("[ ");
        for(int i = 0; i < 11; i++){
          Serial.print(iSensor.sensor[i]);
          if(i!=10)
            Serial.print(" ");
        }
        Serial.println(" ]");
        
      }
  }
  
}

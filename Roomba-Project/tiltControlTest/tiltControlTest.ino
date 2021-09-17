/*

String message = "";

struct SensorValue {
  float x;
  float y;
  float z;
}

String getBluetoothMessage() {
    String input = "";
    if (!mySerial.available()) {
        return "";
    }
    while (mySerial.available()) {
        input += (char) mySerial.read();
        if (!mySerial.available()) delayMicroseconds(50); //  Delay for messages longer than 1 character
    }
   // Serial.println(input);
    int rear = input.lastIndexOf("#");
    if (rear < 0) {
        return "";
    }

    input = input.substring(0, rear);
    int front = input.lastIndexOf("*");
    if (front < 0) {
        return "";
    } else {
        input = input.substring(front + 1);
    }
    return input;
}

SensorValue getSensorXYZValue(String);

void setup() {
  Serial.begin(9600);
  Serial.println("Bluetooth ready");
}

void loop() {

  message = getBluetoothMessage();

  if(message != "") {
    if(message.startsWith("X")) {
    SensorValue vals = getSensorXYZValue(message);
    String output = "X:  ";
    output +=vals.x;
    output +="   Y: ";
    output +=vals.y;
    output +="   Z: ";
    output += vals.z;
    Serial.println(output);
    }
    
  }
  
 
}


SensorValue getSensorXYZValue(String sensorVal) {
   SensorValue sensorval;
    int index_x = sensorVal.indexOf("X:");
    int index_y = sensorVal.indexOf("Y:");
    int index_z = sensorVal.indexOf("Z:");
    if (index_x < 0 || index_y < 0 || index_z < 0) { // missing data
        sensorval.x = -100;
        sensorval.y = -100;
        sensorval.z = -100;
    } else {
        sensorval.x = sensorVal.substring(index_x + 2, index_y).toFloat();
        sensorval.y = sensorVal.substring(index_y + 2, index_z).toFloat();
        sensorval.z = sensorVal.substring(index_z + 2).toFloat();
    }
    //Serial.println(sensorVal);
    return sensorval;
}


*/










#include <SoftwareSerial.h>
#include "structs.h"

void setup() {
    Serial.begin(9600);

}

void loop() {

    String message = getBluetoothMessage();
    if (message != "") {
        if(message.length()>12) {
            if(message.startsWith("X")) { // gyro and acclerometer sensor values
                SensorValue vals = getSensorXYZValue(message);
                String output = "X:  ";
                output +=vals.x;
                output +="   Y: ";
                output +=vals.y;
                output +="   Z: ";
                output += vals.z;
                Serial.println(output);
            } 
        } else {
            Serial.println(message);
        }
      
    }

    delay(100);
}


////////////////////////////////////////


String getBluetoothMessage() {
    String input = "";
    if (!Serial.available()) {
        return "";
    }
    while (Serial.available()) {
        input += (char) Serial.read();
        if (!Serial.available()) delayMicroseconds(50); //  Delay for messages longer than 1 character
    }
   // Serial.println(input);
    int rear = input.lastIndexOf("#");
    if (rear < 0) {
        return "";
    }

    input = input.substring(0, rear);
    int front = input.lastIndexOf("*");
    if (front < 0) {
        return "";
    } else {
        input = input.substring(front + 1);
    }
    return input;
}



SensorValue getSensorXYZValue(String sensorVal) {
    SensorValue sensorval;
    int index_x = sensorVal.indexOf("X:");
    int index_y = sensorVal.indexOf("Y:");
    int index_z = sensorVal.indexOf("Z:");
    if (index_x < 0 || index_y < 0 || index_z < 0) { // missing data
        sensorval.x = -100;
        sensorval.y = -100;
        sensorval.z = -100;
    } else {
        sensorval.x = sensorVal.substring(index_x + 2, index_y).toFloat();
        sensorval.y = sensorVal.substring(index_y + 2, index_z).toFloat();
        sensorval.z = sensorVal.substring(index_z + 2).toFloat();
    }
    //Serial.println(sensorVal);
    return sensorval;
}

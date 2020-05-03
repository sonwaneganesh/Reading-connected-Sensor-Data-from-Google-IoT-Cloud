/******************************************************************************
 * Copyright 2018 Google
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include <CloudIoTCore.h>
#include <Wire.h>
#include "esp8266_mqtt.h"

void setup()
{
  
  
  Wire.begin();   //Use predefined PINS consts
  lcd.begin(20,4);      // The begin call takes the width and height. This
                      // Should match the number provided to the constructor.
  lcd.backlight();      // Turn on the backlight.
  lcd.home();
  
  lcd.setCursor(0, 0);
  lcd.print(" Welcome to IOT "); // Start Print text to Line 1
  Serial.println(" Welcome to IOT "); 
  lcd.setCursor(0, 1);      
  lcd.print(" Ganesh Sonwane "); // Start Print Test to Line 2
  Serial.begin(115200);
  // put your setup co for de google iot core:
  setupCloudIoT(); // Creates globals for MQTT
  pinMode(GPIO_PIN_FAN, OUTPUT);
}

unsigned long lastMillis = 0;
void loop()
{
  mqtt->loop();
  delay(10); // <- fixes some issues with WiFi stability

  if (!mqttClient->connected())
  {
    ESP.wdtDisable();
    connect();
    ESP.wdtEnable(0);
  }

  // TODO: Replace with your code here
  // if you wanted to public data to cloud
 
}

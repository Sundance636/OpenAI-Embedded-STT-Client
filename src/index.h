#include <Arduino.h>
#include "LiquidCrystal.h"
#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"
#include <iostream>
#include <string>
#include <fstream>

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
    <html>
        <head>
        <title>ESP WebServer</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        </head><body><h1>Hello</h1></body>
    </html> edited)rawliteral";

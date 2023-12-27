#include "index.h"

AsyncWebServer server(80);
LiquidCrystal lcd(D10, D9, D8, D1, D5, D6, D7);

std::ifstream htmlfile("index.html");
std::string line;

AsyncWebSocket ws("/ws");
AsyncWebServerRequest *WSrequest;

char MESSAGE[100] = {0};
size_t messlen = 0;

void onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t* data, size_t len) {
    if(type == WS_EVT_CONNECT) {
        lcd.clear();
        lcd.print("Socket Connected!");
    }
    else if (type == WS_EVT_DATA) {
        //int cursorPosy = 0;
        //int cursorflag = 0;
        strcpy(MESSAGE, (char*)data);
        messlen = len;

        lcd.clear();
        //lcd.print(((char*)data));

        /*for(size_t i = 0; i < len; i++) {
            if((cursorflag == 1) && (i%16 == 0) && i > 0) {
                
                //cursorflag = 0;
                //cursorPosy = 0;
                //delay(1000);
                lcd.clear();
            }
            if(i%16 == 0 && i > 0) {
                cursorPosy = !cursorPosy;
                cursorflag = !cursorflag;
                lcd.setCursor(0,cursorPosy);
                lcd.print(MESSAGE[i]);
                
            }
            else{
                lcd.print(MESSAGE[i]);
            }
            
            
        }*/

        //delay(2000);
        //lcd.printf("%d",(int)len);
        

        /*for(size_t i = 0 ; i < len; i++) {
            if(i%16 == 0) {
                cursorPosy = 1;
                cursorflag = 1;
                lcd.setCursor(0,cursorPosy);
                lcd.print( ((char*)(data))[i] );//maybe try without pointer cast
                cursorPosy = 0;

                }
            else {
                lcd.print( (char)(data[i]) );
            }
            if((cursorflag == 1) && (i%16 == 0)) {
                delay(1000);
                cursorflag = 0;
            }
        }*/
    }


    return;
}

int main() {
  
    setup();
    //serverSetup();
    loop();
    return 0;
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);//JUST For led blink
    Serial.begin(115200);//sets bitrate (NECESSARY)
    lcd.begin(16,2);
    lcd.print("Hello, ESP!");

    delay(1000);

    
    //lcd.println("");
    WiFi.mode(WIFI_STA);
    WiFi.begin("SSID", "PASSWORD");
    lcd.clear();
    lcd.print("Connecting");
    int counter = 0;


    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        lcd.print(".");
        counter++;

        if(counter == 3) {
            counter = 0;
            delay(500);
            lcd.clear();
            lcd.print("Connecting");
        }
    }

        lcd.println("");
        lcd.clear();
        lcd.print("Connected, IP:  ");
        lcd.setCursor(0,1);
        lcd.print( WiFi.localIP().toString() );

        ws.onEvent(onWsEvent);
        server.addHandler(&ws);
 
  /*  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });*/
  server.begin();
    //lcd.clear();
    return;
}
bool cursorPosy = 0;
        bool cursorflag = 0;
        int scrline = 0;

void loop()
{
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED_BUILTIN, HIGH);
    // wait for a second
    delay(1000);
    // turn the LED off by making the voltage LOW
    digitalWrite(LED_BUILTIN, LOW);
    // wait for a second
    delay(1000);
    //ws.cleanupClients(600);

    for(size_t i = 0; i < messlen; i++) {
            if(i == 0) {//clear screen when writing from scratch
                lcd.clear();
                cursorflag = 0;
                cursorPosy = 0;

            }
            if((cursorflag == 1) && (i%16 == 0) && i > 0) {
                
                //cursorflag = 0;
                //cursorPosy = 0;
                delay(2500);
                //lcd.clear();
            }
            if(i%16 == 0 && i > 0) {
                cursorPosy = !cursorPosy;//new line
                cursorflag = !cursorflag;
                lcd.setCursor(0,cursorPosy);
                scrline++;

                if(scrline == 2) {
                    lcd.clear();
                    scrline = 0;
                }
                lcd.print(MESSAGE[i]);
                
                
            }
            else{
                lcd.print(MESSAGE[i]);
            }

            
        }
        
}
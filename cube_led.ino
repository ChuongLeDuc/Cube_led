#include "header.h"

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer webserver(80);

char* ssid = "CUBE_LED";
char* password = "123456789";

void setup() {
  Serial.begin(115200);
  pinMode(clock_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);

  IPAddress ip(192,168,1,8);
  IPAddress gateway(192,168,1,1);
  IPAddress subnet(255,255,255,0);

  WiFi.softAPConfig(ip, gateway, subnet);
  WiFi.softAP(ssid,password);

  webserver.on("/",mainpage);
  webserver.on("/animation",action);
  webserver.begin();
}

void loop() {

 if(WiFi.softAPgetStationNum()>=1){
  webserver.handleClient();
  String k=webserver.arg("animation_name");
  int num=k.toInt();
  if(num>0){
    old_animation=num;
  }  
    Serial.print(old_animation);
    
      switch(old_animation){
       case 1:
        webserver.send(200,"text/html","Current animation:<span style='color: red'> Square left right</span>");
        square_left_right();
        Serial.println("1 ACTION");
       break;
       
       case 2:
        webserver.send(200,"text/html","Current animation:<span style='color: red'> Square up down</span>");
        square_up_down();
        Serial.println("2 ACTION");
       break;
       
       case 3:
        webserver.send(200,"text/html","Current animation:<span style='color: red'> Square front back</span>");
        square_front_back();
        Serial.println("3 ACTION");
       break;
      
       case 4:
        webserver.send(200,"text/html","Current animation:<span style='color: red'> Cycle</span>");
        cycle();
        Serial.println("4 ACTION");
       break;
      
       case 5:
        webserver.send(200,"text/html","Current animation:<span style='color: red'> Light random</span>");
        light_random();
        Serial.println("5 ACTION");
       break;
      
       case 6:
        webserver.send(200,"text/html","Current animation:<span style='color: red'>Rain</span>");
        rain();
        Serial.println("6 ACTION");
       break;
      
       case 7:
        webserver.send(200,"text/html","Current animation:<span style='color: red'>Wave</span>");
        wave();
        Serial.println("7 ACTION");
       break;
      
       case 8:
        webserver.send(200,"text/html","Current animation:<span style='color: red'>Display text</span>");
        display_text();
        Serial.println("8 ACTION");
       break;
      
       case 9:
        webserver.send(200,"text/html","Current animation:<span style='color: red'> Dynamic</span>");
        dynamic();
        Serial.println("9 ACTION");
       break;

       case 10:
        webserver.send(200,"text/html","Current animation:<span style='color: red'> Cube expanding</span>");
        cube_expand();
        Serial.println("10 ACTION");
       break;

       case 11:
        webserver.send(200,"text/html","Current animation:<span style='color: red'>Mini cube</span>");
        mini_cube();
        Serial.println("11 ACTION");
       break;
      
       case 12:
        webserver.send(200,"text/html","Current animation:<span style='color: red'>X moving</span>");
        X_moving();
        Serial.println("12 ACTION");
       break;

       case 13:
        webserver.send(200,"text/html","Current animation:<span style='color: red'> Square blink</span>");
        each_square();
        Serial.println("13 ACTION");
       break;
      }
   }else{
    non_control();
  }
  
}

void mainpage(){
  webserver.send(200,"text/html",index_page);
}

void non_control(){
   
    for(int i=1;i<=3;i++){
     square_front_back();
    }
    
    for(int i=1;i<=3;i++){
     square_up_down();
    }
    
    for(int i=1;i<=3;i++){
      square_left_right();
    }

    for(int i=1;i<=5;i++){
     light_random();
    }

    for(int i=1;i<=1;i++){
       rain();
    }
    
    for(int i=1;i<=5;i++){
     light_random();
    }

    
    for(int i=1;i<=1;i++){
      cycle();
    }
    
    for(int i=1;i<=5;i++){
     light_random();
    }
     
    for(int i=1;i<=10;i++){
     wave();
    }
    
    for(int i=1;i<=5;i++){
     light_random();
    }
    
     for(int i=1;i<=5;i++){
      display_text();
    }

    for(int i=1;i<=5;i++){
     light_random();
    }

    for(int i=1;i<=5;i++){
      dynamic();
    }

    for(int i=1;i<=5;i++){
     light_random();
    }
    
    for(int i=1;i<=10;i++){
      cube_expand();
    }

    for(int i=1;i<=5;i++){
     light_random();
    }
    
    for(int i=1;i<=6;i++){
      X_moving();
    }

    for(int i=1;i<=5;i++){
     light_random();
    }
    
     for(int i=1;i<=3;i++){
      each_square();
    }

    for(int i=1;i<=8;i++){
      mini_cube();
    }
}

void action(){
  
}

#include "functions_play_sounds.h"
short int state1 = 0;
short int state2 = 0;
unsigned int currentTime1;
boolean isOpen = true;
void setup()
{
  currentTime1=0;
  myservo.attach(2);
  myservo.write(0);
  SerialBT.begin("اسکلت سخنگو");
  Serial.begin(9600);
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(SCL_PIN, OUTPUT);
  pinMode(SDO_PIN, INPUT);
  mySoftwareSerial.begin(9600, SERIAL_8N1, 16, 17);  // speed, type, RX, TX
  pinMode(LEDLanguage, OUTPUT);
  pinMode(LEDJomjomeh, OUTPUT);
  pinMode(LEDKetf, OUTPUT);
  pinMode(LEDTarghove, OUTPUT);
  pinMode(LEDJenaghSine, OUTPUT);
  pinMode(LEDDandeh, OUTPUT);
  pinMode(LEDStoneMohreh, OUTPUT);
  pinMode(LEDBazo, OUTPUT);
  pinMode(LEDSaed, OUTPUT);
  pinMode(LEDDast, OUTPUT);
  pinMode(LEDLagan, OUTPUT);
  pinMode(LEDRan, OUTPUT);
  pinMode(LEDSagh, OUTPUT);
  pinMode(LEDPa, OUTPUT);
  LEDTurnOff(LEDJomjomeh);
  LEDTurnOff(LEDKetf);
  LEDTurnOff(LEDTarghove);
  LEDTurnOff(LEDJenaghSine);
  LEDTurnOff(LEDDandeh);
  LEDTurnOff(LEDStoneMohreh);
  LEDTurnOff(LEDBazo);
  LEDTurnOff(LEDSaed);
  LEDTurnOff(LEDDast);
  LEDTurnOff(LEDLagan);
  LEDTurnOff(LEDRan);
  LEDTurnOff(LEDSagh);
  LEDTurnOff(LEDPa);
  LEDTurnOff(LEDLanguage);


  mySwitch.enableReceive(13);
  if (!player.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(player.readType());
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true) {
      LEDTurnOn(LEDLanguage);
      delay(1000);
      LEDTurnOff(LEDLanguage);
    }
  }
  player.setTimeOut(500); //Set serial communictaion time out 500ms
  Serial.println("OK");
  player.volume(30);
  player.EQ(DFPLAYER_EQ_NORMAL);

  player.outputDevice(DFPLAYER_DEVICE_SD);
  player.disableLoop();
}
void loop() {
  touch_sens();
  state1 = state2;
  state2 = player.readState();
  if ((state1 == 1 && state2 == 0) || (state1 == -1 && state2 == 0)) {
    LEDTurnOff(LEDJomjomeh);
    LEDTurnOff(LEDKetf);
    LEDTurnOff(LEDTarghove);
    LEDTurnOff(LEDJenaghSine);
    LEDTurnOff(LEDDandeh);
    LEDTurnOff(LEDStoneMohreh);
    LEDTurnOff(LEDBazo);
    LEDTurnOff(LEDSaed);
    LEDTurnOff(LEDDast);
    LEDTurnOff(LEDLagan);
    LEDTurnOff(LEDRan);
    LEDTurnOff(LEDSagh);
    LEDTurnOff(LEDPa);
    state1 = state2 = 0;
    myservo.write(0);
  }
  if (isOpen && millis() - currentTime1 > 700 && state1 == 1 && state2 == 1) {
    myservo.write(38);  // tell servo to go to a particular angle
    isOpen=false;
    currentTime1=millis();
  }
  if (!isOpen && millis() - currentTime1 > 700 && state1 == 1 && state2 == 1) {
    myservo.write(0);  // tell servo to go to a particular angle
    isOpen=true;
    currentTime1=millis();
  }
  if (SerialBT.available()) {
    String a = SerialBT.readString();
    int b = a.toInt();
    LEDTurnOn(LEDJomjomeh);
    LEDTurnOn(LEDKetf);
    LEDTurnOn(LEDTarghove);
    LEDTurnOn(LEDJenaghSine);
    LEDTurnOn(LEDDandeh);
    LEDTurnOn(LEDStoneMohreh);
    LEDTurnOn(LEDBazo);
    LEDTurnOn(LEDSaed);
    LEDTurnOn(LEDDast);
    LEDTurnOn(LEDLagan);
    LEDTurnOn(LEDRan);
    LEDTurnOn(LEDSagh);
    LEDTurnOn(LEDPa);
    delay(1000);
    LEDTurnOff(LEDJomjomeh);
    LEDTurnOff(LEDKetf);
    LEDTurnOff(LEDTarghove);
    LEDTurnOff(LEDJenaghSine);
    LEDTurnOff(LEDDandeh);
    LEDTurnOff(LEDStoneMohreh);
    LEDTurnOff(LEDBazo);
    LEDTurnOff(LEDSaed);
    LEDTurnOff(LEDDast);
    LEDTurnOff(LEDLagan);
    LEDTurnOff(LEDRan);
    LEDTurnOff(LEDSagh);
    LEDTurnOff(LEDPa);
    play_BT(b);
    state1 = state2 = 0;
  }
  if (mySwitch.available()) {
    LEDTurnOn(LEDJomjomeh);
    LEDTurnOn(LEDKetf);
    LEDTurnOn(LEDTarghove);
    LEDTurnOn(LEDJenaghSine);
    LEDTurnOn(LEDDandeh);
    LEDTurnOn(LEDStoneMohreh);
    LEDTurnOn(LEDBazo);
    LEDTurnOn(LEDSaed);
    LEDTurnOn(LEDDast);
    LEDTurnOn(LEDLagan);
    LEDTurnOn(LEDRan);
    LEDTurnOn(LEDSagh);
    LEDTurnOn(LEDPa);
    delay(1000);
    LEDTurnOff(LEDJomjomeh);
    LEDTurnOff(LEDKetf);
    LEDTurnOff(LEDTarghove);
    LEDTurnOff(LEDJenaghSine);
    LEDTurnOff(LEDDandeh);
    LEDTurnOff(LEDStoneMohreh);
    LEDTurnOff(LEDBazo);
    LEDTurnOff(LEDSaed);
    LEDTurnOff(LEDDast);
    LEDTurnOff(LEDLagan);
    LEDTurnOff(LEDRan);
    LEDTurnOff(LEDSagh);
    LEDTurnOff(LEDPa);
    player.stop();
    unsigned long Value = mySwitch.getReceivedValue();
    Serial.println(Value);
    if (Value == 5330691) {
      player.stop();
      if (fa) {
        Serial.println("Enable EN");
        LEDTurnOn(LEDLanguage);
        fa = false;
        delay(1000);
      }
      else {
        Serial.println("Enable FA");
        LEDTurnOff(LEDLanguage);
        fa = true;
        delay(1000);
      }
    }
    else {
      player.stop();
      switch (Value)
      {
        case 5330700:
          play_RF(1);
          break;

        case 5330736:
          play_RF(2);
          break;

        case 5330892:
          play_RF(3);
          break;

        case 5330895:
          play_RF(4);
          break;

        case 5330748:
          play_RF(5);
          break;

        case 5330751:
          play_RF(6);
          break;

        case 5330928:
          play_RF(7);
          break;

        case 5330883:
          play_RF(8);
          break;

        case 5330703:
          play_RF(9);
          break;

        case 5330940:
          play_RF(10);
          break;

        case 5330931:
          play_RF(11);
          break;

        case 5330943:
          play_RF(12);
          break;

        case 5330880:
          play_RF(13);
          break;

        case 5330739:
          //player.volumeDown();
          break;

        case 5330688:
          //player.volumeUp();
          break;

        default :
          break;

      }
    }
    mySwitch.resetAvailable();
    state1 = state2 = 0;
  }

}

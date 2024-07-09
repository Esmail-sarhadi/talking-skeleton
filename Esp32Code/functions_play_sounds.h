#include <ESP32Servo.h>
#include <analogWrite.h>

#include <Arduino.h>
#include "DFRobotDFPlayerMini.h"
#include <RCSwitch.h>
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif
#define LEDJomjomeh 5
#define LEDKetf 4
#define LEDTarghove 15
#define LEDJenaghSine 23
#define LEDDandeh 19
#define LEDStoneMohreh 18
#define LEDBazo 12
#define LEDSaed 14
#define LEDDast 27
#define LEDLagan 33
#define LEDRan 25
#define LEDSagh 26
#define LEDPa 32
#define LEDLanguage 35
#define SCL_PIN 22
#define SDO_PIN 21

BluetoothSerial SerialBT;
RCSwitch mySwitch = RCSwitch();
bool fa = true;
byte key;
byte keyIsTrue;
bool doIt = false;
unsigned int currentTime;

HardwareSerial mySoftwareSerial(1);
DFRobotDFPlayerMini player;
Servo myservo;
void LEDTurnOff(int in) {
  digitalWrite(in, LOW);
}
void LEDTurnOn(int in) {
  digitalWrite(in, HIGH);
}
void play_BT(int input) {
  player.stop();
  switch (input) {

    case 1:
      player.playMp3Folder(1);  //0001-jomjome-fa.mp3
      LEDTurnOn(LEDJomjomeh);
      break;

    case 2:
      player.playMp3Folder(2);  //0002-jomjome-en.mp3
      LEDTurnOn(LEDJomjomeh);
      break;

    case 3:
      player.playMp3Folder(3);  //0003-targhove-fa.mp3
      LEDTurnOn(LEDTarghove);
      break;

    case 4:
      player.playMp3Folder(4);  //0004-targhove-en.mp3
      LEDTurnOn(LEDTarghove);
      break;

    case 5:
      player.playMp3Folder(5);  //0005-ketf-fa.mp3
      LEDTurnOn(LEDKetf);
      break;

    case 6:
      player.playMp3Folder(6);  //0006-ketf-en.mp3
      LEDTurnOn(LEDKetf);
      break;

    case 7:
      player.playMp3Folder(7);  //0007-jenagh sine-fa.mp3
      LEDTurnOn(LEDJenaghSine);
      break;

    case 8:
      player.playMp3Folder(8);  //0008-jenagh sine-en.mp3
      LEDTurnOn(LEDJenaghSine);
      break;

    case 9:
      player.playMp3Folder(9);  //0009-dandeha-fa.mp3
      LEDTurnOn(LEDDandeh);
      break;

    case 10:
      player.playMp3Folder(10);  //0010-dande ha-en.mp3
      LEDTurnOn(LEDDandeh);
      break;

    case 11:
      player.playMp3Folder(11);  //0011-sotun mohre-fa.mp3
      LEDTurnOn(LEDStoneMohreh);
      break;

    case 12:
      player.playMp3Folder(12);  //0012-sotun mohre-en.mp3
      LEDTurnOn(LEDStoneMohreh);
      break;

    case 13:
      player.playMp3Folder(13);  //0013-bazoo-fa.mp3
      LEDTurnOn(LEDBazo);
      break;

    case 14:
      player.playMp3Folder(14);  //0014-bazoo-en.mp3
      LEDTurnOn(LEDBazo);
      break;

    case 15:
      player.playMp3Folder(15);  //0015-saed-fa.mp3
      LEDTurnOn(LEDSaed);
      break;

    case 16:
      player.playMp3Folder(16);  //0016-saed-en.mp3
      LEDTurnOn(LEDSaed);
      break;

    case 17:
      player.playMp3Folder(17);  //0017-moch & angoshtan dast-fa.mp3
      LEDTurnOn(LEDDast);
      break;

    case 18:
      player.playMp3Folder(18);  //0018-moch & angoshtan dast-en.mp3
      LEDTurnOn(LEDDast);
      break;

    case 19:
      player.playMp3Folder(19);  //0019-lagan-fa.mp3
      LEDTurnOn(LEDLagan);
      break;

    case 20:
      player.playMp3Folder(20);  //0020-lagan-en.mp3
      LEDTurnOn(LEDLagan);
      break;

    case 21:
      player.playMp3Folder(21);  //0021-ran-fa.mp3
      LEDTurnOn(LEDRan);
      break;

    case 22:
      player.playMp3Folder(22);  //0022-ran-en.mp3
      LEDTurnOn(LEDRan);
      break;

    case 23:
      player.playMp3Folder(23);  //0023-sagh-fa.mp3
      LEDTurnOn(LEDSagh);
      break;

    case 24:
      player.playMp3Folder(24);  //0024-sagh-en.mp3
      LEDTurnOn(LEDSagh);
      break;

    case 25:
      player.playMp3Folder(25);  //0025-moch & angoshtan pa-fa.mp3
      LEDTurnOn(LEDPa);
      break;

    case 26:
      player.playMp3Folder(26);  //0026-moch & angoshtan pa-en.mp3
      LEDTurnOn(LEDPa);
      break;

    default:
      break;
  }
  delay(1000);
}

void play_RF(int v) {
  player.stop();
  switch (v) {

    case 1:
      if (fa) {
        player.playMp3Folder(1);  //0001-jomjome-fa.mp3
      } else {
        player.playMp3Folder(2);  //0002-jomjome-en.mp3
      }
      LEDTurnOn(LEDJomjomeh);
      break;

    case 2:
      if (fa) {
        player.playMp3Folder(5);  //0005-ketf-fa.mp3
      } else {
        player.playMp3Folder(6);  //0006-ketf-en.mp3
      }
      LEDTurnOn(LEDKetf);
      break;

    case 3:
      if (fa) {
        player.playMp3Folder(3);  //0003-targhove-fa.mp3
      } else {
        player.playMp3Folder(4);  //0004-targhove-en.mp3
      }
      LEDTurnOn(LEDTarghove);
      break;

    case 4:
      if (fa) {
        player.playMp3Folder(7);  //0007-jenagh sine-fa.mp3
      } else {
        player.playMp3Folder(8);  //0008-jenagh sine-en.mp3
      }
      LEDTurnOn(LEDJenaghSine);
      break;

    case 5:
      if (fa) {
        player.playMp3Folder(9);  //0009-dandeha-fa.mp3
      } else {
        player.playMp3Folder(10);  //0010-dande ha-en.mp3
      }
      LEDTurnOn(LEDDandeh);
      break;

    case 6:
      if (fa) {
        player.playMp3Folder(11);  //0011-sotun mohre-fa.mp3
      } else {
        player.playMp3Folder(12);  //0012-sotun mohre-en.mp3
      }
      LEDTurnOn(LEDStoneMohreh);
      break;

    case 7:
      if (fa) {
        player.playMp3Folder(13);  //0013-bazoo-fa.mp3
      } else {
        player.playMp3Folder(14);  //0014-bazoo-en.mp3
      }
      LEDTurnOn(LEDBazo);
      break;

    case 8:
      if (fa) {
        player.playMp3Folder(15);  //0015-saed-fa.mp3
      } else {
        player.playMp3Folder(16);  //0016-saed-en.mp3
      }
      LEDTurnOn(LEDSaed);
      break;

    case 9:
      if (fa) {
        player.playMp3Folder(17);  //0017-moch & angoshtan dast-fa.mp3
      } else {
        player.playMp3Folder(18);  //0018-moch & angoshtan dast-en.mp3
      }
      LEDTurnOn(LEDDast);
      break;

    case 10:
      if (fa) {
        player.playMp3Folder(19);  //0019-lagan-fa.mp3
      } else {
        player.playMp3Folder(20);  //0020-lagan-en.mp3
      }
      LEDTurnOn(LEDLagan);
      break;

    case 11:
      if (fa) {
        player.playMp3Folder(21);  //0021-ran-fa.mp3
      } else {
        player.playMp3Folder(22);  //0022-ran-en.mp3
      }
      LEDTurnOn(LEDRan);
      break;

    case 12:
      if (fa) {
        player.playMp3Folder(23);  //0023-sagh-fa.mp3
      } else {
        player.playMp3Folder(24);  //0024-sagh-en.mp3
      }
      LEDTurnOn(LEDSagh);
      break;

    case 13:
      if (fa) {
        player.playMp3Folder(25);  //0025-moch & angoshtan pa-fa.mp3
      } else {
        player.playMp3Folder(26);  //0026-moch & angoshtan pa-en.mp3
      }
      LEDTurnOn(LEDPa);
      break;

    case 14:
      if (fa) {
        //player.playMp3Folder("14f.wav");
      } else {
        //player.playMp3Folder("14e.wav");
      }
      break;

    case 15:
      if (fa) {
        //player.playMp3Folder("15f.wav");
      } else {
        //player.playMp3Folder("15e.wav");
      }
      break;

    default:
      break;
  }
  delay(1000);
}
byte Read_Keypad(void) {
  byte Count;
  byte Key_State = 0;

  /* Pulse the clock pin 16 times (one for each key of the keypad)
     and read the state of the data pin on each pulse */
  for (Count = 1; Count <= 16; Count++) {
    digitalWrite(SCL_PIN, LOW);

    /* If the data pin is low (active low mode) then store the
       current key number */
    if (!digitalRead(SDO_PIN))
      Key_State = Count;

    digitalWrite(SCL_PIN, HIGH);
  }

  return Key_State;
}
void touch_sens() {
  key = Read_Keypad();
  if (key != 16) {
    if (key > 0) {
      currentTime = millis();
      doIt = true;
      while (millis() - currentTime < 1000) {
        Serial.println("x");
        keyIsTrue = Read_Keypad();
        Serial.println(keyIsTrue);
        if (key != keyIsTrue) {
          Serial.println("...");
          doIt = false;
          break;
        }
      }
      if (doIt) {
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
        Serial.println(key);
        switch (key) {
          case 1:
            doIt = false;
            player.stop();
            if (fa) {
              Serial.println("Enable EN");
              LEDTurnOn(LEDLanguage);
              fa = false;
              delay(1000);
            } else {
              Serial.println("Enable FA");
              LEDTurnOff(LEDLanguage);
              fa = true;
              delay(1000);
            }
            break;

          case 2:
            doIt = false;
            play_RF(1);
            break;
          case 3:
            doIt = false;
            play_RF(2);
            break;
          case 4:
            doIt = false;
            play_RF(3);
            break;
          case 5:
            doIt = false;
            play_RF(4);
            break;
          case 6:
            doIt = false;
            play_RF(5);
            break;
          case 7:
            doIt = false;
            play_RF(6);
            break;
          case 8:
            doIt = false;
            play_RF(7);
            break;
          case 9:
            doIt = false;
            play_RF(8);
            break;
          case 10:
            doIt = false;
            play_RF(9);
            break;
          case 11:
            doIt = false;
            play_RF(10);
            break;
          case 12:
            doIt = false;
            play_RF(11);
            break;
          case 13:
            doIt = false;
            play_RF(12);
            break;
          case 14:
            doIt = false;
            play_RF(13);
            break;
        }
      }
    }
  }
}

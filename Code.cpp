#define USE_NIMBLE
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

#define UP 16
#define LEFT 17
#define DOWN 18
#define RIGHT 19
#define BUTTON_A 21
#define BUTTON_B 22

bool keyStates[6] = {false, false, false, false, false, false};
int keyPins[6] = {UP, LEFT, DOWN, RIGHT, BUTTON_A, BUTTON_B};
uint8_t keyCodes[6] = {'w', 'a', 's', 'd', 'z', 'x'};


void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando...");
  setInputs();
  bleKeyboard.begin();
}

bool connectNotificationSent = false;

void loop() {
  int counter;
  if(bleKeyboard.isConnected()) {
    if (!connectNotificationSent) {
      Serial.println("Conectado!");
      connectNotificationSent = true;
    }
    for(counter = 0; counter < 6; counter ++){
      handleButton(counter);
    }
  }
}

void setInputs() {
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
}

void handleButton(int keyIndex){
  // handle the button press
  if (!digitalRead(keyPins[keyIndex])){
    // button pressed
    if (!keyStates[keyIndex]){
      // key not currently pressed
      keyStates[keyIndex] = true;
      bleKeyboard.press(keyCodes[keyIndex]);
    }
  }
  else {
    // button not pressed
    if (keyStates[keyIndex]){
      // key currently pressed
      keyStates[keyIndex] = false;
      bleKeyboard.release(keyCodes[keyIndex]);
    }
  }
}

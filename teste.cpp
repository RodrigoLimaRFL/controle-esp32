#define USE_NIMBLE
//#include <BleKeyboard.h>

//BleKeyboard bleKeyboard;

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
  //setInputs();
  //bleKeyboard.begin();
  pinMode(2, OUTPUT);

}

bool connectNotificationSent = false;

void loop() {
  int counter;
        Serial.print("Botao1 = ");
        counter++;
        delay(500);

}

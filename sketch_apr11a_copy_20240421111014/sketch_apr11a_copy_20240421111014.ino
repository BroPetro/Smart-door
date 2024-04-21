 char Pass = 'A';
String ID_card = "ID PASS";
char Password = 0;

#include <VarSpeedServo.h>

VarSpeedServo myServo14;

#include <Keypad.h>
byte Pins_Rows[]={9,8,7,6};
byte Pins_Columns[]={5,4,3,2};
char keys[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};
Keypad Keyboard= Keypad(makeKeymap(keys),Pins_Rows,Pins_Columns,4,4);

#include <SPI.h>
#include <MFRC522.h>
MFRC522 mfrc522(10,9);
 byte cardx[4]= {0x3F,0x01,0x23,0x44};
 String cardreaded(byte *buffer,byte bufferSize)
 {
 String card="";
 for (byte i=0; i<bufferSize; i++)
 {
 card+=String(buffer[i]<0x10 ? " 0" : " ");
 card+=String(buffer[i],HEX);
 }
 return card;
  }


void my_1() {
  if (Pass == 'D') {
    Serial.println("Reset");
     void(* resetFunc) (void) = 0;
       resetFunc();
  }
}

void my_2() {
  if (ID_card == " 2c d8 e5 59") {
    Serial.println("IP CARD .OPEN DORS ");
    delay(1000);
    ID_card = "ID PASS";
    myServo14.attach(14);
     myServo14.slowmove(90,255);
    delay(5000);
    myServo14.attach(14);
     myServo14.slowmove(180,255);
     void(* resetFunc) (void) = 0;
       resetFunc();
  }
}

void my_3() {
  if (Pass == 'B') {
    Password = Password + 2;
    Serial.println("Ok");
  }
  if (Pass == '1') {
    Password = Password + 2;
    Serial.println("Ok");
  }
  if (Pass == '5') {
    Password = Password + 1;
    Serial.println("Ok");
  }
  if (Password == 5) {
    Serial.println("Open door");
    myServo14.attach(14);
     myServo14.slowmove(90,255);
    delay(5000);
    myServo14.attach(14);
     myServo14.slowmove(180,255);
     void(* resetFunc) (void) = 0;
       resetFunc();
  }
}

void my_4() {
  if (Password == 5) {
    pinMode(16, OUTPUT);
     digitalWrite(16, 0);
    pinMode(15, OUTPUT);
     digitalWrite(15, 1);
    delay(5000);
    pinMode(15, OUTPUT);
     digitalWrite(15, 0);
  }
  if (Password != 5) {
    pinMode(16, OUTPUT);
     digitalWrite(16, 1);
  }
}

void my_5() {
  if (digitalRead(17)) {
    myServo14.attach(14);
     myServo14.slowmove(90,255);
    delay(5000);
    myServo14.attach(14);
     myServo14.slowmove(180,255);
  }
}


void setup() {
  myServo14.attach(14);

  Serial.begin(9600);
  SPI.begin();

  mfrc522.PCD_Init();


  pinMode(17, INPUT);
}

void loop() {
    Pass = Keyboard.getKey();
     if (mfrc522.PICC_ReadCardSerial() == 1 | mfrc522.PICC_IsNewCardPresent() == 1) {
      ID_card = cardreaded(mfrc522.uid.uidByte, mfrc522.uid.size);
      }
       Serial.println(ID_card);
    if (Pass > 0) {
      Serial.println(Pass);
    }
    my_3();
    my_2();
    my_3();
    my_4();
    my_5();

} 
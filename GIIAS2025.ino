#include <PS2X_lib.h>
#define PS2_DAT 12  // Pin data stik PS2
#define PS2_CMD 11  // Pin perintah stik PS2
#define PS2_ATT 10  // Pin seleksi stik PS2
#define PS2_CLK 13  // Pin clock stik PS2
int error = 0;
int in1 = 4;  // Input 1 motor 1
int in2 = 5;
int in3 = 8;
int in4 = 7;  // Input 2 motor 1
int ENA = 3;
int ENB = 6;

PS2X ps2x;

void setup() {  //
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT); 
  pinMode(ENA, OUTPUT); 
  pinMode(ENB, OUTPUT);

  // Inisialisasi stik PS2
  ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_ATT, PS2_DAT, false, false);

  if (error == 1) {
    Serial.println("Stik PS2 ditemukan.");
  } else {
    Serial.println("Tidak dapat menemukan stik PS2. Periksa koneksi.");
    Serial.println(error);
  }
}

void loop() {
  ps2x.read_gamepad();
  // Inisialisasi tombol pada controller PS2 menggunakan pustaka PS2X
  int btnCross = ps2x.Button(PSB_CROSS);         // MUNDUR KANAN
  int btnCircle = ps2x.Button(PSB_CIRCLE);       // MAJU KANAN
  int btnTriangle = ps2x.Button(PSB_TRIANGLE);   // MUNDUR KIRI
  int btnSquare = ps2x.Button(PSB_SQUARE);       // MAJU KIRI
  int btnPadUp = ps2x.Button(PSB_PAD_UP);        // MAJU
  int btnPadDown = ps2x.Button(PSB_PAD_DOWN);    // MUNDUR
  int btnPadRight = ps2x.Button(PSB_PAD_RIGHT);  // KANAN
  int btnPadLeft = ps2x.Button(PSB_PAD_LEFT);    // KIRI

  // Tombol L1, L2, R1, R2
  int btnL1 = ps2x.Button(PSB_L1);  // TOMBOL L1
  int btnL2 = ps2x.Button(PSB_L2);  // TOMBOL L2
  int btnR1 = ps2x.Button(PSB_R1);  // TOMBOL R1
  int btnR2 = ps2x.Button(PSB_R2);  // TOMBOL R2

  // Tombol Start dan Select
  int btnStart = ps2x.Button(PSB_START);    // START
  int btnSelect = ps2x.Button(PSB_SELECT);  // SELECT


  if (ps2x.Button(PSB_PAD_UP)) {  // MAJU
  Serial.println("maju");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(ENA, 90);
    analogWrite(ENB, 110);
    

  } else if (ps2x.Button(PSB_PAD_DOWN)) {  // MUNDUR
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENA, 90);
    analogWrite(ENB, 110);
    Serial.println("Mundur");

  }  else if (ps2x.Button(PSB_PAD_RIGHT)) {  // BELOK KANAN
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(ENA, 90);
    Serial.println("KANAN");

  } else if (ps2x.Button(PSB_PAD_LEFT)) {  // BELOK KIRI
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, 110);
    Serial.println("KIRI");

  } else if (ps2x.Button(PSB_R1)) { // MAJU KANAN
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(ENA, 90);
    analogWrite(ENB, 110);

  }else if (ps2x.Button(PSB_TRIANGLE)) {  // MUNDUR KIRI
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

  }  else if (ps2x.Button(PSB_SQUARE)) { // MAJU KIRI
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

  } else if (ps2x.Button(PSB_CIRCLE)) { // MAJU KANAN
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

  } else if (ps2x.Button(PSB_R2)) {  // MUNDUR KANAN
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

  } else if (ps2x.Button(PSB_L1)) { //kanan putar

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

  } else if (ps2x.Button(PSB_L2)) {  // MUNDUR
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

  }
  else  //berhenti
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

  }
  delay(5);
}
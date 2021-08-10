#define LATCH 4
#define CLK 3
#define DATA 2
int coinPin = 2;


const byte digitOne[10] =
{
  B00111111,  // 0
  B00000110,  // 1
  B01011011,  // 2
  B01001111,  // 3
  B01100110,  // 4
  B01101101,  // 5
  B01111101,  // 6
  B00000111,  // 7
  B01111111,  // 8
  B01101111,  // 9
};

const byte digitTwo[10] =
{
  B00111111,  // 0
  B00000110,  // 1
  B01011011,  // 2
  B01001111,  // 3
  B01100110,  // 4
  B01101101,  // 5
  B01111101,  // 6
  B00000111,  // 7
  B01111111,  // 8
  B01101111,  // 9
};

int i;

void setup(){

  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

void loop(){
for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLK, MSBFIRST, ~digitTwo[i]); // digitTwo
      shiftOut(DATA, CLK, MSBFIRST, ~digitOne[j]); // digitOne
      digitalWrite(LATCH, HIGH);
      delay(500);
    }
  }
}    

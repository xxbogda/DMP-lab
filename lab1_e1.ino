```// Read status of buttons and display it on LEDs connected to
//PORTA
// Variables for reading the status of the buttons connected
//to the
// digital pins 4, 5, 6, 7
int b1;
int b2;
int b3;
int b4;
// variable for the LED status
unsigned char stat = 0;
void setup() {
// configure digital pins as inputs
pinMode(4, INPUT_PULLUP);
pinMode(5, INPUT_PULLUP);
pinMode(6, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
// activate PORTA, as output,
DDRA = 0b11111111;
stat=0b000100;
}
void loop() {
// read BTNs status
//b1 = digitalRead(4);
//b2 = digitalRead(5);
b3 = digitalRead(6);
b4 = digitalRead(7);
// combine result: each LED is controlled by a button.
//Some buttons are //duplicated
//stat = (b4<<5) | (b3<<4) | (b4<<3) | (b3<<2) | (b2<<1) | b1;
// Display status on the LEDs connected to port A

if(b3==0){//left
  if((stat>>5)&1==1){
    stat=0b000001;
  }
  stat=stat<<1;
}
if(b4==0){//right
  if(stat&1==1){
    stat=0b100000;
  }
  stat=stat>>1;
}
PORTA = stat;
// delay 50 ms
delay(300);
}```
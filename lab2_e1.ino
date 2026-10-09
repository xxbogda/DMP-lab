int latchPin = 4;
int clockPin =7;
int dataPin = 8; // SSD pins

const unsigned char ssdlut[] = {0b00111111, 0b00000110,
0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101,
0b00000111, 0b01111111, 0b01101111};
const unsigned char anodelut[] = {0b00000001, 0b00000010,
0b00000100, 0b00001000};
unsigned char digits[] = {1,0,0,0}; // The number to be
//displayed is 1234. You can change it.

int no = 1000;
int T=0;

void setup ()
{

 pinMode(latchPin,OUTPUT);
 pinMode(clockPin,OUTPUT);
 pinMode(dataPin,OUTPUT); // The three pins connected to
 // the shift register must be output pins
}
void loop()
{
  T++;
  if(T % 10 == 0){
    T=0;
    
    if(no==9999) no=0;
    else no++;
    
    digits[0]= (unsigned char) (no / 1000);
    digits[1]= (unsigned char) (no / 100 % 10);
    digits[2]= (unsigned char) (no / 10 % 10);
    digits[3]= (unsigned char) (no % 10);
  }  


  for(char i=0; i<=3; i++) // For each of the 4 digits
  {
    unsigned char digit = digits[i]; // the current digit
    unsigned char cathodes = ~ssdlut[digit]; // The
    //cathodes of the current digit, we’ll
    //negate the value from the original LUT

    digitalWrite(latchPin,LOW); // Activate the latch to
    //allow writing
    shiftOut(dataPin,clockPin,MSBFIRST, cathodes); //
    //shift out the cathode byte
    shiftOut(dataPin,clockPin,MSBFIRST, anodelut [i] );
    // shift out the anode byte
    digitalWrite(latchPin,HIGH); // De-activate the latch
    //signal
    delay(2); // Short wait
  }


}

#define PD5 0x20

DDRD &= ~(PD5);

PORTD ^= PD5;


if((PIN & PD5) == 0){
    // code
}

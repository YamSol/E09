#define PD6 0x40
#define PD7 0x80

DDRD |= (PD6) | (PD7);

PORTD &= ~(PD6);

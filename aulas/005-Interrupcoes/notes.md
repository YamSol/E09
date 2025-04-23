# Interrupcões

Recurso do microcontrolador que interrompe a execução do programa principal, executar outra parte de código, e retornar ao programa principal.

## Exemplo LED

```c

_delay_ms(50000);

if (!(PIND & 1<<PD2)) {
	PORTC |= (1<<PC6);
}
```
*: Se o botão for pressionado durante a execução do delay, ele não é identificado pelo IF.

Interrupção detecta o botão, independente do código estar no meio da execução de um delay.

## Para onde vai a interrupção
Quando o código é interrompido, ele é desviado para a Rotina de Serviço de Interrupção (ISR).

## Exemplo
```c

int main(void) {
   /*  ... */
   sei();
   
   for(;;){
   
   }
}

ISR(INT0_vect) {
	/* code */
}
```

## Tipos de Interrupçao

Vector name | 

INT0_vect
INT0_vect



## Registradores para Interrupções

### EICRA - External Input Control Register A
ISC11  | ISC10  | Description
0      |   0    | O nivel baixo de INT1 gera uma requisição de interrupção
0      |   1    | Qualquer mudança de INT1 gera uma requisição de interrupção
1      |   0    | ...
1      |   1    | ...

ISC01  | ISC00  | Description
0      |   0    | O nivel baixo de INT0 gera uma requisição de interrupção
0      |   1    | Qualquer mudança de INT1 gera uma requisição de interrupção
1      |   0    | ...
1      |   1    | ...

```
EICRA |= (1<<ISC11);
```

### EIMSK - External Input Mask Register

```
EIMSK |= (1<<INT1) + (1<<INT0);
```

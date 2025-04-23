# GPIO

GPIOs são pinos de uso geral.

Pinos são agrupados em portais.

Para a configuracao entrada/saida dos pinos, utilizamos registradores para cada portal: PB, PC, PD (cada um com 8 pinos).



## Registradores
Unidade de armazenamento para dados temporários (ou instruções)

Usado para operações rápidas.

Sua capacidade pode variar (ATMega328 possui registradores de 8 bits)

### ?
#### DDRx (Data Direction Register)
Configuração  do portal **x**(x = B, C, D) que indica ao microcontrolador se o pino equivalente (0 - 7) será utilizado para escrita (*write*, W) ou leitura (*read*, R).

```
DDRB = 0b00000000;
```

#### PORTx 
Registrador para escrita de nível lógico (1/0) nos pinos do portal **x**

É utilizado tanto para escrita de valores no registrador, quanto para ativar o Pull-Up interno (Que evita estados Hi-z, ao conectar um botão na entrada, quando o pino estiver configurado para leitura). 

```
PORTB = 0b00000100;
```

#### PINx
Registrador de entrada, usado para ler o conteúdo dos pino do portal **x**

```
unsigned int = (PINB & 0b00000100)
```


### 
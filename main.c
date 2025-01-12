#include <stdio.h> // Biblioteca padrão de entrada e saída, usada para funções como printf.
#include "pico/stdlib.h" // Biblioteca padrão do SDK da Raspberry Pi Pico, fornece funções de controle de GPIO e temporização.

#define led_pin_red 13 // Define o pino 13 como o pino onde o LED vermelho está conectado.

int s, o; // Declara as variáveis globais `s` e `o`, usadas como contadores nas funções.

void sinal_S() {
    // Gera o sinal "S" em código Morse (...).
    for (s = 0; s <= 2; s++) { // Itera 3 vezes para os 3 sinais curtos do "S".
        if (s <= 1) {
            gpio_put(led_pin_red, true); // Liga o LED.
            printf("."); // Imprime um ponto na saída padrão.
            sleep_ms(200); // Aguarda 200 ms.
            gpio_put(led_pin_red, false); // Desliga o LED.
            sleep_ms(125); // Aguarda 125 ms (intervalo entre os sinais).
        } else {
            gpio_put(led_pin_red, true); // Liga o LED.
            printf(". "); // Imprime um ponto seguido de espaço na saída padrão.
            sleep_ms(200); // Aguarda 200 ms.
            gpio_put(led_pin_red, false); // Desliga o LED.
        }
    }
}

void sinal_O() {
    // Gera o sinal "O" em código Morse (---).
    for (o = 0; o <= 2; o++) { // Itera 3 vezes para os 3 sinais longos do "O".
        if (o <= 1) {
            gpio_put(led_pin_red, true); // Liga o LED.
            printf("-"); // Imprime um traço na saída padrão.
            sleep_ms(800); // Aguarda 800 ms.
            gpio_put(led_pin_red, false); // Desliga o LED.
            sleep_ms(125); // Aguarda 125 ms (intervalo entre os sinais).
        } else {
            gpio_put(led_pin_red, true); // Liga o LED.
            printf("- "); // Imprime um traço seguido de espaço na saída padrão.
            sleep_ms(800); // Aguarda 800 ms.
            gpio_put(led_pin_red, false); // Desliga o LED.
        }
    }
}

int main() {
    stdio_init_all(); // Inicializa a biblioteca de entrada e saída padrão, necessária para `printf`.

    gpio_init(led_pin_red); // Inicializa o pino 13 para uso.
    gpio_set_dir(led_pin_red, GPIO_OUT); // Configura o pino 13 como saída.

    printf("|Sinal de SOS|\n\nS = ...\nO = ---\n\n"); // Exibe uma legenda na saída padrão.

    while (true) {
        // Loop infinito que gera o sinal SOS repetidamente.
        sinal_S(); // Gera o sinal "S".
        sleep_ms(250); // Aguarda 250 ms antes de iniciar o próximo sinal.
        sinal_O(); // Gera o sinal "O".
        sleep_ms(250); // Aguarda 250 ms antes de iniciar o próximo sinal.
        sinal_S(); // Gera o sinal "S" novamente.
        sleep_ms(3000); // Aguarda 3 segundos antes de reiniciar o ciclo.
        printf("   "); // Adiciona um espaço visual na saída padrão.
    }

    return 0; // Retorna 0 indicando que o programa terminou corretamente (embora nunca seja alcançado devido ao loop infinito).
}

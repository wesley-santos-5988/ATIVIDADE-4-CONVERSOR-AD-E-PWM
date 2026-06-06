#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

// Definição dos pinos - Placa BitDogLAB
#define PINO_JOYSTICK_Y 26
#define CANAL_ADC_Y      0
#define PINO_SERVOMOTOR 18

// Configura o PWM para o servomotor (frequência de 50Hz)
void configurar_pwm_servo(uint pino) {
    gpio_set_function(pino, GPIO_FUNC_PWM); 
    uint slice = pwm_gpio_to_slice_num(pino);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 125.0f); // Divisor de clock para 1us
    pwm_config_set_wrap(&config, 19999);    // Período de 20ms
    
    pwm_init(slice, &config, true);
}

int main() {
    // Inicialização dos periféricos
    configurar_pwm_servo(PINO_SERVOMOTOR);

    adc_init();
    adc_gpio_init(PINO_JOYSTICK_Y);
    adc_select_input(CANAL_ADC_Y); 

    while (true) {
        // Leitura do eixo Y do joystick (0 a 4095)
        uint16_t valor_y = adc_read();

        // Conversão do valor do ADC para o pulso do PWM (544us a 2400us)
        // Regra de três invertida para alinhar o movimento físico
        uint32_t pulso_motor = 2400 - ((uint32_t)valor_y * 1856 / 4095);

        // Atualiza a posição do motor
        pwm_set_gpio_level(PINO_SERVOMOTOR, pulso_motor);

        sleep_ms(10); // Delay para estabilidade
    }
}
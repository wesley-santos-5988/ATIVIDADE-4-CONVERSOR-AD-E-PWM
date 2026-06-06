# Controle de Servomotor com Joystick Analógico (Raspberry Pi Pico)

Este projeto foi desenvolvido como parte de uma atividade acadêmica utilizando o ecossistema do **Raspberry Pi Pico (RP2040)**. O objetivo principal é controlar a posição angular de um servomotor de forma proporcional e precisa através dos movimentos do eixo vertical (Y) de um joystick analógico.

O projeto foi validado utilizando o simulador **Wokwi** integrado com as especificações da placa pedagógica **BitDogLAB**.

## 🚀 Como Funciona?

1. **Leitura Analógica (ADC):** O eixo Y do joystick está conectado ao pino **GP26** (Canal 0 do ADC). O movimento gera uma variação de tensão que o microcontrolador lê como valores digitais entre `0` (totalmente para cima) e `4095` (totalmente para baixo).
2. **Controle por PWM:** O servomotor é controlado por um sinal PWM no pino **GP18**. A frequência foi configurada para **50Hz** (período de 20ms), ideal para dispositivos de modelismo.
3. **Mapeamento Dinâmico:** Para garantir o curso completo do motor (0° a 180°), o código converte digitalmente os valores do ADC para uma largura de pulso específica entre **544µs** e **2400µs** através de uma regra de três calibrada, evitando travamentos no simulador.

## 🛠️ Componentes e Conexões

* **Placa Principal:** Raspberry Pi Pico W (ou BitDogLAB)
* **Joystick Analógico:** Pino `GP26` (Eixo VERT / Y)
* **Servomotor Padrão:** Pino `GP18` (Sinal de PWM)

## 📌 Links do Projeto

* Pasta Drive com Relatório do Projeto e Vídeo Demonstrativo: https://drive.google.com/drive/folders/1O5H_7WHxuJVeUMnwirh0YnkCOIx5PfZ-?usp=sharing

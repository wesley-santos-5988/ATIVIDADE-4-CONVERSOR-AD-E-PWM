# Controle de Servomotor com Joystick Analógico (Raspberry Pi Pico)

Este projeto foi desenvolvido como parte de uma atividade acadêmica utilizando o ecossistema do **Raspberry Pi Pico (RP2040)**. O objetivo principal é controlar a posição angular de um servomotor de forma proporcional e precisa através dos movimentos do eixo vertical (Y) de um joystick analógico.

O projeto foi validado utilizando o simulador **Wokwi** integrado com as especificações da placa pedagógica **BitDogLAB**.

## Como Funciona

1. **Leitura Analógica (ADC):** O eixo Y do joystick está conectado ao pino GP26 (Canal 0 do ADC). O movimento gera uma variação de tensão que o microcontrolador lê como valores digitais entre 0 (totalmente para cima) e 4095 (totalmente para baixo).
2. **Controle por PWM:** O servomotor é controlado por um sinal PWM gerado no pino GP18. A frequência foi configurada matematicamente para 50Hz (período de 20ms), que é o padrão de operação exigido pela maioria dos servomotores.
3. **Mapeamento Dinâmico:** Para garantir o curso completo do motor (0 a 180 graus), o código converte a escala digital do ADC para uma largura de pulso específica entre 544 us e 2400 us através de uma equação linear invertida. Isso garante um movimento fluido e evita travamentos no simulador.

## Componentes e Conexões

* **Placa Principal:** Raspberry Pi Pico W (BitDogLAB)
* **Joystick Analógico:** Pino GP26 (Eixo VERT / Y)
* **Servomotor Padrão:** Pino GP18 (Sinal de PWM)

## Instruções de Uso

Para compilar e executar a simulação deste projeto em sua máquina local, siga os passos abaixo:

1. **Pré-requisitos:** Certifique-se de ter o Visual Studio Code (VS Code) instalado, juntamente com a extensão oficial do **Raspberry Pi Pico** e a extensão do simulador **Wokwi**.
2. **Preparação:** Clone este repositório (ou baixe os arquivos fonte) e abra a pasta do projeto no VS Code.
3. **Configuração do CMake:** Pressione `F1`, digite `CMake: Configure` e selecione o compilador adequado para o Pico SDK.
4. **Compilação:** Na barra inferior do VS Code, clique em "Compile" para compilar o código em C e gerar o arquivo binário executável do projeto.
5. **Simulação:** Abra o arquivo `diagram.json` e inicie a simulação. Clique na haste do joystick e arraste-a para cima e para baixo para observar o servomotor acompanhando o movimento em tempo real.

## Links do Projeto

* Pasta Drive com Relatório do Projeto e Vídeo Demonstrativo: https://drive.google.com/drive/folders/1O5H_7WHxuJVeUMnwirh0YnkCOIx5PfZ-?usp=sharing

# robo-balao
Proposta de plataforma inicial do seu projeto de um robô móvel controlado por comunicação bluetooth
# 🤖 Robô Móvel com ESP32 Controlado via Bluetooth

Este projeto apresenta o desenvolvimento de um robô móvel de duas rodas, baseado na placa microcontrolada **ESP32-WROOM-32**, controlado remotamente via conexão Bluetooth. A estrutura do robô é composta por dois motores DC, uma roda auxiliar ("roda boba") para equilíbrio, e uma interface de comunicação com o usuário por meio de um aplicativo Bluetooth.

## 🚀 Objetivos

- Implementar controle de movimento (frente, ré, esquerda, direita, parar) via Bluetooth.
- Utilizar o ESP32 para leitura dos comandos e acionamento dos motores.
- Criar um projeto simples, replicável e didático.

## 🧰 Componentes Utilizados

- 1x Placa ESP32-WROOM-32
- 2x Motores DC com suporte
- 1x Ponte H (L298N ou similar)
- 1x Roda boba (roda livre)
- 1x Suporte de bateria (7.4V ou 9V)
- Jumpers e fios
- Chassi para montagem
- Aplicativo de controle Bluetooth (como o **Serial Bluetooth Terminal** no Android)

## Sugestão de chassi

<figure style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/3dadba52-299c-4dad-9f0d-bdd21da6264d" alt="Robô Móvel" width="200" style="display: block; margin: 0 auto;">
  <figcaption style="font-size: 0.9em; color: #555; margin-top: 8px;">
    <em>Figura 1 – Exemplo de chassi com os motores e roda boba.</em>
  </figcaption>
</figure>

## Diagrama

<figure style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/a7e14632-fd20-43dd-92ae-67db5882b4b2" alt="Robô Móvel" width="300" style="display: block; margin: 0 auto;">
  <figcaption style="font-size: 0.9em; color: #555; margin-top: 8px;">
    <em>Figura 2 – Diagrama de ligações entre a placa microcontrala, driver de potência (módulo L298), motores DC e bateria.</em>
  </figcaption>
</figure>

## Identificação dos pinos da placa microcontrolada ESP32-WROOM32

<figure style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/50861263-49db-4662-87bb-51c0d9d4e0a6" alt="Robô Móvel" width="300" style="display: block; margin: 0 auto;">
  <figcaption style="font-size: 0.9em; color: #555; margin-top: 8px;">
    <em>Figura 3 – Diagrama de ligações entre a placa microcontrala, driver de potência (módulo L298), motores DC e bateria.
    Fonte: https://lastminuteengineers.com/esp32-pinout-reference/</em>
  </figcaption>
</figure>

## Algoritmo de exemplo



## 🛠️ Funcionamento

O ESP32 se conecta via Bluetooth a um smartphone ou computador. Comandos são enviados por meio de um app terminal (ou interface gráfica), e a ESP32 interpreta esses comandos para ativar os motores conforme a direção desejada:

- `F`: para frente
- `T`: para tras
- `E`: para a esquerda
- `D`: para a direita
- `P`: parar

A ponte H (módulo com L298) é utilizada para controlar o sentido de rotação dos motores, permitindo os movimentos básicos do robô.

## 📱 Aplicativo de Controle: Bluetooth Electronics

Para controlar o robô móvel via Bluetooth, recomenda-se o uso do aplicativo Bluetooth Electronics, disponível gratuitamente na Play Store. O aplicativo permite criar uma interface personalizada com botões que enviam comandos seriais (como F, T, D, E, P) diretamente ao ESP32. Cada botão pode ser configurado com um rótulo e um caractere correspondente à ação desejada no robô.

A conexão é feita diretamente com o módulo Bluetooth do ESP32, sem necessidade de pareamento complexo. Com isso, o controle do robô se torna intuitivo e acessível, mesmo em ambientes educacionais ou de prototipagem rápida.

Configuração de um painel
- Escolha um painel vazio e clique na opção de edição
<figure style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/b9fe19b2-3d73-42d6-a99b-971f66002edb" alt="Robô Móvel" width="400" style="display: block; margin: 0 auto;">
  <figcaption style="font-size: 0.9em; color: #555; margin-top: 8px;">
    <em>Figura 4 – Tela inicial do aplicativo Bluetooth Electronics.</em>
  </figcaption>
</figure>

- Na lista de ferramentas à direita, encontre o conjunto de ferramentas "Pads" e insira o tipo que mais lhe agradar
<figure style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/5c36a51c-f13d-4abb-8d5b-eb24aaa89958" alt="Robô Móvel" width="400" style="display: block; margin: 0 auto;">
  <figcaption style="font-size: 0.9em; color: #555; margin-top: 8px;">
    <em>Figura 5 – Montagem de um painel com os comandos necessários.</em>
  </figcaption>
</figure>

- Associe os botões direicionais aos caracteres correspondentes de movimentação do robô
<figure style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/c4e2d2a5-b41b-482b-8e6a-026ecef7ad64" alt="Robô Móvel" width="400" style="display: block; margin: 0 auto;">
  <figcaption style="font-size: 0.9em; color: #555; margin-top: 8px;">
    <em>Figura 6 – Tela de configuração de um painel do aplicativo Bluetooth Electronics.</em>
  </figcaption>
</figure>

- Insira um botão (encontrado no conjunto Buttons) para associar o caractere P para parar a movimentação do robô
- Retorne à tela de seleção dos painéis e clique no botão "Connect"
<figure style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/9df3c579-55b0-49dd-85bb-2eca010fcea9" alt="Robô Móvel" width="400" style="display: block; margin: 0 auto;">
  <figcaption style="font-size: 0.9em; color: #555; margin-top: 8px;">
    <em>Figura 7 – Iniciar a conexão com a placa microcontrolada.</em>
  </figcaption>
</figure>

- Já com a placa microcontrolada energizada, selecione a opção "Bluetooth Classic" e logo a após clique no botão "Next"
- Encontre e selecione na lista o nome do dispositivo assim como foi estabelecido na programação da placa ESP32
<figure style="text-align: center;">
  <img src="https://github.com/user-attachments/assets/125a917f-3ad7-4413-94a7-568dbc6db63d" alt="Robô Móvel" width="400" style="display: block; margin: 0 auto;">
  <figcaption style="font-size: 0.9em; color: #555; margin-top: 8px;">
    <em>Figura 8 – Indicar o nome previamente configurado da placa microcontrolada.</em>
  </figcaption>
</figure>

- Clique em "Connect" e logo após em "Done"
- Novamente na tela de seleção dos painéis, o botão "Run" deve estar disponível.

- Divirta-se!

## 📲 Como Usar

1. Clone este repositório:
   ```bash
   git clone https://github.com/ProfMarcoVinchi/robo-balao.git

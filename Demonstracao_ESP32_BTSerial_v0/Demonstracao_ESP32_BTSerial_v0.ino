
//Biblioteca para habilitar a comunicação SERIAL
#include "BluetoothSerial.h"

//Verifica se o bluetooth esta habilitado corretamente
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run 'make menuconfig' to and enable it
#endif

#define LED_BUILTIN 2
#define M1_F 26
#define M1_T 25
#define M2_F 33
#define M2_T 32

//Cria uma instância de BluetoothSerial chamado SerialBT (objeto)
BluetoothSerial SerialBT;

//---Protótipo das Funções Auxiliares---//
void configuracao();
void frente();
void tras();
void direita();
void esquerda();


//---Função Principal---//
void setup() 
{
configuracao();
for(int x = 0; x <= 9; x++){
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(1000);
}
/*
frente();
delay(2000);
tras();
delay(2000);
direita();
delay(2000);
esquerda();
delay(2000);
parar();
*/
}

//---Loop Infinito---//
void loop() 
{
  //Verifica de chegou um novo comando da conexão Bluetooth
  if(SerialBT.available() > 0){
    char comando = SerialBT.read();
    switch(comando){
      case 'F': frente(); break;
      case 'T': tras(); break;
      case 'D': direita(); break;
      case 'E': esquerda(); break;
      case 'P': parar(); break;
    }
  }
}

//---Funções Auxiliares---//
void configuracao()
{
Serial.begin(115200);
//Edite a istrução abaixo para colocar o nome do seu robô!
SerialBT.begin("FESA_RoboBalao"); 
Serial.println("O dispositivo foi iniciado, agora você pode emparelhá-lo com bluetooth!");
//Define as saídas digitais da placa microcontrolada
pinMode(LED_BUILTIN, OUTPUT);
pinMode(M1_F, OUTPUT);
pinMode(M1_T, OUTPUT);
pinMode(M2_F, OUTPUT);
pinMode(M2_T, OUTPUT);
//Inicia os sinais como falsos
digitalWrite(M1_F, LOW);
digitalWrite(M1_T, LOW);
digitalWrite(M2_F, LOW);
digitalWrite(M2_T, LOW);
}

void frente(){
  digitalWrite(M1_F, HIGH);
  digitalWrite(M2_F, HIGH);
  digitalWrite(M1_T, LOW);
  digitalWrite(M2_T, LOW);
}

void tras(){
  digitalWrite(M1_F, LOW);
  digitalWrite(M2_F, LOW);
  digitalWrite(M1_T, HIGH);
  digitalWrite(M2_T, HIGH);
}

void direita(){
  digitalWrite(M1_T, HIGH);
  digitalWrite(M2_T, LOW);
  digitalWrite(M1_F, LOW);
  digitalWrite(M2_F, HIGH);
}

void esquerda(){
  digitalWrite(M1_T, LOW);
  digitalWrite(M2_T, HIGH);
  digitalWrite(M1_F, HIGH);
  digitalWrite(M2_F, LOW);
}

void parar(){
  digitalWrite(M1_F, LOW);
  digitalWrite(M2_F, LOW);
  digitalWrite(M1_T, LOW);
  digitalWrite(M2_T, LOW);
}
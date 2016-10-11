/*
   19/07/2016
   Jose Maria Cesario Jr
   Exemplo ARDUINO ETHERNET
   Hardware: Arduino UNO + Ethernet Shield
   
   Logica:
   1. define um MAC address para o Ethernet Shield
   2. inicializa a biblioteca Ethernet e cria o objeto de conexao client do tipo EthernetClient
   3. inicia a conexao ethernet baseado no MAC address definido no passo 1 e tenta obter endereco IP via DHCP
   4. caso endereco IP for obtido com sucesso, imprime o mesmo no console serial  

*/

#include <SPI.h>
#include <Ethernet.h>


byte mac[]    = {0x98, 0x4b, 0x4a, 0x15, 0x91, 0x1b };
char macstr[] = "984b4a15911b";

// Inicializa Ethernet client library
EthernetClient client;

void setup() {
  Serial.begin(9600);
  // inicia conexao Ethernet
  if (Ethernet.begin(mac) == 0) {
   Serial.println("Falha em obter endereco IP via DHCP. Reinicialize o Arduino.");
    while (1) {}
  }
  Serial.print("[INFO] IP: ");
  Serial.println(Ethernet.localIP());
}

void loop() {

}

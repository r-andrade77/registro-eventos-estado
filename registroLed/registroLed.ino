#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "NOME-WIFI";
const char* senha = "senhaSegura";
const char* URL_API = "http://10.116.75.98:8080/api/mensagens";

const int LED = 0;

const int botao = 0;



void conectarWifi(){
  Serial.println("Ligando o WiFi!");
  WiFi.begin(ssid, senha);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWi-fi Conectado.");
}





void enviarMensagemParaApi(String mensagem){
  if(WiFi.status() != WL_CONNECTED){
    Serial.println("Erro: WiFi desconectado.");
    conectarWiFi();
    return;
  
  HTTPClient http;
  http.begin(URL_API);
  http.addHeader("Content-type", "application/json");
  String textoJson = "(\"conteudo:\":" + mensagem + "}";

  int codigoResposta = http.POST(textoJson);

  if (codigoResposta > 0){
    Serial.prin("Mensagem gravada com sucesso! Código HTTP: ");
    Serial.println(codigoResposta);
    Serial.print("Resposta do servidor: ");
    Serial.println(http.getString());
  } else {
    Serial.println("Falha ao gravar a mensagem. Codigo do erro: ");
    Serial.println(codigoResposta);
  }
}
 




void setup(){
  Serial.begin(9600);
  delay(1000);
  conectarWiFi();
  pinMode(LED, OUTPUT);
  pinMode(botao, INPUT_PULLUP)
}

void loop() {

  bool estadoBotao = analogRead(botao);
  String estadoLed = "";

  if(estadoBotao = true){
    estadoLed = "Led Aceso";
  } else {
    estadoLed = "Led Apagado";
  }

  enviarMensagemParaApi(estadoLed);
  delay(5000);
}
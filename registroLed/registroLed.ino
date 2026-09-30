#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "NOME-WIFI";
const char* senha = "senhaSegura";
const char* URL_API = "http://10.116.75.98:8080/api/mensagens";

const int LED_1 = 0;
const int LED_2 = 0;
const int LED_3 = 0;
const int LED_4 = 0;
const int potenciometro = 0;



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
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(potenciometro, INPUT)
}

void loop() {

  int valorPotenciometro = analogRead(potenciometro);

  if (valorPotenciometro < 800){
    digitalWrite(LED_1, LOW)
    digitalWrite(LED_2, LOW)
    digitalWrite(LED_3, LOW)
    digitalWrite(LED_4, LOW)
  }

  if(valorPotenciometro >= 800 && valorPotenciometro <= 1600){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_4, LOW);
  } 
  
  if(valorPotenciometro >= 1601 && valorPotenciometro <= 2400){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  } 
  
  if(valorPotenciometro >= 2401 && valorPotenciometro <= 3200){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, LOW);
  } 
  
  if(valorPotenciometro > 3200){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
  } 
  

  enviarMensagemParaApi(valorPotenciometro);
  delay(5000);
}
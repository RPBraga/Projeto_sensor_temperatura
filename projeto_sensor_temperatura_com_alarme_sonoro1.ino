/*Código do projeto sensor de temperatura*/

int t=5;
void setup(){
  Serial.begin(9600); // Inicializa a comunicação serial em 9600 bits por segundo
  pinMode(A0,INPUT); // Declaração (Leitura) do pino que está conectado ao sensor
  pinMode(7, OUTPUT); // Declaração (saída) do pino que está conectado ao sensor
}

void loop()
{
  float tempc = ((analogRead(A0)*(5.0/1024))-0.5)/0.01;
  float tempf = (tempc * 9/5)+32;
  if((tempc > 30)||(tempc <-10)){
    for(int f=500;f<=600;f++){
    tone(7,f,t);
    }
  }
                   
 	Serial.print("Celsius:");
 	Serial.print(tempc);
 	Serial.print(" ºC");
 	Serial.print("Fahrenheit: ");
 	Serial.print(tempf);
 	Serial.println(" ºF");
 	delay(1000);
}
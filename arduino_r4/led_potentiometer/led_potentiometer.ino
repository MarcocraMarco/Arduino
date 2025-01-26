
int pinIn=A1;
int piOut= 6;
int readAnag=0;
float volts=0;
long baud= 9600;


//this function converts numbers base two in volts
float conversioneInputVolt (float a, float volts){
  float voltsConerted=(a*volts)/1023;
  return voltsConerted;
}

long conversioneOutputLed(float  readingAnalog){
  float factor= (readingAnalog/1023)*8;
  float converted = pow(2, factor);
  return converted;

}

void setup() {
  // put your setup code here, to run once:
 pinMode(pinIn,INPUT);
 pinMode(piOut,OUTPUT);
 Serial.begin(baud);
}

void loop() {
  // put your main code here, to run repeatedly:
  readAnag=analogRead(pinIn);
  volts=conversioneInputVolt(readAnag,5);
  Serial.print("Lettura a 10 bit: ");
  Serial.println(readAnag);
  Serial.print("Lettura volt: ");
  Serial.print(volts);
  Serial.println(" V.");
  long outputAn=conversioneOutputLed(readAnag);
  Serial.print("Lettura output 8 but: ");
  Serial.println(outputAn);

    Serial.print(" outputAn --> ");
    Serial.println(outputAn);
    analogWrite(piOut,readAnag);
 
}


long first = 0;
long second = 0;
const int one_pin = 3;
const int two_pin = 6;

uint8_t one_bit = 0b00001000;
uint8_t two_bit = 0b01000000;
uint8_t port = "PD";

int start = 0;
int last = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(one_pin, INPUT);
  pinMode(two_pin, INPUT);
  Serial.print("ready: ");
}

void loop() {
  if(start == 0){
    if(PIND & one_bit){
      first = micros();
      start = 1;
    }
    else{
      return;
    }
  }
  // put your main code here, to run repeatedly:
  if(PIND & two_bit){
    second = micros();
    double seconds = (second-first)/(1000.0*1000.0);
    double fps = 3.5/seconds;
    if(last == 0){
      Serial.print("FPS is: ");
      Serial.print(fps, 10);
      Serial.print("\n");
      Serial.print("In ");
      Serial.print((second-first)/(1000.0*1000.0), 10);
      Serial.print("\n");
      delay(10000000);
      last = 1;
    }
  }
}

/* Arduino USB Keyboard HID
 * For Kerbal Space Program
 */

uint8_t buf[8] = { 
  0 };     /* Keyboard report buffer */

#define CHANGE_STAGE 2

int state = 1;

void setup() 
{
  Serial.begin(9600);
  pinMode(CHANGE_STAGE, INPUT);
  // enable internal pull-ups
  digitalWrite(CHANGE_STAGE, 1); 
  delay(200);
}

void loop() 
{
  state = digitalRead(CHANGE_STAGE);
  if (state != 1) {
    buf[2] = 44;      // Volume up key
    Serial.write(buf, 8);    // Send keypress
    releaseKey();
    delay(200);
  } 
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);    // Release key  
}

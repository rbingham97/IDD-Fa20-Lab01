/*
 * Digital Timer
 * 
 * Written by Russell Bingham for CT IDD Fa20 Lab 1
 * 
 * Based on the sample code specified in the lab manual
 * 
 * 9/7/20
 * 
 */


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define ENC_A 6 //these need to be digital input pins
#define ENC_B 7

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

// notes in the melody:
int melody[] = {
  262, 196, 262, 262, 196, 262, 262, 196, 262, 262, 196, 262, 262, 196, 262, 262, 196, 262
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 4, 4, 8, 4, 4, 8, 4, 4, 8, 4, 4, 8, 4, 4, 8, 4
};


void setup() {

  // screen setup
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(500); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  display.setTextSize(2);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.cp437(true);         // Use full 256 char 'Code Page 437' font


  //encoder setup
  /* Setup encoder pins as inputs */
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);

  int timeAmt = 0;

  display.clearDisplay();
  display.setCursor(8, 10);
  display.print("Time: ");
  display.print(timeAmt);
  display.println(" s");
 
  display.display();

  // get time amount from encoder
  static unsigned int counter4x = 0;      //the SparkFun encoders jump by 4 states from detent to detent
  static unsigned int counter = 0;
  static unsigned int prevCounter = 0;
  int tmpdata;

  // turn encoder up to set time, loop until user turns counterclockwise to start timer
  while (prevCounter <= counter) {
    tmpdata = read_encoder();
    
    if( tmpdata) {
      prevCounter = counter;
      counter4x += tmpdata;
      counter = counter4x/4;
      if (prevCounter != counter){
        Serial.print("Counter value: ");
        Serial.println(counter);
      }
    }

    // show current set value
    display.clearDisplay();
    display.setCursor(20, 10);
    display.print("Set: ");
    display.print(counter);
    display.println(" s");
   
    display.display();
  }

  // count down
  while (counter >= 0 && counter < 1000) {
    // display time left
    display.clearDisplay();
    display.setCursor(8, 10);
    display.print("Time: ");
    display.print(counter);
    display.println(" s");
   
    display.display();
    delay(1000);
    counter = counter - 1;
  }

  // show end alert
  display.clearDisplay();
  display.setCursor(8, 10);
  display.println("Time's up!");
 
  display.display();
  playTune(); // play jingle

}

void loop() {
// no need to loop
}


/* returns change in encoder state (-1,0,1) */
int read_encoder()
{
  static int enc_states[] = {
    0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0  };
  static byte ABab = 0;
  ABab *= 4;                   //shift the old values over 2 bits
  ABab = ABab%16;      //keeps only bits 0-3
  ABab += 2*digitalRead(ENC_A)+digitalRead(ENC_B); //adds enc_a and enc_b values to bits 1 and 0
  return ( enc_states[ABab]);
 
 
}


// plays the timer end tune
// yoinked from sample code
void playTune() {

  for (int thisNote = 0; thisNote < 18; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 500 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

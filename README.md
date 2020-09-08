# IDD-Fa20-Lab01: Blink!

**A lab report by Russell Bingham**

# Section 1 - Light It Up

## Part A. Set Up a Breadboard

![Breadboard pic](/images/IMG_4178.JPG "Breadboard!")

## Part B. Manually Blink a LED

**a. What color stripes are on a 220 Ohm resistor?**

Our resistors use the 5-band color coding scheme and have red, red, black, black, brown stripes, corresponding to 220 x1 Ohms +-1%. 
 
**b. What do you have to do to light your LED?**

Once the circuit is set up like in the diagram, pushing the button lights up the LED. I had some minor debugging issues because I (accidentally) used the long breadboard with split power/ground rails, but once I connected the rails (see red bridges in the picture from Part A) the circuit worked as intended. 


## Part C. Blink a LED using Arduino

### 1. Blink the on-board LED

**a. What line(s) of code do you need to change to make the LED blink (like, at all)?**

I'm confused by this question, since my LED blinks at 0.5Hz without me changing anything.

**b. What line(s) of code do you need to change to change the rate of blinking?**

Lines 34 and 36 of the base sketch specify the delay lengths (in ms) that control the blink rate (currently 1s on, 1s off). Changing the function parameter for delay() here will change the blink rate.

**c. What circuit element would you want to add to protect the board and external LED?**

I'm assuming this question is referring to the resistor(s) we include in the LED circuit to regulate current, thus protecting the other elements. 
 
**d. At what delay can you no longer *perceive* the LED blinking? How can you prove to yourself that it is, in fact, still blinking?**

When the delay is 15 ms on, 15 ms off, I can see the LED visually vibrating, but it doesn't look like it's blinking. This makes sense, because 30 ms blink period corresponds to about 30 Hz, which is the limit of what the human eye can perceive. I took a slow-mo video of the board with my phone, and since the frame rate of a slow-mo video is faster than the blink cycle, the video captures the blinking. 

**e. Modify the code to make your LED blink your way. Save your new blink code to your lab 1 repository, with a link on the README.md.**

I changed the blink cycle to make the onboard red LED match the brightness of the green power LED. After some trial and error, I generated [code](./customBlink.ino) that blinks the LED with a manual 20% PWM duty cycle, roughly matching the brightness of the two LEDs. 


### 2. Blink your LED

**Make a video of your LED blinking, and add it to your lab submission.**

The video is [here](https://youtu.be/ODiTFwJLC9Y).

## Part D. Manually fade an LED

**a. Are you able to get the LED to glow the whole turning range of the potentiometer? Why or why not?**

Yes. This is because adding more resistance to an LED circuit just reduces the amount of current the whole system pulls, and in this case the highest resistance from the pot still leaves enough current to make the LED glow. 

## Part E. Fade an LED using Arduino

**a. What do you have to modify to make the code control the circuit you've built on your breadboard?**

To change the output pin from 9 to 11, I changed the value of the "led" variable from 9 to 11 on line 16. This updates the later references appropriately.

**b. What is analogWrite()? How is that different than digitalWrite()?**

According to the Arduino documentation, analogWrite() automatically outputs a PWM waveform to the specified pin, with duty cycle determined by the second argument proportional to its value in the range of 0 to 255. Contrastingly, digitalWrite() simply puts either a constant high or low voltage onto the specified pin. We can thus infer that analogWrite() is doing some ongoing internal computation to ouptut a waveform (or is outsourcing that task to a board peripheral), whereas digitalWrite() simply changes the state of a pin once. 


# Section 2 - Make A Digital Timer!

## Part A - Solder the OLED

See the video in part E for the breadboard setup!

## Part B - Lowly Multimeter

My code to run the lowly multimeter can be found [here](./lowlyMultimeter.ino)

## Part C - Rotary Encoder

When set up on the breadboard, the encoder works correctly. 

## Part D - Make the Arduino Sing!

**a. How would you change the code to make the song play twice as fast?**

On line 36 of the example, the code calculates the time-domain length of each note by dividing 1000 ms by the note lengths. By changing this line to calculate note lengths by dividing 500 by the note lengths, the song plays twice as fast.

**b. What song is playing?**

I think that it's Taps? I could be wrong about that. It's a recognizable jingle for sure, but I never learned the names of common jingles very well. 

## Part E - Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

The video is [here](https://youtu.be/oCDRtn8BXFE)

**b. Post a link of the completed lab report to your GitHub repo.**

Done!





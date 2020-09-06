# IDD-Fa20-Lab01: Blink!

**A lab report by Russell Bingham**

## Part A. Set Up a Breadboard

[insert a photo of your breadboard setup here]


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
 
**d. At what delay can you no longer *perceive* the LED blinking? How can you prove to yourself that it is, in fact, still blinking?**

**e. Modify the code to make your LED blink your way. Save your new blink code to your lab 1 repository, with a link on the README.md.**


### 2. Blink your LED

**Make a video of your LED blinking, and add it to your lab submission.**

[link to your video here; feel free to upload to youtube and just paste in a link here]


## Part D. Manually fade an LED

**a. Are you able to get the LED to glow the whole turning range of the potentiometer? Why or why not?**


## Part E. Fade an LED using Arduino

**a. What do you have to modify to make the code control the circuit you've built on your breadboard?**

**b. What is analogWrite()? How is that different than digitalWrite()?**


## Part F. FRANKENLIGHT!!!

### 1. Take apart your electronic device, and draw a schematic of what is inside. 

**a. Is there computation in your device? Where is it? What do you think is happening inside the "computer?"**

**b. Are there sensors on your device? How do they work? How is the sensed information conveyed to other portions of the device?**

**c. How is the device powered? Is there any transformation or regulation of the power? How is that done? What voltages are used throughout the system?**

**d. Is information stored in your device? Where? How?**

### 2. Using your schematic, figure out where a good point would be to hijack your device and implant an LED.

**Describe what you did here.**

### 3. Build your light!

**Make a video showing off your Frankenlight.**

**Include any schematics or photos in your lab write-up.**

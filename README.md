# module-1-esp32

materials used: TTGO T-Display ESP32, 3.7V 500mAh Battery, JST connector, popsicle stick, string, tape, card stock 
The device is an ESP32 that has a display. A program was written using the Arduino IDE and uploaded from a computer to the ESP32 through a USBC that plugged into the ESP32. Once the code was uploaded to the ESP32 the artist ran the code from the IDE many times to fix bugs and tinker.
Power source: A 2 pin JST connector was soldered to a battery. The soldered area was wrapped with electrical tape and/or heat shrink. A slight tug test should confirmed that the soldering would hold. The JST connector was plugged in the the back of the ESP32 and the entire device was plugged in to the computer with the USBC so that the battery could charge. Once the battery was charged the battery could power the ESP32.
Display: The ESP32 was placed into an envelope made from card stock. The envelope had a cutout for the screen, a hole at the top to attach a string, and enough width to fit the ESP32 and the battery. Tape was used to hold the contents in place. A popsicle stick was attached to the end of the string and the display was hung up.

description of project:
Countdown by Beyonce brought to you on an ESP32! The installation 'module #1' is a product of the collective effort of the COMS3930 Art Group.  Each suspended device visualizes a text using a generative program. My ESP32 displays a portion of Beyonce's "Countdown" lyrics.

arduino IDE was used to write this code and specific settings and libraries had to be selected in order to run the code on an ESP32 TTGO T-Display 

problem encoutered: random number generator was used to index a list of colors but was using colors from a previous version of the code. The artist was infuriated and confused by this so she hard coded a color as a last minute attempt to salvage the project. 

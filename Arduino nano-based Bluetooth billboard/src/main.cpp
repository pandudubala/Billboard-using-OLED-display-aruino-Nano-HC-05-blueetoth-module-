//Kindly read the .me file before you are going to excute 
//download all library files stated with  "#include<>" files 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// I2C Address of OLED
#define OLED_ADDR 0x3C 

// Create OLED display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Define SoftwareSerial for HC-05 (Use different pins than D0 & D1)
SoftwareSerial BTSerial(2, 3); // RX, TX

void setup() {
    Serial.begin(115200);   // Debugging Serial Monitor
    BTSerial.begin(9600);   // HC-05 Default Baud Rate

    // Initialize OLED Display
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }

    // Show startup message
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(10, 20);
    display.println("BT Billboard Ready");
    display.display();
}

void loop() {
    if (BTSerial.available()) { 
        String receivedText = BTSerial.readStringUntil('\n'); // Read from HC-05

        Serial.println("Received: " + receivedText); // Debug output

        // Display message on OLED
        display.clearDisplay();
        display.setTextSize(2);
        display.setCursor(5, 20);
        display.print(receivedText);
        display.display();
    }
}
//if you are facing any issues in excuteing the code dont hesitate to reach 
//me at via mail pandudubala9666@gmail.com or www.kspelectronics.com mention my name pandudubala happy programmeing follow for more sstuff 
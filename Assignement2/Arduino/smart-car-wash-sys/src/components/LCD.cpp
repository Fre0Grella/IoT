#include "LCD.h"
LCD::LCD() {
    lcd = new LiquidCrystal_I2C(0x27,20,4);
}

void LCD::init() {
    lcd->init();
    lcd->backlight();
    cursorX=0;
    cursorY=1;
    lcd->setCursor(cursorX,cursorY);

}

void LCD::print(String string) {
    //[TODO]: check lenght for avoiding overflow of the screen
   //int length = string.length();
    lcd->print(string);
}

void LCD::clear() {
    lcd->clear();
}
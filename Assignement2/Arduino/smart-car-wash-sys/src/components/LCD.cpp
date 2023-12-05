#include <LCD.h>
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
    lcd->clear();
    lcd->print(string);
}

void LCD::clear() {
    lcd->clear();
}

void LCD::backLighOn() {
    lcd->backlight();
}

void LCD::backLightOff() {
    lcd->noBacklight();
}




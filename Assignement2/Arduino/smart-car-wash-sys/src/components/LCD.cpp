#include "LCD.h"

LCD::LCD() {
    lcd.init();
    lcd.backlight();
    cursorX=0;
    cursorY=0;
    lcd.setCursor(cursorX,cursorY);
}

void LCD::print(char string[]) {

}

void LCD::clear() {
    lcd.clear();
}

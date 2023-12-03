#include <Gate.h>

Gate::Gate(int pin)
{
    this->pin = pin;
    open = 180;
    close = 90;
}

void Gate::on() {
    motor.attach(pin);
}

void Gate::off() {
    motor.detach();
}

void Gate::setPosition(int angle)
{
	if (angle > 180){
		angle = 180;
	} else if (angle < 0){
		angle = 0;
	}
    // 750 + angle*(2250-750)/180
    // updated values: min is 544, max 2400 (see ServoTimer2 doc)
    float coeff = (2400.0-544.0)/180;
    motor.write(544 + angle*coeff);              

}

void Gate::openGate() {
    Serial.println("Gate Opening");
    setPosition(open);
}

void Gate::closeGate() {
    Serial.println("Gate Closing");
    setPosition(close);
}

bool Gate::isOpen() {
    float coeff = (2400.0-544.0)/180;
    return motor.read() == (544 + open*coeff); 
}
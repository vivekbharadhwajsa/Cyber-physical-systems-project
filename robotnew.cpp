#include "ev3dev.h"
#include <iostream>

using namespace ev3dev;

touch_sensor* ts=new touch_sensor(INPUT_1);
motor* left=new motor(OUTPUT_A);
motor* right=new motor(OUTPUT_B);
bool state=false;
ultrasonic_sensor* us=new ultrasonic_sensor(INPUT_4);
motor* usmotor=new motor(OUTPUT_D);
float distance;
int usangle;
int usangleabs;
bool goleft = false;

bool press_and_release(touch_sensor* ts)
{
if(ts->is_pressed()==1)
{
	while(ts->is_pressed()==1){ }
	return true;
}else return false;
}


float shortdistance=256;
int shortdistanceangle;

void setMotorSpeed() {
	if ( shortdistanceangle < 15 && shortdistanceangle > -15 ) {
		right->set_duty_cycle_sp(50);
		left->set_duty_cycle_sp(50);
	}
	else if(shortdistanceangle <= -15)
	{
		right->set_duty_cycle_sp(60);
		left->set_duty_cycle_sp(40);	
	}
	else
	{
		left->set_duty_cycle_sp(60);
		right->set_duty_cycle_sp(40);	
	}

	left->run_direct();
	right->run_direct();
}


int main()
{
usmotor->set_duty_cycle_sp(30);
usmotor->set_position(0);

while(1)
{
	std::cout << "State: " << state << std::endl;
	if(press_and_release(ts)==true)
	{
		if ( state ) {
			left->stop();
			right->stop();
			usmotor->stop();
			state=false;
			
		} else {
			state = true;
		}
	}

	if ( state ) {
		
		usmotor->run_direct();
		if ( usmotor->position() > 45 && !goleft) {
			usmotor->set_duty_cycle_sp(-30);
			goleft = !goleft;
			setMotorSpeed();
			shortdistance = 256;
		} else if ( usmotor->position() < -45 && goleft) {
			usmotor->set_duty_cycle_sp(30);
			goleft = !goleft;
			setMotorSpeed();
			shortdistance = 256;
		}

		int curDist = us->distance_centimeters();
		int curAngle = usmotor->position();
		if ( curDist < shortdistance ) {
			shortdistance = curDist;
			shortdistanceangle = curAngle;
		}
	}



}

}

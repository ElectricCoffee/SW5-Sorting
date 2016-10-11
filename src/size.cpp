// The implementation file of size
#include "size.hpp"

#define ENGINESPEED 0 //temporary, should be the speed of engine, prolly shouldnt be gotten here, maybe make a macro?


int size::get_size(){
	return newest_size; //makes it possible to get it some time after it measured it, maybe not necessary
}

//put into its own method so it can measure while doing other stuff
void size::start_measuring(){
	current_time = millis();
	newest_size = null; //just in case
}

void size::stop_measuring(){
	newest_size = ENGINESPEED * ( millis() - current_time ); 
	//maybe send a signal or something? 
}

//this is what the controller should use to check if there are any bricks.
void size::check_measuring(){
	if(newest_size != null){ //this is when there isn't one being measured. 
		if(digitalRead(pin) == true)
			start_measuring();
	}
	else{ //this is for when there currently is one being measured.
		if(digitalRead(pin) == false)
			stop_measuring();
	}
}

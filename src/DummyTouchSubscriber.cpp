#include "DummyTouchSubscriber.h"
#include "CST816Touch.h"

//#define DEBUG
//#include <mdomisc.h>



namespace MDO {


//the pointer is the 'this' from the CST816Touch source 
/*virtual*/ void DummyTouchSubscriber::gestureNotification(CST816Touch* pTouch, int iGestureId) {
	Serial.print("Gesture detected: ");
	Serial.print(CST816Touch::gestureIdToString(iGestureId));
	
	if ((pTouch != 0) && (iGestureId == (int)CST816Touch::gesture_t::GESTURE_LONG_PRESS)){
		int x = 0;
		int y = 0;
		CST816Touch::gesture_t eGesture;
		
		pTouch->getLastGesture(eGesture, x, y);
		
		Serial.print(" at: (");
		Serial.print(x);
		Serial.print(",");
		Serial.print(y);
		Serial.print(")");
	}
	
	Serial.println();
}

//the pointer is the 'this' from the CST816Touch source 
/*virtual*/ void DummyTouchSubscriber::touchNotification(CST816Touch* pTouch, int x, int y) {
	Serial.print("Touch detected: (");
	Serial.print(x);
	Serial.print(",");
	Serial.print(y);
	Serial.println(")");	
}

DummyTouchSubscriber::DummyTouchSubscriber() {
}

DummyTouchSubscriber::~DummyTouchSubscriber() {
}

}	//namespace end
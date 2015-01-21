/*
 * ControlScheme.h
 *
 *  Created on: Jan 15, 2015
 *      Author: robbiemarkwick
 */

#ifndef SRC_CONTROLSCHEME_H_
#define SRC_CONTROLSCHEME_H_
#include "WPILib.h"
#include "ButtonMonitor.h"
#include <mutex>

enum class ControlReferenceFrame {
	Absolute,Relative
};
class ControlScheme: public ButtonResponder {
public:
	ControlScheme(Joystick* drive);
	virtual ~ControlScheme();

	void getDriveControls(double& x, double& y, double&r);
	ControlReferenceFrame getDriveReferenceFrame();

	void respondToButton(int button);

private:
	bool getPerfectControls(double& x, double& y);

	Joystick* driveStick;
	//Reference Frame Monitor
	ButtonMonitor* referenceFrameSwitchMonitor;
	ControlReferenceFrame driveReferenceFrame = ControlReferenceFrame::Absolute;
	std::mutex driveRefLock;
};

#endif /* SRC_CONTROLSCHEME_H_ */
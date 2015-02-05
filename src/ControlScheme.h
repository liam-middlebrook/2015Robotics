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
enum class ControlAlignmentMode {
	Align, Drive
};
class ControlScheme: public ButtonResponder {
public:
	ControlScheme(Joystick* drive, Joystick* lift);
	virtual ~ControlScheme();

	void getDriveControls(double& x, double& y, double&r);
	void getLiftControls(double& vs);
	ControlReferenceFrame getDriveReferenceFrame();
	ControlAlignmentMode getAlignmentMode();

	void respondToButton(int button);

private:
	bool getPerfectControls(double& x, double& y, double& r);

	Joystick* driveStick;
	Joystick* liftStick;

	//Reference Frame Monitor
	ButtonMonitor* absoluteButtonMonitor;
	ButtonMonitor* relativeButtonMonitor;
	ControlReferenceFrame driveReferenceFrame = ControlReferenceFrame::Absolute;
	std::mutex driveRefLock;
};

#endif /* SRC_CONTROLSCHEME_H_ */

#include "cl_5.h"
#include "cl_6.h"
#include "cl_7.h"
void cl_6::handler(string msg)
{
	// emitting signal to display about coffee
	emit_signal(SIGNAL_D(cl_7::signal), msg);

	// emitting signal to money changer
	emit_signal(SIGNAL_D(cl_5::signal), msg);

	return;
}

void cl_6::signal(string& msg)
{
	// setting message for next signal
	msg = "Take the coffee " + msg;
	return;
}



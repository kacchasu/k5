#include "cl_7.h"
void cl_7::handler(string msg)
{
	// in case we need to stop the system
	if (msg == "Turned off")
	{
		cout << msg;
		exit(0);
	}
	else
		cout << msg;
	cout << endl;
	return;
}

void cl_7::signal(string& msg)
{
	// request about cancel
	if (msg == "Cancel")
		msg = "Turned off";
	return;
}
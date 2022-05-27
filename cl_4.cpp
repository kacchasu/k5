#include "cl_4.h"
#include "cl_7.h"
void cl_4::handler(string msg)
{
	// emit display signal with updated money amount
	emit_signal(SIGNAL_D(cl_7::signal), msg);
	return;
}

void cl_4::signal(string& msg)
{
	// updating current money amount
	if (msg == "5")
		get_parent()->set_money(get_parent()->get_money() + 5);
	else if (msg == "10")
		get_parent()->set_money(get_parent()->get_money() + 10);
	else if (msg == "50")
	{
		if (get_parent()->get_change().first * 5 + get_parent()->get_change().second * 10 >= 50)
			get_parent()->set_money(get_parent()->get_money() + 50);
		else
		{
			msg = "Take the money back, no change";
			return;
		}
	}
	else if (msg == "100")
	{
		if (get_parent()->get_change().first * 5 + get_parent()->get_change().second * 10 >= 100)
			get_parent()->set_money(get_parent()->get_money() + 100);
		else
		{
			msg = "Take the money back, no change";
			return;
		}
	}

	// setting message for next signal
	msg = "The amount: " + to_string(get_parent()->get_money());

	return;
}
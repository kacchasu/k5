#include "cl_3.h"
#include "cl_6.h"
#include "cl_7.h"
void cl_3::handler(string msg)
{
	// emitting signal to display if not enough money
	if (msg == "There is not enough money")
		emit_signal(SIGNAL_D(cl_7::signal), msg);
	// emitting signal to coffee deliver
	else
		emit_signal(SIGNAL_D(cl_6::signal), msg);

	return;
}

void cl_3::signal(string& msg)
{
	// getting coffee title from message
	string coffee_title = msg.substr(7);

	// analysing money amount and setting message for next signal depending on it
	for (auto coffee : get_parent()->get_coffee_types())
		if (coffee_title == coffee.first)
			if (coffee.second <= get_parent()->get_money())
			{
				msg = coffee_title;

				// reducing available money amount
				get_parent()->set_money(get_parent()->get_money() - coffee.second);
			}
			else
				msg = "There is not enough money";

	return;
}
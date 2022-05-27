#include "cl_5.h"
#include "cl_7.h"
void cl_5::handler(string msg)
{
	// emitting signal to display
	emit_signal(SIGNAL_D(cl_7::signal), msg);

	return;
}

void cl_5::signal(string& msg)
{
	// if signal from coffee deliver
	cl_base* system;
	system = this;
	while (system->get_parent() != nullptr)
		system = system->get_parent();
	if (msg.find("Take the coffee") != string::npos)
	{
		if (system->get_money() > 0 &&
			(system->get_change().first > 0 || system->get_change().second > 0))
		{
			int money_rest = system->get_money();
			int money_change = 0;
			int change_ten = system->get_change().second;
			int change_five = system->get_change().first;
			while (money_change < money_rest && ((change_five > 0 || change_ten > 0)))
			{
				if (change_ten > 0 && money_rest - money_change >= 10)
				{
					money_change += 10;
					change_ten--;
				}
				else
				{
					money_change += 5;
					change_five--;
				}
			}
			// setting message for next signal
			msg = "Take the change: 10 * " + to_string(system->get_change().second - change_ten)
				+ " rub.,  5 * " + to_string(system->get_change().first - change_five) + " rub.";
			msg += "\nReady to work";

			// updating change available
			system->set_money(system->get_money() - money_change);
			system->set_change(make_pair(change_five, change_ten));
		}
		else
			// setting message for next signal
			msg = "Ready to work";
	}
	// if money refund request
	else
	{
		int money_rest = system->get_money();
		int money_change = 0;
		int change_ten = system->get_change().second;
		int change_five = system->get_change().first;
		while (money_change < money_rest && ((change_five > 0 || change_ten > 0)))
		{
			if (change_ten > 0 && money_rest - money_change >= 10)
			{
				money_change += 10;
				change_ten--;
			}
			else
			{
				money_change += 5;
				change_five--;
			}
		}
		// setting message for next signal
		msg = "Take the money: 10 * " + to_string(system->get_change().second - change_ten)
			+ " rub.,  5 * " + to_string(system->get_change().first - change_five) + " rub.";
		msg += "\nReady to work";

		// updating change available
		system->set_money(system->get_money() - money_change);
		system->set_change(make_pair(change_five, change_ten));
	}

	return;
}
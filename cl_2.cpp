#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_7.h"
void cl_2::handler(string msg)
{
	// analysing msg and emitting signal depending on it
	if (msg == "Ready to work")
		emit_signal(SIGNAL_D(cl_7::signal), msg);
	else if (msg == "5" || msg == "10" || msg == "50" || msg == "100")
		emit_signal(SIGNAL_D(cl_4::signal), msg);
	else if (msg.find("Coffee") != string::npos)
		emit_signal(SIGNAL_D(cl_3::signal), msg);
	else if (msg == "Refund money")
		emit_signal(SIGNAL_D(cl_5::signal), msg);
	else if (msg == "Cancel")
		emit_signal(SIGNAL_D(cl_7::signal), msg);
	
	return;
}

void cl_2::signal(string& msg)
{
	// if we have command to input
	if (msg == "command")
	{
		getline(cin, msg);
	}
	// if we have settings to input
	else
	{
		// getting coffee types
		int n;
		cin >> n;
		vector<pair<string, int> > coffee_types;
		for (int i = 0; i < n; i++)
		{
			string type;
			cin >> type;
			coffee_types.push_back(make_pair(type, 0));
		}

		// getting coffee prices
		for (int i = 0; i < n; i++)
		{
			int price;
			cin >> price;
			coffee_types[i].second = price;
		}

		// getting available money for change
		pair<int, int> change;
		int five, ten;
		cin >> five >> ten;
		change = make_pair(five, ten);

		// set available coffee types and available money for change in system object
		set_coffee_change(coffee_types, change);

		// setting message for next signal
		msg = "Ready to work";
	}
	
	return;
}
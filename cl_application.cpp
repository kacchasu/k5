#include "cl_application.h"
void cl_application::signal(string& msg)
{
	return;
}
void cl_application::build_tree_objects()
{
	// creating objects and building tree
	set_name("system");
	cl_base* reader, * controller, * money_receiever, * 
		money_changer, * coffee_deliver, * state_display;
	reader = new cl_2("reader", this);
	controller = new cl_3("controller", reader);
	money_receiever = new cl_4("money receiver", reader);
	money_changer = new cl_5("money changer", reader);
	coffee_deliver = new cl_6("coffee deliver", reader);
	state_display = new cl_7("state display", reader);

	// setting connections
	this->set_connect(SIGNAL_D(cl_2::signal), reader, HANDLER_D(cl_2::handler));

	reader->set_connect(SIGNAL_D(cl_3::signal), controller, HANDLER_D(cl_3::handler));
	reader->set_connect(SIGNAL_D(cl_4::signal), money_receiever, HANDLER_D(cl_4::handler));
	reader->set_connect(SIGNAL_D(cl_5::signal), money_changer, HANDLER_D(cl_5::handler));
	reader->set_connect(SIGNAL_D(cl_7::signal), state_display, HANDLER_D(cl_7::handler));

	controller->set_connect(SIGNAL_D(cl_6::signal), coffee_deliver, HANDLER_D(cl_6::handler));
	controller->set_connect(SIGNAL_D(cl_7::signal), state_display, HANDLER_D(cl_7::handler));

	money_receiever->set_connect(SIGNAL_D(cl_7::signal), state_display, HANDLER_D(cl_7::handler));

	money_changer->set_connect(SIGNAL_D(cl_7::signal), state_display, HANDLER_D(cl_7::handler));

	coffee_deliver->set_connect(SIGNAL_D(cl_7::signal), state_display, HANDLER_D(cl_7::handler));
	coffee_deliver->set_connect(SIGNAL_D(cl_5::signal), money_changer, HANDLER_D(cl_5::handler));

	return;
}

int cl_application::exec_app()
{
	// finding reader and setting on all objects
	cl_base* reader;
	set_on(this);
	reader = find_object_by_name("reader");

	// setting coffee machine
	string comm = "setting";
	emit_signal(SIGNAL_D(cl_2::signal), comm);

	// coffee machine started working and accepting commands
	comm = "command";
	while (true)
	{
		emit_signal(SIGNAL_D(cl_2::signal), comm);
		comm = "command";
	}

	return 0;
}
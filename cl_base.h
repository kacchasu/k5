#ifndef __CL_BASE_H__
#define __CL_BASE_H__
#include <iostream>
#include <vector>
#include <string>
using namespace std;


#define SIGNAL_D( signal_f ) ( TYPE_SIGNAL ) ( & signal_f )
#define HANDLER_D( handler_f ) ( TYPE_HANDLER ) ( & handler_f )


class cl_base;
typedef void (cl_base ::* TYPE_SIGNAL) (string&);
typedef void (cl_base ::* TYPE_HANDLER) (string);

struct o_sh
{
	cl_base* p_cl_base;
	TYPE_SIGNAL p_signal;
	TYPE_HANDLER p_handler;
	o_sh(cl_base* p_cl_base,
		TYPE_SIGNAL p_signal,
		TYPE_HANDLER p_handler) :
		p_cl_base(p_cl_base),
		p_signal(p_signal),
		p_handler(p_handler) {};
};

class cl_base
{
	int state = 0;
	string name;
	cl_base* parent;
	vector<cl_base*> children;
	vector <o_sh*> connects;


	vector<pair<string, int> > coffee_types;
	pair<int, int> change;
	int money;
public:
	cl_base(string name = "cl_base", cl_base* parent = nullptr);
	~cl_base();
	string get_name();
	void set_name(string name);
	cl_base* get_parent();
	void set_parent(cl_base* new_parent);
	void print();
	void print_new(string);
	void print_new_state(string);
	virtual cl_base* find_object_by_name(string name);
	bool set_state(int state);
	int get_state();
	cl_base* find_object_by_coord(cl_base*, cl_base*, string);
	vector<cl_base*> get_children();
	
	// setter for coffee and change
	void set_coffee_change(vector<pair<string, int> >, pair<int, int>);

	// setter for money
	void set_money(int);

	// getter for money
	int get_money();
	
	// getter for coffee types
	vector<pair<string, int> > get_coffee_types();

	// getter for change
	pair<int, int> get_change();

	// setter for change
	void set_change(pair<int, int>);

	void set_connect(TYPE_SIGNAL p_signal,
		cl_base* p_object, TYPE_HANDLER p_ob_hendler);

	void delete_connect(TYPE_SIGNAL p_signal,
		cl_base* p_object, TYPE_HANDLER p_ob_hendler);

	void emit_signal(TYPE_SIGNAL p_signal, string& s_command);

	string coord(string);


	void set_on(cl_base*);
};


#endif
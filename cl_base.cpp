#include "cl_base.h"
cl_base::cl_base(string name, cl_base* parent)
{
	this->name = name;
	this->parent = parent;
	if (parent)
		parent->children.push_back(this);
	return;
}
cl_base::~cl_base()
{
	for (int i = 0; i < children.size(); i++)
		delete children[i];
}
string cl_base::get_name()
{
	return name;
}

void cl_base::set_name(string name)
{
	this->name = name;
	return;
}
void cl_base::set_parent(cl_base* new_parent)
{
	if (parent)
		for (int i = 0; i < parent->children.size(); i++)
			if (parent->children[i] == this)
				parent->children.erase(parent->children.begin() + i);
	parent = new_parent;
	if (new_parent)
		new_parent->children.push_back(this);
	return;
}
cl_base* cl_base::get_parent()
{
	return this->parent;
}

void cl_base::print()
{
	if (children.size())
	{
		cout << endl << get_name();
		for (int i = 0; i < children.size(); i++)
			cout << "  " << children[i]->get_name();
		for (int i = 0; i < children.size(); i++)
			children[i]->print();
	}
	return;
}



void cl_base::print_new(string depth)
{
	cout << endl << depth << get_name();
	for (auto child : children)
		child->print_new(depth + "    ");
}
void cl_base::print_new_state(string depth)
{
	cout << endl << depth << get_name();
	if (!state)
		cout << " is not ready";
	else
		cout << " is ready";
	for (cl_base* child : children)
		child->print_new_state(depth + "    ");
}
cl_base* cl_base::find_object_by_name(string name)
{
	if (this->name == name)
		return this;
	else
	{
		for (cl_base* child : children)
		{
			cl_base* result = child->find_object_by_name(name);
			if (result)
				return result;
		}
		return nullptr;
	}
}
int cl_base::get_state()
{
	return this->state;
}
bool cl_base::set_state(int state)
{
	if (!state)
		if ((parent && parent->get_state() == 0) || get_state() == 0)
			return true;
		else
		{
			for (cl_base* child : children)
				child->set_state(0);
			this->state = 0;
			return true;
		}
	else
		if (parent && parent->get_state() == 0)
			return false;
		else
		{
			this->state = state;
			return true;
		}
}

void cl_base::set_on(cl_base* root)
{
	if (root == nullptr)
		return;
	root->set_state(1);
	for (cl_base* child : root->get_children())
		if (child == nullptr)
			return;
		else
			set_on(child);

}

vector<cl_base*> cl_base::get_children()
{
	return this->children;
}

cl_base* cl_base::find_object_by_coord(cl_base* current_object, cl_base* root_object, string coord)
{
	if (coord == "")
		return nullptr;

	if (coord == ".")
		return current_object;

	if (coord == "/")
		return root_object;

	if (coord[0] == '/' && coord[1] == '/')
	{
		string name = "";

		for (int i = 2; i < coord.length(); ++i)
			name += coord[i];

		return root_object->find_object_by_name(name);
	}

	cl_base* now_object;
	string name = "";
	int i;

	if (coord[0] == '/')
	{
		now_object = root_object;
		i = 1;
	}
	else
	{
		now_object = current_object;
		i = 0;
	}

	for (; i < coord.length(); ++i)
	{
		if (coord[i] == '/' || i == coord.length() - 1)
		{
			if (i == coord.length() - 1)
				name += coord[i];

			if (name == ".")
				continue;

			bool found = false;

			for (cl_base* pointer : now_object->get_children())
				if (pointer->get_name() == name)
				{
					now_object = pointer;
					name = "";
					found = true;
				}

			if (!found)
				return nullptr;
		}
		else
			name += coord[i];

	}
	return now_object;
}

void cl_base::set_connect(TYPE_SIGNAL p_signal,
	cl_base* p_object,
	TYPE_HANDLER p_ob_hendler)
{
	o_sh* p_value;
	for (int i = 0; i < connects.size(); i++)
		if (connects[i]->p_signal == p_signal &&
			connects[i]->p_cl_base == p_object &&
			connects[i]->p_handler == p_ob_hendler)
			return;
	p_value = new o_sh(p_object, p_signal, p_ob_hendler);
	connects.push_back(p_value);
}

void cl_base::delete_connect(TYPE_SIGNAL p_signal,
	cl_base* p_object,
	TYPE_HANDLER p_ob_hendler)
{
	for (int i = 0; i < connects.size(); i++)
		if (connects[i]->p_signal == p_signal &&
			connects[i]->p_cl_base == p_object &&
			connects[i]->p_handler == p_ob_hendler)
		{
			connects.erase(connects.begin() + i);
			return;
		}

}

void cl_base::emit_signal(TYPE_SIGNAL p_signal, string& s_command)
{
	(this->*p_signal)(s_command);
	for (int i = 0; i < connects.size(); i++)
		if (connects[i]->p_signal == p_signal && connects[i]->p_cl_base->get_state() == 1)
			((connects[i]->p_cl_base)->*(connects[i]->p_handler))(s_command);
}

string cl_base::coord(string path)
{
	if (parent)
		return parent->coord("/" + get_name() + path);
	else
		path == "" ? path = "/" : path;
	return path;
}

void cl_base::set_coffee_change(vector<pair<string, int> > coffee_types, pair<int, int> change)
{
	this->coffee_types = coffee_types;
	this->change = change;
	return;
}

void cl_base::set_money(int money)
{
	this->money = money;
	return;
}

int cl_base::get_money()
{
	return this->money;
}

vector<pair<string, int> > cl_base::get_coffee_types()
{
	return this->coffee_types;
}

pair<int, int> cl_base::get_change()
{
	return this->change;
}

void cl_base::set_change(pair<int, int> change)
{
	this->change = change;
	return;
}
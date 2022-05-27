#ifndef __CL_2_H__
#define __CL_2_H__
#include "cl_base.h"
class cl_2 : public cl_base
{
public:
	cl_2(string name, cl_base* parent) : cl_base(name, parent) {};

	void handler(string msg);
	void signal(string& msg);
};
#endif
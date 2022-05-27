#ifndef __CL_6_H__
#define __CL_6_H__
#include "cl_base.h"
class cl_6 : public cl_base
{
public:
	cl_6(string name, cl_base* parent) : cl_base(name, parent) {};
	
	void handler(string msg);
	void signal(string& msg);
};
#endif
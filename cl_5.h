#ifndef __CL_5_H__
#define __CL_5_H__
#include "cl_base.h"
class cl_5 : public cl_base
{
public:
	cl_5(string name, cl_base* parent) : cl_base(name, parent) {};
	
	void handler(string msg);
	void signal(string& msg);
};
#endif
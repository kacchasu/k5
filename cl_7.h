#ifndef __CL_7_H__
#define __CL_7_H__
#include "cl_base.h"
class cl_7 : public cl_base
{
public:
	cl_7(string name, cl_base* parent) : cl_base(name, parent) {};
	
	void handler(string msg);
	void signal(string& msg);
};
#endif
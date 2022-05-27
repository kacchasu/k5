#ifndef __CL_3_H__
#define __CL_3_H__
#include "cl_base.h"
class cl_3 : public cl_base
{
public:
	cl_3(string name, cl_base* parent) : cl_base(name, parent) {};

	void handler(string msg);
	void signal(string& msg);
};
#endif
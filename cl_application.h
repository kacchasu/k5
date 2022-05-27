#ifndef __CL_APPLICATION_H__
#define __CL_APPLICATION_H__
#include "cl_base.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"
#include "cl_7.h"
class cl_application : public cl_base
{
public:
	cl_application(string name = "") : cl_base(name) {};

	void signal(string& msg);

	void build_tree_objects();
	int exec_app();

};
#endif
#include "cl_application.h"

int main()
{
	cl_application application;

	application.build_tree_objects();

	return application.exec_app();
}

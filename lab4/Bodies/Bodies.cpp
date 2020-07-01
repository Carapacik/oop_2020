#include "Controller.h"

using namespace std;

int main()
{
	vector<shared_ptr<CBody>> bodies;
	Controller(bodies, cin, cout);
	return 0;
}
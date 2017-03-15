
#include "core/simulation/Coordinator.h"

#include "DevsSlide.h"


int main() {
	cout << "Starting DevsSlide" << endl;
	DevsSlide dataCenter("DevsSlide", "data/wkload/test-10job-alloc/alloc/slurm/joblogger-default-slurm.txt");
	Coordinator coordinator(&dataCenter);
	coordinator.initialize();
	coordinator.simulate((long int)100000000);
	coordinator.exit();
	return 0;
} 

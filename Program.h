#include "Statement.h"
#include "Tank.h"

class Program {
	public:
		Program();
		void execute();
		bool isFinished();
		void load(std::string filename);
	private:
		Tank tank;
		bool finish;
		std::vector<Statement> searching;
		int ipSearch;
};


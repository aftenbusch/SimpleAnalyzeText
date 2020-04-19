#include <iostream>
#include <string>
#include <vector>

#include "textanalysis.h"

using namespace std;

int main(int argc, char *argv[])
{
	bool debug_mode{false};
	
	// read in and check command line arguments:
	vector<string> commandLineArguments{};
	for( int i=0; i<argc; ++i )
	{
		commandLineArguments.push_back(argv[i]);
	}
	if( argc < 2 || commandLineArguments[1] == "--help" )
	{
		cout << "Usage: " << commandLineArguments[0] << " <input file>\n";
		cout << "       --help  Displays this message.\n";
	}
	if(debug_mode)
	{
		cout << "*** debug: ";
		for( const auto &a : commandLineArguments )
			cout << a << " ";
		cout << "\n";
	}

	// perform the text analysis on the input:
	string inputFile = commandLineArguments[1];
	TextAnalysis textAnalysis{inputFile};
	
	textAnalysis.outputAnalysis();
	
	return 0;
}

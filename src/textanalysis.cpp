#include "textanalysis.h"

#include <cctype>
#include <fstream>
#include <stdexcept>
#include <sstream>

TextAnalysis::TextAnalysis( string infile )
 : originalText{}, cleanedText{}, words{}, wordCount{}
{
	ifstream input;
	input.open( infile );
	if(!input.is_open()) {
		string errorMessage = "Error in TextAnalysis(): " + infile + " could not be opened";
		throw( runtime_error{ errorMessage } );
	}
	
	string line{};
	while( getline( input, line ) )
	{
		originalText.push_back( line );
	}
	
	input.close();
}

void TextAnalysis::outputAnalysis( ostream &output )
{
	vector<string> cleanedText{};
	for( size_t i=0; i<originalText.size(); ++i )
	{
		string line = originalText[i];
		
		// convert line to all lowercase characters:
		for( auto &c : line )
			c=tolower(c);
		
		// copy line characters less punctuation into new string:
		string cleanedLine{};
		for( auto c : line ) {
			if( !ispunct(c) )
				cleanedLine.push_back(c);
		}
		
		cleanedText.push_back( cleanedLine );
		
		// decompose each cleanedLine into words:
		istringstream inputString( cleanedLine );
		string word{};
		while( inputString >> word ) {
			words.insert( word );
		}
	}
	// count the occurrence of each word and store in wordCount map:
	for( auto w : words )
		wordCount[ w ]++;
		
	// output the results:
	output << "Results:\n\n";
	output << "  number of lines: " << originalText.size() << "\n";
	output << "  number of unique words: " << wordCount.size() << "\n";
	output << "  word count -\n\n";
	for( const auto &p : wordCount )
		output << "    " << p.first << " : " << p.second << "\n";
}

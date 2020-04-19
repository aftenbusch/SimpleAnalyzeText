#ifndef TEXTANALYSIS_H
#define TEXTANALYSIS_H

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class TextAnalysis
{
	public:

		explicit TextAnalysis( string infile );
		void outputAnalysis( ostream &output = cout );

	private:

		vector<string> originalText;
		vector<string> cleanedText;
		multiset<string> words;
		map<string,int> wordCount;
};

#endif // TEXTANALYSIS_H

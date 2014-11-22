//probably don't need all this shit
#include <iostream>
#include <cstdio>
#include "rapidjson/include/rapidjson/rapidjson.h"
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/reader.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;
using namespace rapidjson;

int main() {
	const int SPACING_COLUMN = 8;

	//Read crap into a file
	std::ifstream infile("complaintsbyrace.json");
	std::stringstream strStream;
	strStream << infile.rdbuf();
	std::string json = strStream.str();
	//std::cout << json<<endl;

	
	//Do stuff with json
	Document d;
	d.Parse<0>(json.c_str()).HasParseError();
	const Value& complaints = d["data"];
	//assert(complaints.IsArray());
	//std::cout << "Colour:\tHex:" <<endl;
	//capture the size of the largest first array
	float largestGroup = 0;
	for (SizeType i = 0; i < complaints.Size(); i++)
	{
		if (complaints[i][8].GetStringLength() > largestGroup)
		{
			largestGroup = complaints[i][8].GetStringLength();
		}
	}
	//Print the useful context for the user
	std::cout << "Complaints about the police department of San Francisco by race." << endl << endl;
	std::cout << "Race:" << std::setw(largestGroup - 5 + SPACING_COLUMN) << "2004:" << std::setw(SPACING_COLUMN) << "2005:" << std::setw(SPACING_COLUMN)
		<< "2006:" << std::setw(SPACING_COLUMN) << "2007:" << std::setw(SPACING_COLUMN) << "2008:" << std::setw(SPACING_COLUMN) << "2009:" << endl << endl;
	for (SizeType i = 0; i < complaints.Size(); i++)
	{
		//We do not want to print anything before the "/n" 
		bool bUsefulInfo = false;
		bool bIsGroupName = false;
		for (SizeType y = 0; y < complaints[i].Size(); y++)
		{
			if (bUsefulInfo && complaints[i][y].IsString() == 1 )
			{
				std::cout << complaints[i][y].GetString();
				if (bIsGroupName)
				{
					int hi = largestGroup - complaints[i][y].GetStringLength();
					std::cout <<std::setw(largestGroup - complaints[i][y].GetStringLength() + SPACING_COLUMN);
					bIsGroupName = false;
				}
				else
				{
					std::cout << std::setw(SPACING_COLUMN);
				}
			}
			
			if (!bUsefulInfo && complaints[i][y].IsString())
			{
				std::string jsonString(complaints[i][y].GetString());
				if (jsonString.compare("{\n}") == 0)
				{
					bUsefulInfo = true;
					bIsGroupName = true;
				}

			}
		}
		std::cout << "" <<endl;
		/*
		std::cout << complaints[i]["colorName"].GetString();
		std::cout << "\t";
		std::cout << complaints[i]["hexValue"].GetString()<<endl;
		*/
	}
	//Use this to store information and eventually print it
	//std::vector<string> colourInformation;
	
	//StringBuffer buffer;
 //   Writer<StringBuffer> writer(buffer);
 //   d.Accept(writer);
	//std::cout << colours[0]["colorName"].GetString();
	cin.ignore();

    return 0;
}

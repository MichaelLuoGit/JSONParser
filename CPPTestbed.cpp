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
using namespace std;
using namespace rapidjson;

int main() {
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
	for (SizeType i = 0; i < complaints.Size(); i++)
	{
		//We do not want to print anything before the "/n" 
		bool bUsefulInfo = false;
		for (SizeType y = 0; y < complaints[i].Size(); y++)
		{
			if (bUsefulInfo && complaints[i][y].IsString() == 1 )
			{
				cout << complaints[i][y].GetString();
				cout << "" <<endl;
			}
			
			if (!bUsefulInfo && complaints[i][y].IsString())
			{
				std::string jsonString(complaints[i][y].GetString());
				if (jsonString.compare("{\n}") == 0)
				{
					bUsefulInfo = true;
				}

			}
		}
		
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

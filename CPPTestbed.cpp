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
	std::ifstream infile("colours.json");
	std::stringstream strStream;
	strStream << infile.rdbuf();
	std::string json = strStream.str();
	std::cout << json<<endl;

	
	//Do stuff with json
	Document d;
	d.Parse<0>(json.c_str()).HasParseError();
	const Value& colours = d["colorsArray"];
	assert(colours.IsArray());
	std::cout << "Colour:\tHex:" <<endl;
	for (SizeType i = 0; i < colours.Size(); i++)
	{
		std::cout << colours[i]["colorName"].GetString();
		std::cout << "\t";
		std::cout << colours[i]["hexValue"].GetString()<<endl;
	}
	//Use this to store information and eventually print it
	//std::vector<string> colourInformation;
	
	//StringBuffer buffer;
 //   Writer<StringBuffer> writer(buffer);
 //   d.Accept(writer);
	//std::cout << colours[0]["colorName"].GetString();
	_sleep(10000);
    return 0;
}

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
using namespace std;
using namespace rapidjson;

int main() {
	//Read crap into a file
	std::ifstream infile("colours.json");
	std::stringstream strStream;
	strStream << infile.rdbuf();
	std::string json = strStream.str();
	std::cout << json;

	//Do stuff with json
	Document d;
	d.Parse<0>(json.c_str()).HasParseError();

	_sleep(10000);
    return 0;
}

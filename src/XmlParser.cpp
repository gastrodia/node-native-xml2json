#include <iostream>
#include "tinyxml/tinyxml2.h"
#include "xml2json/xml2json.hpp"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
using namespace tinyxml2;

int readxml1(){
    XMLDocument doc;
    doc.LoadFile("src/resource/test.xml");
    const char* content= doc.FirstChildElement( "Hello" )->GetText();
    printf( "Hello,%s", content );
}

void readxml2()
{
    XMLDocument doc;
    doc.LoadFile("src/resource/test2.xml");
    XMLElement *scene=doc.RootElement();
    XMLElement *surface=scene->FirstChildElement("node");
    while (surface)
    {
        XMLElement *surfaceChild=surface->FirstChildElement();
        const char* content;
        const XMLAttribute *attributeOfSurface = surface->FirstAttribute();
        cout<< attributeOfSurface->Name() << ":" << attributeOfSurface->Value() << endl;
        while(surfaceChild)
        {
            content=surfaceChild->GetText();
            surfaceChild=surfaceChild->NextSiblingElement();
            cout<<content<<endl;
        }
        surface=surface->NextSiblingElement();
    }
}

int readxml3()
{
	static const char* xml =
			"<?xml version=\"1.0\"?>"
			"<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
			"<PLAY>"
			"<TITLE>A Midsummer Night's Dream</TITLE>"
			"</PLAY>";

		XMLDocument doc;
		doc.Parse( xml );

		XMLElement* titleElement = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" );
		const char* title = titleElement->GetText();
		printf( "Name of play (1): %s\n", title );

		XMLText* textNode = titleElement->FirstChild()->ToText();
		title = textNode->Value();
		printf( "Name of play (2): %s\n", title );

		return doc.ErrorID();
}

void xml2json1(){
	string xml_str, json_str;
	ifstream inf;
	ostringstream oss;
	inf.open("src/resource/test2.xml");
	oss << inf.rdbuf();
	xml_str = oss.str();
	inf.close();
	json_str = xml2json(xml_str.c_str());
	cout << json_str << endl;
}

void xml2json2(){
	static const string xml_str =
				"<?xml version=\"1.0\"?>"
				"<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
				"<PLAY>"
				"<TITLE>A Midsummer Night's Dream</TITLE>"
				"</PLAY>";
	string json_str = xml2json(xml_str.c_str());
	cout << json_str << endl;
}


int main()
{
    xml2json1();
    xml2json2();
    return 0;
}

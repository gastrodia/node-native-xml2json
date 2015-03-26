var xmlParser = require('./index');


var xml_str = "<?xml version=\"1.0\"?>"
+ "<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
+ "<PLAY>"
+ "<TITLE>Hello World 0.0</TITLE>"
+ "</PLAY>";

console.log(xmlParser.xml2json(xml_str));
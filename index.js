var xmlParser = require('./build/Release/xml_parser.node');

exports.xml2json = function(xml_str){
  var json_str = xmlParser.xml2json(xml_str);
  var json = null;
  try{
    json = JSON.parse(json_str);
  }catch(e){
    console.log('after call native xml2json parse json_str error! maybe it not a json string -->',json_str);
    console.log(e);
  }

  return json;
}


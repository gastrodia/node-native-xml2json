#include <node.h>
#include <v8.h>
#include <nan.h>
#include <unistd.h>
#include <string>
#include "xml2json/xml2json.hpp"

using namespace v8;
using namespace std;


// Handle<Value> ReadXMLStrAsJSONStr(const Arguments& args) {
//   HandleScope scope;
//
// char *c_arg, *ret;
//
//  if (args.Length() < 1) {
//    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
//    return scope.Close(Undefined());
//  }
//
//  c_arg = *v8::String::Utf8Value(args[0]->ToString());
//
//  ret = c_arg; //do_sqlsig(c_arg);
//
//   string json_str = xml2json(ret);
//
//   return scope.Close(String::New(json_str.c_str()));
// }

NAN_METHOD(ReadXMLFunction) {
    NanScope();

    NanUtf8String* location = new NanUtf8String(args[0]);

    string json_str = xml2json(location->operator*());
    NanReturnValue(json_str);
}

void init(Handle<Object> exports) {
  //NODE_SET_METHOD(target, "xml2json", ReadXMLStrAsJSONStr);
  exports->Set(NanNew<String>("xml2json"),
    NanNew<FunctionTemplate>(ReadXMLFunction)->GetFunction());
}

NODE_MODULE(xml_parser, init);

#include <node.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NLPIR.h"

namespace demo {

using v8::Exception;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

  void init(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    // 此处硬编码，与目录Data的相对目录
    // 1表示使用uft8编码
    NLPIR_Init("./", 1);
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "ok"));
  }

  void wordFreqStat(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() != 1) {
      // Throw an Error that is passed back to JavaScript
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong number of arguments")));
      return;
    }

    // Check the argument types
    if (!args[0]->IsString()) {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "String type needed !")));
      return;
    }

    String::Utf8Value txt(args[0]);
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, NLPIR_WordFreqStat(*txt)));
  }


  void Init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "init", init);
    NODE_SET_METHOD(exports, "wordFreqStat", wordFreqStat);
  }

  NODE_MODULE(ictclas, Init)

}  // namespace demo

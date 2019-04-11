#ifndef ADAPTER_H
#define ADAPTER_H

#include <node.h>
#include <node_object_wrap.h>
#include "lib/bitalino.h"

namespace adapter {

class BITalinoAdapter : public node::ObjectWrap {
 public:
  static void Init(v8::Local<v8::Object> exports);

 private:
  explicit BITalinoAdapter(const char* address);
  ~BITalinoAdapter();

  static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void Version(const v8::FunctionCallbackInfo<v8::Value>& args);
  static v8::Persistent<v8::Function> constructor;
  const char* address_;
  BITalino adaptee;
};

}

#endif
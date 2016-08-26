#include <node.h>
#include <v8.h>

using namespace v8;

void Substract(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if(args.Length()< 2){
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong Number of arguments")));
    return;
  }

  if(!args[0]->IsNumber() || !args[1]->IsNumber()){
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  double value = args[0]->NumberValue() - args[1]->NumberValue();
  Local<Number> num = Number::New(isolate,value);

  args.GetReturnValue().Set(num);
}

void Init(v8::Local<v8::Object> exports) {
  
NODE_SET_METHOD(exports, "substract", Substract);
}

NODE_MODULE(addon, Init) //Entry point for Node Addon- must match with the name in "target" in binding.gyp


#include <nan.h>

void Substract(const Nan::FunctionCallbackInfo<v8::Value>& values) {
  if(values.Length() < 2) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  if(!values[0]->IsNumber() || !values[1]->IsNumber()){
    Nan::ThrowTypeError("Wrong arguments");
    return;
  }

  double arg0 = values[0]->NumberValue();
  double arg1 = values[1]->NumberValue();
  v8::Local<v8::Number> num = Nan::New(arg0 - arg1);

  values.GetReturnValue().Set(num);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("substract").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(Substract)->GetFunction());
}

NODE_MODULE(addon,Init);

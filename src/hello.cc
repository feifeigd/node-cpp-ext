
#include <node.h>
#include <v8.h>

using namespace v8;

void SayHello(FunctionCallbackInfo<Value> const& args) {
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);
	args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello World"));
}

void Init_Hello(Handle<Object> exports) {
	NODE_SET_METHOD(exports, "sayHello", SayHello);
}
NODE_MODULE(hello, Init_Hello);

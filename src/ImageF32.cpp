
#include <basic/ImageF32.h>


namespace vnx {

void read(TypeInput& in, ::basic::ImageF32& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

void write(TypeOutput& out, const ::basic::ImageF32& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

void read(std::istream& in, ::basic::ImageF32& value) {
	value.read(in);
}

void write(std::ostream& out, const ::basic::ImageF32& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::basic::ImageF32& value) {
	value.accept(visitor);
}


} // vnx

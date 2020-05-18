
// AUTO GENERATED by vnxcppcodegen

#include <automy/basic/package.hxx>
#include <automy/basic/Scalar.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>


namespace automy {
namespace basic {


const vnx::Hash64 Scalar::VNX_TYPE_HASH(0xc0b8bdb61e0ca70eull);
const vnx::Hash64 Scalar::VNX_CODE_HASH(0xa6723f13a3a352bdull);

vnx::Hash64 Scalar::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* Scalar::get_type_name() const {
	return "automy.basic.Scalar";
}
const vnx::TypeCode* Scalar::get_type_code() const {
	return automy::basic::vnx_native_type_code_Scalar;
}

std::shared_ptr<Scalar> Scalar::create() {
	return std::make_shared<Scalar>();
}

std::shared_ptr<vnx::Value> Scalar::clone() const {
	return std::make_shared<Scalar>(*this);
}

void Scalar::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Scalar::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Scalar::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = automy::basic::vnx_native_type_code_Scalar;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, time);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, key);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, value);
	_visitor.type_end(*_type_code);
}

void Scalar::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"time\": "; vnx::write(_out, time);
	_out << ", \"key\": "; vnx::write(_out, key);
	_out << ", \"value\": "; vnx::write(_out, value);
	_out << "}";
}

void Scalar::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "key") {
			vnx::from_string(_entry.second, key);
		} else if(_entry.first == "time") {
			vnx::from_string(_entry.second, time);
		} else if(_entry.first == "value") {
			vnx::from_string(_entry.second, value);
		}
	}
}

vnx::Object Scalar::to_object() const {
	vnx::Object _object;
	_object["time"] = time;
	_object["key"] = key;
	_object["value"] = value;
	return _object;
}

void Scalar::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "key") {
			_entry.second.to(key);
		} else if(_entry.first == "time") {
			_entry.second.to(time);
		} else if(_entry.first == "value") {
			_entry.second.to(value);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Scalar& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Scalar& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Scalar::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0xc0b8bdb61e0ca70eull));
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Scalar::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "automy.basic.Scalar";
	type_code->type_hash = vnx::Hash64(0xc0b8bdb61e0ca70eull);
	type_code->code_hash = vnx::Hash64(0xa6723f13a3a352bdull);
	type_code->is_class = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Scalar>(); };
	type_code->methods.resize(0);
	type_code->fields.resize(3);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "time";
		field.code = {8};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "key";
		field.code = {12, 5};
	}
	{
		vnx::TypeField& field = type_code->fields[2];
		field.name = "value";
		field.code = {10};
	}
	type_code->build();
	return type_code;
}


} // namespace automy
} // namespace basic


namespace vnx {

void read(TypeInput& in, ::automy::basic::Scalar& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code) {
		throw std::logic_error("read(): type_code == 0");
	}
	if(code) {
		switch(code[0]) {
			case CODE_STRUCT: type_code = type_code->depends[code[1]]; break;
			case CODE_ALT_STRUCT: type_code = type_code->depends[vnx::flip_bytes(code[1])]; break;
			default: vnx::skip(in, type_code, code); return;
		}
	}
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		{
			const vnx::TypeField* const _field = type_code->field_map[0];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.time, _field->code.data());
			}
		}
		{
			const vnx::TypeField* const _field = type_code->field_map[2];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.value, _field->code.data());
			}
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.key, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::automy::basic::Scalar& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = automy::basic::vnx_native_type_code_Scalar;
		out.write_type_code(type_code);
		vnx::write_class_header<::automy::basic::Scalar>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(16);
	vnx::write_value(_buf + 0, value.time);
	vnx::write_value(_buf + 8, value.value);
	vnx::write(out, value.key, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::automy::basic::Scalar& value) {
	value.read(in);
}

void write(std::ostream& out, const ::automy::basic::Scalar& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::automy::basic::Scalar& value) {
	value.accept(visitor);
}

} // vnx

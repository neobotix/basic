
// AUTO GENERATED by vnxcppcodegen

#include <automy/basic/package.hxx>
#include <automy/basic/Trigger.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>


namespace automy {
namespace basic {


const vnx::Hash64 Trigger::VNX_TYPE_HASH(0xae5ff291c2d59cceull);
const vnx::Hash64 Trigger::VNX_CODE_HASH(0x7cc3f18cb3878861ull);

vnx::Hash64 Trigger::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* Trigger::get_type_name() const {
	return "automy.basic.Trigger";
}
const vnx::TypeCode* Trigger::get_type_code() const {
	return automy::basic::vnx_native_type_code_Trigger;
}

std::shared_ptr<Trigger> Trigger::create() {
	return std::make_shared<Trigger>();
}

std::shared_ptr<vnx::Value> Trigger::clone() const {
	return std::make_shared<Trigger>(*this);
}

void Trigger::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Trigger::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Trigger::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = automy::basic::vnx_native_type_code_Trigger;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, time);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, seq_num);
	_visitor.type_end(*_type_code);
}

void Trigger::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"time\": "; vnx::write(_out, time);
	_out << ", \"seq_num\": "; vnx::write(_out, seq_num);
	_out << "}";
}

void Trigger::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "seq_num") {
			vnx::from_string(_entry.second, seq_num);
		} else if(_entry.first == "time") {
			vnx::from_string(_entry.second, time);
		}
	}
}

vnx::Object Trigger::to_object() const {
	vnx::Object _object;
	_object["time"] = time;
	_object["seq_num"] = seq_num;
	return _object;
}

void Trigger::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "seq_num") {
			_entry.second.to(seq_num);
		} else if(_entry.first == "time") {
			_entry.second.to(time);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Trigger& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Trigger& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Trigger::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0xae5ff291c2d59cceull));
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Trigger::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "automy.basic.Trigger";
	type_code->type_hash = vnx::Hash64(0xae5ff291c2d59cceull);
	type_code->code_hash = vnx::Hash64(0x7cc3f18cb3878861ull);
	type_code->is_class = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Trigger>(); };
	type_code->methods.resize(0);
	type_code->fields.resize(2);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "time";
		field.code = {8};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.name = "seq_num";
		field.code = {8};
	}
	type_code->build();
	return type_code;
}


} // namespace automy
} // namespace basic


namespace vnx {

void read(TypeInput& in, ::automy::basic::Trigger& value, const TypeCode* type_code, const uint16_t* code) {
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
			const vnx::TypeField* const _field = type_code->field_map[1];
			if(_field) {
				vnx::read_value(_buf + _field->offset, value.seq_num, _field->code.data());
			}
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::automy::basic::Trigger& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = automy::basic::vnx_native_type_code_Trigger;
		out.write_type_code(type_code);
		vnx::write_class_header<::automy::basic::Trigger>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(16);
	vnx::write_value(_buf + 0, value.time);
	vnx::write_value(_buf + 8, value.seq_num);
}

void read(std::istream& in, ::automy::basic::Trigger& value) {
	value.read(in);
}

void write(std::ostream& out, const ::automy::basic::Trigger& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::automy::basic::Trigger& value) {
	value.accept(visitor);
}

} // vnx

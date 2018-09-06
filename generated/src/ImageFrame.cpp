
// AUTO GENERATED by vnxcppcodegen

#include <basic/package.hxx>
#include <basic/ImageFrame.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>


namespace basic {


const vnx::Hash64 ImageFrame::VNX_TYPE_HASH(0x281627f6740afbb2ull);
const vnx::Hash64 ImageFrame::VNX_CODE_HASH(0x7ee39bedf7a3b1feull);

vnx::Hash64 ImageFrame::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* ImageFrame::get_type_name() const {
	return "basic.ImageFrame";
}

std::shared_ptr<ImageFrame> ImageFrame::create() {
	return std::make_shared<ImageFrame>();
}

std::shared_ptr<vnx::Value> ImageFrame::clone() const {
	return std::make_shared<ImageFrame>(*this);
}

void ImageFrame::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void ImageFrame::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void ImageFrame::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = get_type_code();
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, time);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, frame);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, format);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, properties);
	_visitor.type_end(*_type_code);
}

void ImageFrame::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"time\": "; vnx::write(_out, time);
	_out << ", \"frame\": "; vnx::write(_out, frame);
	_out << ", \"format\": "; vnx::write(_out, format);
	_out << ", \"properties\": "; vnx::write(_out, properties);
	_out << "}";
}

void ImageFrame::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "format") {
			vnx::from_string(_entry.second, format);
		} else if(_entry.first == "frame") {
			vnx::from_string(_entry.second, frame);
		} else if(_entry.first == "properties") {
			vnx::from_string(_entry.second, properties);
		} else if(_entry.first == "time") {
			vnx::from_string(_entry.second, time);
		}
	}
}

vnx::Object ImageFrame::to_object() const {
	vnx::Object _object;
	_object["time"] = time;
	_object["frame"] = frame;
	_object["format"] = format;
	_object["properties"] = properties;
	return _object;
}

void ImageFrame::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "format") {
			_entry.second.to(format);
		} else if(_entry.first == "frame") {
			_entry.second.to(frame);
		} else if(_entry.first == "properties") {
			_entry.second.to(properties);
		} else if(_entry.first == "time") {
			_entry.second.to(time);
		}
	}
}

std::ostream& operator<<(std::ostream& _out, const ImageFrame& _value) {
	_value.write(_out);
	return _out;
}

std::istream& operator>>(std::istream& _in, ImageFrame& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* ImageFrame::get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0x281627f6740afbb2ull));
	if(!type_code) {
		type_code = vnx::register_type_code(create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> ImageFrame::create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "basic.ImageFrame";
	type_code->type_hash = vnx::Hash64(0x281627f6740afbb2ull);
	type_code->code_hash = vnx::Hash64(0x7ee39bedf7a3b1feull);
	type_code->is_class = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<ImageFrame>(); };
	type_code->fields.resize(4);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "time";
		field.code = {8};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "frame";
		field.code = {12, 5};
	}
	{
		vnx::TypeField& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "format";
		field.code = {12, 5};
	}
	{
		vnx::TypeField& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "properties";
		field.code = {13, 4, 12, 5, 17};
	}
	type_code->build();
	return type_code;
}


} // namespace basic


namespace vnx {

void read(TypeInput& in, ::basic::ImageFrame& value, const TypeCode* type_code, const uint16_t* code) {
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
	{
		const vnx::TypeField* const _field = type_code->field_map[0];
		if(_field) {
			vnx::read_value(_buf + _field->offset, value.time, _field->code.data());
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.frame, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.format, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.properties, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::basic::ImageFrame& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::write_type_code<::basic::ImageFrame>(out);
		vnx::write_class_header<::basic::ImageFrame>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value.time);
	vnx::write(out, value.frame, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.format, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.properties, type_code, type_code->fields[3].code.data());
}

void read(std::istream& in, ::basic::ImageFrame& value) {
	value.read(in);
}

void write(std::ostream& out, const ::basic::ImageFrame& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::basic::ImageFrame& value) {
	value.accept(visitor);
}

} // vnx
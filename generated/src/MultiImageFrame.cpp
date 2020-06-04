
// AUTO GENERATED by vnxcppcodegen

#include <vnx/vnx.h>
#include <automy/basic/package.hxx>
#include <automy/basic/MultiImageFrame.hxx>
#include <automy/basic/ImageFrame.hxx>



namespace automy {
namespace basic {


const vnx::Hash64 MultiImageFrame::VNX_TYPE_HASH(0x5ee9279d2299dc0dull);
const vnx::Hash64 MultiImageFrame::VNX_CODE_HASH(0x22094641e7db27d4ull);

vnx::Hash64 MultiImageFrame::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* MultiImageFrame::get_type_name() const {
	return "automy.basic.MultiImageFrame";
}
const vnx::TypeCode* MultiImageFrame::get_type_code() const {
	return automy::basic::vnx_native_type_code_MultiImageFrame;
}

std::shared_ptr<MultiImageFrame> MultiImageFrame::create() {
	return std::make_shared<MultiImageFrame>();
}

std::shared_ptr<vnx::Value> MultiImageFrame::clone() const {
	return std::make_shared<MultiImageFrame>(*this);
}

void MultiImageFrame::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void MultiImageFrame::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void MultiImageFrame::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = automy::basic::vnx_native_type_code_MultiImageFrame;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, time);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, frame);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, format);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, properties);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, frames);
	_visitor.type_end(*_type_code);
}

void MultiImageFrame::write(std::ostream& _out) const {
	_out << "{\"__type\": \"automy.basic.MultiImageFrame\"";
	_out << ", \"time\": "; vnx::write(_out, time);
	_out << ", \"frame\": "; vnx::write(_out, frame);
	_out << ", \"format\": "; vnx::write(_out, format);
	_out << ", \"properties\": "; vnx::write(_out, properties);
	_out << ", \"frames\": "; vnx::write(_out, frames);
	_out << "}";
}

void MultiImageFrame::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "format") {
			vnx::from_string(_entry.second, format);
		} else if(_entry.first == "frame") {
			vnx::from_string(_entry.second, frame);
		} else if(_entry.first == "frames") {
			vnx::from_string(_entry.second, frames);
		} else if(_entry.first == "properties") {
			vnx::from_string(_entry.second, properties);
		} else if(_entry.first == "time") {
			vnx::from_string(_entry.second, time);
		}
	}
}

vnx::Object MultiImageFrame::to_object() const {
	vnx::Object _object;
	_object["time"] = time;
	_object["frame"] = frame;
	_object["format"] = format;
	_object["properties"] = properties;
	_object["frames"] = frames;
	return _object;
}

void MultiImageFrame::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "format") {
			_entry.second.to(format);
		} else if(_entry.first == "frame") {
			_entry.second.to(frame);
		} else if(_entry.first == "frames") {
			_entry.second.to(frames);
		} else if(_entry.first == "properties") {
			_entry.second.to(properties);
		} else if(_entry.first == "time") {
			_entry.second.to(time);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const MultiImageFrame& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, MultiImageFrame& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* MultiImageFrame::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> MultiImageFrame::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "automy.basic.MultiImageFrame";
	type_code->type_hash = vnx::Hash64(0x5ee9279d2299dc0dull);
	type_code->code_hash = vnx::Hash64(0x22094641e7db27d4ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->parents.resize(1);
	type_code->parents[0] = ::automy::basic::ImageFrame::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<MultiImageFrame>(); };
	type_code->fields.resize(5);
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
	{
		vnx::TypeField& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "frames";
		field.code = {12, 16};
	}
	type_code->build();
	return type_code;
}


} // namespace automy
} // namespace basic


namespace vnx {

void read(TypeInput& in, ::automy::basic::MultiImageFrame& value, const TypeCode* type_code, const uint16_t* code) {
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
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.frame, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.format, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.properties, type_code, _field->code.data()); break;
			case 4: vnx::read(in, value.frames, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::automy::basic::MultiImageFrame& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = automy::basic::vnx_native_type_code_MultiImageFrame;
		out.write_type_code(type_code);
		vnx::write_class_header<::automy::basic::MultiImageFrame>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value.time);
	vnx::write(out, value.frame, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.format, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.properties, type_code, type_code->fields[3].code.data());
	vnx::write(out, value.frames, type_code, type_code->fields[4].code.data());
}

void read(std::istream& in, ::automy::basic::MultiImageFrame& value) {
	value.read(in);
}

void write(std::ostream& out, const ::automy::basic::MultiImageFrame& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::automy::basic::MultiImageFrame& value) {
	value.accept(visitor);
}

} // vnx


// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_automy_basic_TransformPublisher_set_transform_return_HXX_
#define INCLUDE_automy_basic_TransformPublisher_set_transform_return_HXX_

#include <automy/basic/package.hxx>
#include <vnx/Value.h>


namespace automy {
namespace basic {

class TransformPublisher_set_transform_return : public ::vnx::Value {
public:
	
	
	typedef ::vnx::Value Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	vnx::Hash64 get_type_hash() const override;
	const char* get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	static std::shared_ptr<TransformPublisher_set_transform_return> create();
	std::shared_ptr<vnx::Value> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	friend std::ostream& operator<<(std::ostream& _out, const TransformPublisher_set_transform_return& _value);
	friend std::istream& operator>>(std::istream& _in, TransformPublisher_set_transform_return& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};


} // namespace automy
} // namespace basic

#endif // INCLUDE_automy_basic_TransformPublisher_set_transform_return_HXX_


// AUTO GENERATED by vnxcppcodegen

#include <automy/basic/package.hxx>
#include <automy/basic/TransformPublisherAsyncClient.hxx>
#include <automy/basic/Transform3D.hxx>
#include <automy/basic/TransformPublisher_set_transform.hxx>
#include <automy/basic/TransformPublisher_set_transform_return.hxx>
#include <vnx/Module.h>
#include <vnx/ModuleInterface_vnx_get_type_code.hxx>
#include <vnx/ModuleInterface_vnx_get_type_code_return.hxx>
#include <vnx/Object.hpp>

#include <vnx/vnx.h>


namespace automy {
namespace basic {

TransformPublisherAsyncClient::TransformPublisherAsyncClient(const std::string& service_name)
	:	AsyncClient::AsyncClient(vnx::Hash64(service_name))
{
}

TransformPublisherAsyncClient::TransformPublisherAsyncClient(vnx::Hash64 service_addr)
	:	AsyncClient::AsyncClient(service_addr)
{
}

uint64_t TransformPublisherAsyncClient::vnx_get_type_code(const std::function<void(::vnx::TypeCode)>& _callback, const std::function<void(const std::exception&)>& _error_callback) {
	auto _method = ::vnx::ModuleInterface_vnx_get_type_code::create();
	const auto _request_id = vnx_request(_method);
	vnx_queue_vnx_get_type_code[_request_id] = std::make_pair(_callback, _error_callback);
	vnx_num_pending++;
	return _request_id;
}

uint64_t TransformPublisherAsyncClient::set_transform(const std::shared_ptr<const ::automy::basic::Transform3D>& new_transform, const std::function<void()>& _callback, const std::function<void(const std::exception&)>& _error_callback) {
	auto _method = ::automy::basic::TransformPublisher_set_transform::create();
	_method->new_transform = new_transform;
	const auto _request_id = vnx_request(_method);
	vnx_queue_set_transform[_request_id] = std::make_pair(_callback, _error_callback);
	vnx_num_pending++;
	return _request_id;
}

std::vector<uint64_t> TransformPublisherAsyncClient::vnx_get_pending_ids() const {
	std::vector<uint64_t> _list;
	for(const auto& entry : vnx_queue_vnx_get_type_code) {
		_list.push_back(entry.first);
	}
	for(const auto& entry : vnx_queue_set_transform) {
		_list.push_back(entry.first);
	}
	return _list;
}

void TransformPublisherAsyncClient::vnx_purge_request(uint64_t _request_id, const std::exception& _ex) {
	{
		const auto _iter = vnx_queue_vnx_get_type_code.find(_request_id);
		if(_iter != vnx_queue_vnx_get_type_code.end()) {
			if(_iter->second.second) {
				_iter->second.second(_ex);
			}
			vnx_queue_vnx_get_type_code.erase(_iter);
			vnx_num_pending--;
		}
	}
	{
		const auto _iter = vnx_queue_set_transform.find(_request_id);
		if(_iter != vnx_queue_set_transform.end()) {
			if(_iter->second.second) {
				_iter->second.second(_ex);
			}
			vnx_queue_set_transform.erase(_iter);
			vnx_num_pending--;
		}
	}
}

void TransformPublisherAsyncClient::vnx_callback_switch(uint64_t _request_id, std::shared_ptr<const vnx::Value> _value) {
	const auto _type_hash = _value->get_type_hash();
	if(_type_hash == vnx::Hash64(0x9f4322ca83b0d1ull)) {
		auto _result = std::dynamic_pointer_cast<const ::vnx::ModuleInterface_vnx_get_type_code_return>(_value);
		if(!_result) {
			throw std::logic_error("TransformPublisherAsyncClient: !_result");
		}
		const auto _iter = vnx_queue_vnx_get_type_code.find(_request_id);
		if(_iter != vnx_queue_vnx_get_type_code.end()) {
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_vnx_get_type_code.erase(_iter);
			vnx_num_pending--;
			if(_callback) {
				_callback(_result->_ret_0);
			}
		} else {
			throw std::runtime_error("TransformPublisherAsyncClient: invalid return received");
		}
	}
	else if(_type_hash == vnx::Hash64(0x2798b4f2ee70b0a4ull)) {
		const auto _iter = vnx_queue_set_transform.find(_request_id);
		if(_iter != vnx_queue_set_transform.end()) {
			const auto _callback = std::move(_iter->second.first);
			vnx_queue_set_transform.erase(_iter);
			vnx_num_pending--;
			if(_callback) {
				_callback();
			}
		} else {
			throw std::runtime_error("TransformPublisherAsyncClient: invalid return received");
		}
	}
	else {
		throw std::runtime_error("TransformPublisherAsyncClient: unknown return type");
	}
}


} // namespace automy
} // namespace basic

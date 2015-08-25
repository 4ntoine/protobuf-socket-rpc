// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rpc.proto

#ifndef PROTOBUF_rpc_2eproto__INCLUDED
#define PROTOBUF_rpc_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf {
namespace socketrpc {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_rpc_2eproto();
void protobuf_AssignDesc_rpc_2eproto();
void protobuf_ShutdownFile_rpc_2eproto();

class Request;
class Response;

enum ErrorReason {
  BAD_REQUEST_DATA = 0,
  BAD_REQUEST_PROTO = 1,
  SERVICE_NOT_FOUND = 2,
  METHOD_NOT_FOUND = 3,
  RPC_ERROR = 4,
  RPC_FAILED = 5,
  SECURITY_ERROR = 10,
  INVALID_REQUEST_PROTO = 6,
  BAD_RESPONSE_PROTO = 7,
  UNKNOWN_HOST = 8,
  IO_ERROR = 9
};
bool ErrorReason_IsValid(int value);
const ErrorReason ErrorReason_MIN = BAD_REQUEST_DATA;
const ErrorReason ErrorReason_MAX = SECURITY_ERROR;
const int ErrorReason_ARRAYSIZE = ErrorReason_MAX + 1;

const ::google::protobuf::EnumDescriptor* ErrorReason_descriptor();
inline const ::std::string& ErrorReason_Name(ErrorReason value) {
  return ::google::protobuf::internal::NameOfEnum(
    ErrorReason_descriptor(), value);
}
inline bool ErrorReason_Parse(
    const ::std::string& name, ErrorReason* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ErrorReason>(
    ErrorReason_descriptor(), name, value);
}
// ===================================================================

class Request : public ::google::protobuf::Message {
 public:
  Request();
  virtual ~Request();

  Request(const Request& from);

  inline Request& operator=(const Request& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Request& default_instance();

  void Swap(Request* other);

  // implements Message ----------------------------------------------

  Request* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Request& from);
  void MergeFrom(const Request& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string service_name = 1;
  inline bool has_service_name() const;
  inline void clear_service_name();
  static const int kServiceNameFieldNumber = 1;
  inline const ::std::string& service_name() const;
  inline void set_service_name(const ::std::string& value);
  inline void set_service_name(const char* value);
  inline void set_service_name(const char* value, size_t size);
  inline ::std::string* mutable_service_name();
  inline ::std::string* release_service_name();
  inline void set_allocated_service_name(::std::string* service_name);

  // required string method_name = 2;
  inline bool has_method_name() const;
  inline void clear_method_name();
  static const int kMethodNameFieldNumber = 2;
  inline const ::std::string& method_name() const;
  inline void set_method_name(const ::std::string& value);
  inline void set_method_name(const char* value);
  inline void set_method_name(const char* value, size_t size);
  inline ::std::string* mutable_method_name();
  inline ::std::string* release_method_name();
  inline void set_allocated_method_name(::std::string* method_name);

  // required bytes request_proto = 3;
  inline bool has_request_proto() const;
  inline void clear_request_proto();
  static const int kRequestProtoFieldNumber = 3;
  inline const ::std::string& request_proto() const;
  inline void set_request_proto(const ::std::string& value);
  inline void set_request_proto(const char* value);
  inline void set_request_proto(const void* value, size_t size);
  inline ::std::string* mutable_request_proto();
  inline ::std::string* release_request_proto();
  inline void set_allocated_request_proto(::std::string* request_proto);

  // @@protoc_insertion_point(class_scope:protobuf.socketrpc.Request)
 private:
  inline void set_has_service_name();
  inline void clear_has_service_name();
  inline void set_has_method_name();
  inline void clear_has_method_name();
  inline void set_has_request_proto();
  inline void clear_has_request_proto();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* service_name_;
  ::std::string* method_name_;
  ::std::string* request_proto_;
  friend void  protobuf_AddDesc_rpc_2eproto();
  friend void protobuf_AssignDesc_rpc_2eproto();
  friend void protobuf_ShutdownFile_rpc_2eproto();

  void InitAsDefaultInstance();
  static Request* default_instance_;
};
// -------------------------------------------------------------------

class Response : public ::google::protobuf::Message {
 public:
  Response();
  virtual ~Response();

  Response(const Response& from);

  inline Response& operator=(const Response& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Response& default_instance();

  void Swap(Response* other);

  // implements Message ----------------------------------------------

  Response* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Response& from);
  void MergeFrom(const Response& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bytes response_proto = 1;
  inline bool has_response_proto() const;
  inline void clear_response_proto();
  static const int kResponseProtoFieldNumber = 1;
  inline const ::std::string& response_proto() const;
  inline void set_response_proto(const ::std::string& value);
  inline void set_response_proto(const char* value);
  inline void set_response_proto(const void* value, size_t size);
  inline ::std::string* mutable_response_proto();
  inline ::std::string* release_response_proto();
  inline void set_allocated_response_proto(::std::string* response_proto);

  // optional string error = 2;
  inline bool has_error() const;
  inline void clear_error();
  static const int kErrorFieldNumber = 2;
  inline const ::std::string& error() const;
  inline void set_error(const ::std::string& value);
  inline void set_error(const char* value);
  inline void set_error(const char* value, size_t size);
  inline ::std::string* mutable_error();
  inline ::std::string* release_error();
  inline void set_allocated_error(::std::string* error);

  // optional bool callback = 3 [default = false];
  inline bool has_callback() const;
  inline void clear_callback();
  static const int kCallbackFieldNumber = 3;
  inline bool callback() const;
  inline void set_callback(bool value);

  // optional .protobuf.socketrpc.ErrorReason error_reason = 4;
  inline bool has_error_reason() const;
  inline void clear_error_reason();
  static const int kErrorReasonFieldNumber = 4;
  inline ::protobuf::socketrpc::ErrorReason error_reason() const;
  inline void set_error_reason(::protobuf::socketrpc::ErrorReason value);

  // @@protoc_insertion_point(class_scope:protobuf.socketrpc.Response)
 private:
  inline void set_has_response_proto();
  inline void clear_has_response_proto();
  inline void set_has_error();
  inline void clear_has_error();
  inline void set_has_callback();
  inline void clear_has_callback();
  inline void set_has_error_reason();
  inline void clear_has_error_reason();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* response_proto_;
  ::std::string* error_;
  bool callback_;
  int error_reason_;
  friend void  protobuf_AddDesc_rpc_2eproto();
  friend void protobuf_AssignDesc_rpc_2eproto();
  friend void protobuf_ShutdownFile_rpc_2eproto();

  void InitAsDefaultInstance();
  static Response* default_instance_;
};
// ===================================================================


// ===================================================================

// Request

// required string service_name = 1;
inline bool Request::has_service_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Request::set_has_service_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Request::clear_has_service_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Request::clear_service_name() {
  if (service_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    service_name_->clear();
  }
  clear_has_service_name();
}
inline const ::std::string& Request::service_name() const {
  // @@protoc_insertion_point(field_get:protobuf.socketrpc.Request.service_name)
  return *service_name_;
}
inline void Request::set_service_name(const ::std::string& value) {
  set_has_service_name();
  if (service_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    service_name_ = new ::std::string;
  }
  service_name_->assign(value);
  // @@protoc_insertion_point(field_set:protobuf.socketrpc.Request.service_name)
}
inline void Request::set_service_name(const char* value) {
  set_has_service_name();
  if (service_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    service_name_ = new ::std::string;
  }
  service_name_->assign(value);
  // @@protoc_insertion_point(field_set_char:protobuf.socketrpc.Request.service_name)
}
inline void Request::set_service_name(const char* value, size_t size) {
  set_has_service_name();
  if (service_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    service_name_ = new ::std::string;
  }
  service_name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:protobuf.socketrpc.Request.service_name)
}
inline ::std::string* Request::mutable_service_name() {
  set_has_service_name();
  if (service_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    service_name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:protobuf.socketrpc.Request.service_name)
  return service_name_;
}
inline ::std::string* Request::release_service_name() {
  clear_has_service_name();
  if (service_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = service_name_;
    service_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Request::set_allocated_service_name(::std::string* service_name) {
  if (service_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete service_name_;
  }
  if (service_name) {
    set_has_service_name();
    service_name_ = service_name;
  } else {
    clear_has_service_name();
    service_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:protobuf.socketrpc.Request.service_name)
}

// required string method_name = 2;
inline bool Request::has_method_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Request::set_has_method_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Request::clear_has_method_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Request::clear_method_name() {
  if (method_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    method_name_->clear();
  }
  clear_has_method_name();
}
inline const ::std::string& Request::method_name() const {
  // @@protoc_insertion_point(field_get:protobuf.socketrpc.Request.method_name)
  return *method_name_;
}
inline void Request::set_method_name(const ::std::string& value) {
  set_has_method_name();
  if (method_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    method_name_ = new ::std::string;
  }
  method_name_->assign(value);
  // @@protoc_insertion_point(field_set:protobuf.socketrpc.Request.method_name)
}
inline void Request::set_method_name(const char* value) {
  set_has_method_name();
  if (method_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    method_name_ = new ::std::string;
  }
  method_name_->assign(value);
  // @@protoc_insertion_point(field_set_char:protobuf.socketrpc.Request.method_name)
}
inline void Request::set_method_name(const char* value, size_t size) {
  set_has_method_name();
  if (method_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    method_name_ = new ::std::string;
  }
  method_name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:protobuf.socketrpc.Request.method_name)
}
inline ::std::string* Request::mutable_method_name() {
  set_has_method_name();
  if (method_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    method_name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:protobuf.socketrpc.Request.method_name)
  return method_name_;
}
inline ::std::string* Request::release_method_name() {
  clear_has_method_name();
  if (method_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = method_name_;
    method_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Request::set_allocated_method_name(::std::string* method_name) {
  if (method_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete method_name_;
  }
  if (method_name) {
    set_has_method_name();
    method_name_ = method_name;
  } else {
    clear_has_method_name();
    method_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:protobuf.socketrpc.Request.method_name)
}

// required bytes request_proto = 3;
inline bool Request::has_request_proto() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Request::set_has_request_proto() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Request::clear_has_request_proto() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Request::clear_request_proto() {
  if (request_proto_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    request_proto_->clear();
  }
  clear_has_request_proto();
}
inline const ::std::string& Request::request_proto() const {
  // @@protoc_insertion_point(field_get:protobuf.socketrpc.Request.request_proto)
  return *request_proto_;
}
inline void Request::set_request_proto(const ::std::string& value) {
  set_has_request_proto();
  if (request_proto_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    request_proto_ = new ::std::string;
  }
  request_proto_->assign(value);
  // @@protoc_insertion_point(field_set:protobuf.socketrpc.Request.request_proto)
}
inline void Request::set_request_proto(const char* value) {
  set_has_request_proto();
  if (request_proto_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    request_proto_ = new ::std::string;
  }
  request_proto_->assign(value);
  // @@protoc_insertion_point(field_set_char:protobuf.socketrpc.Request.request_proto)
}
inline void Request::set_request_proto(const void* value, size_t size) {
  set_has_request_proto();
  if (request_proto_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    request_proto_ = new ::std::string;
  }
  request_proto_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:protobuf.socketrpc.Request.request_proto)
}
inline ::std::string* Request::mutable_request_proto() {
  set_has_request_proto();
  if (request_proto_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    request_proto_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:protobuf.socketrpc.Request.request_proto)
  return request_proto_;
}
inline ::std::string* Request::release_request_proto() {
  clear_has_request_proto();
  if (request_proto_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = request_proto_;
    request_proto_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Request::set_allocated_request_proto(::std::string* request_proto) {
  if (request_proto_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete request_proto_;
  }
  if (request_proto) {
    set_has_request_proto();
    request_proto_ = request_proto;
  } else {
    clear_has_request_proto();
    request_proto_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:protobuf.socketrpc.Request.request_proto)
}

// -------------------------------------------------------------------

// Response

// optional bytes response_proto = 1;
inline bool Response::has_response_proto() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Response::set_has_response_proto() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Response::clear_has_response_proto() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Response::clear_response_proto() {
  if (response_proto_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    response_proto_->clear();
  }
  clear_has_response_proto();
}
inline const ::std::string& Response::response_proto() const {
  // @@protoc_insertion_point(field_get:protobuf.socketrpc.Response.response_proto)
  return *response_proto_;
}
inline void Response::set_response_proto(const ::std::string& value) {
  set_has_response_proto();
  if (response_proto_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    response_proto_ = new ::std::string;
  }
  response_proto_->assign(value);
  // @@protoc_insertion_point(field_set:protobuf.socketrpc.Response.response_proto)
}
inline void Response::set_response_proto(const char* value) {
  set_has_response_proto();
  if (response_proto_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    response_proto_ = new ::std::string;
  }
  response_proto_->assign(value);
  // @@protoc_insertion_point(field_set_char:protobuf.socketrpc.Response.response_proto)
}
inline void Response::set_response_proto(const void* value, size_t size) {
  set_has_response_proto();
  if (response_proto_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    response_proto_ = new ::std::string;
  }
  response_proto_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:protobuf.socketrpc.Response.response_proto)
}
inline ::std::string* Response::mutable_response_proto() {
  set_has_response_proto();
  if (response_proto_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    response_proto_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:protobuf.socketrpc.Response.response_proto)
  return response_proto_;
}
inline ::std::string* Response::release_response_proto() {
  clear_has_response_proto();
  if (response_proto_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = response_proto_;
    response_proto_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Response::set_allocated_response_proto(::std::string* response_proto) {
  if (response_proto_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete response_proto_;
  }
  if (response_proto) {
    set_has_response_proto();
    response_proto_ = response_proto;
  } else {
    clear_has_response_proto();
    response_proto_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:protobuf.socketrpc.Response.response_proto)
}

// optional string error = 2;
inline bool Response::has_error() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Response::set_has_error() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Response::clear_has_error() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Response::clear_error() {
  if (error_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    error_->clear();
  }
  clear_has_error();
}
inline const ::std::string& Response::error() const {
  // @@protoc_insertion_point(field_get:protobuf.socketrpc.Response.error)
  return *error_;
}
inline void Response::set_error(const ::std::string& value) {
  set_has_error();
  if (error_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    error_ = new ::std::string;
  }
  error_->assign(value);
  // @@protoc_insertion_point(field_set:protobuf.socketrpc.Response.error)
}
inline void Response::set_error(const char* value) {
  set_has_error();
  if (error_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    error_ = new ::std::string;
  }
  error_->assign(value);
  // @@protoc_insertion_point(field_set_char:protobuf.socketrpc.Response.error)
}
inline void Response::set_error(const char* value, size_t size) {
  set_has_error();
  if (error_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    error_ = new ::std::string;
  }
  error_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:protobuf.socketrpc.Response.error)
}
inline ::std::string* Response::mutable_error() {
  set_has_error();
  if (error_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    error_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:protobuf.socketrpc.Response.error)
  return error_;
}
inline ::std::string* Response::release_error() {
  clear_has_error();
  if (error_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = error_;
    error_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Response::set_allocated_error(::std::string* error) {
  if (error_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete error_;
  }
  if (error) {
    set_has_error();
    error_ = error;
  } else {
    clear_has_error();
    error_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:protobuf.socketrpc.Response.error)
}

// optional bool callback = 3 [default = false];
inline bool Response::has_callback() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Response::set_has_callback() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Response::clear_has_callback() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Response::clear_callback() {
  callback_ = false;
  clear_has_callback();
}
inline bool Response::callback() const {
  // @@protoc_insertion_point(field_get:protobuf.socketrpc.Response.callback)
  return callback_;
}
inline void Response::set_callback(bool value) {
  set_has_callback();
  callback_ = value;
  // @@protoc_insertion_point(field_set:protobuf.socketrpc.Response.callback)
}

// optional .protobuf.socketrpc.ErrorReason error_reason = 4;
inline bool Response::has_error_reason() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Response::set_has_error_reason() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Response::clear_has_error_reason() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Response::clear_error_reason() {
  error_reason_ = 0;
  clear_has_error_reason();
}
inline ::protobuf::socketrpc::ErrorReason Response::error_reason() const {
  // @@protoc_insertion_point(field_get:protobuf.socketrpc.Response.error_reason)
  return static_cast< ::protobuf::socketrpc::ErrorReason >(error_reason_);
}
inline void Response::set_error_reason(::protobuf::socketrpc::ErrorReason value) {
  assert(::protobuf::socketrpc::ErrorReason_IsValid(value));
  set_has_error_reason();
  error_reason_ = value;
  // @@protoc_insertion_point(field_set:protobuf.socketrpc.Response.error_reason)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace socketrpc
}  // namespace protobuf

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::protobuf::socketrpc::ErrorReason> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::protobuf::socketrpc::ErrorReason>() {
  return ::protobuf::socketrpc::ErrorReason_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_rpc_2eproto__INCLUDED

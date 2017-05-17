// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: position.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "position.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace demo {

namespace {

const ::google::protobuf::Descriptor* Position_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Position_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_position_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_position_2eproto() {
  protobuf_AddDesc_position_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "position.proto");
  GOOGLE_CHECK(file != NULL);
  Position_descriptor_ = file->message_type(0);
  static const int Position_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Position, positionid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Position, secname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Position, accountid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Position, posqty_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Position, avgcost_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Position, mv_),
  };
  Position_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Position_descriptor_,
      Position::default_instance_,
      Position_offsets_,
      -1,
      -1,
      -1,
      sizeof(Position),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Position, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Position, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_position_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Position_descriptor_, &Position::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_position_2eproto() {
  delete Position::default_instance_;
  delete Position_reflection_;
}

void protobuf_AddDesc_position_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_position_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016position.proto\022\004demo\"o\n\010Position\022\022\n\npo"
    "sitionId\030\001 \001(\003\022\017\n\007secName\030\002 \001(\t\022\021\n\taccou"
    "ntId\030\003 \001(\005\022\016\n\006posQty\030\004 \001(\001\022\017\n\007avgCost\030\005 "
    "\001(\001\022\n\n\002mv\030\006 \001(\001b\006proto3", 143);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "position.proto", &protobuf_RegisterTypes);
  Position::default_instance_ = new Position();
  Position::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_position_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_position_2eproto {
  StaticDescriptorInitializer_position_2eproto() {
    protobuf_AddDesc_position_2eproto();
  }
} static_descriptor_initializer_position_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Position::kPositionIdFieldNumber;
const int Position::kSecNameFieldNumber;
const int Position::kAccountIdFieldNumber;
const int Position::kPosQtyFieldNumber;
const int Position::kAvgCostFieldNumber;
const int Position::kMvFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Position::Position()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:demo.Position)
}

void Position::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

Position::Position(const Position& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:demo.Position)
}

void Position::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  positionid_ = GOOGLE_LONGLONG(0);
  secname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  accountid_ = 0;
  posqty_ = 0;
  avgcost_ = 0;
  mv_ = 0;
}

Position::~Position() {
  // @@protoc_insertion_point(destructor:demo.Position)
  SharedDtor();
}

void Position::SharedDtor() {
  secname_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void Position::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Position::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Position_descriptor_;
}

const Position& Position::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_position_2eproto();
  return *default_instance_;
}

Position* Position::default_instance_ = NULL;

Position* Position::New(::google::protobuf::Arena* arena) const {
  Position* n = new Position;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Position::Clear() {
// @@protoc_insertion_point(message_clear_start:demo.Position)
#if defined(__clang__)
#define ZR_HELPER_(f) \
  _Pragma("clang diagnostic push") \
  _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") \
  __builtin_offsetof(Position, f) \
  _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<Position*>(16)->f)
#endif

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(posqty_, accountid_);
  positionid_ = GOOGLE_LONGLONG(0);
  secname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());

#undef ZR_HELPER_
#undef ZR_

}

bool Position::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:demo.Position)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 positionId = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &positionid_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_secName;
        break;
      }

      // optional string secName = 2;
      case 2: {
        if (tag == 18) {
         parse_secName:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_secname()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->secname().data(), this->secname().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "demo.Position.secName"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_accountId;
        break;
      }

      // optional int32 accountId = 3;
      case 3: {
        if (tag == 24) {
         parse_accountId:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &accountid_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(33)) goto parse_posQty;
        break;
      }

      // optional double posQty = 4;
      case 4: {
        if (tag == 33) {
         parse_posQty:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &posqty_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(41)) goto parse_avgCost;
        break;
      }

      // optional double avgCost = 5;
      case 5: {
        if (tag == 41) {
         parse_avgCost:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &avgcost_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(49)) goto parse_mv;
        break;
      }

      // optional double mv = 6;
      case 6: {
        if (tag == 49) {
         parse_mv:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &mv_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:demo.Position)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:demo.Position)
  return false;
#undef DO_
}

void Position::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:demo.Position)
  // optional int64 positionId = 1;
  if (this->positionid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->positionid(), output);
  }

  // optional string secName = 2;
  if (this->secname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->secname().data(), this->secname().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "demo.Position.secName");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->secname(), output);
  }

  // optional int32 accountId = 3;
  if (this->accountid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->accountid(), output);
  }

  // optional double posQty = 4;
  if (this->posqty() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(4, this->posqty(), output);
  }

  // optional double avgCost = 5;
  if (this->avgcost() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(5, this->avgcost(), output);
  }

  // optional double mv = 6;
  if (this->mv() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(6, this->mv(), output);
  }

  // @@protoc_insertion_point(serialize_end:demo.Position)
}

::google::protobuf::uint8* Position::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:demo.Position)
  // optional int64 positionId = 1;
  if (this->positionid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->positionid(), target);
  }

  // optional string secName = 2;
  if (this->secname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->secname().data(), this->secname().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "demo.Position.secName");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->secname(), target);
  }

  // optional int32 accountId = 3;
  if (this->accountid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->accountid(), target);
  }

  // optional double posQty = 4;
  if (this->posqty() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, this->posqty(), target);
  }

  // optional double avgCost = 5;
  if (this->avgcost() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, this->avgcost(), target);
  }

  // optional double mv = 6;
  if (this->mv() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(6, this->mv(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:demo.Position)
  return target;
}

int Position::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:demo.Position)
  int total_size = 0;

  // optional int64 positionId = 1;
  if (this->positionid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->positionid());
  }

  // optional string secName = 2;
  if (this->secname().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->secname());
  }

  // optional int32 accountId = 3;
  if (this->accountid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->accountid());
  }

  // optional double posQty = 4;
  if (this->posqty() != 0) {
    total_size += 1 + 8;
  }

  // optional double avgCost = 5;
  if (this->avgcost() != 0) {
    total_size += 1 + 8;
  }

  // optional double mv = 6;
  if (this->mv() != 0) {
    total_size += 1 + 8;
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Position::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:demo.Position)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const Position* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Position>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:demo.Position)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:demo.Position)
    MergeFrom(*source);
  }
}

void Position::MergeFrom(const Position& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:demo.Position)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.positionid() != 0) {
    set_positionid(from.positionid());
  }
  if (from.secname().size() > 0) {

    secname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.secname_);
  }
  if (from.accountid() != 0) {
    set_accountid(from.accountid());
  }
  if (from.posqty() != 0) {
    set_posqty(from.posqty());
  }
  if (from.avgcost() != 0) {
    set_avgcost(from.avgcost());
  }
  if (from.mv() != 0) {
    set_mv(from.mv());
  }
}

void Position::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:demo.Position)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Position::CopyFrom(const Position& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:demo.Position)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Position::IsInitialized() const {

  return true;
}

void Position::Swap(Position* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Position::InternalSwap(Position* other) {
  std::swap(positionid_, other->positionid_);
  secname_.Swap(&other->secname_);
  std::swap(accountid_, other->accountid_);
  std::swap(posqty_, other->posqty_);
  std::swap(avgcost_, other->avgcost_);
  std::swap(mv_, other->mv_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Position::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Position_descriptor_;
  metadata.reflection = Position_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Position

// optional int64 positionId = 1;
void Position::clear_positionid() {
  positionid_ = GOOGLE_LONGLONG(0);
}
 ::google::protobuf::int64 Position::positionid() const {
  // @@protoc_insertion_point(field_get:demo.Position.positionId)
  return positionid_;
}
 void Position::set_positionid(::google::protobuf::int64 value) {
  
  positionid_ = value;
  // @@protoc_insertion_point(field_set:demo.Position.positionId)
}

// optional string secName = 2;
void Position::clear_secname() {
  secname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& Position::secname() const {
  // @@protoc_insertion_point(field_get:demo.Position.secName)
  return secname_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void Position::set_secname(const ::std::string& value) {
  
  secname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:demo.Position.secName)
}
 void Position::set_secname(const char* value) {
  
  secname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:demo.Position.secName)
}
 void Position::set_secname(const char* value, size_t size) {
  
  secname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:demo.Position.secName)
}
 ::std::string* Position::mutable_secname() {
  
  // @@protoc_insertion_point(field_mutable:demo.Position.secName)
  return secname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* Position::release_secname() {
  // @@protoc_insertion_point(field_release:demo.Position.secName)
  
  return secname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void Position::set_allocated_secname(::std::string* secname) {
  if (secname != NULL) {
    
  } else {
    
  }
  secname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), secname);
  // @@protoc_insertion_point(field_set_allocated:demo.Position.secName)
}

// optional int32 accountId = 3;
void Position::clear_accountid() {
  accountid_ = 0;
}
 ::google::protobuf::int32 Position::accountid() const {
  // @@protoc_insertion_point(field_get:demo.Position.accountId)
  return accountid_;
}
 void Position::set_accountid(::google::protobuf::int32 value) {
  
  accountid_ = value;
  // @@protoc_insertion_point(field_set:demo.Position.accountId)
}

// optional double posQty = 4;
void Position::clear_posqty() {
  posqty_ = 0;
}
 double Position::posqty() const {
  // @@protoc_insertion_point(field_get:demo.Position.posQty)
  return posqty_;
}
 void Position::set_posqty(double value) {
  
  posqty_ = value;
  // @@protoc_insertion_point(field_set:demo.Position.posQty)
}

// optional double avgCost = 5;
void Position::clear_avgcost() {
  avgcost_ = 0;
}
 double Position::avgcost() const {
  // @@protoc_insertion_point(field_get:demo.Position.avgCost)
  return avgcost_;
}
 void Position::set_avgcost(double value) {
  
  avgcost_ = value;
  // @@protoc_insertion_point(field_set:demo.Position.avgCost)
}

// optional double mv = 6;
void Position::clear_mv() {
  mv_ = 0;
}
 double Position::mv() const {
  // @@protoc_insertion_point(field_get:demo.Position.mv)
  return mv_;
}
 void Position::set_mv(double value) {
  
  mv_ = value;
  // @@protoc_insertion_point(field_set:demo.Position.mv)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace demo

// @@protoc_insertion_point(global_scope)

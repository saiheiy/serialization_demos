// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foobar.proto

#ifndef PROTOBUF_foobar_2eproto__INCLUDED
#define PROTOBUF_foobar_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace benchpb {
class Bar;
class BarDefaultTypeInternal;
extern BarDefaultTypeInternal _Bar_default_instance_;
class Foo;
class FooDefaultTypeInternal;
extern FooDefaultTypeInternal _Foo_default_instance_;
class FooBar;
class FooBarDefaultTypeInternal;
extern FooBarDefaultTypeInternal _FooBar_default_instance_;
class FooBarContainer;
class FooBarContainerDefaultTypeInternal;
extern FooBarContainerDefaultTypeInternal _FooBarContainer_default_instance_;
}  // namespace benchpb

namespace benchpb {

namespace protobuf_foobar_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_foobar_2eproto

enum Enum {
  Apples = 0,
  Pears = 1,
  Bananas = 2
};
bool Enum_IsValid(int value);
const Enum Enum_MIN = Apples;
const Enum Enum_MAX = Bananas;
const int Enum_ARRAYSIZE = Enum_MAX + 1;

const ::google::protobuf::EnumDescriptor* Enum_descriptor();
inline const ::std::string& Enum_Name(Enum value) {
  return ::google::protobuf::internal::NameOfEnum(
    Enum_descriptor(), value);
}
inline bool Enum_Parse(
    const ::std::string& name, Enum* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Enum>(
    Enum_descriptor(), name, value);
}
// ===================================================================

class Foo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:benchpb.Foo) */ {
 public:
  Foo();
  virtual ~Foo();

  Foo(const Foo& from);

  inline Foo& operator=(const Foo& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Foo& default_instance();

  static inline const Foo* internal_default_instance() {
    return reinterpret_cast<const Foo*>(
               &_Foo_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Foo* other);

  // implements Message ----------------------------------------------

  inline Foo* New() const PROTOBUF_FINAL { return New(NULL); }

  Foo* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Foo& from);
  void MergeFrom(const Foo& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Foo* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint64 id = 1;
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::uint64 id() const;
  void set_id(::google::protobuf::uint64 value);

  // required int32 count = 2;
  bool has_count() const;
  void clear_count();
  static const int kCountFieldNumber = 2;
  ::google::protobuf::int32 count() const;
  void set_count(::google::protobuf::int32 value);

  // required int32 prefix = 3;
  bool has_prefix() const;
  void clear_prefix();
  static const int kPrefixFieldNumber = 3;
  ::google::protobuf::int32 prefix() const;
  void set_prefix(::google::protobuf::int32 value);

  // required uint32 length = 4;
  bool has_length() const;
  void clear_length();
  static const int kLengthFieldNumber = 4;
  ::google::protobuf::uint32 length() const;
  void set_length(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:benchpb.Foo)
 private:
  void set_has_id();
  void clear_has_id();
  void set_has_count();
  void clear_has_count();
  void set_has_prefix();
  void clear_has_prefix();
  void set_has_length();
  void clear_has_length();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::uint64 id_;
  ::google::protobuf::int32 count_;
  ::google::protobuf::int32 prefix_;
  ::google::protobuf::uint32 length_;
  friend struct protobuf_foobar_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Bar : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:benchpb.Bar) */ {
 public:
  Bar();
  virtual ~Bar();

  Bar(const Bar& from);

  inline Bar& operator=(const Bar& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Bar& default_instance();

  static inline const Bar* internal_default_instance() {
    return reinterpret_cast<const Bar*>(
               &_Bar_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(Bar* other);

  // implements Message ----------------------------------------------

  inline Bar* New() const PROTOBUF_FINAL { return New(NULL); }

  Bar* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Bar& from);
  void MergeFrom(const Bar& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Bar* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .benchpb.Foo parent = 1;
  bool has_parent() const;
  void clear_parent();
  static const int kParentFieldNumber = 1;
  const ::benchpb::Foo& parent() const;
  ::benchpb::Foo* mutable_parent();
  ::benchpb::Foo* release_parent();
  void set_allocated_parent(::benchpb::Foo* parent);

  // required int32 time = 2;
  bool has_time() const;
  void clear_time();
  static const int kTimeFieldNumber = 2;
  ::google::protobuf::int32 time() const;
  void set_time(::google::protobuf::int32 value);

  // required float ratio = 3;
  bool has_ratio() const;
  void clear_ratio();
  static const int kRatioFieldNumber = 3;
  float ratio() const;
  void set_ratio(float value);

  // required uint32 size = 4;
  bool has_size() const;
  void clear_size();
  static const int kSizeFieldNumber = 4;
  ::google::protobuf::uint32 size() const;
  void set_size(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:benchpb.Bar)
 private:
  void set_has_parent();
  void clear_has_parent();
  void set_has_time();
  void clear_has_time();
  void set_has_ratio();
  void clear_has_ratio();
  void set_has_size();
  void clear_has_size();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::benchpb::Foo* parent_;
  ::google::protobuf::int32 time_;
  float ratio_;
  ::google::protobuf::uint32 size_;
  friend struct protobuf_foobar_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class FooBar : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:benchpb.FooBar) */ {
 public:
  FooBar();
  virtual ~FooBar();

  FooBar(const FooBar& from);

  inline FooBar& operator=(const FooBar& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const FooBar& default_instance();

  static inline const FooBar* internal_default_instance() {
    return reinterpret_cast<const FooBar*>(
               &_FooBar_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(FooBar* other);

  // implements Message ----------------------------------------------

  inline FooBar* New() const PROTOBUF_FINAL { return New(NULL); }

  FooBar* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const FooBar& from);
  void MergeFrom(const FooBar& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(FooBar* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string name = 2;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional .benchpb.Bar sibling = 1;
  bool has_sibling() const;
  void clear_sibling();
  static const int kSiblingFieldNumber = 1;
  const ::benchpb::Bar& sibling() const;
  ::benchpb::Bar* mutable_sibling();
  ::benchpb::Bar* release_sibling();
  void set_allocated_sibling(::benchpb::Bar* sibling);

  // optional double rating = 3;
  bool has_rating() const;
  void clear_rating();
  static const int kRatingFieldNumber = 3;
  double rating() const;
  void set_rating(double value);

  // optional uint32 postfix = 4;
  bool has_postfix() const;
  void clear_postfix();
  static const int kPostfixFieldNumber = 4;
  ::google::protobuf::uint32 postfix() const;
  void set_postfix(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:benchpb.FooBar)
 private:
  void set_has_sibling();
  void clear_has_sibling();
  void set_has_name();
  void clear_has_name();
  void set_has_rating();
  void clear_has_rating();
  void set_has_postfix();
  void clear_has_postfix();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::benchpb::Bar* sibling_;
  double rating_;
  ::google::protobuf::uint32 postfix_;
  friend struct protobuf_foobar_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class FooBarContainer : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:benchpb.FooBarContainer) */ {
 public:
  FooBarContainer();
  virtual ~FooBarContainer();

  FooBarContainer(const FooBarContainer& from);

  inline FooBarContainer& operator=(const FooBarContainer& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const FooBarContainer& default_instance();

  static inline const FooBarContainer* internal_default_instance() {
    return reinterpret_cast<const FooBarContainer*>(
               &_FooBarContainer_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(FooBarContainer* other);

  // implements Message ----------------------------------------------

  inline FooBarContainer* New() const PROTOBUF_FINAL { return New(NULL); }

  FooBarContainer* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const FooBarContainer& from);
  void MergeFrom(const FooBarContainer& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(FooBarContainer* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .benchpb.FooBar list = 1;
  int list_size() const;
  void clear_list();
  static const int kListFieldNumber = 1;
  const ::benchpb::FooBar& list(int index) const;
  ::benchpb::FooBar* mutable_list(int index);
  ::benchpb::FooBar* add_list();
  ::google::protobuf::RepeatedPtrField< ::benchpb::FooBar >*
      mutable_list();
  const ::google::protobuf::RepeatedPtrField< ::benchpb::FooBar >&
      list() const;

  // optional string location = 4;
  bool has_location() const;
  void clear_location();
  static const int kLocationFieldNumber = 4;
  const ::std::string& location() const;
  void set_location(const ::std::string& value);
  #if LANG_CXX11
  void set_location(::std::string&& value);
  #endif
  void set_location(const char* value);
  void set_location(const char* value, size_t size);
  ::std::string* mutable_location();
  ::std::string* release_location();
  void set_allocated_location(::std::string* location);

  // optional bool initialized = 2;
  bool has_initialized() const;
  void clear_initialized();
  static const int kInitializedFieldNumber = 2;
  bool initialized() const;
  void set_initialized(bool value);

  // optional .benchpb.Enum fruit = 3;
  bool has_fruit() const;
  void clear_fruit();
  static const int kFruitFieldNumber = 3;
  ::benchpb::Enum fruit() const;
  void set_fruit(::benchpb::Enum value);

  // @@protoc_insertion_point(class_scope:benchpb.FooBarContainer)
 private:
  void set_has_initialized();
  void clear_has_initialized();
  void set_has_fruit();
  void clear_has_fruit();
  void set_has_location();
  void clear_has_location();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::benchpb::FooBar > list_;
  ::google::protobuf::internal::ArenaStringPtr location_;
  bool initialized_;
  int fruit_;
  friend struct protobuf_foobar_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Foo

// required uint64 id = 1;
inline bool Foo::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Foo::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Foo::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Foo::clear_id() {
  id_ = GOOGLE_ULONGLONG(0);
  clear_has_id();
}
inline ::google::protobuf::uint64 Foo::id() const {
  // @@protoc_insertion_point(field_get:benchpb.Foo.id)
  return id_;
}
inline void Foo::set_id(::google::protobuf::uint64 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:benchpb.Foo.id)
}

// required int32 count = 2;
inline bool Foo::has_count() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Foo::set_has_count() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Foo::clear_has_count() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Foo::clear_count() {
  count_ = 0;
  clear_has_count();
}
inline ::google::protobuf::int32 Foo::count() const {
  // @@protoc_insertion_point(field_get:benchpb.Foo.count)
  return count_;
}
inline void Foo::set_count(::google::protobuf::int32 value) {
  set_has_count();
  count_ = value;
  // @@protoc_insertion_point(field_set:benchpb.Foo.count)
}

// required int32 prefix = 3;
inline bool Foo::has_prefix() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Foo::set_has_prefix() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Foo::clear_has_prefix() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Foo::clear_prefix() {
  prefix_ = 0;
  clear_has_prefix();
}
inline ::google::protobuf::int32 Foo::prefix() const {
  // @@protoc_insertion_point(field_get:benchpb.Foo.prefix)
  return prefix_;
}
inline void Foo::set_prefix(::google::protobuf::int32 value) {
  set_has_prefix();
  prefix_ = value;
  // @@protoc_insertion_point(field_set:benchpb.Foo.prefix)
}

// required uint32 length = 4;
inline bool Foo::has_length() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Foo::set_has_length() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Foo::clear_has_length() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Foo::clear_length() {
  length_ = 0u;
  clear_has_length();
}
inline ::google::protobuf::uint32 Foo::length() const {
  // @@protoc_insertion_point(field_get:benchpb.Foo.length)
  return length_;
}
inline void Foo::set_length(::google::protobuf::uint32 value) {
  set_has_length();
  length_ = value;
  // @@protoc_insertion_point(field_set:benchpb.Foo.length)
}

// -------------------------------------------------------------------

// Bar

// required .benchpb.Foo parent = 1;
inline bool Bar::has_parent() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Bar::set_has_parent() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Bar::clear_has_parent() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Bar::clear_parent() {
  if (parent_ != NULL) parent_->::benchpb::Foo::Clear();
  clear_has_parent();
}
inline const ::benchpb::Foo& Bar::parent() const {
  // @@protoc_insertion_point(field_get:benchpb.Bar.parent)
  return parent_ != NULL ? *parent_
                         : *::benchpb::Foo::internal_default_instance();
}
inline ::benchpb::Foo* Bar::mutable_parent() {
  set_has_parent();
  if (parent_ == NULL) {
    parent_ = new ::benchpb::Foo;
  }
  // @@protoc_insertion_point(field_mutable:benchpb.Bar.parent)
  return parent_;
}
inline ::benchpb::Foo* Bar::release_parent() {
  // @@protoc_insertion_point(field_release:benchpb.Bar.parent)
  clear_has_parent();
  ::benchpb::Foo* temp = parent_;
  parent_ = NULL;
  return temp;
}
inline void Bar::set_allocated_parent(::benchpb::Foo* parent) {
  delete parent_;
  parent_ = parent;
  if (parent) {
    set_has_parent();
  } else {
    clear_has_parent();
  }
  // @@protoc_insertion_point(field_set_allocated:benchpb.Bar.parent)
}

// required int32 time = 2;
inline bool Bar::has_time() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Bar::set_has_time() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Bar::clear_has_time() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Bar::clear_time() {
  time_ = 0;
  clear_has_time();
}
inline ::google::protobuf::int32 Bar::time() const {
  // @@protoc_insertion_point(field_get:benchpb.Bar.time)
  return time_;
}
inline void Bar::set_time(::google::protobuf::int32 value) {
  set_has_time();
  time_ = value;
  // @@protoc_insertion_point(field_set:benchpb.Bar.time)
}

// required float ratio = 3;
inline bool Bar::has_ratio() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Bar::set_has_ratio() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Bar::clear_has_ratio() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Bar::clear_ratio() {
  ratio_ = 0;
  clear_has_ratio();
}
inline float Bar::ratio() const {
  // @@protoc_insertion_point(field_get:benchpb.Bar.ratio)
  return ratio_;
}
inline void Bar::set_ratio(float value) {
  set_has_ratio();
  ratio_ = value;
  // @@protoc_insertion_point(field_set:benchpb.Bar.ratio)
}

// required uint32 size = 4;
inline bool Bar::has_size() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Bar::set_has_size() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Bar::clear_has_size() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Bar::clear_size() {
  size_ = 0u;
  clear_has_size();
}
inline ::google::protobuf::uint32 Bar::size() const {
  // @@protoc_insertion_point(field_get:benchpb.Bar.size)
  return size_;
}
inline void Bar::set_size(::google::protobuf::uint32 value) {
  set_has_size();
  size_ = value;
  // @@protoc_insertion_point(field_set:benchpb.Bar.size)
}

// -------------------------------------------------------------------

// FooBar

// optional .benchpb.Bar sibling = 1;
inline bool FooBar::has_sibling() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void FooBar::set_has_sibling() {
  _has_bits_[0] |= 0x00000002u;
}
inline void FooBar::clear_has_sibling() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void FooBar::clear_sibling() {
  if (sibling_ != NULL) sibling_->::benchpb::Bar::Clear();
  clear_has_sibling();
}
inline const ::benchpb::Bar& FooBar::sibling() const {
  // @@protoc_insertion_point(field_get:benchpb.FooBar.sibling)
  return sibling_ != NULL ? *sibling_
                         : *::benchpb::Bar::internal_default_instance();
}
inline ::benchpb::Bar* FooBar::mutable_sibling() {
  set_has_sibling();
  if (sibling_ == NULL) {
    sibling_ = new ::benchpb::Bar;
  }
  // @@protoc_insertion_point(field_mutable:benchpb.FooBar.sibling)
  return sibling_;
}
inline ::benchpb::Bar* FooBar::release_sibling() {
  // @@protoc_insertion_point(field_release:benchpb.FooBar.sibling)
  clear_has_sibling();
  ::benchpb::Bar* temp = sibling_;
  sibling_ = NULL;
  return temp;
}
inline void FooBar::set_allocated_sibling(::benchpb::Bar* sibling) {
  delete sibling_;
  sibling_ = sibling;
  if (sibling) {
    set_has_sibling();
  } else {
    clear_has_sibling();
  }
  // @@protoc_insertion_point(field_set_allocated:benchpb.FooBar.sibling)
}

// optional string name = 2;
inline bool FooBar::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void FooBar::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void FooBar::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void FooBar::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& FooBar::name() const {
  // @@protoc_insertion_point(field_get:benchpb.FooBar.name)
  return name_.GetNoArena();
}
inline void FooBar::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:benchpb.FooBar.name)
}
#if LANG_CXX11
inline void FooBar::set_name(::std::string&& value) {
  set_has_name();
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:benchpb.FooBar.name)
}
#endif
inline void FooBar::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:benchpb.FooBar.name)
}
inline void FooBar::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:benchpb.FooBar.name)
}
inline ::std::string* FooBar::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:benchpb.FooBar.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* FooBar::release_name() {
  // @@protoc_insertion_point(field_release:benchpb.FooBar.name)
  clear_has_name();
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void FooBar::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:benchpb.FooBar.name)
}

// optional double rating = 3;
inline bool FooBar::has_rating() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void FooBar::set_has_rating() {
  _has_bits_[0] |= 0x00000004u;
}
inline void FooBar::clear_has_rating() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void FooBar::clear_rating() {
  rating_ = 0;
  clear_has_rating();
}
inline double FooBar::rating() const {
  // @@protoc_insertion_point(field_get:benchpb.FooBar.rating)
  return rating_;
}
inline void FooBar::set_rating(double value) {
  set_has_rating();
  rating_ = value;
  // @@protoc_insertion_point(field_set:benchpb.FooBar.rating)
}

// optional uint32 postfix = 4;
inline bool FooBar::has_postfix() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void FooBar::set_has_postfix() {
  _has_bits_[0] |= 0x00000008u;
}
inline void FooBar::clear_has_postfix() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void FooBar::clear_postfix() {
  postfix_ = 0u;
  clear_has_postfix();
}
inline ::google::protobuf::uint32 FooBar::postfix() const {
  // @@protoc_insertion_point(field_get:benchpb.FooBar.postfix)
  return postfix_;
}
inline void FooBar::set_postfix(::google::protobuf::uint32 value) {
  set_has_postfix();
  postfix_ = value;
  // @@protoc_insertion_point(field_set:benchpb.FooBar.postfix)
}

// -------------------------------------------------------------------

// FooBarContainer

// repeated .benchpb.FooBar list = 1;
inline int FooBarContainer::list_size() const {
  return list_.size();
}
inline void FooBarContainer::clear_list() {
  list_.Clear();
}
inline const ::benchpb::FooBar& FooBarContainer::list(int index) const {
  // @@protoc_insertion_point(field_get:benchpb.FooBarContainer.list)
  return list_.Get(index);
}
inline ::benchpb::FooBar* FooBarContainer::mutable_list(int index) {
  // @@protoc_insertion_point(field_mutable:benchpb.FooBarContainer.list)
  return list_.Mutable(index);
}
inline ::benchpb::FooBar* FooBarContainer::add_list() {
  // @@protoc_insertion_point(field_add:benchpb.FooBarContainer.list)
  return list_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::benchpb::FooBar >*
FooBarContainer::mutable_list() {
  // @@protoc_insertion_point(field_mutable_list:benchpb.FooBarContainer.list)
  return &list_;
}
inline const ::google::protobuf::RepeatedPtrField< ::benchpb::FooBar >&
FooBarContainer::list() const {
  // @@protoc_insertion_point(field_list:benchpb.FooBarContainer.list)
  return list_;
}

// optional bool initialized = 2;
inline bool FooBarContainer::has_initialized() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void FooBarContainer::set_has_initialized() {
  _has_bits_[0] |= 0x00000002u;
}
inline void FooBarContainer::clear_has_initialized() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void FooBarContainer::clear_initialized() {
  initialized_ = false;
  clear_has_initialized();
}
inline bool FooBarContainer::initialized() const {
  // @@protoc_insertion_point(field_get:benchpb.FooBarContainer.initialized)
  return initialized_;
}
inline void FooBarContainer::set_initialized(bool value) {
  set_has_initialized();
  initialized_ = value;
  // @@protoc_insertion_point(field_set:benchpb.FooBarContainer.initialized)
}

// optional .benchpb.Enum fruit = 3;
inline bool FooBarContainer::has_fruit() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void FooBarContainer::set_has_fruit() {
  _has_bits_[0] |= 0x00000004u;
}
inline void FooBarContainer::clear_has_fruit() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void FooBarContainer::clear_fruit() {
  fruit_ = 0;
  clear_has_fruit();
}
inline ::benchpb::Enum FooBarContainer::fruit() const {
  // @@protoc_insertion_point(field_get:benchpb.FooBarContainer.fruit)
  return static_cast< ::benchpb::Enum >(fruit_);
}
inline void FooBarContainer::set_fruit(::benchpb::Enum value) {
  assert(::benchpb::Enum_IsValid(value));
  set_has_fruit();
  fruit_ = value;
  // @@protoc_insertion_point(field_set:benchpb.FooBarContainer.fruit)
}

// optional string location = 4;
inline bool FooBarContainer::has_location() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void FooBarContainer::set_has_location() {
  _has_bits_[0] |= 0x00000001u;
}
inline void FooBarContainer::clear_has_location() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void FooBarContainer::clear_location() {
  location_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_location();
}
inline const ::std::string& FooBarContainer::location() const {
  // @@protoc_insertion_point(field_get:benchpb.FooBarContainer.location)
  return location_.GetNoArena();
}
inline void FooBarContainer::set_location(const ::std::string& value) {
  set_has_location();
  location_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:benchpb.FooBarContainer.location)
}
#if LANG_CXX11
inline void FooBarContainer::set_location(::std::string&& value) {
  set_has_location();
  location_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:benchpb.FooBarContainer.location)
}
#endif
inline void FooBarContainer::set_location(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_location();
  location_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:benchpb.FooBarContainer.location)
}
inline void FooBarContainer::set_location(const char* value, size_t size) {
  set_has_location();
  location_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:benchpb.FooBarContainer.location)
}
inline ::std::string* FooBarContainer::mutable_location() {
  set_has_location();
  // @@protoc_insertion_point(field_mutable:benchpb.FooBarContainer.location)
  return location_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* FooBarContainer::release_location() {
  // @@protoc_insertion_point(field_release:benchpb.FooBarContainer.location)
  clear_has_location();
  return location_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void FooBarContainer::set_allocated_location(::std::string* location) {
  if (location != NULL) {
    set_has_location();
  } else {
    clear_has_location();
  }
  location_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), location);
  // @@protoc_insertion_point(field_set_allocated:benchpb.FooBarContainer.location)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace benchpb

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::benchpb::Enum> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::benchpb::Enum>() {
  return ::benchpb::Enum_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_foobar_2eproto__INCLUDED

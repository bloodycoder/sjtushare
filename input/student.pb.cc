// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: student.proto

#include "student.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_student_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_somestudent_Course_student_2eproto;
namespace somepack {
class somestudent_CourseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<somestudent_Course> _instance;
} _somestudent_Course_default_instance_;
class somestudentDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<somestudent> _instance;
} _somestudent_default_instance_;
}  // namespace somepack
static void InitDefaultsscc_info_somestudent_student_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::somepack::_somestudent_default_instance_;
    new (ptr) ::somepack::somestudent();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::somepack::somestudent::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_somestudent_student_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_somestudent_student_2eproto}, {
      &scc_info_somestudent_Course_student_2eproto.base,}};

static void InitDefaultsscc_info_somestudent_Course_student_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::somepack::_somestudent_Course_default_instance_;
    new (ptr) ::somepack::somestudent_Course();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::somepack::somestudent_Course::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_somestudent_Course_student_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_somestudent_Course_student_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_student_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_student_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_student_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_student_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::somepack::somestudent_Course, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::somepack::somestudent_Course, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::somepack::somestudent_Course, _coursename_),
  PROTOBUF_FIELD_OFFSET(::somepack::somestudent_Course, _courseid_),
  0,
  1,
  PROTOBUF_FIELD_OFFSET(::somepack::somestudent, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::somepack::somestudent, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::somepack::somestudent, _name_),
  PROTOBUF_FIELD_OFFSET(::somepack::somestudent, _sex_),
  PROTOBUF_FIELD_OFFSET(::somepack::somestudent, _age_),
  PROTOBUF_FIELD_OFFSET(::somepack::somestudent, _studentid_),
  PROTOBUF_FIELD_OFFSET(::somepack::somestudent, _marriage_),
  PROTOBUF_FIELD_OFFSET(::somepack::somestudent, _phonenumber_),
  PROTOBUF_FIELD_OFFSET(::somepack::somestudent, _selectedcourse_),
  0,
  3,
  2,
  1,
  4,
  ~0u,
  ~0u,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 7, sizeof(::somepack::somestudent_Course)},
  { 9, 21, sizeof(::somepack::somestudent)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::somepack::_somestudent_Course_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::somepack::_somestudent_default_instance_),
};

const char descriptor_table_protodef_student_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\rstudent.proto\022\010somepack\"\336\001\n\013somestuden"
  "t\022\r\n\005_name\030\001 \002(\t\022\014\n\004_sex\030\002 \002(\010\022\014\n\004_age\030\003"
  " \002(\005\022\022\n\n_studentid\030\004 \002(\t\022\021\n\t_marriage\030\005 "
  "\001(\010\022\024\n\014_phonenumber\030\013 \003(\t\0225\n\017_selectedco"
  "urse\030\014 \003(\0132\034.somepack.somestudent.Course"
  "\0320\n\006Course\022\023\n\013_coursename\030\001 \002(\t\022\021\n\t_cour"
  "seid\030\002 \002(\005"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_student_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_student_2eproto_sccs[2] = {
  &scc_info_somestudent_student_2eproto.base,
  &scc_info_somestudent_Course_student_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_student_2eproto_once;
static bool descriptor_table_student_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_student_2eproto = {
  &descriptor_table_student_2eproto_initialized, descriptor_table_protodef_student_2eproto, "student.proto", 250,
  &descriptor_table_student_2eproto_once, descriptor_table_student_2eproto_sccs, descriptor_table_student_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_student_2eproto::offsets,
  file_level_metadata_student_2eproto, 2, file_level_enum_descriptors_student_2eproto, file_level_service_descriptors_student_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_student_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_student_2eproto), true);
namespace somepack {

// ===================================================================

void somestudent_Course::InitAsDefaultInstance() {
}
class somestudent_Course::_Internal {
 public:
  using HasBits = decltype(std::declval<somestudent_Course>()._has_bits_);
  static void set_has__coursename(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has__courseid(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

somestudent_Course::somestudent_Course()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:somepack.somestudent.Course)
}
somestudent_Course::somestudent_Course(const somestudent_Course& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  _coursename_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has__coursename()) {
    _coursename_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._coursename_);
  }
  _courseid_ = from._courseid_;
  // @@protoc_insertion_point(copy_constructor:somepack.somestudent.Course)
}

void somestudent_Course::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_somestudent_Course_student_2eproto.base);
  _coursename_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _courseid_ = 0;
}

somestudent_Course::~somestudent_Course() {
  // @@protoc_insertion_point(destructor:somepack.somestudent.Course)
  SharedDtor();
}

void somestudent_Course::SharedDtor() {
  _coursename_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void somestudent_Course::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const somestudent_Course& somestudent_Course::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_somestudent_Course_student_2eproto.base);
  return *internal_default_instance();
}


void somestudent_Course::Clear() {
// @@protoc_insertion_point(message_clear_start:somepack.somestudent.Course)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _coursename_.ClearNonDefaultToEmptyNoArena();
  }
  _courseid_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* somestudent_Course::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required string _coursename = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable__coursename();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "somepack.somestudent.Course._coursename");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required int32 _courseid = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has__courseid(&has_bits);
          _courseid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* somestudent_Course::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:somepack.somestudent.Course)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string _coursename = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal__coursename().data(), static_cast<int>(this->_internal__coursename().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "somepack.somestudent.Course._coursename");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal__coursename(), target);
  }

  // required int32 _courseid = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal__courseid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:somepack.somestudent.Course)
  return target;
}

size_t somestudent_Course::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:somepack.somestudent.Course)
  size_t total_size = 0;

  if (_internal_has__coursename()) {
    // required string _coursename = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal__coursename());
  }

  if (_internal_has__courseid()) {
    // required int32 _courseid = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal__courseid());
  }

  return total_size;
}
size_t somestudent_Course::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:somepack.somestudent.Course)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x00000003) ^ 0x00000003) == 0) {  // All required fields are present.
    // required string _coursename = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal__coursename());

    // required int32 _courseid = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal__courseid());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void somestudent_Course::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:somepack.somestudent.Course)
  GOOGLE_DCHECK_NE(&from, this);
  const somestudent_Course* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<somestudent_Course>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:somepack.somestudent.Course)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:somepack.somestudent.Course)
    MergeFrom(*source);
  }
}

void somestudent_Course::MergeFrom(const somestudent_Course& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:somepack.somestudent.Course)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      _coursename_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._coursename_);
    }
    if (cached_has_bits & 0x00000002u) {
      _courseid_ = from._courseid_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void somestudent_Course::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:somepack.somestudent.Course)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void somestudent_Course::CopyFrom(const somestudent_Course& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:somepack.somestudent.Course)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool somestudent_Course::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  return true;
}

void somestudent_Course::InternalSwap(somestudent_Course* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _coursename_.Swap(&other->_coursename_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(_courseid_, other->_courseid_);
}

::PROTOBUF_NAMESPACE_ID::Metadata somestudent_Course::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void somestudent::InitAsDefaultInstance() {
}
class somestudent::_Internal {
 public:
  using HasBits = decltype(std::declval<somestudent>()._has_bits_);
  static void set_has__name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has__sex(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has__age(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has__studentid(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has__marriage(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
};

somestudent::somestudent()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:somepack.somestudent)
}
somestudent::somestudent(const somestudent& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      _phonenumber_(from._phonenumber_),
      _selectedcourse_(from._selectedcourse_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  _name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has__name()) {
    _name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._name_);
  }
  _studentid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has__studentid()) {
    _studentid_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._studentid_);
  }
  ::memcpy(&_age_, &from._age_,
    static_cast<size_t>(reinterpret_cast<char*>(&_marriage_) -
    reinterpret_cast<char*>(&_age_)) + sizeof(_marriage_));
  // @@protoc_insertion_point(copy_constructor:somepack.somestudent)
}

void somestudent::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_somestudent_student_2eproto.base);
  _name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _studentid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&_age_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_marriage_) -
      reinterpret_cast<char*>(&_age_)) + sizeof(_marriage_));
}

somestudent::~somestudent() {
  // @@protoc_insertion_point(destructor:somepack.somestudent)
  SharedDtor();
}

void somestudent::SharedDtor() {
  _name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _studentid_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void somestudent::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const somestudent& somestudent::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_somestudent_student_2eproto.base);
  return *internal_default_instance();
}


void somestudent::Clear() {
// @@protoc_insertion_point(message_clear_start:somepack.somestudent)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _phonenumber_.Clear();
  _selectedcourse_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _name_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      _studentid_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 0x0000001cu) {
    ::memset(&_age_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&_marriage_) -
        reinterpret_cast<char*>(&_age_)) + sizeof(_marriage_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* somestudent::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required string _name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable__name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "somepack.somestudent._name");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required bool _sex = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has__sex(&has_bits);
          _sex_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required int32 _age = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has__age(&has_bits);
          _age_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string _studentid = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable__studentid();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "somepack.somestudent._studentid");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bool _marriage = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          _Internal::set_has__marriage(&has_bits);
          _marriage_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated string _phonenumber = 11;
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 90)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add__phonenumber();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            #ifndef NDEBUG
            ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "somepack.somestudent._phonenumber");
            #endif  // !NDEBUG
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<90>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .somepack.somestudent.Course _selectedcourse = 12;
      case 12:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 98)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add__selectedcourse(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<98>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* somestudent::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:somepack.somestudent)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required string _name = 1;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal__name().data(), static_cast<int>(this->_internal__name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "somepack.somestudent._name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal__name(), target);
  }

  // required bool _sex = 2;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(2, this->_internal__sex(), target);
  }

  // required int32 _age = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal__age(), target);
  }

  // required string _studentid = 4;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal__studentid().data(), static_cast<int>(this->_internal__studentid().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "somepack.somestudent._studentid");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal__studentid(), target);
  }

  // optional bool _marriage = 5;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(5, this->_internal__marriage(), target);
  }

  // repeated string _phonenumber = 11;
  for (int i = 0, n = this->_internal__phonenumber_size(); i < n; i++) {
    const auto& s = this->_internal__phonenumber(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "somepack.somestudent._phonenumber");
    target = stream->WriteString(11, s, target);
  }

  // repeated .somepack.somestudent.Course _selectedcourse = 12;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal__selectedcourse_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(12, this->_internal__selectedcourse(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:somepack.somestudent)
  return target;
}

size_t somestudent::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:somepack.somestudent)
  size_t total_size = 0;

  if (_internal_has__name()) {
    // required string _name = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal__name());
  }

  if (_internal_has__studentid()) {
    // required string _studentid = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal__studentid());
  }

  if (_internal_has__age()) {
    // required int32 _age = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal__age());
  }

  if (_internal_has__sex()) {
    // required bool _sex = 2;
    total_size += 1 + 1;
  }

  return total_size;
}
size_t somestudent::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:somepack.somestudent)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x0000000f) ^ 0x0000000f) == 0) {  // All required fields are present.
    // required string _name = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal__name());

    // required string _studentid = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal__studentid());

    // required int32 _age = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal__age());

    // required bool _sex = 2;
    total_size += 1 + 1;

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string _phonenumber = 11;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(_phonenumber_.size());
  for (int i = 0, n = _phonenumber_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      _phonenumber_.Get(i));
  }

  // repeated .somepack.somestudent.Course _selectedcourse = 12;
  total_size += 1UL * this->_internal__selectedcourse_size();
  for (const auto& msg : this->_selectedcourse_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // optional bool _marriage = 5;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000010u) {
    total_size += 1 + 1;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void somestudent::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:somepack.somestudent)
  GOOGLE_DCHECK_NE(&from, this);
  const somestudent* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<somestudent>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:somepack.somestudent)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:somepack.somestudent)
    MergeFrom(*source);
  }
}

void somestudent::MergeFrom(const somestudent& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:somepack.somestudent)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  _phonenumber_.MergeFrom(from._phonenumber_);
  _selectedcourse_.MergeFrom(from._selectedcourse_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      _name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._name_);
    }
    if (cached_has_bits & 0x00000002u) {
      _has_bits_[0] |= 0x00000002u;
      _studentid_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._studentid_);
    }
    if (cached_has_bits & 0x00000004u) {
      _age_ = from._age_;
    }
    if (cached_has_bits & 0x00000008u) {
      _sex_ = from._sex_;
    }
    if (cached_has_bits & 0x00000010u) {
      _marriage_ = from._marriage_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void somestudent::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:somepack.somestudent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void somestudent::CopyFrom(const somestudent& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:somepack.somestudent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool somestudent::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;
  if (!::PROTOBUF_NAMESPACE_ID::internal::AllAreInitialized(_selectedcourse_)) return false;
  return true;
}

void somestudent::InternalSwap(somestudent* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _phonenumber_.InternalSwap(&other->_phonenumber_);
  _selectedcourse_.InternalSwap(&other->_selectedcourse_);
  _name_.Swap(&other->_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  _studentid_.Swap(&other->_studentid_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(_age_, other->_age_);
  swap(_sex_, other->_sex_);
  swap(_marriage_, other->_marriage_);
}

::PROTOBUF_NAMESPACE_ID::Metadata somestudent::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace somepack
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::somepack::somestudent_Course* Arena::CreateMaybeMessage< ::somepack::somestudent_Course >(Arena* arena) {
  return Arena::CreateInternal< ::somepack::somestudent_Course >(arena);
}
template<> PROTOBUF_NOINLINE ::somepack::somestudent* Arena::CreateMaybeMessage< ::somepack::somestudent >(Arena* arena) {
  return Arena::CreateInternal< ::somepack::somestudent >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

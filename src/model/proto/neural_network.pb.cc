// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: neural_network.proto

#include "neural_network.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace s21 {
        template <typename>
PROTOBUF_CONSTEXPR NeuralNetworkMessage::NeuralNetworkMessage(::_pbi::ConstantInitialized)
    : _impl_{
      /*decltype(_impl_._has_bits_)*/ {},
      /*decltype(_impl_._cached_size_)*/ {},
      /*decltype(_impl_.weights_hidden__)*/ {},
      /*decltype(_impl_.bias_hidden__)*/ {},
      /*decltype(_impl_.weights_output__)*/ nullptr,
      /*decltype(_impl_.bias_output__)*/ nullptr,
      /*decltype(_impl_.learning_rate_)*/ 0,
      /*decltype(_impl_.hidden_layers_count__)*/ 0,
    } {}
struct NeuralNetworkMessageDefaultTypeInternal {
  PROTOBUF_CONSTEXPR NeuralNetworkMessageDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~NeuralNetworkMessageDefaultTypeInternal() {}
  union {
    NeuralNetworkMessage _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 NeuralNetworkMessageDefaultTypeInternal _NeuralNetworkMessage_default_instance_;
        template <typename>
PROTOBUF_CONSTEXPR MatrixMessage::MatrixMessage(::_pbi::ConstantInitialized)
    : _impl_{
      /*decltype(_impl_.data__)*/ {},
      /*decltype(_impl_._cached_size_)*/ {},
    } {}
struct MatrixMessageDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MatrixMessageDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~MatrixMessageDefaultTypeInternal() {}
  union {
    MatrixMessage _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MatrixMessageDefaultTypeInternal _MatrixMessage_default_instance_;
        template <typename>
PROTOBUF_CONSTEXPR Vector::Vector(::_pbi::ConstantInitialized)
    : _impl_{
      /*decltype(_impl_.data__)*/ {},
      /*decltype(_impl_._cached_size_)*/ {},
    } {}
struct VectorDefaultTypeInternal {
  PROTOBUF_CONSTEXPR VectorDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~VectorDefaultTypeInternal() {}
  union {
    Vector _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 VectorDefaultTypeInternal _Vector_default_instance_;
}  // namespace s21
static ::_pb::Metadata file_level_metadata_neural_5fnetwork_2eproto[3];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_neural_5fnetwork_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_neural_5fnetwork_2eproto = nullptr;
const ::uint32_t TableStruct_neural_5fnetwork_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    PROTOBUF_FIELD_OFFSET(::s21::NeuralNetworkMessage, _impl_._has_bits_),
    PROTOBUF_FIELD_OFFSET(::s21::NeuralNetworkMessage, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::s21::NeuralNetworkMessage, _impl_.learning_rate_),
    PROTOBUF_FIELD_OFFSET(::s21::NeuralNetworkMessage, _impl_.hidden_layers_count__),
    PROTOBUF_FIELD_OFFSET(::s21::NeuralNetworkMessage, _impl_.weights_hidden__),
    PROTOBUF_FIELD_OFFSET(::s21::NeuralNetworkMessage, _impl_.weights_output__),
    PROTOBUF_FIELD_OFFSET(::s21::NeuralNetworkMessage, _impl_.bias_hidden__),
    PROTOBUF_FIELD_OFFSET(::s21::NeuralNetworkMessage, _impl_.bias_output__),
    ~0u,
    ~0u,
    ~0u,
    0,
    ~0u,
    1,
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::s21::MatrixMessage, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::s21::MatrixMessage, _impl_.data__),
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::s21::Vector, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::s21::Vector, _impl_.data__),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, 14, -1, sizeof(::s21::NeuralNetworkMessage)},
        {20, -1, -1, sizeof(::s21::MatrixMessage)},
        {29, -1, -1, sizeof(::s21::Vector)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::s21::_NeuralNetworkMessage_default_instance_._instance,
    &::s21::_MatrixMessage_default_instance_._instance,
    &::s21::_Vector_default_instance_._instance,
};
const char descriptor_table_protodef_neural_5fnetwork_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\024neural_network.proto\022\003s21\"\371\001\n\024NeuralNe"
    "tworkMessage\022\025\n\rlearning_rate\030\001 \001(\001\022\034\n\024h"
    "idden_layers_count_\030\002 \001(\005\022+\n\017weights_hid"
    "den_\030\003 \003(\0132\022.s21.MatrixMessage\022+\n\017weight"
    "s_output_\030\004 \001(\0132\022.s21.MatrixMessage\022(\n\014b"
    "ias_hidden_\030\005 \003(\0132\022.s21.MatrixMessage\022(\n"
    "\014bias_output_\030\006 \001(\0132\022.s21.MatrixMessage\""
    "+\n\rMatrixMessage\022\032\n\005data_\030\001 \003(\0132\013.s21.Ve"
    "ctor\"\027\n\006Vector\022\r\n\005data_\030\001 \003(\001b\006proto3"
};
static ::absl::once_flag descriptor_table_neural_5fnetwork_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_neural_5fnetwork_2eproto = {
    false,
    false,
    357,
    descriptor_table_protodef_neural_5fnetwork_2eproto,
    "neural_network.proto",
    &descriptor_table_neural_5fnetwork_2eproto_once,
    nullptr,
    0,
    3,
    schemas,
    file_default_instances,
    TableStruct_neural_5fnetwork_2eproto::offsets,
    file_level_metadata_neural_5fnetwork_2eproto,
    file_level_enum_descriptors_neural_5fnetwork_2eproto,
    file_level_service_descriptors_neural_5fnetwork_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_neural_5fnetwork_2eproto_getter() {
  return &descriptor_table_neural_5fnetwork_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_neural_5fnetwork_2eproto(&descriptor_table_neural_5fnetwork_2eproto);
namespace s21 {
// ===================================================================

class NeuralNetworkMessage::_Internal {
 public:
  using HasBits = decltype(std::declval<NeuralNetworkMessage>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_._has_bits_);
  static const ::s21::MatrixMessage& weights_output_(const NeuralNetworkMessage* msg);
  static void set_has_weights_output_(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static const ::s21::MatrixMessage& bias_output_(const NeuralNetworkMessage* msg);
  static void set_has_bias_output_(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

const ::s21::MatrixMessage& NeuralNetworkMessage::_Internal::weights_output_(const NeuralNetworkMessage* msg) {
  return *msg->_impl_.weights_output__;
}
const ::s21::MatrixMessage& NeuralNetworkMessage::_Internal::bias_output_(const NeuralNetworkMessage* msg) {
  return *msg->_impl_.bias_output__;
}
NeuralNetworkMessage::NeuralNetworkMessage(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:s21.NeuralNetworkMessage)
}
NeuralNetworkMessage::NeuralNetworkMessage(const NeuralNetworkMessage& from) : ::google::protobuf::Message() {
  NeuralNetworkMessage* const _this = this;
  (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){from._impl_._has_bits_},
      /*decltype(_impl_._cached_size_)*/ {},
      decltype(_impl_.weights_hidden__){from._impl_.weights_hidden__},
      decltype(_impl_.bias_hidden__){from._impl_.bias_hidden__},
      decltype(_impl_.weights_output__){nullptr},
      decltype(_impl_.bias_output__){nullptr},
      decltype(_impl_.learning_rate_){},
      decltype(_impl_.hidden_layers_count__){},
  };
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  if ((from._impl_._has_bits_[0] & 0x00000001u) != 0) {
    _this->_impl_.weights_output__ = new ::s21::MatrixMessage(*from._impl_.weights_output__);
  }
  if ((from._impl_._has_bits_[0] & 0x00000002u) != 0) {
    _this->_impl_.bias_output__ = new ::s21::MatrixMessage(*from._impl_.bias_output__);
  }
  ::memcpy(&_impl_.learning_rate_, &from._impl_.learning_rate_,
    static_cast<::size_t>(reinterpret_cast<char*>(&_impl_.hidden_layers_count__) -
    reinterpret_cast<char*>(&_impl_.learning_rate_)) + sizeof(_impl_.hidden_layers_count__));

  // @@protoc_insertion_point(copy_constructor:s21.NeuralNetworkMessage)
}
inline void NeuralNetworkMessage::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){},
      /*decltype(_impl_._cached_size_)*/ {},
      decltype(_impl_.weights_hidden__){arena},
      decltype(_impl_.bias_hidden__){arena},
      decltype(_impl_.weights_output__){nullptr},
      decltype(_impl_.bias_output__){nullptr},
      decltype(_impl_.learning_rate_){0},
      decltype(_impl_.hidden_layers_count__){0},
  };
}
NeuralNetworkMessage::~NeuralNetworkMessage() {
  // @@protoc_insertion_point(destructor:s21.NeuralNetworkMessage)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void NeuralNetworkMessage::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.weights_hidden__.~RepeatedPtrField();
  _impl_.bias_hidden__.~RepeatedPtrField();
  if (this != internal_default_instance()) delete _impl_.weights_output__;
  if (this != internal_default_instance()) delete _impl_.bias_output__;
}
void NeuralNetworkMessage::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

PROTOBUF_NOINLINE void NeuralNetworkMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:s21.NeuralNetworkMessage)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_mutable_weights_hidden_()->Clear();
  _internal_mutable_bias_hidden_()->Clear();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      ABSL_DCHECK(_impl_.weights_output__ != nullptr);
      _impl_.weights_output__->Clear();
    }
    if (cached_has_bits & 0x00000002u) {
      ABSL_DCHECK(_impl_.bias_output__ != nullptr);
      _impl_.bias_output__->Clear();
    }
  }
  ::memset(&_impl_.learning_rate_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.hidden_layers_count__) -
      reinterpret_cast<char*>(&_impl_.learning_rate_)) + sizeof(_impl_.hidden_layers_count__));
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* NeuralNetworkMessage::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 6, 4, 0, 2> NeuralNetworkMessage::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_._has_bits_),
    0, // no _extensions_
    6, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967232,  // skipmap
    offsetof(decltype(_table_), field_entries),
    6,  // num_field_entries
    4,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_NeuralNetworkMessage_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // double learning_rate = 1;
    {::_pbi::TcParser::FastF64S1,
     {9, 63, 0, PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.learning_rate_)}},
    // int32 hidden_layers_count_ = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(NeuralNetworkMessage, _impl_.hidden_layers_count__), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.hidden_layers_count__)}},
    // repeated .s21.MatrixMessage weights_hidden_ = 3;
    {::_pbi::TcParser::FastMtR1,
     {26, 63, 0, PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.weights_hidden__)}},
    // .s21.MatrixMessage weights_output_ = 4;
    {::_pbi::TcParser::FastMtS1,
     {34, 0, 1, PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.weights_output__)}},
    // repeated .s21.MatrixMessage bias_hidden_ = 5;
    {::_pbi::TcParser::FastMtR1,
     {42, 63, 2, PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.bias_hidden__)}},
    // .s21.MatrixMessage bias_output_ = 6;
    {::_pbi::TcParser::FastMtS1,
     {50, 1, 3, PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.bias_output__)}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // double learning_rate = 1;
    {PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.learning_rate_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kDouble)},
    // int32 hidden_layers_count_ = 2;
    {PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.hidden_layers_count__), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // repeated .s21.MatrixMessage weights_hidden_ = 3;
    {PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.weights_hidden__), -1, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
    // .s21.MatrixMessage weights_output_ = 4;
    {PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.weights_output__), _Internal::kHasBitsOffset + 0, 1,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // repeated .s21.MatrixMessage bias_hidden_ = 5;
    {PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.bias_hidden__), -1, 2,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
    // .s21.MatrixMessage bias_output_ = 6;
    {PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.bias_output__), _Internal::kHasBitsOffset + 1, 3,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::s21::MatrixMessage>()},
    {::_pbi::TcParser::GetTable<::s21::MatrixMessage>()},
    {::_pbi::TcParser::GetTable<::s21::MatrixMessage>()},
    {::_pbi::TcParser::GetTable<::s21::MatrixMessage>()},
  }}, {{
  }},
};

::uint8_t* NeuralNetworkMessage::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:s21.NeuralNetworkMessage)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // double learning_rate = 1;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_learning_rate = this->_internal_learning_rate();
  ::uint64_t raw_learning_rate;
  memcpy(&raw_learning_rate, &tmp_learning_rate, sizeof(tmp_learning_rate));
  if (raw_learning_rate != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteDoubleToArray(
        1, this->_internal_learning_rate(), target);
  }

  // int32 hidden_layers_count_ = 2;
  if (this->_internal_hidden_layers_count_() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<2>(
            stream, this->_internal_hidden_layers_count_(), target);
  }

  // repeated .s21.MatrixMessage weights_hidden_ = 3;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_weights_hidden__size()); i < n; i++) {
    const auto& repfield = this->_internal_weights_hidden_().Get(i);
    target = ::google::protobuf::internal::WireFormatLite::
        InternalWriteMessage(3, repfield, repfield.GetCachedSize(), target, stream);
  }

  cached_has_bits = _impl_._has_bits_[0];
  // .s21.MatrixMessage weights_output_ = 4;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessage(4, _Internal::weights_output_(this),
        _Internal::weights_output_(this).GetCachedSize(), target, stream);
  }

  // repeated .s21.MatrixMessage bias_hidden_ = 5;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_bias_hidden__size()); i < n; i++) {
    const auto& repfield = this->_internal_bias_hidden_().Get(i);
    target = ::google::protobuf::internal::WireFormatLite::
        InternalWriteMessage(5, repfield, repfield.GetCachedSize(), target, stream);
  }

  // .s21.MatrixMessage bias_output_ = 6;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessage(6, _Internal::bias_output_(this),
        _Internal::bias_output_(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:s21.NeuralNetworkMessage)
  return target;
}

::size_t NeuralNetworkMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:s21.NeuralNetworkMessage)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .s21.MatrixMessage weights_hidden_ = 3;
  total_size += 1UL * this->_internal_weights_hidden__size();
  for (const auto& msg : this->_internal_weights_hidden_()) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  // repeated .s21.MatrixMessage bias_hidden_ = 5;
  total_size += 1UL * this->_internal_bias_hidden__size();
  for (const auto& msg : this->_internal_bias_hidden_()) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // .s21.MatrixMessage weights_output_ = 4;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          *_impl_.weights_output__);
    }

    // .s21.MatrixMessage bias_output_ = 6;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          *_impl_.bias_output__);
    }

  }
  // double learning_rate = 1;
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_learning_rate = this->_internal_learning_rate();
  ::uint64_t raw_learning_rate;
  memcpy(&raw_learning_rate, &tmp_learning_rate, sizeof(tmp_learning_rate));
  if (raw_learning_rate != 0) {
    total_size += 9;
  }

  // int32 hidden_layers_count_ = 2;
  if (this->_internal_hidden_layers_count_() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_hidden_layers_count_());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData NeuralNetworkMessage::_class_data_ = {
    ::google::protobuf::Message::CopyWithSourceCheck,
    NeuralNetworkMessage::MergeImpl
};
const ::google::protobuf::Message::ClassData*NeuralNetworkMessage::GetClassData() const { return &_class_data_; }


void NeuralNetworkMessage::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<NeuralNetworkMessage*>(&to_msg);
  auto& from = static_cast<const NeuralNetworkMessage&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:s21.NeuralNetworkMessage)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_weights_hidden_()->MergeFrom(from._internal_weights_hidden_());
  _this->_internal_mutable_bias_hidden_()->MergeFrom(from._internal_bias_hidden_());
  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_mutable_weights_output_()->::s21::MatrixMessage::MergeFrom(
          from._internal_weights_output_());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_internal_mutable_bias_output_()->::s21::MatrixMessage::MergeFrom(
          from._internal_bias_output_());
    }
  }
  static_assert(sizeof(::uint64_t) == sizeof(double),
                "Code assumes ::uint64_t and double are the same size.");
  double tmp_learning_rate = from._internal_learning_rate();
  ::uint64_t raw_learning_rate;
  memcpy(&raw_learning_rate, &tmp_learning_rate, sizeof(tmp_learning_rate));
  if (raw_learning_rate != 0) {
    _this->_internal_set_learning_rate(from._internal_learning_rate());
  }
  if (from._internal_hidden_layers_count_() != 0) {
    _this->_internal_set_hidden_layers_count_(from._internal_hidden_layers_count_());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void NeuralNetworkMessage::CopyFrom(const NeuralNetworkMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:s21.NeuralNetworkMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool NeuralNetworkMessage::IsInitialized() const {
  return true;
}

void NeuralNetworkMessage::InternalSwap(NeuralNetworkMessage* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.weights_hidden__.InternalSwap(&other->_impl_.weights_hidden__);
  _impl_.bias_hidden__.InternalSwap(&other->_impl_.bias_hidden__);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.hidden_layers_count__)
      + sizeof(NeuralNetworkMessage::_impl_.hidden_layers_count__)
      - PROTOBUF_FIELD_OFFSET(NeuralNetworkMessage, _impl_.weights_output__)>(
          reinterpret_cast<char*>(&_impl_.weights_output__),
          reinterpret_cast<char*>(&other->_impl_.weights_output__));
}

::google::protobuf::Metadata NeuralNetworkMessage::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_neural_5fnetwork_2eproto_getter, &descriptor_table_neural_5fnetwork_2eproto_once,
      file_level_metadata_neural_5fnetwork_2eproto[0]);
}
// ===================================================================

class MatrixMessage::_Internal {
 public:
};

MatrixMessage::MatrixMessage(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:s21.MatrixMessage)
}
MatrixMessage::MatrixMessage(const MatrixMessage& from) : ::google::protobuf::Message() {
  MatrixMessage* const _this = this;
  (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.data__){from._impl_.data__},
      /*decltype(_impl_._cached_size_)*/ {},
  };
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);

  // @@protoc_insertion_point(copy_constructor:s21.MatrixMessage)
}
inline void MatrixMessage::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.data__){arena},
      /*decltype(_impl_._cached_size_)*/ {},
  };
}
MatrixMessage::~MatrixMessage() {
  // @@protoc_insertion_point(destructor:s21.MatrixMessage)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void MatrixMessage::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.data__.~RepeatedPtrField();
}
void MatrixMessage::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

PROTOBUF_NOINLINE void MatrixMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:s21.MatrixMessage)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_mutable_data_()->Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* MatrixMessage::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 1, 0, 2> MatrixMessage::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_MatrixMessage_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // repeated .s21.Vector data_ = 1;
    {::_pbi::TcParser::FastMtR1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(MatrixMessage, _impl_.data__)}},
  }}, {{
    65535, 65535
  }}, {{
    // repeated .s21.Vector data_ = 1;
    {PROTOBUF_FIELD_OFFSET(MatrixMessage, _impl_.data__), 0, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::s21::Vector>()},
  }}, {{
  }},
};

::uint8_t* MatrixMessage::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:s21.MatrixMessage)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // repeated .s21.Vector data_ = 1;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_data__size()); i < n; i++) {
    const auto& repfield = this->_internal_data_().Get(i);
    target = ::google::protobuf::internal::WireFormatLite::
        InternalWriteMessage(1, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:s21.MatrixMessage)
  return target;
}

::size_t MatrixMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:s21.MatrixMessage)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .s21.Vector data_ = 1;
  total_size += 1UL * this->_internal_data__size();
  for (const auto& msg : this->_internal_data_()) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData MatrixMessage::_class_data_ = {
    ::google::protobuf::Message::CopyWithSourceCheck,
    MatrixMessage::MergeImpl
};
const ::google::protobuf::Message::ClassData*MatrixMessage::GetClassData() const { return &_class_data_; }


void MatrixMessage::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<MatrixMessage*>(&to_msg);
  auto& from = static_cast<const MatrixMessage&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:s21.MatrixMessage)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_data_()->MergeFrom(from._internal_data_());
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void MatrixMessage::CopyFrom(const MatrixMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:s21.MatrixMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool MatrixMessage::IsInitialized() const {
  return true;
}

void MatrixMessage::InternalSwap(MatrixMessage* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.data__.InternalSwap(&other->_impl_.data__);
}

::google::protobuf::Metadata MatrixMessage::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_neural_5fnetwork_2eproto_getter, &descriptor_table_neural_5fnetwork_2eproto_once,
      file_level_metadata_neural_5fnetwork_2eproto[1]);
}
// ===================================================================

class Vector::_Internal {
 public:
};

Vector::Vector(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:s21.Vector)
}
Vector::Vector(const Vector& from) : ::google::protobuf::Message() {
  Vector* const _this = this;
  (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.data__){from._impl_.data__},
      /*decltype(_impl_._cached_size_)*/ {},
  };
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);

  // @@protoc_insertion_point(copy_constructor:s21.Vector)
}
inline void Vector::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.data__){arena},
      /*decltype(_impl_._cached_size_)*/ {},
  };
}
Vector::~Vector() {
  // @@protoc_insertion_point(destructor:s21.Vector)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Vector::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.data__.~RepeatedField();
}
void Vector::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

PROTOBUF_NOINLINE void Vector::Clear() {
// @@protoc_insertion_point(message_clear_start:s21.Vector)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_mutable_data_()->Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Vector::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 0, 2> Vector::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Vector_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // repeated double data_ = 1;
    {::_pbi::TcParser::FastF64P1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Vector, _impl_.data__)}},
  }}, {{
    65535, 65535
  }}, {{
    // repeated double data_ = 1;
    {PROTOBUF_FIELD_OFFSET(Vector, _impl_.data__), 0, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kPackedDouble)},
  }},
  // no aux_entries
  {{
  }},
};

::uint8_t* Vector::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:s21.Vector)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // repeated double data_ = 1;
  if (this->_internal_data__size() > 0) {
    target = stream->WriteFixedPacked(1, _internal_data_(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:s21.Vector)
  return target;
}

::size_t Vector::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:s21.Vector)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated double data_ = 1;
  {
    std::size_t data_size = std::size_t{8} *
        ::_pbi::FromIntSize(this->_internal_data__size())
    ;
    std::size_t tag_size = data_size == 0
        ? 0
        : 1 + ::_pbi::WireFormatLite::Int32Size(
                            static_cast<int32_t>(data_size))
    ;
    total_size += tag_size + data_size;
  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData Vector::_class_data_ = {
    ::google::protobuf::Message::CopyWithSourceCheck,
    Vector::MergeImpl
};
const ::google::protobuf::Message::ClassData*Vector::GetClassData() const { return &_class_data_; }


void Vector::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<Vector*>(&to_msg);
  auto& from = static_cast<const Vector&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:s21.Vector)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_data_()->MergeFrom(from._internal_data_());
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Vector::CopyFrom(const Vector& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:s21.Vector)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Vector::IsInitialized() const {
  return true;
}

void Vector::InternalSwap(Vector* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.data__.InternalSwap(&other->_impl_.data__);
}

::google::protobuf::Metadata Vector::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_neural_5fnetwork_2eproto_getter, &descriptor_table_neural_5fnetwork_2eproto_once,
      file_level_metadata_neural_5fnetwork_2eproto[2]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace s21
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"

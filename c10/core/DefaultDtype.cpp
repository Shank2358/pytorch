#include <c10/util/typeid.h>
#include <c10/core/DefaultDtype.h>

namespace c10 {
static auto default_dtype = caffe2::TypeMeta::Make<float>();
static auto default_dtype_as_scalartype = typeMetaToScalarType(default_dtype);
static auto default_complex_dtype = caffe2::TypeMeta::Make<c10::complex<float>>();

void set_default_dtype(caffe2::TypeMeta dtype) {
  default_dtype = std::move(dtype);
  default_dtype_as_scalartype = typeMetaToScalarType(default_dtype);
  if(default_dtype_as_scalartype == ScalarType::Double) {
    default_complex_dtype = std::move(caffe2::TypeMeta::Make<c10::complex<double>>());
  } else {
    default_complex_dtype = std::move(caffe2::TypeMeta::Make<c10::complex<float>>());
  }
}

const caffe2::TypeMeta& get_default_dtype() {
  return default_dtype;
}
ScalarType get_default_dtype_as_scalartype() {
  return default_dtype_as_scalartype;
}
const caffe2::TypeMeta& get_default_complex_dtype() {
  return default_complex_dtype;
}
} // namespace c10

#include "RE/Bethesda/BSScript/Variable.hpp"

#include "RE/Bethesda/BSScript/Array.hpp"
#include "RE/Bethesda/BSScript/Object.hpp"
#include "RE/Bethesda/BSScript/Struct.hpp"

namespace RE::BSScript
{
	Variable& Variable::operator=(BSTSmartPointer<Object> a_object)
	{
		reset();

		if (!a_object) {
			return *this;
		}

		varType = a_object->GetTypeInfo();
		value.o = std::move(a_object);
		assert(is<Object>());
		return *this;
	}

	Variable& Variable::operator=(BSTSmartPointer<Struct> a_struct)
	{
		reset();

		if (!a_struct) {
			return *this;
		}

		varType = a_struct->GetTypeInfo();
		value.t = std::move(a_struct);
		assert(is<Struct>());
		return *this;
	}

	Variable& Variable::operator=(BSTSmartPointer<Array> a_array)
	{
		reset();

		if (!a_array) {
			return *this;
		}

		varType = a_array->elementType;
		value.a = std::move(a_array);
		varType.SetArray(true);
		assert(is<Array>());
		return *this;
	}

	void Variable::reset()
	{
		switch (varType.GetRawType()) {
			case RawType::kObject:
				value.o.reset();
				break;
			case RawType::kString:
				value.s.~BSFixedString();
				break;
			case RawType::kVar:
				delete value.v;
				break;
			case RawType::kStruct:
				value.t.reset();
				break;
			case RawType::kArrayObject:
			case RawType::kArrayString:
			case RawType::kArrayInt:
			case RawType::kArrayFloat:
			case RawType::kArrayBool:
			case RawType::kArrayVar:
			case RawType::kArrayStruct:
				value.a.reset();
				break;
			case RawType::kNone:
			case RawType::kInt:
			case RawType::kFloat:
			case RawType::kBool:
				break;
			default:
				assert(false);
				break;
		}

		varType = RawType::kNone;
		value.v = nullptr;
		assert(is<std::nullptr_t>());
	}

	// NOLINTNEXTLINE(misc-no-recursion)
	void Variable::copy(const Variable& a_rhs)
	{
		assert(varType.GetRawType() == RawType::kNone);
		assert(value.v == nullptr);

		switch (a_rhs.varType.GetRawType()) {
			case RawType::kObject:
				value.o = a_rhs.value.o;
				break;
			case RawType::kString:
				value.s = a_rhs.value.s;
				break;
			case RawType::kVar:
				if (a_rhs.value.v) {
					value.v = new Variable(*a_rhs.value.v);
				}
				break;
			case RawType::kStruct:
				value.t = a_rhs.value.t;
				break;
			case RawType::kArrayObject:
			case RawType::kArrayString:
			case RawType::kArrayInt:
			case RawType::kArrayFloat:
			case RawType::kArrayBool:
			case RawType::kArrayVar:
			case RawType::kArrayStruct:
				value.a = a_rhs.value.a;
				break;
			case RawType::kNone:
				break;
			case RawType::kInt:
				value.u = a_rhs.value.u;
				break;
			case RawType::kFloat:
				value.f = a_rhs.value.f;
				break;
			case RawType::kBool:
				value.b = a_rhs.value.b;
				break;
			default:
				assert(false);
				break;
		}

		varType = a_rhs.varType;
	}
}

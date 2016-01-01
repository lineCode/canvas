#ifndef _CANVAS_FLOATATTRIBUTE_H_
#define _CANVAS_FLOATATTRIBUTE_H_

#include "Attribute.h"

#include <string>

namespace canvas {
  class FloatAttribute : public Attribute {
  public:
    FloatAttribute(GraphicsState * _context, float _value = 0.0f) : Attribute(_context), value(_value) { }
    FloatAttribute(GraphicsState * _context, const FloatAttribute & other)
      : Attribute(_context), value(other.value) { }
    FloatAttribute(const FloatAttribute & other) = delete;
    
    FloatAttribute & operator=(const FloatAttribute & other) { value = other.value; return *this; }
    FloatAttribute & operator=(const std::string & s) { value = stof(s); return *this; }
    FloatAttribute & operator=(const float & _value) { value = _value; return *this; }

    GraphicsState & operator()(const std::string & s) { value = stof(s); return *context; }
    GraphicsState & operator()(const float & _value) { value = _value; return *context; }

    float getValue() const { return value; }
    
  private:
    float value;
  };
};

#endif

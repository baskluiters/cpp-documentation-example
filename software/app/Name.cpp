/*
Copyright © 2022 Bas Kluiters

Permission is hereby granted, free of charge, to any person obtaining a copy of this 
software and associated documentation files (the “Software”), to deal in the Software 
without restriction, including without limitation the rights to use, copy, modify, 
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
permit persons to whom the Software is furnished to do so, subject to the following 
conditions:

The above copyright notice and this permission notice shall be included in all copies 
or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Name.h"
#include <string.h>
#ifdef ARDUINO
#include "aux.h"
#endif

Name::Name(const char *name) {
  _name = name;
  _base = NULL;
}

Name::Name(Name *base) {
  _name = NULL;
  _base = NULL;
  if( base ) {
    _name = base->_name;
    _base = base->_base;
    delete base;
  }
}

unsigned Name::print(unsigned padding, char separator) {
  unsigned printed = 0;
  if( _base ) {
    printed += _base->print();
    if( _name ) {
      printf("%c", separator);
      printed++;
    }
  }
  if( _name ) {
    printf("%s", _name);
    printed += strlen(_name);
  }
  if( padding ) {
    for(unsigned i = printed; i < padding; i++ ) {
      printf(" ");
      printed++;
    }
  }
  return printed;
}

void Name::fillWithName(char **p, char separator) {
  if( _base ) {
    _base->fillWithName(p);
    if( _name )
      *(*p)++ = separator;
  }
  if( _name ) {
    sprintf(*p, "%s", _name);
    (*p) += strlen(_name);
  }
}

void Name::snprint(char *p, size_t len) {
  fillWithName(&p);
}

// Name::~Name() {
// Do not delete _base as it is used when Name object is copied. 
//   if( _base )
//     delete _base;
// }

int Name::_compare(const char **p) {
  int retval;
  if( _base ) {
    retval = _base->_compare(p);
    if( retval ) // unequal
      return retval;
    retval = '.' - **p;
    if( retval ) // unequal
      return retval;
    *p = *p + 1; // skipping the dot
  }
  if( _name ) {
    retval = strncmp(*p, _name, strlen(_name));
    *p += strlen(_name);
    return retval;
  }
  return 42; // Exceptional value. Just not zero
}

int Name::compare(const char *p) {
  if( !p )
    return 42; // Exceptional value. Just not zero
  return _compare(&p);
}

int Name::compareName(Name *p) {
  if( !p )
    return 42; // Exceptional value. Just not zero
  int retval;
  if( _base && !p->_base ) {
    retval = _base->compareName(p);
    if( retval )
      return retval;
  }
  if( !_base && p->_base ) {
    retval = compareName(p->_base);
    if( retval )
      return retval;
  }
  if( _base && p->_base ) {
    retval = _base->compareName(p->_base);
    if( retval )
      return retval;
  }
  return strcmp(_name, p->_name);
}

void Name::setAsBase(Name *base) {
  _base = base;
}

Name *Name::Multi(const char *a, const char *b, const char *c, const char *d, const char *e) {
  Name *retval  = NULL;
  const char *ptrs[] = {a,b,c,d,e};
  for(unsigned i = 0; i < sizeof(ptrs)/sizeof(ptrs[0]); i++) {
    const char *p = ptrs[i];
    if( p ) {
      Name *tmp = new Name(p);
      tmp->setAsBase(retval);
      retval = tmp;
    }
  }
  return retval;
}

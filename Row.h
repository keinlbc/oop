#pragma once
#include "ColInt.h"
#include "ColFloat.h"
#include "ColString.h"
class Row{

private:

  ColumnBase** columns;
	size_t count;
	size_t capacity;
	void resize();
	void copy(const Row& row);
	void destroy();


      static ColumnBase* createCopy(const ColumnBase* other = NULL)
      {
        if(other == NULL)return NULL;

        ColumnBase* out = NULL;
        switch(other->getType())
        {
        case ColumnBase::TYPE_INT:
        {
          ColInt* t = new ColInt();
          t->setValue(((ColInt*)other)->getValue());
          out = t;
        }
        break;

        case ColumnBase::TYPE_FLOAT:
        {
        ColFloat* t = new ColFloat();
        t->setValue(((ColFloat*)other)->getValue());
        out = t;
        }
        break;

        case ColumnBase::TYPE_STRING:
        {
        ColString* t = new ColString();
        t->setValue(((ColString*)other)->getValue());
        out = t;
        }
        break;

      }

      return out;
    }

public:

	Row();
	Row(const Row& Row);
	Row& operator= (const Row& row);
	~Row();
	bool addColumn(const ColumnBase* col);

    ColumnBase** getColumns();

};

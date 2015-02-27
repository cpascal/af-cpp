#ifndef APDOS_PLUGINS_UUID_OBJECT_ID_H
#define APDOS_PLUGINS_UUID_OBJECT_ID_H

#include <iostream>
#include <boost\shared_ptr.hpp>

namespace apdos {
  namespace plugins {
    namespace uuid {

      class Object_Id {
      public:
        Object_Id();
        Object_Id(std::string id);
        virtual ~Object_Id();

        std::string get_value() { return id; }

        bool operator==(Object_Id id);

        virtual bool is_null() { return false; }

      private:
        std::string id;
      };
    }
  }
}

typedef boost::shared_ptr<apdos::plugins::uuid::Object_Id> Object_Id_Shared_Ptr;

#endif //APDOS_PLUGINS_UUID_OBJECT_ID_H
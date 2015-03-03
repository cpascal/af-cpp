#ifndef APDOS_KERNEL_ACTOR_ACTOR_CONNECTER_H
#define APDOS_KERNEL_ACTOR_ACTOR_CONNECTER_H

#include <iostream>
#include <vector>
#include <queue>
#include <apdos/kernel/actor/component.h>
#include <apdos/kernel/event/event.h>

namespace apdos {
  namespace kernel {
    namespace actor {
      namespace connecters {
        class Actor_Connecter: public Component {
        public:
          static const int READ_BUFFER_SIZE = 8192;

          Actor_Connecter();
          virtual ~Actor_Connecter();

          void send_by_path(std::string sender_path, std::string receiver_path, apdos::kernel::event::Event event);

          void process_data(std::vector<char> &recv_data, size_t recv_size);
        protected:

          virtual void write(std::string &data) = 0;

        private:
          std::vector<std::string> get_messages();
          // 전송받고 있는 이벤트 데이터가 있는지 조사 
          bool has_fragment_message(std::vector<std::string>& messages);
          std::vector<std::string> get_address_tokens(std::string address);

          void process_event(std::string message);

        private:
          int read_index;
          std::string send_buffer;
          std::vector<char> recv_buffer;
        };
      }
    }
  }
}

#endif //APDOS_KERNEL_ACTOR_ACTOR_CONNECTER_H
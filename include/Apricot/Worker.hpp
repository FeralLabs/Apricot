#include <Apricot/Threads.hpp>
#include <Apricot/Request.hpp>

#pragma once

namespace Apricot {
    class Worker : public Thread {
        private:
            RequestPool<Request*>& RP;
        public:
            Worker(RequestPool <Request*>& Pool) : RP(Pool) {}

            void* run() {
                for ( int i = 0 ;; i++ ) {
                    Request* Req = RP.remove();
                    delete Req;
                }

                return NULL;
            }
    };
}

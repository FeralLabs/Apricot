#include <pthread.h>
#include <list>

#pragma once

namespace Apricot {
    class Thread
    {
        public:
            virtual void* run() = 0;

            static void* runThread(void *arg) {
                return ((Thread*)arg)->run();
            }

            Thread () : uID(0), isRunning(false), isDetached(false) {}
            ~Thread() {
                if (isRunning && isDetached == false)
                    pthread_detach(uID);

                if (isRunning)
                    pthread_cancel(uID);
            }

            int join() {
                int result = -1;
                if ( isRunning == true ) {
                    result = pthread_join(uID, NULL);

                    if ( result == 0 ) {
                        isDetached = false;
                    }
                }

                return result;
            }

            int detach() {
                int result = -1;
                if ( isRunning && isDetached == false ) {
                    result = pthread_detach(uID);
                    if ( result == 0 ) {
                        isDetached = true;
                    }
                }

                return result;
            }

            int start() {
                int result = pthread_create(&uID, NULL, runThread, this);
                if ( result == 0 )
                    isRunning = true;

                return result;
            }

            pthread_t self() {
                return this -> uID;
            }
        private:
            bool isRunning;
            bool isDetached;
            pthread_t uID;
    };

    template <typename T> class RequestPool {
        public:
            std::list <T>       Pool;
            pthread_mutex_t     Mutex;
            pthread_cond_t      CondV;

            RequestPool() {
                pthread_mutex_init(&Mutex, NULL);
                pthread_cond_init(&CondV, NULL);
            }

            ~RequestPool() {
                pthread_mutex_destroy(&Mutex);
                pthread_cond_destroy(&CondV);
            }

            void add (T item) {
                pthread_mutex_lock(&Mutex);
                Pool.push_back(item);
                pthread_cond_signal(&CondV);
                pthread_mutex_unlock(&Mutex);
            }

            T remove () {
                pthread_mutex_lock (&Mutex);

                while (Pool.size() == 0) {
                    pthread_cond_wait(&CondV, &Mutex);
                }

                T item = Pool.front();
                
                pthread_mutex_unlock (&Mutex);
                return item;
            }

            int size() {
                pthread_mutex_lock(&Mutex);
                int size = Pool.size(0);
                pthread_mutex_unlock(&Mutex);
                return size;
            }

        private:
    };
}

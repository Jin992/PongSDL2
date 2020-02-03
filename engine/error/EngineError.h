//
// Created by jin on 2/1/20.
//

#ifndef PONGSDL2_ENGINEERROR_H
#define PONGSDL2_ENGINEERROR_H

#include <string>

namespace Engine {
    namespace Error {
        class EngineError {
        public:
            EngineError();

            void err_msg(std::string const&);
            std::string err_msg();

            explicit operator bool() const;

        private:
            std::string _err_msg;
        };
    }
}



#endif //PONGSDL2_ENGINEERROR_H

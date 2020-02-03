//
// Created by jin on 2/1/20.
//

#include "EngineError.h"

namespace Engine {
    namespace Error {
        EngineError::EngineError()
        {}

        void EngineError::err_msg(std::string const&msg){
            _err_msg = msg;
        }

        std::string EngineError::err_msg(){
            return _err_msg;
        }

        EngineError::operator bool() const{
            return !_err_msg.empty();
        }
    }
}
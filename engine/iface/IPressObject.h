//
// Created by User on 03.02.2020.
//

#ifndef PONGSDL2_IPRESSOBJECT_H
#define PONGSDL2_IPRESSOBJECT_H

namespace Engine {

    typedef std::function<void(SDL_KeyboardEvent &)> engine_key_hdl;

	class IPressObject {
    public:
        virtual ~IPressObject() = 0;

		void onKeyPressDown(SDL_KeyboardEvent &event){
		    if (_pressDown != nullptr) _pressDown(event);
		    else throw std::string(__FUNCTION__ ) + std::string( " uninitialized handler.");
		};
		void onKeyPressUp(SDL_KeyboardEvent &event) {
		    if (_pressUp != nullptr) _pressUp(event);
		    else throw std::string(__FUNCTION__ ) + std::string( " uninitialized handler.");
		}
		void setOnKeyPressDown_hdl(engine_key_hdl func) {
		    _pressDown = func;
		}
		void setOnKeyPressUp_hdl(engine_key_hdl func){
		    _pressUp = func;
		}
        bool pressed() const {
            return _status;
        }
        void pressed(bool status){
            _status = status;
        }

    private:
	    bool            _status;
        engine_key_hdl _pressDown;
        engine_key_hdl _pressUp;

	};

	inline IPressObject::~IPressObject() {}
}

#endif //PONGSDL2_IPRESSOBJECT_H

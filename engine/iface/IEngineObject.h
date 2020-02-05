//
// Created by User on 03.02.2020.
//

#ifndef PONGSDL2_IENGINEOBJECT_H
#define PONGSDL2_IENGINEOBJECT_H

#include <cstdint>

namespace Engine {
	class IEngineObject {
	public:
	    enum {
	        Static,
	        Movable,
	        Pressable,
	        Collidable
	    };
		int32_t	type() const { return _type;}
		void	type(int32_t v) { _type = v;}
		virtual ~IEngineObject() = 0; // use pure virtual destructor

	private:
		int64_t _type;
	};

	inline IEngineObject::~IEngineObject() {}
}
#endif //PONGSDL2_IENGINEOBJECT_H
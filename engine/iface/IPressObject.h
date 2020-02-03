//
// Created by User on 03.02.2020.
//

#ifndef PONGSDL2_IPRESSOBJECT_H
#define PONGSDL2_IPRESSOBJECT_H

namespace Engine {
	class IPressObject {
		virtual void onClickDown(SDL_KeyboardEvent &event) = 0;
		virtual void onClickUp(SDL_KeyboardEvent &event) = 0;
		virtual void onKeyPressDown(SDL_KeyboardEvent &event) = 0;
		virtual void onKeyPressUp(SDL_KeyboardEvent &event) = 0;
		virtual IPressObject() = default;
	};
}

#endif //PONGSDL2_IPRESSOBJECT_H

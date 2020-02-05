//
// Created by jin on 04.02.20.
//

#include "GameFieldScene.h"

namespace PongGame {
    void GameFieldScene::sceneEvent(SDL_Event &ev) {

        for_each_entity([&ev](Engine::entity::engine_entity_ptr entity) {

            if (entity->type() != Engine::IEngineObject::Pressable) return;
            if (ev.type == SDL_KEYDOWN) {}
               /* switch (ev.key.keysym.sym) {
                    case SDLK_DOWN:
                        _menu->nextIndex();
                        break;

                    case SDLK_UP:
                        _menu->prevIndex();
                        break;

                    case SDLK_RETURN:
                        std::cout << "ENTER PRESSED" << std::endl;
                        break;

                    default:
                        break;
                }
            }*/
        });
    }

    void GameFieldScene::render(Engine::Renderer::engine_renderer &renderer) {
        for_each_entity([&renderer](Engine::entity::engine_entity_ptr entity) {
            entity->render(renderer);
        });
    }

    void GameFieldScene::update() {

    }
}
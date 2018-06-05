#ifndef PLAYING_H_INCLUDED
#define PLAYING_H_INCLUDED

#include "Game_State.h"

#include "../Model.h"
#include "../Shaders/Simple_Shader.h"
#include "../Textures/Texture_Atlas.h"

#include "../Temp/Quad.h"

class Application;
class Camera;

namespace State
{
    class Playing : public Game_State
    {
    public:
        Playing(Application& application);

        void input(Camera& camera) override;
        void update(Camera& camera, float dt) override;
        void draw(Renderer::Master& renderer) override;
    private:
        Shader::Simple_Shader m_shader;
        Texture::Atlas m_texture;

        Quad m_quad;
        std::vector<Quad*> m_quads;
    };
}

#endif // PLAYING_H_INCLUDED

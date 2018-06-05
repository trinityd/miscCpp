#include "Playing.h"

#include <SFML/System/Clock.hpp>

#include "../Renderer/Master.h"

#include "../Camera.h"

namespace State
{
    sf::Clock clock;

    Playing::Playing(Application& application)
    : Game_State(application)
    , m_texture("Texture_Atlas", 512, 16)
    , m_quad(m_texture)
    {
        m_texture.bind();

        m_quad.position.z -= 2;
        m_quad.position.y -= 2;
    }

    void Playing::input(Camera& camera)
    {

    }

    void Playing::update(Camera& camera, float dt)
    {
        camera.input(dt);

//        m_quad.position.x = sin(clock.getElapsedTime().asSeconds());
    }

    void Playing::draw(Renderer::Master& renderer)
    {
        renderer.draw(m_quad);
//        for(auto& quad : m_quads)
//        {
//            renderer.draw(*quad);
//        }
    }
}

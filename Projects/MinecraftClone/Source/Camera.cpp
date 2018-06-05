#include "Camera.h"

#include <cmath>
#include <iostream>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "Display.h"

#include "Math/Matrix_Math.h"

Camera::Camera()
: m_projectionMatrix(Math::createProjMatrix())
{}

void Camera::update()
{
    m_viewMatrix = Math::createViewMatrix(*this);
}

void Camera::input(float dt)
{
    Vector3 change;
    float speed = 2;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        change.x += -cos(glm::radians(rotation.y + 90)) * speed;
        change.z += -sin(glm::radians(rotation.y + 90)) * speed;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        change.x += cos(glm::radians(rotation.y + 90)) * speed;
        change.z += sin(glm::radians(rotation.y + 90)) * speed;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        change.x += -cos(glm::radians(rotation.y)) * speed;
        change.z += -sin(glm::radians(rotation.y)) * speed;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        change.x += cos(glm::radians(rotation.y)) * speed;
        change.z += sin(glm::radians(rotation.y)) * speed;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        change.y += speed;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        change.y -= speed;
    }

    position += change * dt;

    mouseInput();
}

void Camera::mouseInput()
{
    static sf::Vector2i lastMousePosition = sf::Mouse::getPosition();

    auto mouseChange = sf::Mouse::getPosition() - lastMousePosition;

    rotation.y += mouseChange.x * 0.5;
    rotation.x += mouseChange.y * 0.5;

    if(rotation.x > 90)
    {
        rotation.x = 90;
    }
    else if(rotation.x < -90)
    {
        rotation.x = -90;
    }

    if(rotation.y > 360)
    {
        rotation.y = 0;
    }
    else if(rotation.y < 0)
    {
        rotation.y = 360;
    }

    auto centerX = Display::WIDTH / 2;
    auto centerY = Display::HEIGHT / 2;

    sf::Mouse::setPosition(sf::Vector2i{centerX, centerY}, Display::get());

    lastMousePosition = sf::Mouse::getPosition();
}

const Matrix4& Camera::getViewMatrix() const
{
    return m_viewMatrix;
}

const Matrix4& Camera::getProjMatrix() const
{
    return m_projectionMatrix;
}



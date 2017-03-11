#include "Player.h"

#include <SFML/Graphics.hpp>

#include "Camera.h"
#include "World/Chunk/CMap.h"
#include "Input/Key_Binds.h"


Player::Player(Camera& camera)
:   m_p_camera  (&camera)
,   box         ({0.5, 0.5, 0.5})
{
    position = {5000, 100, 5000};
}

void Player::addForce(const Vector3& force)
{
    m_velocity += force;
}

void Player::testForCollide(Chunk::Map& chunkMap, float dt)
{
    if (!m_isOnGround)
    {
        m_velocity.y -= 1;
    }
    m_isOnGround = false;

    position.x += m_velocity.x * dt;
    collisionTest(chunkMap, dt, m_velocity.x, 0, 0);

    position.y += m_velocity.y * dt;
    collisionTest(chunkMap, dt, 0, m_velocity.y, 0);

    position.z += m_velocity.z * dt;
    collisionTest(chunkMap, dt, 0, 0, m_velocity.z);



    //box.update(position + (m_velocity * dt));
}

float size = 0.45;
float height = 1.75;

void Player::collisionTest( Chunk::Map& chunkMap,
                            float dt,
                            float vx,
                            float vy,
                            float vz)
{
    for (int x = position.x - size; x < position.x + size; x++)
    for (int y = position.y - height; y < position.y + height; y++)
    for (int z = position.z - size; z < position.z + size; z++)
    if (chunkMap.getBlockAt({x, y, z}) != Block::ID::Air)
    {
        if (vx > 0)
        {
            position.x = x - size;
        }
        if (vx < 0)
        {
            position.x = x + size + 1;
        }
        if (vy > 0)
        {
            position.y = y - height;
        }
        if (vy < 0)
        {
            position.y = y + height + 1;
            m_isOnGround = true;
        }
        if (vz > 0)
        {
            position.z = z - size;
        }
        if (vz < 0)
        {
            position.z = z + size + 1;
        }
    }
}




void Player::input()
{
    /*
    static sf::Clock c;
    if (c.getElapsedTime().asSeconds() >= 0.5)
    {
        std::cout << "Y: " << position.y << std::endl;
        c.restart();
    }
    */

    if (sf::Keyboard::isKeyPressed(Key_Binds::getKey(Key_Binds::Control::Player_Up)))
    {
        if (m_isOnGround)
        {
            m_velocity.y += 100;
        }
    }


    addForce(m_p_camera->input());
    rotation = m_p_camera->rotation;
    m_p_camera->position = position;
}

void Player::update(float dt)
{
    if (position.x < 0.2)
    {
        position.x = 0.2;
    }
    if (position.z < 0.2)
    {
        position.z = 0.2;
    }

    m_velocity *= 0.95;
}

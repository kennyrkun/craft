#ifndef CHUNK_RENDERER_H
#define CHUNK_RENDERER_H

#include "Chunk_Shader.h"

#include <vector>

class Chunk;
class Camera;

class Chunk_Renderer
{
    public:
        Chunk_Renderer ();

        void renderChunk    ( const Chunk& chunk );
        void render         ( const Camera& camera );

    private:
        void prepareChunk   ( const Chunk& chunk );

        Chunk_Shader m_shader;

        std::vector<const Chunk*> m_chunks;
};

#endif // CHUNK_RENDERER_H
#include "../Render/Texture.h"
#include "../Render/TextureManager.h"
#include "../Render/Vertex.h"
#include "../helpers.h"
#include "ActorHouse.h"

ActorHouse::ActorHouse(GLfloat x, GLfloat y, GLfloat z, GLfloat size) :
    TexturedActor(x, y, size, z)
{
    m_shader->Load("Data/Shaders/house");
    m_texture = TextureManager::GetInstance()->GetTexture("Data/Textures/house.png");

    ShapeData<TexturedVertex> *vertexData = shapeGenerator::generateTexturedQuad(0, -m_size / 2, m_z, m_size, m_size);

    m_VAO->GetVBO()->Bind(GL_ARRAY_BUFFER);
    m_VAO->GetVBO()->AddData(vertexData->vertices, vertexData->vertexBufferSize());
    m_VAO->GetVBO()->UploadDataToGPU(GL_STATIC_DRAW);

    BindShaderAttributesAndUniforms();

    m_VAO->Generate<TexturedVertex>(m_shader, vertexData, "inPosition", 0);
    m_VAO->Generate<TexturedVertex>(m_shader, vertexData, "inCoord", 1);

    delete vertexData;
}

ActorHouse::~ActorHouse()
{
}

void ActorHouse::Draw()
{
    TexturedActor::Draw();

    m_shader->Bind();
    glDrawArrays(GL_QUADS, 0, 4);
    m_shader->UnBind();
}

void ActorHouse::BindShaderAttributesAndUniforms()
{
    TexturedActor::BindShaderAttributesAndUniforms();

    m_shader->RegisterAttribute({ "inPosition", "inCoord" });
    m_shader->RegisterUniform("gSampler");

    glUniform1i(m_shader->GetUniformLocation("gSampler"), 0);
}

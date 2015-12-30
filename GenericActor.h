#pragma once

#include <GL\glew.h>
#include "Shader.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"

class GenericActor
{
public:
	GenericActor(GLfloat x, GLfloat y, GLfloat z = 0.0f, bool animated = true) :
		m_x(x),
		m_y(y),
        m_z(z),
		m_animated(animated),
        m_shader(NULL),
        m_VAO(NULL)
    {
        m_VAO = new VertexArrayObject();
        m_shader = new Shader();
    }

	virtual ~GenericActor()
    {
        if (m_shader)
        {
            delete m_shader;
            m_shader = NULL;
        }

        if (m_VAO)
        {
            delete m_VAO;
            m_VAO = NULL;
        }
    }

    virtual void Draw()
    {
        m_VAO->Bind();
    }
    virtual void Animate() { Draw(); }

	virtual void Move(GLfloat xShift, GLfloat yShift)
	{
		m_x += xShift;
		m_y += yShift;
	}

    GLfloat X() { return m_x; }
    GLfloat Y() { return m_y; }
    GLfloat Z() { return m_z; }

protected:
    GLfloat m_x, m_y, m_z;
	bool   m_animated;

    Shader *m_shader;
    VertexArrayObject *m_VAO;
};

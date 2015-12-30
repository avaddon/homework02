#include "homework02.h"
#include "Scene.h"
#include "ActorSun.h"
#include "ActorCloud.h"
#include "ActorBackgroundMountain.h"

Scene::Scene(GLuint width, GLuint height) :
    GenericScene(width, height),
    m_sun(NULL)
{
    AddActor("sun", new ActorSun(100.0f, 100.0f, -0.19f, 100.0f));
    AddActor("cloud01", new ActorCloud(0, 0, (GLfloat)m_sceneWidth, (GLfloat)m_sceneHeight / 1.5f, -0.2f));
    AddActor("background_mountain", new ActorBackgroundMountain((GLfloat)m_sceneWidth, (GLfloat)m_sceneHeight, -0.1f));
}


Scene::~Scene()
{}

void Scene::Draw()
{
    RecalcBackground();

    GenericScene::Draw();

    GenericActor *sun = GetActor("sun");
    double x = sun->X();
    if (x < m_sceneWidth - 100)
    {
        sun->Move(0.01f, 0);
    }
}

GenericActor* Scene::GetActor(std::string name)
{
    if (name == "sun")
    {
        m_sun = m_sun != NULL ? m_sun : GenericScene::GetActor(name);
        return m_sun;
    }

    return GenericScene::GetActor(name);
}

void Scene::RecalcBackground()
{
    GLfloat sunX = GetActor("sun")->X();

    if ((sunX < 0) || (sunX > m_sceneWidth))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
        return;
    }

    GLfloat step = (GLfloat)m_sceneWidth / 255;
    GLfloat blue = sunX / step / 255;

    glClearColor(0.0f, 0.0f, blue, 1.0f);
}

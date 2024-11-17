#include "GunBrosApp.h"
#include <SDL2/SDL.h>

GunBrosApp::GunBrosApp() : OgreBites::ApplicationContextBase("GunBros Simplificado") {}

// //vectores de almacenamiento
// std::vector<Ogre::SceneNode*> enemies;
// std::vector<Ogre::SceneNode*> projectiles; 

// void createEnemy(Ogre::SceneManager* sceneMgr) {
//     Ogre::Entity* enemyEntity = sceneMgr->createEntity("ninja.mesh");
//     Ogre::SceneNode* enemyNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
//     enemyNode->attachObject(enemyEntity);
//     enemyNode->setPosition(Ogre::Vector3(rand() % 400 - 200, 0, rand() % 400 - 200));
//     enemyNode->setScale(0.1f, 0.1f, 0.1f);
//     enemies.push_back(enemyNode);
// }


// void createProjectile(Ogre::SceneManager* sceneMgr, Ogre::SceneNode* playerNode) {
//     Ogre::Entity* projectileEntity = sceneMgr->createEntity("Sphere.mesh");
//     Ogre::SceneNode* projectileNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
//     projectileNode->attachObject(projectileEntity);

//     // Posicionar el proyectil en la posición actual del jugador
//     projectileNode->setPosition(playerNode->getPosition());
//     projectileNode->setScale(0.05f, 0.05f, 0.05f); // Ajustar la escala del proyectil
//     projectiles.push_back(projectileNode);
// }



void GunBrosApp::setup() {

//     // Ogre::ConfigFile cf;
//     // cf.load("resources.cfg");

//     // Ogre::String name, locType;
//     // Ogre::ConfigFile::SettingsBySection_ settings = cf.getSettingsBySection();
//     // for (const auto& section : settings) {
//     //     for (const auto& pair : section.second) {
//     //         locType = pair.first;
//     //         name = pair.second;
//     //         Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, locType);
//     //     }
//     // }

//     // Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();


    // Configuración básica de Ogre
    OgreBites::ApplicationContextBase::setup();
    sceneMgr = getRoot()->createSceneManager();

    // Crear una cámara
    Ogre::Camera* camera = sceneMgr->createCamera("MainCam");
    camera->setAutoAspectRatio(true);
    camera->setNearClipDistance(5);
    
    // Crear un nodo para la cámara
    camNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
    camNode->attachObject(camera);
    camNode->setPosition(0, 100, 200);
    camNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TransformSpace::TS_WORLD);

    // Crear una ventana de visualización
    Ogre::RenderWindow* window = getRenderWindow();
    window->addViewport(camera);

//     // Crear una luz direccional usando un nodo
//     Ogre::Light* directionalLight = sceneMgr->createLight("DirectionalLight");
//     directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
//     directionalLight->setDiffuseColour(Ogre::ColourValue(1, 1, 1));
//     directionalLight->setSpecularColour(Ogre::ColourValue(1, 1, 1));

//     Ogre::SceneNode* lightNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
//     lightNode->attachObject(directionalLight);
//     lightNode->setDirection(Ogre::Vector3(-1, -1, -1));


    Ogre::Light* light = sceneMgr->createLight("MainLight");
    Ogre::SceneNode* lightNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
    lightNode->attachObject(light);
    lightNode->setPosition(20, 80, 50);

    // Crear un plano para el suelo
    Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
    Ogre::MeshManager::getSingleton().createPlane(
        "ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane, 1500, 1500, 20, 20, //size 1500 x 1500
        true,
        1, 5, 5,
        Ogre::Vector3::UNIT_Z);

    Ogre::Entity* groundEntity = sceneMgr->createEntity("ground");
    Ogre::SceneNode* groundNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
    groundNode->attachObject(groundEntity);
    groundEntity->setCastShadows(false);
    groundEntity->setMaterialName("Examples/Rockwall");

    // Crear un nodo para el jugador
    playerEntity = sceneMgr->createEntity("ninja.mesh");
    playerNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
    playerNode->attachObject(playerEntity);
    playerNode->setPosition(0, 0, 0);
    playerNode->setScale(0.1f, 0.1f, 0.1f);
    playerNode->yaw(Ogre::Degree(180));


//     //// Crear un nodo para un enemigo 
//     Ogre::Entity* enemyEntity = sceneMgr->createEntity("ninja.mesh");
//     Ogre::SceneNode* enemyNode = sceneMgr->getRootSceneNode()->createChildSceneNode();
//     enemyNode->attachObject(enemyEntity);
//     enemyNode->setPosition(Ogre::Vector3(rand() % 400 - 200, 0, rand() % 400 - 200));


//     //Crear varios enemigos
//     for (int i = 0; i < 5; ++i) {
//         createEnemy(sceneMgr);
//     }


//     // Registrar el listener de entrada
//     addInputListener(this);
}

// bool GunBrosApp::keyPressed(const OgreBites::KeyboardEvent& evt) {
//     const float speed = 10.0f;

//     if (evt.keysym.sym == SDLK_w) {
//         playerNode->translate(0, 0, -speed * 0.1f, Ogre::Node::TS_LOCAL);
//     } else if (evt.keysym.sym == SDLK_s) {
//         playerNode->translate(0, 0, speed * 0.1f, Ogre::Node::TS_LOCAL);
//     } else if (evt.keysym.sym == SDLK_a) {
//         playerNode->translate(-speed * 0.1f, 0, 0, Ogre::Node::TS_LOCAL);
//     } else if (evt.keysym.sym == SDLK_d) {
//         playerNode->translate(speed * 0.1f, 0, 0, Ogre::Node::TS_LOCAL);
//     } else if (evt.keysym.sym == SDLK_SPACE) {
//         createProjectile(sceneMgr, playerNode);
//     } else if (evt.keysym.sym == SDLK_ESCAPE) {
//         getRoot()->queueEndRendering();
//     }

//     return true;
// }

// bool GunBrosApp::mouseMoved(const OgreBites::MouseMotionEvent& evt) {
//     playerNode->yaw(Ogre::Degree(-evt.xrel * 0.1f));
//     return true;
// }

// void GunBrosApp::frameRendered(const Ogre::FrameEvent& evt) {
//     const Uint8* state = SDL_GetKeyboardState(nullptr);
//     const float speed = 10.0f * evt.timeSinceLastFrame;

//     // Movimiento con teclas WASD
//     if (state[SDL_SCANCODE_W]) {
//         playerNode->translate(0, 0, -speed, Ogre::Node::TS_LOCAL);
//     }
//     if (state[SDL_SCANCODE_S]) {
//         playerNode->translate(0, 0, speed, Ogre::Node::TS_LOCAL);
//     }
//     if (state[SDL_SCANCODE_A]) {
//         playerNode->translate(-speed, 0, 0, Ogre::Node::TS_LOCAL);
//     }
//     if (state[SDL_SCANCODE_D]) {
//         playerNode->translate(speed, 0, 0, Ogre::Node::TS_LOCAL);
//     }

//     // Hacer que la cámara siga al jugador
//     camNode->setPosition(playerNode->getPosition() + Ogre::Vector3(0, 20, 50));
//     camNode->lookAt(playerNode->getPosition(), Ogre::Node::TS_WORLD);

//     // Mover enemigos hacia el jugador
//     for (auto& enemyNode : enemies) {
//         Ogre::Vector3 direction = playerNode->getPosition() - enemyNode->getPosition();
//         direction.normalise();
//         enemyNode->translate(direction * evt.timeSinceLastFrame * 20.0f, Ogre::Node::TS_LOCAL);
//     }

//     // Mover los proyectiles hacia adelante
//     for (auto& projectileNode : projectiles) {
//         projectileNode->translate(0, 0, -50.0f * evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
//     }

// }

int main(int argc, char** argv) {
    GunBrosApp app;
    app.initApp();
    app.getRoot()->startRendering();
    app.closeApp();
    return 0;
}






#ifndef GUNBROS_APP_H
#define GUNBROS_APP_H

#include <Ogre.h>
#include <OgreApplicationContextBase.h>
#include <OgreInput.h>
#include <OgreWindowEventUtilities.h>

class GunBrosApp : public OgreBites::ApplicationContextBase, public OgreBites::InputListener {
public:
    GunBrosApp();
    void setup() override;
    
    //bool keyPressed(const OgreBites::KeyboardEvent& evt) override;
    //bool mouseMoved(const OgreBites::MouseMotionEvent& evt) override;

    //virtual void frameRendered(const Ogre::FrameEvent& evt) override;

private:
    Ogre::Entity* playerEntity;
    Ogre::SceneNode* playerNode;
    Ogre::SceneNode* camNode;
    Ogre::SceneManager* sceneMgr;
};

#endif // GUNBROS_APP_H

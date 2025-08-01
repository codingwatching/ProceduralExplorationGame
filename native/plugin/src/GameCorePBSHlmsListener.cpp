#include "GameCorePBSHlmsListener.h"

#include "OgreHlmsPbs.h"
#include "OgreHlmsManager.h"
#include "OgreRoot.h"

namespace ProceduralExplorationGamePlugin
{

    float GameCorePBSHlmsListener::mTimeValue = 0.0f;
    Ogre::Vector3 GameCorePBSHlmsListener::mPlayerPosition = Ogre::Vector3::ZERO;
    Ogre::Vector3 GameCorePBSHlmsListener::mCustomValues = Ogre::Vector3::ZERO;

    GameCorePBSHlmsListener::GameCorePBSHlmsListener(){

    }

    GameCorePBSHlmsListener::~GameCorePBSHlmsListener(){

    }

    Ogre::uint32 GameCorePBSHlmsListener::getPassBufferSize(const Ogre::CompositorShadowNode *shadowNode, bool casterPass, bool dualParaboloid, Ogre::SceneManager *sceneManager) const {
        return sizeof(float) + sizeof(float) * 3 + sizeof(float) * 3;
    }

    float* GameCorePBSHlmsListener::preparePassBuffer(const Ogre::CompositorShadowNode *shadowNode, bool casterPass, bool dualParaboloid, Ogre::SceneManager *sceneManager, float *passBufferPtr){
        *passBufferPtr++ = mTimeValue;
        *passBufferPtr++ = mPlayerPosition.x;
        *passBufferPtr++ = mPlayerPosition.y;
        *passBufferPtr++ = mPlayerPosition.z;

        *passBufferPtr++ = mCustomValues.x;
        *passBufferPtr++ = mCustomValues.y;
        *passBufferPtr++ = mCustomValues.z;

        return passBufferPtr;
    }

    void GameCorePBSHlmsListener::preparePassHash(const Ogre::CompositorShadowNode *shadowNode, bool casterPass, bool dualParaboloid, Ogre::SceneManager *sceneManager, Ogre::Hlms *hlms){
        const Ogre::CompositorPass* p = sceneManager->getCurrentCompositorPass();
        if(!p) return;
        assert(p);
        if(p->getDefinition()->mIdentifier == 10){
            hlms->_setProperty("disableFog", true);
        }
        else if(p->getDefinition()->mIdentifier == 11){
            hlms->_setProperty("invisibleTerrain", true);
        }
        else if(p->getDefinition()->mIdentifier == 12){
            hlms->_setProperty("renderSceneDecorations", true);
            hlms->_setProperty("disableDefaultPSBody", true);
            hlms->_setProperty("disableFog", true);
        }
        else if(p->getDefinition()->mIdentifier == 13){
            hlms->_setProperty("disableDefaultPSBody", true);
            hlms->_setProperty("disableFog", true);
        }
    }
}

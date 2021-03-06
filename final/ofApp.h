//
//   CS 134 - Midterm Starter File - Fall 2018
//
//
//   This file contains all the necessary startup code for the Midterm problem Part II
//   Please make sure to you the required data files installed in your $OF/data directory.
//
//                                             (c) Kevin M. Smith  - 2018
#pragma once

#include "ofMain.h"
#include  "ofxAssimpModelLoader.h"
#include  "ofxGui.h"
#include "ParticleSystem.h"
#include "ParticleEmitter.h"
#include "box.h"
#include "ray.h"
#include "Octree.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void drawAxis(ofVec3f);
		void initLightingAndMaterials();
		void savePicture();
		void toggleWireframeMode();
		void togglePointsDisplay();
        void checkCollision(); //Stephanie
        void checkFrontCollision(); //Stephanie
        void checkBackCollision(); //Stephanie
        void checkLeftCollision(); //Stephanie
        void checkRightCollision(); //Stephanie
        void playEngineSound(); //Stephanie
        bool bSoundPlaying; //Stephanie
        ofSoundPlayer engineSound;
    
        //Stephanie
        void loadVbo();
        // textures
        ofTexture  particleTex;
        // shaders
        ofVbo vbo;
        ofShader shader;
    
        ofColor particleColor;
    
        void toggleSelectTerrain();
        void toggleDrawBoundingBox();  //Stephanie
        void setCameraTarget();
        bool  doPointSelection();
        void drawBox(const Box &box);
        void drawMovingBox(const Box &box, const ofVec3f &offset); //Stephanie
        Box meshBounds(const ofMesh &, float scale);
        void subDivideBox8(const Box &b, vector<Box> & boxList);
    
        bool mouseIntersectPlane(ofVec3f planePoint, ofVec3f planeNorm, ofVec3f &point);
    
        Box boundingBox;
        Box landerBox;          //Stephanie
        ofxAssimpModelLoader mars, marsTextured, rover;
        bool bPointSelected;
        bool bRoverLoaded;
        bool bTerrainSelected;
        bool bCollision;  //Stephanie
        bool bSideCollision;  //Stephanie
        bool bDrawBounding; //Stephanie
    
        ofVec3f selectedPoint;
        ofVec3f intersectPoint;
    
        ofVec3f contactPoint; //Stephanie
    
        ofVec3f contactPointFront; //Stephanie
        ofVec3f contactPointBack; //Stephanie
        ofVec3f contactPointRight; //Stephanie
        ofVec3f contactPointLeft; //Stephanie
        Octree myTree;
        TreeNode selectedNode;
    
    
    
        const float selectionRange = 4.0;

		ofEasyCam cam;
		ofxAssimpModelLoader lander, landerTextured; //Nicholas
		ofLight light;
        ofLight keyLight; //Stephanie
		ofImage backgroundImage;
		ofCamera *theCam = NULL;
		ofCamera trackingCam; //Nicholas
		ofCamera frontCam; //Nicholas
		ofCamera downCam; //Nicholas

		bool bAltKeyDown;
		bool bCtrlKeyDown;
		bool bWireframe;
		bool bDisplayPoints;
	
		bool bBackgroundLoaded = false;
		bool bLanderLoaded = false;
    
        ParticleEmitter emitter;
        ParticleEmitter engineEmitter;
        ParticleEmitter engineEmitter2;
        TurbulenceForce* turbForce;
        GravityForce* gravityForce;
        ThrustForce* thrustForceLunar;
    
        TurbulenceForce* turbForce2;
        GravityForce* gravityForce2;
        ThrustForce* thrustForceLunar2;
    
        ImpulseForce* impulseForce;
    
        //GUI - Stephanie
        ofxPanel gui;
        ofxFloatSlider gravity;
        ofxFloatSlider restitution;
	

};

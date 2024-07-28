#include "VertexObjects.hpp"
#include <iostream>



VertexObjects::VertexObjects(const float  (&GeoShapes)[Objects::CubeSize], int GeoSize)
: m_aVertices(GeoShapes)
, m_iGeoSize(GeoSize)
{
   
   if (sizeof(m_aVertices)/sizeof(float)  != GeoSize)
   {
        Service::Utility::Print("Object Size Is Wrong") ;
        exit(0);
   }
   else
   {
    Setup() ;
   }
   
   
   
}

VertexObjects::~VertexObjects()
{
}


void VertexObjects::Setup() 
{   
    // Shader Processing 
    Shader oShader("../src/Shader.vs", "../src/Shader.fs");

    glGenVertexArrays(1, &m_iVAO);
    glGenBuffers(1, &m_iVBO);
    glBindVertexArray(m_iVAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, m_iVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_aVertices), m_aVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 8*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE, 8*sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);



}   
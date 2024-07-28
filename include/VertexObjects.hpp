#ifndef VERTEXOBJECTS_HPP
#define VERTEXOBJECTS_HPP

#include <glad/glad.h>
#include "utils.hpp"
#include "Shader.hpp"



class VertexObjects
{
private:
   
public:

    explicit VertexObjects(const float (&)[Objects::CubeSize], int );
    ~VertexObjects();

private :
    void Setup() ;    
    GLuint m_iVAO;
    GLuint m_iVBO;
    const float (&m_aVertices)[Objects::CubeSize];
    const int m_iGeoSize;

public :
   int GetVAO() const { return m_iVAO; }
    
};



#endif
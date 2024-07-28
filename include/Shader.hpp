#ifndef SHADER_HPP 
#define SHADER_PP 

#include <glad/glad.h>
#include <fstream>
#include <sstream> 
#include "utils.hpp"

class Shader 
{
    public :
        Shader() = delete ;
        explicit Shader(const char * vertexSourcePath, const char * fragmetnSourcePath);
        virtual ~Shader();
        void UseProgram() const;
        
        void setBool(const std::string &, bool ) const ;
        void setInt(const std::string &, int ) const;
        void setFloat(const std::string &, float) const;


        GLuint shaderProgram;

    private :
        void ReadSourceFile(std::string& , const std::string&) const ;

};

#endif 
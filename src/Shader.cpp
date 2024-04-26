#include <glad/gl.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Shader.hpp"

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath) {
    std::ifstream vertexShaderStr(vertexShaderPath);
    std::ifstream fragmentShaderStr(fragmentShaderPath);
    std::stringstream vertexSrc;
    std::stringstream fragmentSrc;

    if(!(vertexShaderStr.is_open() && fragmentShaderStr.is_open())){
        std::cerr << "Could not open files" << std::endl;
        return;
    }
    vertexSrc   << vertexShaderStr.rdbuf();
    fragmentSrc << fragmentShaderStr.rdbuf();

    std::string v = vertexSrc.str();
    std::string f = fragmentSrc.str();


    unsigned int vertex;
    unsigned int fragment;
    const char *vsSrc = v.c_str();
    const char *fsSrc = f.c_str();

    vertex   = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vsSrc, nullptr);
    glCompileShader(vertex);

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fsSrc, nullptr);
    glCompileShader(fragment);
    //std::cout << vsSrc << std::endl;
    //std::cout << fsSrc << std::endl;

    unsigned int program;
    program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    this->ID = program;
    printErrorLinking();

}

void Shader::printErrorLinking() const {
    int linkStatus;
    int logLength;
    glGetProgramiv(ID, GL_LINK_STATUS, &linkStatus);
    glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &logLength);
    char log[512];
    if(!linkStatus){
        glGetProgramInfoLog(ID, logLength, nullptr, log );
        std::cerr << "Error Linking: " << log << std::endl;
        return;
    }
}

void Shader::deleteProgram() {
    glDeleteProgram(ID);
}

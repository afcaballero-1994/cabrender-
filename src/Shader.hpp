#pragma once
#include <string>
struct Shader{
    unsigned int ID;
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
    void printErrorLinking() const;
    void deleteProgram();
};